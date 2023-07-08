#include <iostream>

bool IsPrimeRecur(int number, int divisor) {
    // Base cases
    if (divisor < number && !(number % divisor)) {
        return false;
    } else if (divisor >= number) {
        return true;
    }

    // Recursive case => inc divisor until base cond is reached
    return IsPrimeRecur(number, divisor + 1);
}

bool IsArrayPrimeRecur(int* arr, size_t len) {
    std::cout << "Entering " << __func__ << std::endl;
    bool isPrime = IsPrimeRecur(arr[len - 1], 2);
    if (len == 0) {
        std::cout << "Leaving " << __func__ << std::endl;
        return true;
    } else if (!isPrime) {
        std::cout << "Leaving " << __func__ << std::endl;
        return false;
    } 

    return IsArrayPrimeRecur(arr, len - 1); 
}