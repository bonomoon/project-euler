#include <cstdio>

#define ll long long
#define MOD 1000000007

// n(n+1)(2n+1)/6
// pow(

ll fast_pow(ll a, ll b) {
    if(b == 0) return 1;

    ll tmp = fast_pow(a, b/2);

    if(b % 2 == 0) {
        return (tmp * tmp) % MOD; 
    } else {
        return ((((tmp * tmp) % MOD)) * a) % MOD;
    }
}

inline int sum_of_square(int n) {
    return n*(n + 1)*(2*n + 1) / 6;
}

inline ll square_of_sum(int n) {
    int sum = n*(n + 1) / 2;

    return fast_pow(sum, 2);
}

int main () {
    const int n = 100;

    ll res = square_of_sum(n) - sum_of_square(n);

    printf("%lld\n", res); 

    return 0;
}
