//6. Write a C program to find all pairs of elements in an array whose sum is equal to a given target value. 
#include <stdio.h>

int main() {
    int arr[] = {2, 7, 4, 5, 1, 3};
    int n = 6;
    int target = 6;
    int i, j;

    printf("Pairs whose sum is %d:\n", target);

    for (i = 0; i < n; i++) { // Loop through the array to find pairs of elements whose sum is equal to the target value
        for (j = i + 1; j < n; j++) {  // Loop through the array starting from the next element to avoid duplicate pairs
            if (arr[i] + arr[j] == target) { // If the sum of the current pair is equal to the target value, print the pair
                printf("(%d, %d) ", arr[i], arr[j]);
            }
        }
    }

    return 0;
}