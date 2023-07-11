#include <iostream>
#include <cmath>
#include <string>
#define SORT_MAX_SIZE 16

/**
 * Name: Mahanth Mohan
 * Lab: #1
 * This assignment involves the implementation and recursion based algorithms for finding
 * if a sequence of integers are prime, by checking if the only factors for an integer n
 * in the array are 1 and n. In addition, it covers the aspect of time complexity when
 * checking divisors, running in O(sqrt(n)) time each time a factor is checked.
*/

/**
 * Name: Mahanth Mohan
 * Class: CIS 022C
 * Section: 051Z
 * Lab: #1
 * Due Date: 07/11/2023
*/
// This algorithm iteratively checks if an array of integers are prime
// by checking if the number is not divisible by any numbers than 1 
// and itself, by checking if the integers between 2 and n are factors of n using a loop.
// Pre: arr - the array of integers to check if prime or not
//      len - The length of the array
// Post: 
// Return: boolean of true or false, representing if the given array of integers are prime. 
// Pseudocode:
// Algorithm IsArrayPrimeIter(arr, len):
//  i = 0
//  loop (i < len)
//      n = arr[i]
//      divEnd = sqrt(n) + 1 
//      if (n < 2)
//          return false
//      end if
//
//      j = 2
//      loop (j < divEnd)
//          q = n/j;
//          mod = n - q * j
//          if (mod is 0)
//              return false
//          end if
//          j = j + 1
//      end loop
//      i = i + 1
//  end loop
// end IsArrayPrimeIter
bool IsArrayPrimeIter(int* arr, int len) {
    std::cout << "Entering " << __func__ << std::endl;
    for (int i = 0; i < len; i++) {
        int n = arr[i];
        if (n <= 1) {
            std::cout << "Leaving " << __func__ << std::endl;
            return false;
        }

        int divEnd = (int) (sqrt(n) + 1);
        for (int j = 2; j < divEnd; j++) {
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

/**
 * Name: Mahanth Mohan
 * Class: CIS 022C
 * Section: 051Z
 * Lab: #1
 * Due Date: 07/11/2023
*/
// This algorithm recursively checks if a given integer n is prime,
// by checking if the only factors of the number are 1
// and itself, by checking if the integers between 2 and n are factors of n.
// Pre: number - the integer to be validated if prime or not
//      divisor - the starting integer to check if a factor of number or not (default: 2)
// Post:
// Return: boolean of true or false, representing if the given integer n is prime.
// Pseudocode:
// Algorithm IsPrimeRecur(number, divisor)
//   divEnd = sqrt(number) + 1;
//   if (number < 2)
//      return false
//   else if (divisor < divEnd && number is divisible by divisor)
//      return false
//   else if (divisor >= divEnd)
//      return true
//   end if
//   return IsPrimeRecur(number, divisor + 1)
// end IsPrimeRecur
bool IsPrimeRecur(int number, int divisor) {
    std::cout << "Entering " << __func__ << std::endl;
    int divEnd = (int) (sqrt(number) + 1);
    // Base cases
    if (number < 2) {
        return false; 
    } else if (divisor < divEnd && !(number % divisor)) {
        std::cout << "Leaving " << __func__ << std::endl;
        return false;
    } else if (divisor >= divEnd) {
        std::cout << "Leaving " << __func__ << std::endl;
        return true;
    }

    std::cout << "Leaving " << __func__ << std::endl;
    // Recursive case => inc divisor until base cond is reached
    return IsPrimeRecur(number, divisor + 1);
}

/**
 * Name: Mahanth Mohan
 * Class: CIS 022C
 * Section: 051Z
 * Lab: #1
 * Due Date: 07/11/2023
*/
// This algorithm checks if an array of integers are prime, by
// recursively checking if the value at each index in the array is prime
// using the IsPrimeRecur(n, d) method. 
// Pre: arr - The array of integers to check if prime
//      len - The length of the array
// Post:
// Return: boolean of true or false, representing if the given array of integers is prime.
// Pseudocode:
// Algorithm IsArrayPrimeRecur(arr, len)
//   num = arr[len - 1]
//   isPrime = IsPrimeRecur(arr, num)
//   if (len == 0)
//      return true
//   else if (!isPrime)
//      return false
//   end if
//   return IsArrayPrimeRecur(arr, len - 1)
// end IsArrayPrimeRecur
bool IsArrayPrimeRecur(int* arr, int len) {
    std::cout << "Entering " << __func__ << std::endl;
    int num = arr[len - 1];
    bool isPrime = IsPrimeRecur(num, 2);
    if (len == 0) {
        std::cout << "Leaving " << __func__ << std::endl;
        return true;
    } else if (!isPrime) {
        std::cout << "Leaving " << __func__ << std::endl;
        return false;
    } 

    std::cout << "Leaving " << __func__ << std::endl;
    return IsArrayPrimeRecur(arr, len - 1); 
}

int main(int argc, const char* argv[]) {
    int len;
    // Collecting user input for the size of the array
    std::cout << "NumInts (max size: 16) = ";
    std::string len_str;
    std::getline(std::cin, len_str);
    len = std::stoi(len_str);
    int* arr;
    // Selection statement to default array to MAX_SORT_SIZE in case len > 16
    if (len > SORT_MAX_SIZE) {
        len = SORT_MAX_SIZE;
    }
    
    arr = new int[len];
    std::string input_data;
    std::string temp;
    std::cout << "Ints = ";
    std::getline(std::cin, input_data);
    int arr_idx = 0;
    // Splitting the input by space after getline() writes to the string
    for (int i = 0; i < input_data.length(); i++) {
        char c = input_data[i];
        if (c == ' ') {
            int num = std::stoi(temp);
            arr[arr_idx++] = num; 
            temp = "";
        } else if (i == input_data.length() - 1) {
            temp += c;
            arr[arr_idx++] = std::stoi(temp);
        } else {
            temp += c;
        }
    }

    // Print out the array
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Iteration call
    bool isPrime = IsArrayPrimeIter(arr, len);
    if (isPrime) {
        std::cout << "Prime Array using iteration" << std::endl;
    } else {
        std::cout << "Not a Prime Array using iteration" << std::endl;
    }

    // Recursion call
    isPrime = IsArrayPrimeRecur(arr, len);
    if (isPrime) {
        std::cout << "Prime Array using recursion" << std::endl;
    } else {
        std::cout << "Not a Prime Array using recursion" << std::endl;
    }

    // Cleanup
    delete[] arr;
}