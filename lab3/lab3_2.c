#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front=NULL;
struct Node *rear=NULL;

void enqueue(int n){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=n;
    newNode->next=NULL;
    if(rear==NULL){
        front=newNode;rear=newNode;
    } 
    else{
        rear->next=newNode;
        rear=newNode;
    }
    printf("%d inserted into queue\n",n);
}

void dequeue(){
    if(front==NULL){
        printf("Queue Underflow\n");
        return;
    }
    struct Node* temp=front;
    printf("Removed: %d\n",front->data);
    front=front->next;
    if(front==NULL)
        rear=NULL;
    free(temp);
}

void peek(){
    if(front==NULL) printf("Queue is empty\n");
    else printf("Front element: %d\n", front->data);
}

void isEmpty(){
    if(front==NULL) printf("Queue is empty\n");
    else printf("Queue is not empty\n");
}

void display(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp=front;
    printf("Queue: ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    while(1){
        printf("\n\t\t MENU:\n");
        printf("Enter 1 for Enqueue (Insert an element at the rear)\n");
        printf("Enter 2 for Dequeue (Remove an element from the front)\n");
        printf("Enter 3 for Peek (View the front element)\n");
        printf("Enter 4 for Check if the queue is empty\n");
        printf("Enter 5 for Display all elements in the queue\n");
        printf("Enter 6 for EXIT\n");
        int c;
        scanf("%d",&c);
        switch(c){
            case 1:{
                int val;
                printf("Enter the value :\n");
                scanf("%d",&val);
                enqueue(val);
                break;
            }
            case 2:{
                dequeue();
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
                display();
                break;
            }
            case 6:{
                return 0;
            }
            case 7:{
                printf("Wrong input\n");
                break;
            }
        }
    }
    return 0;
}
