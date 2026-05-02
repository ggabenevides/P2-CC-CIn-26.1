#include <iostream>

int main(){
    bool isPrime[1000]; //create array
    int counter(0);
    for (int i = 0; i < 1000; i++){
        isPrime[i] = true; //initialize all values as true
    }

    isPrime[0] = isPrime[1] = false; //0 and 1 are not primes

    for (int p = 2; p * p <= 1000; p++) //verify for all numbers between 2 and 1000
    {
        if (isPrime[p])
        {
            for (int m = p*p; m <= 1000; m += p)
            {
                isPrime[m] = false; //update all multiples of prime number as false
            }
        }
    }

    for (int j = 0; j <=1000; j++)
    {
        if (isPrime[j])
        {
            std::cout << j << " ";
            counter++;
        }

    }
    std::cout << "\n Total number of prime numbers between 0 and 1000: " << counter << std::endl;
}