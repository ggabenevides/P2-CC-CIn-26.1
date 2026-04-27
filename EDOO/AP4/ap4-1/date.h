#ifndef _DATE_
#define _DATE_

class Date
{
    private:
        int month, day, year;
        
    public:
        void init(int month, int day, int year);
        void init(void);
        void print(void);

};
#endif