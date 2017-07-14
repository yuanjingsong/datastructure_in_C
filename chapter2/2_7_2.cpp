#include<bits/stdc++.h>
using namespace std;
int rand_int(int min, int max){
    srand(time(0));
    int range = max - min;
    int num = rand() % (range + min);
    return num;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i = 1; i <= n; i++)
        a[i] = i;
    for(int i = 1; i < n; i++)
        swap(a[i-1],a[rand_int(0,i)]);
}