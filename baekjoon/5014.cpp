#include <bits/stdc++.h>

using namespace std;

long long int F,S,G,U,D;
long long int answer = 10000000000;
bool visited[1000001];
void elevatorCase(){

    queue<pair<long long int,long long int>> que;
    //앞의 것은 층 2번째 것은 횟수

    que.push({S,0});
    bool elOk = 0;
    while(!que.empty()){
        pair<long long int, long long int> newPair = que.front();
        que.pop();
        if(newPair.first == G){
            if(newPair.second < answer){
                answer = newPair.second;
                elOk = 1;
            }
            break;
        }
        if(newPair.first > F||newPair.first < 1){
            continue;
        }else{
            for(int i= 0; i <2 ; i++){
                if(i == 0){
                    if(newPair.first+U <= F && visited[newPair.first+U] == 0){
                        que.push({newPair.first+U,newPair.second+1});
                        visited[newPair.first+U] = 1;
                    }
                }else{
                    if(newPair.first-D >= 1 && visited[newPair.first-D] == 0){
                        que.push({newPair.first-D,newPair.second+1});
                        visited[newPair.first-D] = 1;
                    }
                }
            }
        }
    }

    if(elOk){
        cout << answer << "\n";
    }else{
        cout << "use the stairs\n";
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> F >> S >> G >> U >> D;

    elevatorCase();
}