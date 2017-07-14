#include<bits/stdc++.h>
int main(){
    int n;
    scanf("%d",&n);
    int r = rand();
    int a[n];
    int b[n+1];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int i = 0;
    while(!a[i]){
        int randNum = 0;
        randNum = rand() % n + 1;
        if(!b[randNum]){
            a[i++] = randNum;
            b[randNum] = 1;
        }
    }
}
