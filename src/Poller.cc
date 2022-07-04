#include "Poller.h"
#include "Channel.h"
#include "EPollPoller.h"

Poller::Poller(EventLoop *loop)
    : ownerLoop_(loop)
{
}

Poller::~Poller() = default;

bool Poller::hasChannel(Channel *channel) const
{
    auto it = channels_.find(channel->fd());
    return it != channels_.end() && it->second == channel;
}

Poller *Poller::newDefaultPoller(EventLoop *loop)
{
    return new EPollPoller(loop);
}