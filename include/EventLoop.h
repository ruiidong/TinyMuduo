#pragma once
#include "noncopyable.h"
#include "Timestamp.h"
#include "Poller.h"
#include "CurrentThread.h"

#include <functional>
#include <vector>
#include <atomic>
#include <memory>
#include <mutex>
using namespace std;

class Channel;
class EventLoop : noncopyable
{
public:
    using Functor = std::function<void()>;

    EventLoop();
    ~EventLoop();

    void loop();

    void quit();

    void runInLoop(Functor cb);
    void queueInLoop(Functor cb);
    void wakeup();
    void updateChannel(Channel *);
    void removeChannel(Channel *);
    bool hasChannel(Channel *);

    //bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }
    bool eventHanding() const { return eventHanding_; }

private:
    void handleRead();
    void doPendingFunctors();

    using ChannelList = std::vector<Channel *>;

    bool looping_;
    std::atomic_bool quit_;
    bool eventHanding_;
    bool callingPendingFunctors_;
    int64_t iteration_;
    //const pid_t threadId_;
    Timestamp pollReturnTime_;
    std::unique_ptr<Poller> poller_;
    int wakeupFd_;

    std::unique_ptr<Channel> wakeupChannel_;

    ChannelList activeChannels_;
    Channel *currentActiveChannel_;

    std::mutex mutex_;
    std::vector<Functor> pendingFunctors_;
};