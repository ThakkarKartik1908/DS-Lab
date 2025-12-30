//stack opreation
#include<stdio.h>
#define n 5
int stack[n];
int top=-1;

void push(int x){

    if(top==n-1){
        printf("overflow\n");
    }else{
        top++;
        stack[top]=x;
        printf("the push value=%d\n",x);
    }
}


void pop(){
    if(top==-1){
        printf("underflow\n");
    }else{
        printf("pop value=%d\n",stack[top]);
        top--;
    }
}


void peep(){
    printf("Top value =%d\n",stack[top]);
}

void display(){
    if(top==-1){
        printf("stack is empty\n");
    }else{
        printf("value are present in stack:\n");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}

int main(){
    int x,choice,value;
    printf("Name: Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
 do{
    printf("1.Push\n2.Pop\n3.Peep\n4.Display\n");
    printf("Enter choice:");
    scanf("%d",&value);
    
    switch(value){
        case 1: printf("Enter value:");
                scanf("%d",&x);
                push(x);
                break;
        case 2: pop();
                break;
        case 3: peep();
                break;
        case 4: display();
                break;
        default : printf("enter valied choice:");        
    }
      }while(value != 0);
    return 0;
}