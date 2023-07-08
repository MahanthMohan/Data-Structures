#include "prime_iterative.h"
#include "prime_recursive.h"
#include <iostream>

void helper(int* arr, size_t len) {
   bool isPrime = IsArrayPrimeRecur(arr, len);
   if (isPrime) {
      std::cout << "Array is prime" << std::endl;
   } else {
      std::cout << "Array is not prime" << std::endl;
   }
}

int main(int argc, const char* argv[]) {
   int nums1[] = {5, 37, 23, 79, 97, 11, 19};
   int nums2[] = {5, 6, 83, 21, 43};
   int nums3[] = {7, 31, 29, 89, 59};
   helper(nums1, 7);
   helper(nums2, 5);
   helper(nums3, 5);
}