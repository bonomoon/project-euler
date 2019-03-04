# Problem 0005 - Smallest multiple
## 1. Problem
___2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.___

___What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?___

__https://projecteuler.net/problem=5__

## 2. Solution
I solved it in 2 ways. At first I thought that using prime number is the best solution. But, I found other way using lcm(least-common-multiple). I was wondering which the way is optimized between them. So, I wrote two programs using chrono library to find execution time in C++.

ps. I executed it 1000 times to get average execution time. Winner is second one! :)

#### (1) Using prime number
```cpp
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
	
```
##### Result
![result_1](https://raw.githubusercontent.com/bonomoon/project_euler/master/img/p0005/p0005_result1.PNG)

#### (2) Using least-common-multiple(lcm)
``` cpp
#include <iostream>
#include <chrono>

#define ll long long
#define LIMIT 20

using namespace std;

// get greatest common divisor (최대공약수)
inline ll gcd(ll a, ll b) {
    return b == 0? a:gcd(b, a%b); // if a > b
}

// get least common multiple (최소공배수)
inline ll lcm(ll a, ll b) {
    if(a > b) return (a*b)/gcd(a, b);

    return (a*b)/gcd(b, a);
}

// Smallest multiple is least common multiple from start to end.
// Start number tends to be LIMIT number / 2 + 1 because of my experience. (I can't prove it in mathmatical ways haha)
ll getSmallestMultiple() {
    int start = LIMIT/2 + 1;
    int res = start + 1;

    for(int i = start; i <= LIMIT; ++i) {
        res = lcm(i, res);
    }

    return res;
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    ll res = getSmallestMultiple();

    auto end = chrono::high_resolution_clock::now();

    chrono::nanoseconds nano = end - start;

    cout << "result: " << res << "\ntime: " << nano.count() << " nanoseconds\n";    

    return 0;
}

```
##### Result
![result_2](https://raw.githubusercontent.com/bonomoon/project_euler/master/img/p0005/p0005_result2.PNG)
