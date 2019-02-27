#include<cstdio>

#define LIMIT 4000000

// A general term of fibonacci sequence -> f(n+2) = f(n+1) + f(n)
// cur -> f(n+2) or f(n+1)
// last -> f(n)
// tmp -> To store cur(f(n+1)) in last(f(n)) for the next loop  

int main() {
    int sum = 2;
    int tmp = 0, last = 1, cur = 2; 

    while(cur < LIMIT) {
        tmp = cur, cur += last, last = tmp;
        
        if(cur % 2 == 0) sum += cur;
    }

    printf("%d\n", sum);

    return 0;
}



    



