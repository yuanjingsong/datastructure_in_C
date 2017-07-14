#include<stdio.h>
int power(int x, int i){
    if(i == 0)
        return 1;
    return x * power(x,i-1);
}
int quickPower(int x, int i){
    int ans = 1;
    while(i){
        if(i & 1)
            ans *= x;
        x *= x;
        i >>= 1;
    } 
    return ans;
}
int main(){
    int x,n;
    scanf("%d%d",&x,&n);
    long long sum1 = 0;
    long long sum2 = 0;
    for(int i = 0; i <= n; i++){
        sum1 += power(x,i);
    }
    for(int i = 0; i <= n; i++){
        sum2 += quickPower(x,i);
    }
    printf("%lld\n",sum1);
    printf("%lld\n",sum2);
}