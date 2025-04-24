#include <stdio.h>
#define N 10

int queue[10];
int front = -1,rear = -1;

void enque(int data) {

    if ((rear + 1) % N == front) {
        printf("Queue is full\n");
        return;
    }
    else if (front == -1 && rear == -1) {
        
        front = rear = 0;
        queue[rear] = data;
    }
    else {
        rear = (rear + 1) % N;
        queue[rear] = data;
    }
}

void deque(){

    if(front == -1 && rear == -1) return;

    if(front == rear){
        front = -1,rear = -1;
        return;
    }
    else{

        front = (front+1)%N;
    }
}

void Display(){

    if(front == -1 && rear == -1) return;

    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear) break;

        i = (i + 1) % N;
    }
    printf("\n");

}

int main(){

    int data;
    int n;
    printf("Enter number of elements you want to insert(1-10): ");
    scanf("%d",&n);
    
    printf("Enter values: ");
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        enque(data);
    }

    printf("\nQueue: ");
    Display();

    int x;
    printf("\nNumber of elements to deque: ");
    scanf("%d",&x);

    for(int i=0;i<x;i++) deque();
    
    printf("After Deque: ");
    Display();
   
    int e;
    printf("\nNumber of elements to enqueue: ");
    scanf("%d",&e);

    printf("Enter data values: ");
    
    for(int i=0;i<e;i++){
        scanf("%d",&data);
        enque(data);
    }

    Display();

    return 0;
}
