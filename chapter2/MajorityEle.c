#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    int count = 0;
    int ans = 0;
    int b[n];
    int j = 0;
    for(int i = 0; i < n; i++){
        if(count == 0){
            ans = a[i];
        }else if(ans != a[i]){
            count --;
        }else if(ans == a[i]){
            count ++;
        }
    }
    count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == ans)
            count++;
    }
    if(count > (n >>1) )
        printf("%d",ans);
}