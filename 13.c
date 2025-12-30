#include <stdio.h> 
 
void bubbleSort(int arr[], int n) { 
    int i, j, temp; 
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
} 
 
void printArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
 
int main() { 
    int n, i; 
 
    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    int arr[n]; 
    printf("Enter %d elements: ", n); 
    for (i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    printf("\nUnsorted Array: "); 
    printArray(arr, n); 
 
    bubbleSort(arr, n); 
 
    printf("Sorted Array (Ascending Order): "); 
    printArray(arr, n); 
 
    return 0; 
} 