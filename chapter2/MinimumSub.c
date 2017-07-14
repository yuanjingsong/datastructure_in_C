#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    int this_sum = 0, min_sum = 1000000;
    int best_i = 0, i = 0;
    for(int j = 0; j < n; j++){
        this_sum += a[j];
        if(this_sum < min_sum){
            best_i = i;
            min_sum = this_sum;
        }
        if(this_sum > 0 ){
            this_sum = 0;
            i++;
        }
    }
    printf("%d\n",min_sum);
    printf("%d\n",best_i);
}