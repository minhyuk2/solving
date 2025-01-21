#include <bits/stdc++.h>

using namespace std;

int N,M;

int state[1000001];
int arr[1000001];

//이게 아니라면 2차원 배열로 그래프 만들어서 표현해도 괜찮을 것 같음 ㅇㅇ
//진짜 오랜만에 막히게 어려운 문제를 만났네,,BFS,DFS 부분이 아직 많이 부족하다는 의미니까 더 열심히 공부하자
//visited 배열에 값을 다르게 넣어서 O(N^2)을 해소하는 방법을 만들 수 있다.

void run(int x){
    int cur = x;
    while(1){
        state[cur] = x;
        cur = arr[cur];
        //한 바퀴 돌아서 다시 원래 걸로 돌아오게 된 경우
        if(state[cur] == x){
            while(state[cur] != -1){
                state[cur] = -1;
                cur = arr[cur];
            }
            return;
            //그냥 다시 . 돈경우
        }else if(state[cur] != 0) return;
    }
}

// void schools(vector<pair<int,int>> &vec, stack<pair<int,int>> &sta,set<int> &go){

//     set<int> answer;

//     // for(int i=1; i<=M;i++){
//     //     auto it =answer.find(i);
//     //     if(it != answer.end()){
//     //         continue;
//     //     }

        
//         int counting[1000001] = {0,};
//         int called[100001] = {0,};    
//         vector<int> goods;
//         // set<int> go;
//         // que.push({vec[i]});
//         bool allOk =0;
//         while(!sta.empty()){
//             pair<int,int> newPair = sta.top();
//             sta.pop();
//             // cout << newPair.first << " " << newPair.second << "\n";

//             if( newPair.first == newPair.second){
//                 answer.insert(newPair.first);
//                 continue;
//             }
//             if(counting[newPair.first] == 2){
//                 if()
//             }
//             counting[newPair.first]++;
//             que.push({vec[newPair.second]});
//         }
//         //크면 M 일단은 M^2
//         // for(auto it : goods){
//         //     if(counting[it] <= 2){
//         //         allOk = 1;
//         //     }
//         // }
//         // if(allOk == 0){

//         // }
//     // }

//     cout << M - answer.size() << "\n";
// }

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    //여긴 아무런 문제 x
    for(int i=0; i<N;i++){

        cin >> M;
        fill(state+1,state+M+1,0);
        for(int t=1;t<=M;t++){
            cin >> arr[t];
        } 
        int answ = 0;
        for(int t =1 ; t <=M;t++){
            if(state[t] == 0) run(t);
        }
        for(int t=1 ;t <=M; t++){
            if(state[t] != -1) answ++;
        }
        cout << answ << "\n";
    }

}