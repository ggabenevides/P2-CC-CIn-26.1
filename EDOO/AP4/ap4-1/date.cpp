#include "date.h"
#include <iostream>
#include <ctime>

using namespace std;

void Date::print()
{
    cout << month << "-" << day << "-" << year << endl;
}

void Date::init(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

void Date::init()
{
    struct tm *ptr;
    time_t sec;

    time(&sec);
    ptr = localtime(&sec);

    month = ptr->tm_mon + 1;
    day = ptr->tm_mday;
    year = ptr->tm_year + 1900;
}