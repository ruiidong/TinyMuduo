#pragma once
#include "noncopyable.h"
#include "Timestamp.h"
#include <map>
#include <vector>

using namespace std;

class Channel;
class EventLoop;
class Poller : noncopyable
{
public:
    using ChannelList = vector<Channel *>;

    Poller(EventLoop *loop);
    virtual ~Poller();

    virtual Timestamp poll(int timeoutMs, ChannelList *activeChannels) = 0;
    virtual void updateChannel(Channel *channel) = 0;
    virtual void removeChannel(Channel *channel) = 0;
    virtual bool hasChannel(Channel *channel) const;
    static Poller *newDefaultPoller(EventLoop *loop);

protected:
    using ChannelMap = map<int, Channel *>;
    ChannelMap channels_;

private:
    EventLoop *ownerLoop_;
};