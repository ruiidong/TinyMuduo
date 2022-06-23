#pragma once

class Channel;
class EventLoop
{
public:
    void updateChannel(Channel*);
    void removeChannel(Channel*);
private:
};