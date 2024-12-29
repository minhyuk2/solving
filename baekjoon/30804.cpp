#include <bits/stdc++.h>

using namespace std;

char campus[601][601];
int board[601][601];
int countNum;
int pm[2];


void boardCheck(int N, int M,stack<pair<int,int>> stacks){

    while(!stacks.empty()){
        pair<int,int> pairs = make_pair(stacks.top().first,stacks.top().second);
        stacks.pop();
        //여기까지가 현재 꺼낸 것에 대한 처리

        for(int i = 0 ; i < 4; i++){
            //여기서 X가 나오면 그냥 빼면 되는 것이다.
            if(i < 2){
                if((pairs.first+pm[i%2]) < 0){
                    continue;
                }
                if(board[pairs.first+pm[i%2]][pairs.second] >= 0){
                    continue;
                }

                if(campus[pairs.first+pm[i%2]][pairs.second]=='P'){
                    countNum++;
                    board[pairs.first+pm[i%2]][pairs.second] = 1;
                    stacks.push(make_pair(pairs.first+pm[i%2],pairs.second));

                }else if(campus[pairs.first+pm[i%2]][pairs.second]=='X'){
                    continue;
                }else{
                    //그냥 O인 경우
                    stacks.push(make_pair(pairs.first+pm[i%2],pairs.second));
                    board[pairs.first+pm[i%2]][pairs.second] = 1;
                }
            }else{
                if(pairs.second+pm[i%2] < 0){
                    continue;
                }
                if(board[pairs.first][pairs.second+pm[i%2]] >= 0){
                    continue;
                }
                if(campus[pairs.first][pairs.second+pm[i%2]]=='P'){
                    countNum++;
                    board[pairs.first][pairs.second+pm[i%2]] = 1;
                    stacks.push(make_pair(pairs.first,pairs.second+pm[i%2]));

                }else if(campus[pairs.first][pairs.second+pm[i%2]]=='X'){
                    continue;
                }else{
                    //그냥 O인 경우
                    stacks.push(make_pair(pairs.first,pairs.second+pm[i%2]));
                    board[pairs.first][pairs.second+pm[i%2]] = 1;
                }
            }
        }
    }
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    pm[0] = -1;
    pm[1] = 1;
    stack<pair<int,int>> stacks;

    for(int i =0 ;i<N;i++){
        for(int p = 0 ; p < M; p++){
            cin >> campus[i][p];
            board[i][p] = -1;
            if(campus[i][p]=='I'){
                stacks.push(make_pair(i,p));
                board[i][p]=1;
            }
        }
    }
    //bfs? dfs? 스택이냐 큐냐 뭐 상관 없을 듯?
    //맞네 둘 다 상관없네


    boardCheck(N,M,stacks);

    if(countNum ==0){
        cout << "TT\n";
    }else{
        cout << countNum << "\n";
    }

}