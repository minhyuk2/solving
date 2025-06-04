#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[110][110]; //인접리스트로 저장
bool visited[110];


//현재 내 풀이는 n 3승이라서 터지는 구나  그러면

int findNum(int i){
    int answer = 0;
    queue<pair<int,int>> que;
    fill(begin(visited),end(visited),0);
    int dist[110] = {0};
    que.push({i,0});
    visited[i] = 1;
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        //que의 크기가 너무 커져서 그런 경우가 발생할듯
        for(int s =1;s<=N;s++){
            if(arr[newPair.first][s]==1 && visited[s] == 0){
               visited[s] = 1;
               dist[s] = dist[newPair.first] + 1;
               que.push({s,newPair.second+1});
            }
        }
    }
    for(int s =1;s<=N;s++){
        if(s!=i){
            answer += dist[s];
        }
    }
    return answer;
    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int temp1, temp2;
    for(int i =0; i<M;i++){
        cin >> temp1 >> temp2;
        arr[temp1][temp2] = 1;
        arr[temp2][temp1] = 1;
    }//이렇게 무방향 연결리스트 완성

    int answer = 10000000;
    int realNum =-1;
    for(int i=1;i<=N;i++){

        int nums = findNum(i);
        
        // cout << nums << "\n";
        if(answer > nums){
            realNum = i;
            answer = nums;
        }
    }

    cout << realNum << "\n";

}