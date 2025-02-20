#include <bits/stdc++.h>
using namespace std;


//약간 그리디 느낌으로 들어오는 스티커를 바로 판단해서 처리해야한다.
int sticker[14][14];
int N,M,K;
int arr[45][45];
int R,C;

void colorSticker(int nowX,int nowY,vector<pair<int,int>> &vec){
    for(auto it: vec){
        pair<int,int> newPair = it;
        arr[it.first+nowX][it.second+nowY] = 1;
    }
}

//회전 시키는거 필요함 -> 90도 회전시 어떤 위치로 가는지에 따라 벡터 다르게 하면 됨
void rollSticker(vector<pair<int,int>> &vec, int counter){
    if(counter ==0){
        return;
    }else{
        ///90도씩 계속 회전 시키면 되니까
        for(int i=0;i<vec.size();i++){
            // pair<int,int> newPair = it;
            int temp = vec[i].first;
            vec[i].first = vec[i].second;
            vec[i].second = (R-1) -temp;
        }
        //가로 세로 크기도 도려줘야함
        int temp2 = R;
        R = C;
        C = temp2;
    }

    //단위테스트를 하듯이 코드를 짜야함 -> 시뮬레이션 문제의 경우
    // for(auto it: vec){
    //     cout << it.first << " " << it.second << "\n";
    // }
}


int getSticker(vector<pair<int,int>> &vec){

    //sticker가 있는 위치만 pair로 둬서 그게 하나라도 되어있는지 확인할까? 거기에 하나씩 이동하는 식으로 둬서?
    //그럼 4중 중첩 -> 40*40*40*40 -> 1600 * 1600 => 2560000 -> 256만 여기에 100을 곱하면 좀 많이 커지는데
    //아니네 그냥 여기서 걍 바로 해결 되긴하네
    int checking =0;
    
    for(int i = 0;i<N;i++){
        for(int t=0;t<M;t++){
            checking =0;
            for(auto it : vec){
                pair<int,int> newPair = it;
                if(it.first+i >= N||it.second+t >= M){
                    checking = 1;
                    break;
                }

                if(arr[it.first+i][it.second+t]!=0){
                    checking = 1;
                    break;
                }
            }
            if(checking == 0){
                colorSticker(i,t,vec);
                return 1;
            }
        }
    }
    return 0;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;


    for(int i=0;i<K;i++){
        vector<pair<int,int>> vec;
        cin >> R >> C;
        for(int t=0;t<R;t++){
            for(int p=0;p<C;p++){
                cin >> sticker[t][p];
                if(sticker[t][p] ==1){
                    vec.push_back({t,p});
                }
            }
        }
        for(int i=0;i<4;i++){
            rollSticker(vec,i);
            if(getSticker(vec) == 1){
                break;
            }
        }
    }


    long long int answer= 0;
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            if(arr[i][t] ==1){
                answer++;
            }
            // cout << arr[i][t]<<" " ;
        }
        // cout << "\n";
    }

    cout << answer <<"\n";
}