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
    position now = l;
    while(now -> next != NULL){
        now = now -> next;
    }
    position tmp = (position)malloc(sizeof(struct node));
    tmp -> val = data;
    tmp -> next = NULL;
    now -> next = tmp;
}
LIST merge(LIST l, LIST p){
    position curL = l -> next;
    position curP = p -> next;
    LIST final = (LIST)malloc(sizeof(struct node));
    final -> next = NULL;
    while(curL != NULL && curP != NULL){
        int valL = curL -> val;
        int valP = curP -> val;
        int data;
        if(valL > valP){
            data = valP;
            curP = curP -> next;
        }else if(valL < valP){
            data = valL;
            curL = curL -> next;
        }else{
            data = valL; 
            curL = curL -> next;
            curP = curP -> next;
        }
        add(final,data);
    }
    while(curL != NULL){
        add(final,curL -> val);
        curL = curL -> next;
    }
    while(curP != NULL){
        add(final, curP -> val);
        curP = curP -> next;
    }
    return final;
}
void print_list(LIST l){
    position cur = l -> next;
    while(cur != NULL){
        printf("%d ",cur -> val);
        cur = cur -> next;
    }
}
int main (){
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
    final = merge(l,p);
    print_list(final);

}