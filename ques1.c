//1. Write a C program to find the second-largest distinct element in an array without sorting it.

#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = INT_MIN;  // Initialize largest to the minimum integer value
    int secondLargest = INT_MIN;  // Initialize secondLargest to the minimum integer value

    for (i = 0; i < n; i++) {  // Loop through the array to find the largest and second-largest distinct elements
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) {
        printf("There is no second-largest distinct element.\n");
    } else {
        printf("Second-largest distinct element = %d\n", secondLargest);
    }

    return 0;
}
