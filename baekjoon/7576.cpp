#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


//모든 값들을 넣을 것들
int board[1002][1002];

int riped[1002][1002];

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

//이렇게 클래스는 꼭 ;을 붙혀줘야 한다.


int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool isChecked = false;


    int m, n ;
    cin >> m  >> n;
    queue<checking> Q;

    
    //여기에 값들을 전부 넣어준다. 띄어쓰기로 넣어주기 때문에 걍 int로 넣어주면 된다.
    for(int i = 0 ; i < n  ; i++){
        for(int p = 0 ; p < m ; p++){
            cin >> board[i][p];
            //1인 경우에는 첫째 날로 큐에 넣어준다.
            if(board[i][p] == 1){
                Q.push(checking(i,p,0));
                // cout << "여기들러 : " << i << p << "\n";
                riped[i][p] = 1;
            }
            else if(board[i][p] ==-1){
                riped[i][p] = -1;
            }
        }
    }
    //최소날짜다 .
    int minDay = 0 ;
    while(!Q.empty()){
        //pair값을 받는다 
        pair <int , int> newPair = Q.front().getPairs();

        // cout <<"여기 페어1  :" << newPair.first << "\n";
        // cout <<"여기 페어2  :" << newPair.second << "\n";

        //나온 날짜를 현재날짜로 취급한다
        minDay = Q.front().getDay();
        Q.pop();
        // cout << "여기" << minDay << "\n" ;

        for(int i =0 ; i < 4 ; i ++){
            int nx = newPair.first + dx[i];
            int ny = newPair.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
            //이게 0이 아니면 익을 수 없는 것이기에 이렇게 처리해주는 것이다.
            if(riped[nx][ny] == 1 || board[nx][ny] != 0 ) continue;
            
            riped[nx][ny] = 1;
            int dayss = minDay +1;
            // cout << "dayss 값 : " << dayss << "\n";
            Q.push(checking(nx,ny,dayss));
            
        }
    }
    
    


    //끝나고 마지막에 확인할 때 0이 존재하면 그건 안되는걸로안다.
    for(int i = 0 ; i < n  ; i++){
        for(int p = 0 ; p < m ; p++){
            if(riped[i][p] == 0){
                isChecked = true;
            }
        }
    }

    if(isChecked == true){
        cout << -1 << "\n";
    }else{
        cout << minDay << "\n";
    }

}

//이 문제는 클래스를 만들 필요없이 그냥 다 넣어서 놓고
//안익은 토마토를 -1로 두고 -1이 남아있는지 없는지와 dist의 값을 하나씩 늘려감으로써 날짜를 구할 수 있는 쉬운 문제다
//너무 어렵게 생각하지 말자
