#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*first = NULL;

void create(int n){
    
    struct node *last,*t;
    
    first = (struct node *) malloc(sizeof(struct node));
    scanf("%d",&first->data);
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++){

        t = (struct node *) malloc(sizeof(struct node));
        scanf("%d",&t->data);
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct node *p){

    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int len(struct node *p){

    int count = 0;
    while(p){
        p = p->next;
        count++;
    }

    return count;
}

struct node* reverse_k_nodes(struct node* temp, struct node* p) {

    struct node *prev = NULL, *curr = temp, *next = NULL;
    struct node *stop = p->next; 

    while (curr != stop) {

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    return prev; 
}

void reverseKGroups(int k) {

    if (k <= 1 || !first) return;

    int length = len(first);
    if (length < k) return;

    struct node *temp = first;        
    struct node *prevGroupTail = NULL; 

    while (length >= k) {
        struct node *p = temp; 

        for (int i = 1; i < k; i++) {
            p = p->next;
        }
        
        if(p == NULL) break;
        

        struct node * nextGroupHead = p->next;
        
        struct node *newHead = reverse_k_nodes(temp, p);
        
        if (prevGroupTail)
            prevGroupTail->next = newHead;
        else
            first = newHead; 

        temp->next = nextGroupHead; 
        prevGroupTail = temp;
        temp = nextGroupHead;

        length -= k;  
    }
}

int main(){

    int n;
    scanf("%d",&n);

    create(n);
    Display(first);

    printf("\nEnter nodes: ");
    int k;
    scanf("%d",&k);

    reverseKGroups(k);
    Display(first);

    return 0;
}
