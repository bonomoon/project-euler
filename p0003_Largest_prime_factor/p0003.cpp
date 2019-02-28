#include <cstdio>
#include <cmath>

#define ll long long

// prime factorization - 소인수분해

ll getLargestPrimeFactor(ll n) {
    ll num = n;
    ll max = 0;

    // divide by even number untill it is not divided
    while(num % 2 == 0) max = 2, num /= 2;

    // divide the remainder by odd numbers
    // sqrt(num) is proved by Sieve of Eratosthenes
    for(ll i = 3; i <= sqrt(num); i += 2 ) {
        while(num % i == 0) max = i, num /= i;
    }

    // num(finally the remainder) or max is largest prime factor
    if(num > max) return num;

    return max;
}

int main() {
   const ll num = 600851475143;

   printf("%lld\n", getLargestPrimeFactor(6857));

   return 0;
}
