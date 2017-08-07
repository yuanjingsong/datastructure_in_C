#include<stdio.h>
#include<string.h>
int end(int a[], int size){
    int over = 1;
    for(int i = 0; i < size; i++){
        if(a[i]){
            over = 0;
            break;
        }
    }
    return over;
}
int main(){
    int n, m;
    int left;
    scanf("%d%d",&n,&m);
    left = n;
    int a[n];
    memset(&a,1,sizeof a);
    int now = 1;
    int count = 1;
    while(!end(a, n)){
        while(count != m){
            if(a[(now + 1) % n]){
                count++;
            }
            now ++;
        }
        now %= n;
        count = 1;
        a[now] = 0;
        printf("%d ", now);
        left --;
        if (left) {
            while (!a[(now + 1) % n]) {
                now++;
            }
            now++;
            now %= n;
        }else
            return 0;
    }
}