#include <iostream> 

int main()
{
    for (int i = 1; i < 10; i++)
    {
        std::cout << i;
        for (int j = 1; j < 10; i++)
        {
            std::cout << i*j;
        }
        std::cout << std::endl;
    }
}