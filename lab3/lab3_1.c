#include<stdio.h>

int size=100,top=-1;;
int stack[100];

void push(int n){
    if(top==size-1)printf("Stack overflow\n");
    else{
        stack[++top]=n;
        printf("%d pushed onto stack",n);
    }
}

int pop(){
    if(top==-1)printf("Stack Underflow\n");
    else{
        int val=stack[top--];
        printf("Popped element : %d",val);
    }
}

void peek(){
    if(top==-1)printf("Stack Underflow\n");
    else{
        int element=stack[top];
        printf("Top element : %d",element);
    }
}

void isEmpty(){
    if(top==-1)printf("Stack is empty");
    else printf("Stack is not empty");
}

void isFull(){
    if(top==size-1)printf("Stack is full");
    else printf("Stack is not full");
}

void display(){
    if(top==-1)printf("Stack is empty");
    printf("Stack:\n");
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
}
int main(){
    while(1){
    printf("\n\t\t MENU :\n");
    printf("Enter 1 for Push an element onto the stack\n");
    printf("Enter 2 for Pop an element from the stack\n");
    printf("Enter 3 for Peek (View the top element)\n");
    printf("Enter 4 for Check if the stack is empty\n");
    printf("Enter 5 for Check if the stack is full\n");
    printf("Enter 6 for Display all elements in the stack\n");
    printf("Enter 7 for EXIT\n");
    int a;
    printf("Enter your choice:\n");
    scanf("%d",&a);
    switch(a){
        case 1:{
            printf("Enter value: ");
            int num;
            scanf("%d",&num);
            push(num);
            break;
        }
        case 2:{
            pop();
            break;
        }
        case 3:{
            peek();
            break;
        }
        case 4:{
            isEmpty();
            break;
        }
        case 5:{
            isFull();
            break;
        }
        case 6:{
            display();
            break;
        }
        case 7:{
            return 0;
        }
        default:{
            printf("Wrong choice\n");
        }
    
    }
    }
    return 0;
}
