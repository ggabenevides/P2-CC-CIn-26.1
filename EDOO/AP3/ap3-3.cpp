#include <iostream>

long double factorial_recursive (unsigned int n){
    if (n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n*factorial_recursive(n-1);
    }
}

long double factorial_loop (unsigned int n){
    int temp = 1;
    long double result = 1.0;
    while(temp <= n){
        result *= temp;
        temp++;
    }
    return result;
}

int main(){
    for (int i = 1; i <=10; i++){
        long double result_recursive = factorial_recursive(i);
        long double result_loop = factorial_loop(i);
        std::cout << "Factorial of " << i << " using recursive function: " << result_recursive << std::endl;
        std::cout << "Factorial of " << i << " using loop function: " << result_loop << std::endl;
        std::cout << std::endl;
    }
}