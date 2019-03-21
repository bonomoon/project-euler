#include <cstdio>
#include <cmath>

#define LIMIT 1000001

bool isPrime[LIMIT];

void sieve_of_erastothenes() {
    for (int i = 2; i < LIMIT; ++i) isPrime[i] = true;

    for(int i = 2; i < sqrt(LIMIT); ++i) {
        if(!isPrime[i]) continue;

        for(int j = i+i; j < LIMIT; j += i) isPrime[j] = false;
    }
}

int nth_prime(int n) {
    int cnt = 1;

    for(int i = 3; i < LIMIT; i += 2) {
        if(isPrime[i]) ++cnt;
        if(cnt == n) return i;
    }

    return 1; //when it can't find nth number
}

int main() {
    sieve_of_erastothenes();

    int res = nth_prime(10001);
    printf("%d\n", res);

    return 0;
}