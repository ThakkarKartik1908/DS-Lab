// infix to postfix
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100

char stack[max];
char infix[max],postfix[max];
int top=-1;

void push(char);
char pop();
int isEmpty();
void ToPostfix();
int space(char);
void print();
int precedence(char);

int main(){
    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
    printf("Enter the infix expression :");
    gets(infix);

    ToPostfix();
    print();
}

void ToPostfix(){
    int i,j=0;
    char next,s;

    for(i=0;i<strlen(infix);i++){
        s=infix[i];
        if(!space(s)){
        switch(s){
            case'(': 
                push(s);
                break;
            case ')':
                while((next=pop())!='(')  
                postfix[j++]=next;
                break;
            case'+':
            case'-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(stack[top])>=precedence(s))
                    postfix[j++]=pop();
                    push(s);
                    break;
                push(s);
                break;
            default :
            postfix[j++] = s;

        }
    }
    } 
    while(!isEmpty())
        postfix[j++] = pop();
        postfix[j] = '\0';

}
int precedence(char s){
    switch(s){
        case'^':
            return 3 ;
        case'*':
        case '/':
            return 2;
    
        case'+':
        case '-':
            return 1;
        default :
            return 0;
    }
}

 void push(char s){
    if(top==max-1){
        printf("over flow");
    }
    top++;
    stack[top] = s;
    
 }

 char pop(){
    char c;
    if(top==-1){
        printf("underflow");
        exit(1);
    }
    c = stack[top];
    top--;
    return c;
    
 }

 int space(char c){
    if(c == ' '|| c == '\t'){
        return 1;
    }else{
        return 0;
    }
 }

 void print(){
    int i=0;
    printf("The equivalent postfix expression is:");
    while(postfix[i]){
        printf("%c",postfix[i++]);
    }
    printf("\n");
 }

 int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
 }