#include<stdio.h>
#include<malloc.h>
typedef struct node* node_ptr;
struct node{
    int val;
    node_ptr next;
};
typedef node_ptr Position;
typedef node_ptr LIST;
void add(LIST l, int x){
    Position now = l;
    while(now -> next != NULL){
        now = now -> next;
    }
    Position new = (Position)malloc(sizeof( struct node));
    new -> val = x;
    new -> next = NULL;
    now -> next = new;
}
LIST compare(LIST l, LIST p){
    Position curL;
    Position curP;
    LIST final = (Position)malloc(sizeof(struct node));
    final -> next = NULL;
    Position now = final;
    curL = l -> next;
    curP = p -> next;
    while(curL != NULL && curP != NULL){
        int valL = curL -> val;
        int valP = curP -> val;
        if(valL > valP){
            curP = curP -> next;
        }else if(valL < valP){
            curL = curL -> next;
        }else{
            while(now -> next != NULL){
                now = now -> next; 
            }
            Position newNode = (Position)malloc(sizeof(struct node));
            newNode -> val = valL;
            newNode -> next = NULL;
            now -> next = newNode;
            curL = curL -> next;
            curP = curP -> next;
        }
    }
    return final;
}
void print_list(LIST l){
    Position cur = l -> next;
    while(cur != NULL){
        printf("%d ",cur -> val);
        cur = cur -> next;
    }
}
int main(){
    LIST l = (LIST)malloc(sizeof(struct node));
    l -> next = NULL;
    LIST p = (LIST)malloc(sizeof(struct node));
    p -> next = NULL;
    int n1, n2;
    scanf("%d",&n1);
    for(int i = 0; i < n1; i++){
        int data;
        scanf("%d",&data);
        add(l,data);
    }
    scanf("%d",&n2);
    for(int i = 0; i < n2; i++){
        int data;
        scanf("%d",&data);
        add(p,data);
    }
    LIST final = (LIST)malloc(sizeof(struct node));
    final = compare(l,p);
    print_list(final);
}