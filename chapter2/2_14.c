#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);
    int prime[n];
    for(int i = 2; i < n; i++)
        prime[i] = 1;
    for(int i = 2; i <= sqrt(n); i++){
        if(!prime[i])
            continue;
        for(int j = 2; j * i <= n; j++)
            prim[j*i] = 0;
    }
    int count = 0;
    for(int i = 2; i < n; i++){
        if(prime[i]){
            printf("%d\n",i);
            count ++;
        }
    }
}