#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        std::cin >> j;
        sum += j;
    }
    std::cout << "Average = " << sum / n << std::endl; 

}