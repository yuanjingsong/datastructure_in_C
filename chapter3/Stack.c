#include<stdio.h>
#include<malloc.h>
typedef struct node* node_ptr;
struct node{
    int val;
    node_ptr next;
};
typedef node_ptr STACK;
int is_empty(STACK s){
    return (s -> next == NULL);
}
STACK creat(void){
    STACK s;
    s = (STACK)malloc(sizeof(struct node));
    s -> next = NULL;
    if(s == NULL)
        printf("OUT!\n");
    return s;
}
void push(int x, STACK s){
    node_ptr tmp_cell;
    tmp_cell = (node_ptr)malloc(sizeof(struct node));
    if(tmp_cell == NULL)
        printf("OUT!\n");
    else{
        tmp_cell -> val = x;
        tmp_cell -> next = s->next;
        s->next = tmp_cell;
    }
}
int top(STACK s){
    if(is_empty(s)){
        printf("Stack is empty");
    }
    else 
        return (s -> next ->val);
}
void pop(STACK s){
    if(is_empty(s)){
        printf("Stack is empty");
    }
    else{
        node_ptr tmp;
        tmp = (node_ptr) malloc(sizeof(struct node));
        tmp = s -> next;
        s ->next = tmp ->next;
        free(tmp);
    }
}
void print_stack(STACK s){
    node_ptr now = s -> next;
    while(now != NULL){
        printf("%d",now->val);
        now = now -> next;
    }
}
int main(){
    STACK s = creat();
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n; i++){
        int data;
        scanf("%d",&data);
        push(data,s);
    }
    printf("\n");
    int x = top(s);
    printf("%d\n",x);
    pop(s);
    print_stack(s);
}