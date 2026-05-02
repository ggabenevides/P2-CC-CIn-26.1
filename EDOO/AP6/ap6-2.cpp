#include <iostream>
#include <stdarg.h>
using namespace  std;

int min(unsigned int n, ...);

int main()
{
    cout << "The minimum of (34, 47, 19, 22, 58) is: " << min(34, 47, 19, 22, 58, 0) << endl;
    return 0;
}

int min(unsigned int  n, ...)
{
    va_list args;
    int minarg, arg;
    if (n==0)
    {
        return 0;
    }
    va_start(args, n);
    minarg = n;
    while ((arg = va_arg(args, unsigned int)) != 0)
    {
        if (arg < minarg)
        {
            minarg = arg;
        }
    }
    va_end(args);
    return minarg;
}