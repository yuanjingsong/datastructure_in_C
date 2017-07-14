#include<stdio.h>
#include<string.h>
#define MAX 100000
int Val[MAX];
int Fib(int n){
    if(Val[n]) return Val[n];
    if(n <= 2)
        return 1; 
    return Val[n] = Fib(n -1) + Fib(n - 2);
}
int main(){
    int n;
    scanf("%d",&n);
    memset(Val,0,sizeof(Val));
    printf("%d",Fib(n));
}