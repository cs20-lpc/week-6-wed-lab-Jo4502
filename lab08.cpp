#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned n, unsigned result = 1);
unsigned fib(unsigned n , unsigned a = 0, unsigned b = 1);
unsigned mult(unsigned x, unsigned y, unsigned result = 0);
unsigned power(unsigned x, unsigned y, unsigned result = 1);
unsigned product(unsigned x, unsigned y, unsigned result = 1);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * 
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

unsigned fact(unsigned n, unsigned result) {
    // base case
    if (n <= 1) {
        return result;
    }
    // recursive case
    return fact(n - 1, result * n);
}

unsigned fib(unsigned n, unsigned a, unsigned b) {
    // base case
    if (n == 0) {
        return a;
    }
    // recursive case
    return fib(n - 1, b, a + b);
}

unsigned mult(unsigned x, unsigned y, unsigned result) {
    // base case
    while (y > 0) {
        result += x;
        y--;
    }
    // recursive case
    return result;
}

unsigned power(unsigned x, unsigned y, unsigned result) {
    // base case
    if (y == 0) {
        return result;
    }
    // recursive case
    return power(x, y - 1, result * x);
}

unsigned product(unsigned x, unsigned y, unsigned result) {
    //base case
    if (x > y) {
        return result;
    }
    // recursive case
    return product(x + 1, y, result * x);
}
