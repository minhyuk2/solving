#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


// //이렇게 사용하려고 한다면 vector를 쓰는 방법뿐이다. 왜냐면 2차원 배열에서 배열의 크기를 모른다면 처리 할 수 없기 때문이다.
// int bfsS(queue<pair<int,int>> Q, int n  , int m,int vis[][], int arrays[][] ){

//     int popCount = 0;
//     int maxS;
//     while(!Q.empty()){
//     //첫번 째 것을 찾아놓고 pop한다.
//     pair<int, int> cur = Q.front();
//     Q.pop();
//     popCount++;
//     if(popCount > maxS){
//         maxS = popCount;
//     }
//         for(int dir = 0 ; dir  <4 ; dir++){
//             int nx = cur.first + dx[dir];  //이렇게 만들어지는 x값과 y값을 통해서 다음 좌표를 찾아나가는 형식인 것이다.
//             int ny = cur.Y + dy[dir];
//             if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue; //범위에 넘어가는 것에 대해서는 걍 넘어가게 하는 것이다. 그래야지 범위를 벗어나는 것을 선택하여 런타임에러가 나지않기 위해서
//             if(vis[nx][ny] || arrays[nx][ny] != 1) continue; //이미 방문했던 곳이나 arrays에 이미 0인 경우에는 방문안한다.
//             vis[nx][ny] = 1;
//             Q.push({nx,ny}); //큐에 넣어준다.
//         } 
//     }

//     return
// }
//이게 전역에 있지않으면 초기화안되어서 오류
   bool vis[502][502];



int main(void){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count = 0 ; //그림의 개수 세기
    int n,m;
    int maxS = 0 ; //가장 큰 그림의 크기다.
    int popCount = 0;
    //행과 열 개수를 넣어준다.
    cin >> n >> m;
    int arrays[n][m];

    for(int i = 0; i < n ; i++){
        for(int p = 0; p < m ; p++){
            //각 배열에 해당하는 값들을 집어넣는다.
            cin >> arrays[i][p] ;
        
        }
    }

    
    //bfs를 짜는 기본 공식을 암기해야한다.


    //방문했던 것에 대해서는 bool형으로 만들어서 처리해둔다.
 



    //큐가 비어있지 않은 경우에 대한 처리이다.

    
    for(int i = 0 ; i < n; i++){

        for(int p =0; p < m ; p++){
             
            if(arrays[i][p] == 0 || vis[i][p]) continue;
                //그림의 개수 추가하기
                count ++;
                vis[i][p] = 1;
                popCount = 0;
                queue< pair<int,int> > Q;
                Q.push({i,p});
                    while(!Q.empty()){
                    //첫번 째 것을 찾아놓고 pop한다.
                        popCount++;
                        pair<int, int> cur = Q.front();
                        Q.pop();
    
                            for(int dir = 0 ; dir  < 4 ; dir++){
                                int nx = cur.first + dx[dir];  //이렇게 만들어지는 x값과 y값을 통해서 다음 좌표를 찾아나가는 형식인 것이다.
                                int ny = cur.second + dy[dir];
                                if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue; //범위에 넘어가는 것에 대해서는 걍 넘어가게 하는 것이다. 그래야지 범위를 벗어나는 것을 선택하여 런타임에러가 나지않기 위해서
                                if(vis[nx][ny] || arrays[nx][ny] != 1) continue; //이미 방문했던 곳이나 arrays에 이미 0인 경우에는 방문안한다.
                                vis[nx][ny] = 1;
                                Q.push({nx,ny}); //큐에 넣어준다.
                            } 
                        //이렇게 max함수를 사용하면 max를 쉽게 구할 수 있다.
                       
                    }
             maxS = max(maxS,popCount);
        }
    }

    cout <<  count << "\n" << maxS << "\n";


}
