// array opration like add,sub,multi
#include<stdio.h>

int main(){
    
    printf("Name:Kartik Pramodkumar Thakkar \n");
    printf("Enrollment no:240410107057\n");
    
    int a[3][3],b[3][3] ;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
    } 
    printf("\n");
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("b[%d][%d]=",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    printf("addition of array\n") ;
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",a[i][j]+b[i][j]);
            
        }printf("\n");
    }
    printf("substrction of array\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",a[i][j]-b[i][j]);
         
        }printf("\n");
    }
    printf("multiplication of Array\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",a[i][j]*b[i][j]);
            
        }printf("\n");
    }
    return 0;
}