#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

bool isPalindromicNumber(int n) {
    string str = to_string(n);
    string comp_str = str;

    reverse(comp_str.begin(), comp_str.end());

    if(!str.compare(comp_str)) return true;

    return false;
}

int main() {
    int max = 0;

    for(int i = 100; i < 1000; ++i) {
        for(int j = i; j < 1000; ++j) {
            int mul = i * j;

            if(isPalindromicNumber(mul) && mul > max) max = mul;
        }
    }

    printf("%d\n", max);

    return 0;
}
