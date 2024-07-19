#include <iostream>
#include <queue>

//다시 한 번 풀어보자
using namespace std;

int info[101]; //사다리와 뱀에 대한 정보를 저장
bool visited[101]; //방문했는지 안했는지에 대한 판단

void bfs(){
    //현재 위치와 주사위 횟수를 저장하기 위해서 queue를 사용한다...ㅇㅎ 
    queue<pair<int, int> > que;
    que.push( {1,0});//처음에는 1번째 칸 이고 주사위를 한 번도 던지지 않았기 때문
    while(!que.empty()) {
        int cur = que.front().first;
        int cnt = que.front().second;
        que.pop();
        if(cur == 100) {
            cout << cnt << '\n';
            return;
        }

        for(int i = 1; i <= 6; i++) {
            int next = cur + i;
            if(next > 100 || visited[next]) continue;
            if(info[next] > 0) next = info[next]; // 사다리 또는 뱀 따라 이동
            que.push( {next, cnt+1} );
            visited[next] = true;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N  >> M; //입력받을 사다리와 뱀의 개수를 받는다.
    
    int from, to;
    //어디서 어디로 갈지를 저장해주는 것이다.
    for(int i = 0 ; i < N+M;i++){
        cin >> from >> to;
        info[from] = to ;
        //이렇게 1차원 배열로 사다리와 뱀을 나타내주는 것이다.
    }
    //to가 현재 위치보다 작아지면 뱀인 것이고 그렇지 않으면 사다리인 것이지 ㅇㅇ
    bfs();

}

