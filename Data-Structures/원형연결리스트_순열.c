#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node* next;
    struct Node* prev;
    int data;
}Node;
 

Node* head = NULL;
Node* tail = NULL;
 
int main() {
    int num;
    int key;
    int count = 0;
    scanf("%d %d", &num, &key);
    for (int i = 1; i <= num; i++){
        makenodes(i);
    }
 
    head->prev = tail;
    tail->next = head;
 
 		Removes(head,num, key);
    return 0;
}
 
struct Node* makenode(int data){
    Node* new = malloc(sizeof(struct Node));
    new->next = NULL;
    new->prev = NULL;
    new->data = data;
    return new;
}
 
void makenodes(int data){
    Node* temp = head;
    Node* newnode = makenode(data);
 
    if (head == NULL){
        head = newnode;
        tail = head;
    }
 
    else{
        temp = tail; 
        temp->next = newnode;
        newnode->prev = temp;
        tail = newnode;
    }
}
 
void Removes(Node* head,int num ,int key){
    Node* tmp = head->prev;
    int c = 0;
    int t = 0;
    printf("<");
    while (c < num) {
        t = key;
        while (t--) tmp = tmp->next;
        printf(c++ ? ", %d" : "%d", tmp->data);
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
    }
    puts(">");
 
}
