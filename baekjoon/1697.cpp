#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int vis[100002];

int dx[3] = {-1,1,2};

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N , K;
    cin >> N >> K;

    //처음부터 같은 위치에 있는 경우에는 0을 출력한다.
    if( N == K){
        cout << 0 << "\n";
        return 0;
    }
    // for(int  i = 0 ; i < 100002 ; i ++){
    //     vis[]
    // }


    //N을 큐에 넣어준다.

    queue<int> Q;
    Q.push(N);
    

    while(!Q.empty()){
        //큐에서 나온 값을 저장한다.
        int indexs = Q.front();

        Q.pop(); // pop해준다

        for(int i = 0 ; i < 3; i ++){
            int current;
            if(i == 2){
                current = indexs*2;
            }
            else{
                current = indexs + dx[i];
            }

            if(current < 0 || current > 100000 )continue;
            if(vis[current] > 0 )continue;
            
            vis[current] = vis[indexs] + 1;

            if(current == K){
                cout << vis[current] <<"\n";
                return 0;
            }
            Q.push(current);
        }
    }

}