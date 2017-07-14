#include<stdio.h>
int a[100];
int binarySearch(int x, int n){
    unsigned left, right, mid;
    left = 0;
    right = n - 1;
    while(left <= right){
        mid = (left + right) >> 1;
        if(a[mid] < x)
            left = mid + 1;
        else 
            if(a[mid] > x)
            right = mid - 1;
        else
            return mid; 
    }
    return -1;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ;i < n; i++){
        scanf("%d",&a[i]);
    }
    int x;
    scanf("%d",&x);
    printf("%d",binarySearch(x,n));
}