#include<stdio.h>
void insertionSort(int a[], int size){
    int j;
    for(int i = 1; i < size; i++){
        int key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    insertionSort(a,n);
    for(int i = 0; i < n; i++)
        printf("%d ",a[i]);
}