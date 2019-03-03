#include <iostream>
#include <cmath>
#include <chrono>

#define ll long long
#define LIMIT 20

using namespace std;

bool isPrime[LIMIT + 1];

void sieveOfEratosthenes() {
    //sieve of Eratosthenes to get prime number
    for(int i = 2; i <= LIMIT; ++i) isPrime[i] = true;

    for(int i = 2; i <= sqrt(LIMIT); ++i) {
        if(!isPrime[i]) continue;
         
        for(int j = i+i; j <= LIMIT; j += i) isPrime[j] = false;
    }
}

ll getSmallestMultiple() {
    ll mul = 1;

    for(int i = 2; i <= LIMIT; ++i) {
        if(isPrime[i]) {
            int max = i;

            if(i <= sqrt(LIMIT)) {
                //if i = 2, 2^4 is one of the factor in answer.
                while(max*i <= LIMIT) max *= i;
            }

            mul *= max;
        }
    }

    return mul;
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    sieveOfEratosthenes();
    ll res = getSmallestMultiple();

    auto end = chrono::high_resolution_clock::now();

    chrono::nanoseconds nano = end - start;

    cout << "result: " << res << "\ntime: " << nano.count() << " nanoseconds\n";    

    return 0;
}
