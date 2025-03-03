#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int N,M;
int arr[100][100];
ll dp[3000][15];
// void()
//한 놈을 그냥 막는 처리를 해버리고 다른 애들로 감싸는 식으로 풀어야 하나?
//시간 초과가 나는 이유가 뭐지 대체
vector<int> isUsed;
vector<pair<int,int>> chicken;
vector<pair<int,int>> home;

//arr에 표시하는 식으로 진행하면 될 것 같긴하다.
ll answer = 100000000;

void getAns(int num,vector<int> & selected){

    if(num ==  M){
        //치킨 거리에 대한 계산
        ll temp = 0;

        // //집 기준 치킨집을 이동시키면서 계산
        // for(int i=0;i<home.size();i++){
        //     ll realTemp = 10000000;
        //     for(int t =0;t<chicken.size();t++){
        //         if(isUsed[t]!=0){
        //             continue;
        //         }
        //         ll nows = (llabs(home[i].first-chicken[t].first)+llabs(home[i].second-chicken[t].second));
        //         if(nows < realTemp ){
        //             realTemp = nows;
        //         }
        //     }
        //     temp += realTemp;
        // }    
        // if(answer > temp){
        //     answer = temp;
        // }
        for(int i=0;i<home.size();i++){
            ll minist = LLONG_MAX;
            for(int idx : selected){
                minist = min(minist,dp[i][idx]);
                // cout << idx << " ";
            }
            // cout << "\n";
            temp+=minist;
        }
        answer = min(answer,temp);
        return;
    }


    for(int i =num; i<chicken.size();i++){
        if(isUsed[i] == 0){
            //안 쓸 놈들을 선택하는 거니까
            isUsed[i] =1;
            selected.push_back(i);
            getAns(num+1,selected);
            selected.pop_back();
            isUsed[i] =0;
        }
        }

}


//거리를 구하는 것을 줄여야 한다.


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int t=0;t<N;t++){
            cin >> arr[i][t];
            if(arr[i][t] == 2){
                chicken.push_back({i,t});
                isUsed.push_back(0);
            }else if(arr[i][t] == 1){
                home.push_back({i,t});
            }
        }
    }
    for(int i=0;i<home.size();i++){
            for(int t =0;t<chicken.size();t++){
                ll nows = (llabs(home[i].first-chicken[t].first)+llabs(home[i].second-chicken[t].second));
                dp[i][t] = nows;
            }
    }    
    vector<int> selected;
    getAns(0,selected);

    cout << answer << "\n";
    //치킨 거리라는 것은  가장 짧은 거리를 구하라는 것이다.


}