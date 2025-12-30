#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
   
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int num_disks ;
    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
    printf("Enter no of disk:");
    scanf("%d",&num_disks);
    
    towerOfHanoi(num_disks, 'A', 'C', 'B'); // A=Source, C=Destination, B=Auxiliary
    return 0;
}