//4. Write a program to check whether a given string is a palindrome. Ignore spaces and differences between uppercase and lowercase letters.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int left, right, palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);   // Read a line of input from the user, including spaces

    left = 0;
    right = strlen(str) - 1;  // Set right to the index of the last character in the string

    // Remove newline character
    if (str[right] == '\n') 
        right--;

    while (left < right) { // Loop until the left index is less than the right index

        // Ignore spaces
        if (str[left] == ' ') {
            left++;  
            continue;
        }

        if (str[right] == ' ') {
            right--;
            continue;
        }

        // Compare ignoring uppercase/lowercase
        if (tolower(str[left]) != tolower(str[right])) {  // If the characters are not equal, set palindrome to 0 and break the loop
            palindrome = 0;
            break;
        }

        left++;  // Move the left index to the right
        right--;  // Move the right index to the left
    }

    if (palindrome)
        printf("The string is a palindrome.\n"); // If palindrome is still 1, the string is a palindrome
    else
        printf("The string is not a palindrome.\n"); // If palindrome is 0, the string is not a palindrome

    return 0;
}
