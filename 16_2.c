 
#include <stdio.h> 
 
void activitySelection(int start[], int finish[], int n) { 
    int i, j; 
 
    printf("Selected Activities: "); 
    i = 0; 
    printf("A%d ", i + 1); 
 
    for (j = 1; j < n; j++) { 
        if (start[j] >= finish[i]) { 
            printf("A%d ", j + 1); 
            i = j; 
        } 
    } 
    printf("\n"); 
} 
 
int main() { 
    int n; 
    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
    printf("Enter number of activities: "); 
    scanf("%d", &n); 
 
    int start[100], finish[100]; 
    printf("Enter start times:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &start[i]); 
    printf("Enter finish times:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &finish[i]); 
 
    activitySelection(start, finish, n); 
    return 0; 
} 
 
 
 
