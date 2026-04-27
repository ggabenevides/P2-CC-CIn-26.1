#include "date.h"
#include <iostream>
using namespace std;

int main()
{
    Date today, birthday, aDate;

    today.init();
    birthday.init(11, 23, 2006);

    cout << "Today's date: ";
    today.print();

    cout << "Gabi's birthday: ";
    birthday.print();

    cout << "---------------------------" << endl;
    cout<< "Some tests:" << endl;
    aDate = today;
    aDate.print();

    Date *pDate = &birthday;
    pDate -> print();

    Date &holiday = aDate;
    holiday.init(12, 25, 2025);
    holiday.print();

    return 0;

}