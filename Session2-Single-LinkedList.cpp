#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    char name[250];
    int score;
    Node *next; // pointer untuk menunjuk node selanjutnya
} *head, *tail; //global var

Node *createNode(const char *name, int score) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void pushHead(const char *name, int score) {
    
    Node *temp = createNode(name, score);

    if(!head) { // jika tidak ada head
        head = tail = temp; // node menjadi head dan tail
    }
    else { // jika sudah ada head
        temp->next = head; // node menunjuk ke head yg lama
        head = temp; // node akan menjadi head yg baru
    }
}

void pushTail(const char *name, int score) {
    
    Node *temp = createNode(name, score);

    if(!head) { // jika tidak ada head
        head = tail = temp; // node menjadi head dan tail
    }
    else { // jika sudah ada tail
        tail->next = temp; // tail menunjuk ke node
        tail = temp; // node akan menjadi tail yg baru
    }
}

void popHead() {
    if(!head) { // jika tidak ada head
        return;
    }
    else if(head == tail) { // kalau datanya cmn 1
        free(head);
        head = tail = NULL;
    }
    else { // jika ada head
        Node *temp = head->next;
        head->next = NULL;
        free(head);
        head = temp;
    }
}

void popTail() {
    if(!head) { // jika tidak ada head
        return;
    }
    else if(head == tail) { // kalau datanya cmn 1
        free(head);
        head = tail = NULL;
    }
    else { // jika ada head
        Node *temp = head;

        while(temp->next != tail) {
            temp = temp->next; // jalan terus sampe akhir
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

void print() {
    Node *curr = head;

    while(curr) {
        printf("%s %d -> ", curr->name, curr->score);
        curr = curr->next;
    }

    printf("NULL");
}

int main() {
    pushHead("Patrick", 100);
    pushTail("Cahyadi", 95);
    pushHead("Randy", 80);
    pushTail("Vero", 88);
    pushHead("Sarah", 86);

    popTail();
    popHead();
    popTail();
    popTail();

    print();

    return 0;
}