//3. Write a program to merge two sorted arrays into a single sorted array without using any built-insorting function
// O(n + m) time complexity
#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int n, m, i = 0, j = 0, k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    printf("Enter elements of first sorted array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &m);

    printf("Enter elements of second sorted array:\n");
    for (j = 0; j < m; j++)
        scanf("%d", &b[j]);

    i = 0;
    j = 0;

    // Merge the two sorted arrays
    while (i < n && j < m) {  // Loop until we reach the end of either array
        if (a[i] < b[j])   // If the current element of the first array is smaller, add it to the merged array
            c[k++] = a[i++];  // Increment the index of the first array
        else
            c[k++] = b[j++]; // If the current element of the second array is smaller or equal, add it to the merged array and increment the index of the second array       
    }

    // Copy remaining elements of first array
    while (i < n)
        c[k++] = a[i++];

    // Copy remaining elements of second array
    while (j < m)
        c[k++] = b[j++];

    printf("Merged sorted array:\n");
    for (i = 0; i < k; i++)
        printf("%d ", c[i]);

    return 0;
}
