#include <iostream>
#define MAX_VALUE 99999
#define MAX_SORT_SIZE 8

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
*/
// Sorts the palindromes in O(n^2) time complexity
void InsertionSort(int* arr, int start, int end) {
    for (int i = 1; i < end; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            } 
        }
    }
}

bool IsPalindrome(int value) {
    int num_len = 0;
    int value_cpy = value;
    for (int div10 = 10; value_cpy != 0; num_len++) {
        value_cpy /= div10;
    }

    int* digit_array = new int[num_len];
    int div10 = 1;
    // Update the array with digits and check for same digits here
    for (int i = 0; i < num_len; i++) {
        int digit = (value / div10) % 10;
        digit_array[i] = digit;
        div10 *= 10;
    }

    for (int j = 0; j < num_len / 2; j++) {
        if (digit_array[j] != digit_array[num_len - 1 - j]) {
            return false;
        }
    }

    // Default condition, all digits are same
    return true;
}

int* SortedPalindromes(int* arr, int len) {
    int* res = new int[len];
    int counter = 0;
    for (int i = 0; i < len; i++) {
        bool palindrome = IsPalindrome(arr[i]);
        if (palindrome) {
            res[counter] = arr[i];
            counter++;
        }
    }

    // Sorts the palindromes in ascending order
    InsertionSort(res, 0, counter);
    // Reverses the order of the array
    for (int i = 0; i < counter / 2; i++) {
        res[i] = res[counter - i];
    }

    return res;
}

int main(int argc, const char* argv[]) {
    std::string input_data;
    std::string temp;
    std::getline(std::cin, input_data);
    int* arr = new int[MAX_SORT_SIZE];
    int arr_idx = 0;

    // Splitting the input by space after getline() writes to the string
    for (int i = 0; i < input_data.length() && arr_idx < MAX_SORT_SIZE; i++) {
        char c = input_data[i];
        if (c == ' ') {
            int num = std::stoi(temp);
            if (num >= 0 && num <= MAX_VALUE) {
                arr[arr_idx++] = num;
            }

            temp = "";
        } else if (i == input_data.length() - 1) {
            temp += c;
            int num = std::stoi(temp);
            if (num == -1) {
                break;
            }

            if (num > 0 && num < MAX_VALUE) {
                arr[arr_idx++] = num;
            }
        } else {
            temp += c;
        }
    }

    int* result = SortedPalindromes(arr, arr_idx + 1);
    for (int i = 0; i <= arr_idx; i++) {
        if (result[i] != 0) {
            std::cout << result[i] << " ";
        }
    }

    std::cout << std::endl;
}