# Problem 0003 - Largest prime factor
## 1. Problem
___The prime factors of 13195 are 5, 7, 13 and 29.___

___What is the largest prime factor of the number 600851475143 ?___

## 2. Solution
It is prime factorization(소인수 분해) problem. If you know Sieve of Eratosthenes, it is very easy. You can apply to solution.

#### (1) Sieve of Eratosthenes(에라토스테네스의 체)
__<https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes>__

#### (2) Pesudo code
```cpp
// prime factorization - 소인수분해

getLargestPrimeFactor(n) {
    num <- n;
    max <- 0;

    // divide by even number untill it is not divided
    while(num % 2 == 0) max <- 2, num <- num / 2;

    // divide the remainder by odd numbers
    // sqrt(num) is proved by Sieve of Eratosthenes
    for i <- 3 to sqrt(num) by i = i + 2 {
        while(num % i == 0) max <- i, num <- num / i;
    }

    // num(finally the remainder) or max is largest prime factor
    if(num > max) then return num;

    return max;
}

```