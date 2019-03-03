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
