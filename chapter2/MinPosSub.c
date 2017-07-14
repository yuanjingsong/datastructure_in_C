#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    int this_sum = 0, min_sum = 10000;
    for(int i = 0; i < n; i++){
        this_sum += a[i];
        if(this_sum < min_sum && this_sum > 0){
            min_sum = this_sum;
        }
        if(this_sum > 0){
            this_sum = 0;
        }
    }
    printf("%d",min_sum);
}