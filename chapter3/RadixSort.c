#include<stdio.h>
#include<string.h>
void radixSort(int a[], int size, int max){
    int i;
    int semiSorted[size];
    int significantDigit = 1;
    int largestNum = max;
    while(largestNum / significantDigit > 0){
        int bucket[10];
        memset(bucket, 0, sizeof(bucket));
        for(int i = 0; i < size; i++){
            bucket[(a[i] / significantDigit) % 10] ++;
        }
        for(int i = 1; i < 10; i++)
            bucket[i]  += bucket [i-1];
        for(int i = size - 1; i >= 0; i --)   
            semiSorted[--bucket[(a[i] / significantDigit %10)]] = a[i];
        for(int  i = 0; i < size; i++) 
            a[i] = semiSorted[i];
        significantDigit *= 10;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    memset(a,0,sizeof(a));
    int max = -1;
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        if(a[i] > max){
            max = a[i];
        }
    }
    printf("%d\n",max);
    radixSort(a,n,max);
    for(int i = 0; i < n; i++)
        printf("%d ",a[i]);
}