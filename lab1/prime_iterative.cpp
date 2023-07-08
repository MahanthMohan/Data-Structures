#include <cstddef>
#include <iostream>

bool IsArrayPrimeIter(int* arr, size_t len) {
    std::cout << "Entering " << __func__ << std::endl;
    for (size_t i = 0; i < len; i++) {
        int n = arr[i];
        if (n <= 1) {
            std::cout << "Leaving " << __func__ << std::endl;
            return false;
        }

        for (int j = 2; j < n; j++) {
            int q = n/j;
            int mod = n - q * j;
            if (!mod) {
                std::cout << "Leaving " << __func__ << std::endl;
                return false;
            }
        }
    }

    std::cout << "Leaving " << __func__ << std::endl;
    return true;
}