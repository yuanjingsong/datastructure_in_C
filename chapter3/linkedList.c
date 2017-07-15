#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node *node_ptr;
struct node {
    int val;
    node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;
int is_empty(LIST L) { return (L->next == NULL); }
int is_last(position p, LIST L) { return (p->next == NULL); }
position find(int x, LIST L) {
    position p;
    p = L->next;
    while (p->val != x) {
        p = p->next;
        if (p->next == NULL) break;
    }
    if (p->val == x)
        return p;
    else
        return NULL;
}
position find_previous(int x, LIST L) {
    position p;
    p = L;
    while (p->next->val != x) {
        p = p->next;
    }
    if(p -> next == NULL)
        return NULL;
    else
        return p;
}
void delete (int x, LIST L) {
    position p, tmp_cell;
    p = find_previous(x, L);
    if (p->next != NULL) {
        tmp_cell = p->next;
        p->next = tmp_cell->next;
        free(tmp_cell);
    }
}
void insert(int x, LIST L, position p) {
    position tmp_cell;
    tmp_cell = (position)malloc(sizeof(struct node));
    if (tmp_cell == NULL)
        printf("OUT!");
    else {
        tmp_cell->val = x;
        tmp_cell->next = p->next;
        p->next = tmp_cell;
    }
}
void add(position head, int data) {
    position cur = head;
    position newNode = (position)malloc(sizeof(struct node));
    newNode->val = data;
    newNode->next = NULL;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}
void print_list(LIST l) {
    position now = l->next;
    while (now != NULL) {
        printf("%d", now->val);
        now = now->next;
    }
}
position find_position(int x, LIST L){
    int count = 0;
    position now = L;
    while(count != x){
       now = now -> next; 
       count ++;
    }
    return now;
}
void delete_list (LIST l){
    position p;
    p = l -> next;
    while( p -> next != NULL){
        position tmp_cell = p -> next;
        free(p);
        p = tmp_cell;
    }
}
int main() {
    LIST head = malloc(sizeof(LIST));
    head->next = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        add(head, data);
    }
    print_list(head);
    // int del;
    // scanf("%d",&del);
    // delete(del,head);
    // int findNum;
    // scanf("%d",findNum);
    // find(findNum,head);
    // int insertNum;    the number you want insert
    // scanf("%d",&insertNum); 
    // int inserPostion;  the position you want insert 
    // scanf("%d",&inserPostion);
    // position inserPos = find_position(inserPostion,head);
    // insert(insertNum,head,inserPos);
}