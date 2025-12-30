#include<stdio.h>
#define n 5
int Q[n];
int f=-1,r=-1 ;

void cenqueue (int value){
    if(f==-1 && r==-1){
        f=r=0;
        Q[r] = value;
       
    }else if( ((r+1)%n)==f ){
        printf("queue is overflow");
        return;
    }
    else{
        r = (r+1)%n;
        Q[r] = value ;
        
    }
}

 void cdequeue () {
    
    if(f==-1 && r==-1){
     printf("queue is empty");
     return ;
     }else if( f ==r ){
        f=r=-1;
     }else{
        printf(" Deleted element %d\n",Q[f]);
        f=(f+1)%n;
     }
 }
 
 void cdisplay (){
    int i = f ;
     if( f==-1 && r==-1 ){
        printf("queue is empty");
     }else{
        printf("queue is\n");
        while( i != r ){
            printf("\t %d |",Q[i]);
            i = (i+1)%n ;
        }
        printf("\t %d |",Q[r]);
     }
 
 }

 int main(){
    int choice,value;
    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
 do{
    printf("\n0.Exit\n1.cEnqueue\n2.cDequeue\n3.cDisplay\n");
    printf("Enter choice:");
    scanf("%d",&choice);
    
    switch(choice){
        case 1: printf("Enter value:");
                scanf("%d",&value);
                cenqueue(value);
                break;
        case 2: cdequeue();
                break;
        case 3: cdisplay();
                break;
        case 0: printf("exiting.....");
                break;
        
        default : printf("enter valid choice:");        
    }
      }while(choice != 0);
    return 0;
 }

