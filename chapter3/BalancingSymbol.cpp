#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000000
stack <char> s;
int main(){
    char newCharacter ;
    int ok = 1;
    while(scanf("%c",&newCharacter) == 1){
        if(newCharacter == '<' || newCharacter =='['){
            s.push(newCharacter);
        }else if(newCharacter == '>' ||
        newCharacter == ']'){
            if(s.empty()){
                ok = 0;
                break;
            }else{
                char popCharacter = s.top();
                s.pop();
                if(newCharacter == '>' && popCharacter != '<'){
                    ok = 0;
                    break;
                }else if(newCharacter == ']' && popCharacter != '['){
                    ok = 0;
                    break;
                }else  continue;
            }
        }
    }
    if(!s.empty()){
        ok = 0;
    }
    if(!ok)
        printf("WRONG");
}