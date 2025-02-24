#include <bits/stdc++.h>

using namespace std;




set<vector<int>> sets;
vector<int> vec;
bool isUsed[10];
int N;
int M;

//덱을 이용해도 되고 아니면 바로 출력하게끔 짜도 될 것 같긴한데?
void backers(int num, deque<int> &sta){
    if(num == M){
        vector<int> temps;
        for(int i=0;i<M;i++){
            // cout << sta[i] << "\n";
            temps.push_back(sta[i]);
        }
        sets.insert(temps);
        // clear(sta);
        // cout << "\n";
        // sets.insert(arr);
        return; //값을 리턴해야지 의미가 있는게 아닌가?
    }

    for(int i =0 ;i<N;i++){
        // cout << "here\n";
        // 앞에 숫자가 다시 나올 수 있도록 해줘야 한다.
        if(isUsed[i] == 0){
            sta.push_back(vec[i]);
            isUsed[i] = true;
            backers(num+1,sta);
            isUsed[i] = false;
            sta.pop_back();
        }
    }
}

//항상 모든 순열과 조합에 대해서 고민할 때는 next_permutation 함수를 생각해야한다.
//boolean 배열로 중복된 수의 사용을 방지해야 한다.


void getNums(){
    // cout << "here\n";
    for(auto it : sets){
        // cout << it[0];
        for(int i =0;i<it.size();i++){
            cout << it[i] << " ";
        }
        cout << "\n";
    }
}
//stack으로 해버리니까 안되네 바로 출력하던지 아니면 덱을 쓰던지 아니면 원래 했었던 다른 방법을 보던지,,흠


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //누가봐도 백트랙킹이다 왜냐면 너무 경우의 수가 작음
    //수열이 중복되면 안되어서 되는 것을 쓰는데 같은 수가 없어지면 안되는 것이다.
    //중복된 것의 출력의 제거
    //그냥 set에 배열을 넣고 출력해서 꺼내면 되겟네
    //어차피 set이 순서대로 정렬해줄 수 있으니까 믿고
    cin >> N >> M;

    int number;
    for(int i =0; i<N;i++){
        cin >> number;
        vec.push_back(number);
    }
    // sort(vec.begin(),vec.end());
    deque<int> sta;
    backers(0,sta);
    getNums();
}