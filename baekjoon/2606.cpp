#include <bits/stdc++.h>

using namespace std;

int num[102][102];
int inject[102];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //computer의 개수 입력받기
    int computer = 0;
    cin >> computer;

    //쌍의 개수 입력 받음
    int twin;
    cin >> twin;
    

    int n,m;
    //이러면 쌍에 대한 값을 전부 넣어줌
    for(int i= 0; i <twin; i++){
        cin >> n >> m;
        if(m==1){
            num[m][n] = 1;
        }else{
            num[n][m] = 1;
        }
    }

    stack<int> sta;

    // for(int i = 1 ; i <= computer ;  i++){
    //     for(int t = 1 ; t <= computer ; t++){
    //         if(num[i][t] ==1){
    //             sta.push(t);
    //             inject++;
    //         }
    //     }
    // }
    for(int i = 1; i <=computer;i++){
        if(num[1][i] == 1){
            sta.push(i);
            inject[i] = 1;
        }
            
    }

    //stack의 탑을 기준으로 반복문을 수행해야하니까
    while(!sta.empty()){
        int top = sta.top();
        sta.pop();
        for(int i = 1; i <=computer;i++){
            if(num[top][i] == 1){
 
                if(inject[i] != 1){
                    sta.push(i);
                    inject[i] = 1;
                }
            }
        }
        for(int t = 2 ; t <=computer; t++){
            if(num[t][top] == 1){
                if(inject[t] != 1){
                    sta.push(t);
                    inject[t] = 1;
                }
            }
        }
    }

    int ans = 0 ;
    for(int i = 1; i <= computer; i++){
        if(inject[i]==1){
            ans ++;
        }
    }

    cout << ans << "\n";

}   
