// using swap call by value and call by refrance
#include<stdio.h>

void call_value(int a,int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void call_refrance(int* a,int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int n,m;

    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
    printf("enter n1:");
    scanf("%d",&n);

    printf("enter n2:");
    scanf("%d",&m);

    printf("befor swaping n=%d and m=%d\n",n,m);

    call_value(n,m);
    printf("after swap using call by value n=%d and m=%d\n",n,m);

    call_refrance(&n,&m);
    printf("after swap using call by referance n=%d,m=%d\n",n,m);

    return 0;

}