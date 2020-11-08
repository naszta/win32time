#ifndef WIN32_TIME_HEADER__
#define WIN32_TIME_HEADER__ 1

#include <time.h>

#ifdef _WIN32
namespace
{
    inline time_t timegm(struct tm *tm_)
    {
        return ::_mkgmtime(tm_);
    }
    inline time_t timelocal(struct tm *tm_)
    {
        return ::mktime(tm_);
    }
    inline struct tm* localtime_r(const time_t* time_, struct tm* tm_)
    {
        return ::localtime_s(tm_, time_) == 0 ? tm_ : nullptr;
    }
    inline struct tm* gmtime_r(const time_t* time_, struct tm* tm_)
    {
        return ::gmtime_s(tm_, time_) == 0 ? tm_ : nullptr;
    }
}
#endif

#endif