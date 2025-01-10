#include <bits/stdc++.h>

using namespace std;

int N;
int answer;
bool attack[10]; //공격한 애 체크
bool broken[10]; //부숴진 애 체크

void eggReal(int me,vector<pair<int,int>> &vec){
    //자기 자신 번호를 받아서 자기 자신빼고 broken빼고 공격가능하게 하면 되는거잖아
    if(me == N){
        int counting =0;
        for(int i = 0; i < N; i++){
            if(broken[i] == 1)
                counting++;
        }
        if(counting > answer)
            answer = counting;
        return;
    }

    if(broken[me] == 1){
        //부숴져서 다음 순서로 못 넘어가는 경우
        eggReal(me+1,vec);
    }

    for(int i = 0; i < N; i++){
        if(i == me)
            continue;
        if(broken[i]==0 && broken[me] == 0){
            //부숴져 있지 않은 애만 부실 수 있고, 걍 자기자신은 넘기기
            int doBroken = 0;
            int doBroken2 = 0;
            vec[i].first = vec[i].first - vec[me].second ;
            if(vec[i].first <=0){
                doBroken = 1;
                broken[i] = 1;
            }
            vec[me].first = vec[me].first - vec[i].second ;
            if(vec[me].first <=0){
                doBroken2 = 1;
                broken[me] = 1;
            }
            eggReal(me+1,vec);
            //공격한 것을 돌려놓아야지
            vec[i].first = vec[i].first + vec[me].second ;
            if(doBroken == 1)
                broken[i] = 0 ;
            
            vec[me].first = vec[me].first + vec[i].second ;
            if(doBroken2 == 1){
                broken[me] = 0;
            }
            //하나만 공격을 해봐야하는데, 첫번째 애가 이러면 다 공격하는건데
        }
    }
    int counting =0;
    for(int i = 0; i < N; i++){
        if(broken[i] == 1)
            counting++;
    }
    if(counting > answer)
        answer = counting;

}


void eggAtt(int X,vector<pair<int,int>> &vec){

    for(int i = 0; i < N; i++){
        if(!attack[i]){
            attack[i] = 1;

        }
    }
}


//앞의 숫자가 내구도 뒤의 숫자가 무게
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<pair<int,int>> vec;
    //이 문제에서는 어떤게 쓰였는지가 중요하지 않고 모든 애들이 모든 것에 계란치기를 한 번씩 해주기를 바래야하는 문제다.

    for(int i = 0; i < N ; i++){
        pair<int,int> newPair;
        cin >> newPair.first >> newPair.second ;
        vec.push_back(newPair);
    }

    eggReal(0,vec);
    
    cout << answer << "\n";
}