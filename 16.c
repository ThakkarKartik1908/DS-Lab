#include <stdio.h> 
 
struct Item { 
    int weight; 
    int value; 
}; 
 
void fractionalKnapsack(int W, struct Item arr[], int n) { 
    float ratio[100]; 
    for (int i = 0; i < n; i++) 
        ratio[i] = (float)arr[i].value / arr[i].weight; 
 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (ratio[i] < ratio[j]) { 
                float temp = ratio[i]; 
                ratio[i] = ratio[j]; 
                struct Item t = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = t; 
            } 
        } 
    } 
 
    int currentWeight = 0; 
    float finalValue = 0.0; 
 
    for (int i = 0; i < n; i++) {
          if (currentWeight + arr[i].weight <= W) { 
            currentWeight += arr[i].weight; 
            finalValue += arr[i].value; 
        } else { 
            int remain = W - currentWeight; 
            finalValue += arr[i].value * ((float)remain / arr[i].weight); 
            break; 
        } 
    } 
 
    printf("Maximum value in Knapsack = %.2f\n", finalValue); 
} 
 
int main() { 
    int n, W; 
    struct Item arr[100]; 
    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
    printf("Enter number of items: "); 
    scanf("%d", &n); 
    printf("Enter weight and value of each item:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d %d", &arr[i].weight, &arr[i].value); 
 
    printf("Enter capacity of knapsack: "); 
    scanf("%d", &W); 
 
    fractionalKnapsack(W, arr, n); 
    return 0; 
} 
 
