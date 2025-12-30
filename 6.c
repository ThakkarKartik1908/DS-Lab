#include<stdio.h>
#define n 5
int Q[n];
int f=-1,r=-1 ;

void enqueue (int value){
    if(r>=n-1){
        printf("queue is overflow");
        return;
    }else{
        r++;
        Q[r] = value;
        if(f==-1){
        f=0;
        }
    }
}

 void dequeue () {
     if(f==-1||f>r){
     printf("queue is empty");
     return ;
     }else{
     printf("Deleted element %d\n",Q[f]);
     f++;
     }
 }
 
 void display (){
     if(f==-1||f>r){
     printf("queue is empty");
     return ;
     }else{
     printf ("queue elements\n");
     for(int i=f;i<=r;i++){
     printf ("\t %d |",Q[i]);
     }
     printf("\n");
     }
 
 }

 int main(){
    int choice,value;
    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
 do{
    printf("0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n");
    printf("Enter choice:");
    scanf("%d",&choice);
    
    switch(choice){
        case 1: printf("Enter value:");
                scanf("%d",&value);
                enqueue(value);
                break;
        case 2: dequeue();
                break;
        case 3: display();
                break;
        case 0: printf("exiting.....");
                break;
        
        default : printf("enter valid choice:");        
    }
      }while(choice != 0);
    return 0;
 }

