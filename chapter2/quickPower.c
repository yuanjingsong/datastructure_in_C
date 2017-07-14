#include<stdio.h>
long long  quickPow(int x, unsigned int n){
    int ans = 1;
    while(n > 0){
        if(n & 1){
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}
long long pow(int x, unsigned int n){
    if( n == 0)
        return 1;
    if( n == 1)
        return x;
    if(!(n&1))
        return (pow(x*x,n/2));
    else 
        return (pow(x*x, n/2)*x);
}
int main(){
    int x;
    unsigned int n;
    scanf("%d%u",&x,&n);
    printf("%lld",quickPow(x,n));
}