#include "MathLibrary.h"
#include <utility>
#include <limits.h>
static unsigned long long previous_;  // Previous value, if any
static unsigned long long current_;   // Current sequence value
static unsigned index_;               // Current seq. position
void fibonacci_init(
    unsigned long a, unsigned long b)
{
    index_ = 0;
    current_ = a;
    previous_ = b;
}
bool fibonacci_next()
{
    if ((ULONG_MAX - previous_ < current_) ||
        (UINT_MAX == index_))
    {
        return false;
    }
    if (index_ > 0)
    {
        previous_ += current_;
    }
    std::swap(current_, previous_);
    ++index_;
    return true;
}
unsigned long fibonacci_current()
{
    return current_;
}
unsigned int fibonacci_index()
{
    return index_;
}