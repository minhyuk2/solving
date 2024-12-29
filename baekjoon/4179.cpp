#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


//모든 값들을 넣을 것들
string board[1002];

int vis[1002][1002];

class checking{
    
    private : 

    pair < int , int> pairs;

    int day;


    public : 
        checking(int a, int b , int days){
        //와 이렇게 클래스 선언해서 넣어줄 때 days 이름하고 day랑 같게 되면 오류가 발생할 수 있기 때문에 조심
            pairs = {a,b};
            day = days;
        }
        
        void setPairs(int a, int b){
            pairs = {a,b};
        }
        void setDay(int day){
            day = day;
        }
        pair<int,int> getPairs() const{
            return pairs;
        }

        int getDay() const{
            return day;
        }

};

//강의에서는 이 문제를 불을 먼저 이동시키고 불이 이동하는 시간을 고려하고 그 후에 지훈이가 움직이고 그 시간을 비교하는 것이다.
//그러고 이동한 곳에 대한 BFS vis 같은 것을 각각 만들어서 이동을 비교하는 것이다.


int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int r , c;
    cin >> r >> c;

    for(int i = 0 ; i < r ; i ++){
        cin >> board[i];
    }

    //J를 위한 Queue
    queue < pair <int, int> > Q;
    //F를 위한 queue
    queue < checking> Q2;

    int daysss = 0 ;
    //벽에는 -99값을 넣어서 벽이 나왔을때는 결과가 제대로 나오지 않도록 설정한다.
    for(int i = 0 ; i < r ; i ++){
        for(int p = 0 ; p < c ; p++){
            if(board[i][p] == '#'){
                vis[i][p] = -99;
                
            }
            else if(board[i][p] == 'J'){
                vis[i][p] = 1;
                Q.push({i,p});

                if(i==0||i==r-1){
                    cout << 1 << "\n";
                    return 0;
                }else{
                    if(p==0||p==c-1){
                        cout << 1 <<"\n";
                        return 0;
                    }
                }
            }
            else if(board[i][p]=='F'){
                //이렇게 하면 F인 곳에 대해서는 저부 처리할 수 있는건데
                Q2.push(checking(i,p,0));
            }

        }
    }
    int maxDay = 0;
    //Q가 다 비어질 때까지 반복 거리를 구하는 것이다. 나중에 가장 자리만 돌아서 그 값을 구하면 되니까
    //일단 다 돌린다는 마음가짐으로 돌리자
    while(!Q.empty()){  
        pair<int,int> newPair = Q.front();
        Q.pop();
        //이 날짜 설정을 언제할지가 관건이다.
        daysss ++;
        
        for(int i = 0 ; i< 4 ; i ++){

            //nx ny값을 이렇게 설정한다.
            int nx = newPair.first + dx[i];
            int ny = newPair.second + dy[i];

            if(nx <  0 || nx >= r || ny < 0 || ny >=c) 
            {
                cout << vis[newPair.first][newPair.second]  << "\n";
                return 0;
            }
            //갔던 곳을 또 가는건 아닌거 같아서 그건 막아야 할듯
            
           
            //이렇게 하면 가장자리가 남아서 생기는 부분이 있지 않을까? vis의 값을 수정해나가야하는게 아닐까?
            if(vis[nx][ny] != 0 || board[nx][ny] == 'F') continue;
            
            vis[nx][ny] = vis[newPair.first][newPair.second] + 1;
            if(maxDay < vis[nx][ny]){
                maxDay = vis[nx][ny];
            }
            Q.push({nx,ny});
        }

        //이제 불에 대한 이동을 해주어야 한다.
        while(!Q2.empty()){

            checking newCheck = Q2.front();
            if(newCheck.getDay() < daysss){
                Q2.pop();
                for(int i = 0 ; i< 4 ; i++){

                     int nx =  newCheck.getPairs().first + dx[i];
                     int ny = newCheck.getPairs().second + dy[i];

                     if(nx < 0 || nx >= r || ny < 0 || ny >=c ){
                        continue;
                     }
                    // cout << "지금 여기 정보 : " << nx <<" :: " << ny  << "::" << daysss << "\n";
                    if(board[nx][ny] =='F'|| board[nx][ny] =='#'||board[nx][ny] =='J') continue;
                    //이러면 지나간 길에 대해서 안되니까 
                    //이게 걸리는구나 ㅇㅎ
                    //이미 지나갔던 곳에 대해서 vis > 0이라서 안된다고 보는 것이다.
                    //이게 bfs로 이동하다보니까 여러가지 방향으로 가고 머릿속으로 생각하는 것처럼 한 칸씩 움직이려면 J도 딱 정해서 이동시켜야한다.
                    if(vis[nx][ny] > 0 && (vis[nx][ny] == maxDay)){
                        cout << "IMPOSIIBLE1\n";
                        return 0;
                    }
                    board[nx][ny] = 'F';

                    Q2.push(checking(nx,ny,daysss+1));
                }
            }else {
                break;
            }
        }
        //일단 이중 for문이라 안좋긴해
    }

    int minDay=1001;
    //가장 자리를 전부 돌면서 가장 자리가 <0인 경우에는 하면되는거고 어차피 가장자리의 값이 중요한 것이니까 ㅇㅇ.
    
    for(int i = 0 ; i<r; i++){
        for(int p = 0  ; p<c ;p++){

            if(i == 0|| i ==r-1){
                if(board[i][p] == 'J'){
                    cout << 1 << "\n";
                    return 0;
                }
                if(vis[i][p] > 0){
                    //이렇게 되면 걍 못나갔을 때도 minDay에 설정되는건데 ,,,흠
                    if(minDay > vis[i][p]){
                        minDay = vis[i][p];
                    }
                }
            }else{
                if( p == 0 || p == c-1){
                        if(board[i][p] == 'J'){
                            cout << 1 << "\n";
                            return 0;
                        }
                    if(vis[i][p] > 0){
                        //이렇게 되면 걍 못나갔을 때도 minDay에 설정되는건데 ,,,흠
                        if(minDay > vis[i][p]){
                            minDay = vis[i][p];
                        }
                }
            }
        }
    }
}

    if(minDay == 1001){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << minDay << "\n";
    }
}

