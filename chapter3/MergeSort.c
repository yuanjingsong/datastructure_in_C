#include<stdio.h>
void MergeSort(int a[],int left, int right){
    if(right > left){
        int mid = (left + right) >> 1;
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
void merge(int a[], int left, int mid ,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for(int i = 0; i < n2; i++) 
        R[i] = a[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    MergeSort(a,0, n-1);
    for(int i = 0; i < n; i++)
        printf("%d",a[i]);
}