#include<stdio.h>
#include<malloc.h>
typedef struct node* node_ptr;
struct node{
    int val;
    node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;
void add(LIST l, int data){
    position now  = l;
    position tmp_cell = (position)malloc(sizeof(struct node));
    tmp_cell -> val = data;
    tmp_cell -> next = NULL;
    while(now ->next != NULL){
        now = now -> next;
    }
    now -> next = tmp_cell;
}
int find_position(LIST l,int x){
    position now = l -> next;
    int count = 1;
    while(count != x){
        now = now -> next; 
        count++;
    }
    return now -> val;
}
void printf_list(LIST l){
    l = l -> next;
    while(l != NULL){
        printf("%d ", l -> val);
        l = l -> next;
    }
}
int main(){
    LIST l = (LIST)malloc(sizeof(struct node));
    l -> next = NULL;
    LIST p = (LIST)malloc(sizeof(struct node));
    p -> next = NULL;
    int Lsize, Psize;
    scanf("%d",&Lsize);
    for(int i = 0; i < Lsize; i++){
        int data;
        scanf("%d",&data);
        add(l,data);
    }
    scanf("%d",&Psize);
    for(int i = 0; i < Psize; i++){
        int data;
        scanf("%d",&data);
        add(p,data);
    }
    p = p -> next;
    while(p != NULL){
        printf("%d ",find_position(l, p->val + 1));
        p = p -> next;
    }
}