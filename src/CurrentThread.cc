#include "CurrentThread.h"

__thread int CurrentThread::t_cachedTid = 0;

void CurrentThread::cacheTid()
{
    if (t_cachedTid == 0)
    {
        t_cachedTid = gettid();
    }
}

pid_t CurrentThread::gettid()
{
    return static_cast<pid_t>(::syscall(SYS_gettid));
}