#pragma once

#include "Timestamp.h"
#include "noncopyable.h"
#include "CurrentThread.h"

#include <vector>
#include <atomic>
#include <unistd.h>
#include <memory>
#include <mutex>

using namespace std;

/*
                    EventLoop
                    ChannelList
       Channel                      Poller
                                    ChannelMap
                                                activeChannels
*/

class Poller;
class Channel;
class EventLoop : noncopyable
{
public:
    using Functor = std::function<void()>;

    EventLoop();
    ~EventLoop();

    void loop();
    void quit();

    Timestamp pollReturnTime() const {return pollReturnTime_;}
    int64_t iteration() const {return iteration_;}

    void runInLoop(Functor cb);
    void queueInLoop(Functor cb);

    void wakeup();
    void updateChannel(Channel* channel);
    void removeChannel(Channel* channel);
    bool hasChannel(Channel* channel);

    bool isInLoopThread() const { return threadId_ == CurrentThread::tid();}
    bool eventHandling() const {return eventHanding_;}

    static EventLoop* getEventLoopOfCurrentThread();

private:
    using ChannelList = std::vector<Channel*>;

    void handleRead();
    void doPendingFunctors();

    bool looping_;
    std::atomic_bool quit_;
    bool eventHanding_;
    bool callingPendingFunctors_;
    int64_t iteration_;
    const pid_t threadId_;
    Timestamp pollReturnTime_;
    std::unique_ptr<Poller> poller_;
    
    int wakeupFd_;
    std::unique_ptr<Channel> wakeupChannel_;

    ChannelList activeChannels_;
    Channel* currentActiveChannel_;

    std::mutex mutex_;
    std::vector<Functor> pendingFunctors_;
};