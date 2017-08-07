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
    while(l -> next != NULL){
        l = l->next
    }
    position tmp = (position) malloc(sizeof(struct node));
    tmp -> val = data;
    tmp -> next = NULL;
    l -> next = tmp;
}
void addBack(position l, int data){
    position tmp = (position)malloc(sizeof(struct node));
    tmp -> val = data;
}
int main(){
    LIST l, p;    
    l -> next = NULL;
    int n;
    for(int i = 0; i < n; i++){
        int data;
        scanf("%d",&data);
        add(l,data);
    }
    for(int i = 0; i < n; i++){
        
    }
}