// The question
// Write the complement of fib ( ) : a function that takes as its sole
// argument a Fibonacci number and returns its ordinal position
// in the series. Be sure to test for arguments that are not Fibonacci
// numbers. How should your function process an argument of l ?

#include <stdio.h>
#include <math.h>

int isPerfectSquare(int x) {
    int s = sqrt(x);
    return s * s == x;
}

int isFibonacci(int n) {
    // A number n is Fibonacci if and only if one of (5*n*n + 4) or (5*n*n - 4) is a perfect square
    return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

int findFibOrdinal(int num) {
    if (num <= 0) {
        return -1; // Invalid input, return -1 or handle it as you prefer
    }

    int fibIndex = 0;
    int currentFib = 0;
    int nextFib = 1;

    while (currentFib < num) {
        int temp = nextFib;
        nextFib += currentFib;
        currentFib = temp;
        fibIndex++;
    }

    if (currentFib == num || isFibonacci(num)) {
        return fibIndex;
    } else {
        return -1; // Input is not a Fibonacci number
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int fibOrdinal = findFibOrdinal(num);

    if (fibOrdinal >= 0) {
        printf("%d is a Fibonacci number at position %d in the series.\n", num, fibOrdinal);
    } else {
        printf("%d is not a Fibonacci number.\n", num);
    }

    return 0;
}
