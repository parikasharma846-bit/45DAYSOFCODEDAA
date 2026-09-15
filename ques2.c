//2. Write a program to count the frequency of each distinct element in an array.

#include <stdio.h>

int main() {
    int n, i, j;
    int count;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Frequency of each distinct element:\n");
    for (i = 0; i < n; i++) {  // Loop through the array to count the frequency of each distinct element
        count = 1;   // Initialize count to 1 for the current element
        for (j = i + 1; j < n; j++) {  
            if (arr[i] == arr[j]) {     // If a duplicate is found, increment the count
                count++;
            }
        }
        if (count > 0) {    // If the count is greater than 0, print the element and its frequency
            printf("%d occurs %d times\n", arr[i], count);
        }
    }

    return 0;
}
