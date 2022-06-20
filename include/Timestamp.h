#pragma once
#include <string>
#include <sys/time.h>

using namespace std;

class Timestamp
{
public:
    Timestamp()
        : microSecondsSinceEpoch_(0)
    {
    }

    explicit Timestamp(int64_t microSecondsSinceEpoch)
        : microSecondsSinceEpoch_(microSecondsSinceEpoch)
    {
    }

    string toString() const;

    static Timestamp now();

    static const int kMicroSecondsPerSecond = 1000 * 1000;

private:
    int64_t microSecondsSinceEpoch_;
};
