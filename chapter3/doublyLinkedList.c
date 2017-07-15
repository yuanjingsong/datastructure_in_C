#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node* node_ptr;
struct node {
    int val;
    node_ptr next;
    node_ptr pre;
};
typedef node_ptr LIST;
typedef node_ptr position;
void add(LIST head, int data) {
    position cur = head;
    position newNode = (position)malloc(sizeof(struct node));
    newNode->val = data;
    newNode->next = NULL;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->pre = cur;
}
void print_list(LIST head) {
    position now = head->next;
    while (now != NULL) {
        printf("%d", now->val);
        now = now->next;
    }
}
void print_list_BACK(LIST back, LIST head) {
    position now = back;
    while (now != head) {
        printf("%d", now->val);
        now = now->pre;
    }
}
int is_empty(LIST l) { return (l->next == NULL); }
int is_last(LIST l, position p) { return (p->next == NULL); }
position find(int x, LIST l) {
    position p = l->next;
    while (p->val != x) {
        p = p->next;
        if (p->next == NULL) break;
    }
    if (p->val == x)
        return p;
    else
        return NULL;
}
position find_previous(int x, LIST l) {
    position p = l;
    while ((p->next->val) != x) {
        p = p->next;
        if (p->next == NULL) break;
    }
    if (p->next == NULL)
        return NULL;
    else
        return p;
}
void delete (int x, LIST l) {
    position p, tmp_cell, next;
    p = find_previous(x, l);
    if (p->next != NULL) {
        tmp_cell = p->next;
        next = tmp_cell->next;
        p->next = next;
        next->pre = p;
        free(tmp_cell);
    }
}
void insert(int x, LIST l, position p) {
    position tmp_cell;
    tmp_cell = (position)malloc(sizeof(struct node));
    if(tmp_cell == NULL)
        printf("OUT!\n");
    else{
        position next = p -> next;
        tmp_cell -> val = x;
        tmp_cell -> next = next;
        tmp_cell -> pre = p;
        next -> pre = tmp_cell;
        p -> next = tmp_cell;
    }
}
position find_position(int x, LIST l){
    position now = l -> next;
    int count = 1; 
    while(count != x){
        now = now -> next;
        count ++;
    }
    return now;
}
void del_list(LIST l){
    position now = l -> head;
    while(now -> next != NULL){
        position tmp = now -> next;
        free(now);
        now = tmp;
    }
}
int main() {
    LIST head = (LIST)malloc(sizeof(struct node));
    head->next = NULL;
    head->pre = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        add(head, data);
    }
    // int del;
    // scanf("%d",&del);
    // delete(del,head);
    // print_list(head);
    // int data;
    // scanf("%d",&data);
    // position last = find(data,head);
    // print_list_BACK(last, head);
    int insertNum;
    scanf("%d",&insertNum);
    int insertPos;
    scanf("%d",&insertPos);
    position insertPostion =  find_position(insertPos,head);
    insert(insertNum, head, insertPostion);
    print_list(head);
    int data;
    scanf("%d",&data);
    position last = find(data,head);
    print_list_BACK(last, head);

}