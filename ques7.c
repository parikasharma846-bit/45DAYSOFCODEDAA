 //Write a C program to rotate an array to the right by K positions without using another array.
 #include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6, k = 2;
    int i, temp;

    // Rotate the array K times
    for (i = 0; i < k; i++) {
        temp = arr[n - 1];

        for (int j = n - 1; j > 0; j--) { // Shift elements to the right
            arr[j] = arr[j - 1]; // Move each element one position to the right
        }

        arr[0] = temp;  // Place the last element at the first position
    }

    printf("Array after rotation:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}