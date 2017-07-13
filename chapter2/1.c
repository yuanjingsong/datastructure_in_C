#include<stdio.h>
int max_Sub1(int a[], unsigned int n){
    int this_sum, max_sum, best_i, best_j, i, j, k;
    max_sum = 0;
    best_i = best_j = -1;
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            this_sum = 0;
            for(k = i; k <= j; k++){
                this_sum += a[k];
            }
            if(this_sum > max_sum){
                max_sum = this_sum;
                best_i = i;
                best_j = j;
            }
        }
    }
    printf("%d %d\n",best_i,best_j);
    return (max_sum);
}
int max_Sub2(int a[], unsigned int n){
    int this_sum, max_sum, best_i, best_j;
    max_sum = 0;
    best_i = best_j = -1;
    for(int i = 0; i < n; i++){
      this_sum = 0;
      for (int j = i; j < n; j++) {
        this_sum += a[j];
        if (this_sum > max_sum) {
            max_sum = this_sum;
            best_i = i;
            best_j = j;
        }
      }
    }
    printf("%d %d\n", best_i, best_j);
    return (max_sum);
}
int max_sub_sequence_sum(int a[], unsigned int n){
    return max_Sub3(a, 0, n-1);
}
int max_Sub3(int a[], int left, int right){
    int max_left_sum, max_right_sum;
    int max_left_border_sum, max_right_border_sum;
    int left_border_sum, right_border_sum;
    int center ,i;
    if(left == right)
        if(a[left] > 0)
            return a[left];
        else 
            return 0;
    center = (left + right) >> 1;
    max_left_sum = max_Sub3(a, left, center);
    max_right_sum = max_Sub3(a, center+ 1, right);
    max_left_border_sum = 0;
    max_right_border_sum = 0;
    for(i = center; i >= center; i--){
        left_border_sum += a[i];
        if(left_border_sum > max_left_border_sum)
            max_left_border_sum = left_border_sum;
    }
    for(i = center + 1; i <= right; i++){
        right_border_sum += a[i];
        if(right_border_sum > max_right_border_sum)
            max_right_border_sum = right_border_sum;
    }
    return max3(max_left_sum, max_right_sum, max_left_border_sum+max_right_border_sum);
} 
int max_Sub4(int a[], unsigned int n){
    int this_sum, max_sum, best_i, best_j, i, j;
    i = this_sum = 0; 
    max_sum = -1000000;
    best_i = best_j = -1;
    for(j = 0; j < n; j++){
        this_sum += a[j];
        if(this_sum > max_sum){
            max_sum = this_sum;
        }else if(this_sum < 0){
            this_sum = 0; 
        }
    }
    return max_sum;
}
int max3(int a, int b, int c){
    if(a > b){
        if(a > c)
            return a;
        else
            return c;
    }else{
        if(b > c)
            return b;
        else 
            return c;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    printf("%d\n",max_Sub1(a,n));
    printf("%d\n",max_Sub4(a,n));
}