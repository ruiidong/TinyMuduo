#include "Timestamp.h"

Timestamp Timestamp::now()
{
    struct timeval tv;
    gettimeofday(&tv,nullptr);
    int64_t seconds = tv.tv_sec;
    return Timestamp(seconds*kMicroSecondsPerSecond + tv.tv_usec);
}


string Timestamp::toString() const
{
    char buf[64] = {0};
    time_t seconds = static_cast<time_t>(microSecondsSinceEpoch_/kMicroSecondsPerSecond);
    struct tm tm_time;
    localtime_r(&seconds,&tm_time);

    snprintf(buf,sizeof buf,"%4d%02d%02d %02d:%02d:%02d",
            tm_time.tm_year + 1900,tm_time.tm_mon + 1,tm_time.tm_mday,
            tm_time.tm_hour,tm_time.tm_min,tm_time.tm_sec);

    return buf;
}


