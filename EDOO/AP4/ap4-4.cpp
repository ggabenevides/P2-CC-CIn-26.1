#include <iostream>
using namespace std;

void sieveOfEratosthenes(int n) {
    // boolean array "isPrime[0..n]" and initialize all entries as true
    // value in isPrime[i] will be false if i is not a prime, else true

    bool isPrime[n + 1]; //create array

    for (int i = 0; i<n; i++){
        isPrime[i] = true; // initialize all values
    }
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not primes

    // verify for all other numbers starting from two
    for (int p = 2; p * p <= n; p++) { // only need to check until p^2 because if the number is a square root, then it is not a prime
        // if isPrime[p] is not changed, then it is a prime
        if (isPrime[p]) {
            // update all multiples of p starting from p*p
            // multiples smaller than p*p have already been marked
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    // display all prime numbers
    for (int p = 2; p <= n; p++) {
        if (isPrime[p])
            std::cout << p << " ";
    }
}

int main(){
    int n = 1000;
    sieveOfEratosthenes(n);
    cout << endl;

}