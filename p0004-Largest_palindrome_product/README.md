# Problem 0004 - Largest palindrome product
## 1. Problem
___A palindromic number(* 회문 수) reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.___

___Find the largest palindrome made from the product of two 3-digit numbers.___

__https://projecteuler.net/problem=4__

## 2. Solution
#### (1) pesudo code(just Brute-force)
```cpp
isPalindromicNumber(num) {
    str <- n converted string;
    comp_str <- reversed str;

    if(str is comp_str) then return true;

    return false;
}

	...

	max <- 0;

    for i <- 100 to 999 {
        for j <- i to 999 {
            prod <- i * j;

            if(isPalindromicNumber(prod) && prod > max) max <- prod;
        }
    }

	...
	
```

But If you want to apply any mathematical formula, I show you below.

#### (2) Multiple of 11(mathematical formula in only this problem)
This problem has range from 10000(100x100) to 998001(999x999). I expect that answer is 6-digit number because of largest palindromic number in range.
So, It is converted to 'abccba'. and then
	
	100000*a + 10000*b + 1000*c + 100*c + 10*b + a = 100001*a + 10010*b + 1100*c
    
    we can make simple...
    11*(9091*a + 910*b + 100c)
    

