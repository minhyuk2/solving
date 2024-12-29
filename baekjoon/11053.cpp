#include <bits/stdc++.h>
using namespace std;

int visited[1001];
int normal[1001];
int usingArr[1001];


int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    //일단 전부 1로 채워줌
    fill(normal,normal+1001,1);//전부 채우는 함수

    int caseIn;
    cin >> caseIn;
    for(int i = 0 ; i < caseIn;i++){
        cin >> usingArr[i];
    }
    //그러면 dp의 의의가 사라지지 흠..
   fill(visited,visited+1001,1);
    // visited[0] = 1;
    for(int i = 0 ; i < caseIn;i++){
        for(int p = i+1 ; p < caseIn ; p++){
            if(usingArr[i] < usingArr[p]){
                if(visited[p] < visited[i]+1){
                    visited[p] = visited[i]+1;
                }
            }
        }
    }

    cout << *max_element(visited,visited+caseIn) <<"\n";

}