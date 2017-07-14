#include<stdio.h>
unsigned int gcd(unsigned int m, unsigned int n){
    return n == 0 ? m : gcd(n,m%n);
}
int main(){
    unsigned int a, b;
    scanf("%u%u",&a,&b);
    printf("%u",gcd(a,b));
}