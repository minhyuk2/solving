#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

//이렇게 전역에 배열을 선언하여, 0으로 자동으로 초기화 시킨다.
//visit도 하나의 예약어인가보네 ㅇㅋ
int vis[102][102];

//얘네는 동서남북을 표현하기 위해서 사용하는 것들이다.
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


string board[102];

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
    
    //인자로 입력받을 n,m변수를 선언한다.
    int n,m;
    cin >>  n  >>  m; 

    // cout << n << m << "\n";
    // 다 담을 배열선언
    //이렇게 나중에 배열을 선언하는 형식이 별로 좋은 것은 아니다. 이것도 최대한의 넓이로 미리 선언해두고 하는 것이 더 좋을 수 있다.

    
    //왜 문자열 배열로 하는 것일까?

    //값을 전부 입력받아서 넣어준다.
    //문제 조건에서 각 수들이 붙어서 입력된다고 하였기 때문에 문자열로 입력을 받는거구나 떼어져 있어야지만 int배열로 받는데 붙어 있으니까 하나의 숫자로 보는구나..ㅇㅎ
    //약간의 작은 조건들도 문제풀이의 큰 영향을 끼칠 수 있으니까 주의해서 풀자.
    for(int i = 0; i < n ; i++){
        //이렇게 문자열한 줄 씩 입력받게 하는 것이다.
        //이렇게 한 줄씩 입력받아하는거지 하나의 행으로 처리하기 때문에
        cin >> board[i];
    }
    //이런데서 fill을 쓰기 위해서 이중배열을 사용하는 것인가?
    for(int  i =0 ; i< n; i++){
        //visit도 고유명사느낌이기때문에 사용하면 안되나 보네 ㅇㅋ
        fill(vis[i],vis[i]+m,-1);
        // for(int p = 0; p < m; p++){
        //     vis[i][p] = -1;
        // }
    }

    queue < pair<int,int> > Q;
    //첫번째 방문한 것에 대해서 값을 1로 넣어주고
    vis[0][0] = 1;

    Q.push({0,0});

    while(!Q.empty()){
        //첫번째 값을 pair에 넣어준다.
        pair <int, int> newPair = Q.front();
        Q.pop();
        //큐에 넣을 때 더해주면 된다. 원래 애가 갖고 있는 값을 더해주면 되는 것이다.
        for(int i = 0 ; i < 4 ; i++){
                int nx = newPair.first + dx[i];
                int ny = newPair.second + dy[i];
                if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
                if(vis[nx][ny] != -1 || board[nx][ny] != '1' ) continue;
                Q.push({nx,ny});
                // cout << "this is nx ny" << nx << ny << "\n";
                vis[nx][ny] = vis[newPair.first][newPair.second] + 1;
        }

    }

    cout << vis[n-1][m-1] << "\n";

}