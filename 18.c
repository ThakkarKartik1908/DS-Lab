#include <stdio.h>

int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

int main() {
    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
    int n, key, choice;
    printf("Enter size of sorted array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    printf("Choose method:\n1. Iterative\n2. Recursive\n");
    scanf("%d", &choice);
    
    int result;
    if (choice == 1)
        result = binarySearchIterative(arr, n, key);
    else
        result = binarySearchRecursive(arr, 0, n - 1, key);
    
    if (result != -1)
        printf("Element %d found at position %d\n", key, result + 1);
    else
        printf("Element %d not found in the array\n", key);
    
    return 0;
}
