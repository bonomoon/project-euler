#include <cstdio>
#include <cstdlib>

#define LIMIT 999

// For sum of multiples of n, we use arithmetic sequence (등차수열 공식).
// m -> the first term to multiply
// l -> the last term = a + (n-1)d
// n -> n times
// sum of multiples = n(m + l) / 2

int sum_of_multiple(int m) {
    int n = LIMIT/m;
    int l = n*m;

    return n*(m+l)/2;
}

int main() {
    int res = sum_of_multiple(3) + sum_of_multiple(5) - sum_of_multiple(15);

    printf("%d", res);

    return 0;
}

