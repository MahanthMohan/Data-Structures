#include <iostream>
#include <string>
#include <chrono>
#define SORT_MAX_SIZE 16

/**
 * Name: Mahanth Mohan
 * Class: CIS 022C
 * Section: 051Z
 * Assignment: #1
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
//      if (n < 2)
//          return false
//      end if
//
//      j = 2
//      loop (j < n)
//          q = n/j;
//          mod = n - q * j
//          if (mod is 0)
//              return false
//          end if
//      end loop
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

/**
 * Name: Mahanth Mohan
 * Class: CIS 022C
 * Section: 051Z
 * Assignment: #1
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
//   if (divisor < number && number is divisible by divisor)
//      return false
//   else if (divisor >= number)
//      return true
//   end if
//   return IsPrimeRecur(number, divisor + 1)
// end IsPrimeRecur
bool IsPrimeRecur(int number, int divisor) {
    // Base cases
    if (divisor < number && !(number % divisor)) {
        std::cout << "Leaving " << __func__ << std::endl;
        return false;
    } else if (divisor >= number) {
        std::cout << "Leaving " << __func__ << std::endl;
        return true;
    }

    // Recursive case => inc divisor until base cond is reached
    return IsPrimeRecur(number, divisor + 1);
}

/**
 * Name: Mahanth Mohan
 * Class: CIS 022C
 * Section: 051Z
 * Assignment: #1
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
//   isPrime = IsPrimeRecur(arr, len)
//   if (len == 0)
//      return true
//   else if (!isPrime)
//      return false
//   end if
//   return IsArrayPrimeRecur(arr, len + 1)
// end IsArrayPrimeRecur
bool IsArrayPrimeRecur(int* arr, int len) {
    std::cout << "Entering IsPrimeRecur" << std::endl;
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

int main(int argc, const char* argv[]) {
    int len;
    std::cout << "NumInts = ";
    std::string len_str;
    std::getline(std::cin, len_str);
    len = std::stoi(len_str);
    int* arr;
    if (len > SORT_MAX_SIZE) {
        len = SORT_MAX_SIZE;
    }
    
    arr = new int[len];
    std::string input_data;
    std::string temp;
    std::cout << "Ints = ";
    std::getline(std::cin, input_data);
    int arr_idx = 0;
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

    for (int i = 0; i < len; i++) {
            std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bool isPrime = IsArrayPrimeIter(arr, len);
    if (isPrime) {
        std::cout << "Prime Array using iteration" << std::endl;
    } else {
        std::cout << "Not a Prime Array using iteration" << std::endl;
    }


    std::cout << "Entering IsArrayPrimeRecur" << std::endl;
    isPrime = IsArrayPrimeRecur(arr, len);
    if (isPrime) {
        std::cout << "Prime Array using recursion" << std::endl;
    } else {
        std::cout << "Not a Prime Array using recursion" << std::endl;
    }
}