#include <bits/stdc++.h>

using namespace std;

bool isUsed[10];
vector<int> vec;
vector<int> outVec; 
set<vector<int>> sets;
int N,M;
void getTrack(int num,int prev){
    if(num == M){
        // set<int> temps;
        // for(int i=0;i<M;i++){
        //     cout << outVec[i] << " ";
        // }
        // cout << "\n";
        sets.insert(outVec); //이것도 중복을 잡는 것이다.
        return;
    }

    for(int i=prev;i<N;i++){
        if(!isUsed[i]){
            isUsed[i] = 1; //얘가 중복을 잡는 것이고 자기 자신 사용에 대한
            outVec[num] = vec[i];
            getTrack(num+1,i);
            isUsed[i] = 0;
        }
    }
}

void showSet(){
    for(auto it : sets){
        for(int i =0;i<M;i++){
            cout << it[i] << " ";
        }
        cout << "\n";
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int number;
    for(int i =0; i<N;i++){
        cin >> number;
        outVec.push_back(0);
        vec.push_back(number);
    } 
    sort(vec.begin(),vec.end());
    getTrack(0,0);
    showSet();

}