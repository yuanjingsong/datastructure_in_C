#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    int max_sum = -10000;
    int this_sum = 0;
    for(int i = 0; i < n; i++){
        this_sum += a[i];
        if(this_sum > max_sum){
            max_sum = this_sum;
        }else if(this_sum < 0){
            this_sum = 0;
        }
    }
    printf("%d",max_sum);
}