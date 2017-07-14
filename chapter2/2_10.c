#include<stdio.h>
int bianrySearch(int a[], int left, int right){
    while(left <= right){
        int mid = (left + right) >> 1;
        if(a[mid] > mid){
            right = mid - 1;
        }
        if(a[mid] < mid){
            left = mid + 1;
        }
        if(a[mid] == mid){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n + 1];
    for(int i = 1; i <= n;i++)
        scanf("%d",&a[i]);
    int i;
    scanf("%d",&i);
    printf("%d",bianrySearch(a, 1, n));
}