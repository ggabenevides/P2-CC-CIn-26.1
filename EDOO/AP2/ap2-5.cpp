#include <iostream>
#include <cstdlib>

int main(){
    
    unsigned short i;
    std::cin >> i;
    std::srand(i);
    int count(1);

    while (count <= 20){
        int rand_n = rand();
        if (rand_n >= 0 && rand_n <= 100){
            std::cout << "Number "<< count << ": "<< rand_n << std::endl;
            count++;
        }
    }
    std::cout << "Program finished with success!" << std::endl;
    return 0;
}