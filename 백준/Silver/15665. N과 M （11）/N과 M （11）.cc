#include <bits/stdc++.h>

using namespace std;

int N,M;

vector<int> vec;
int arr[10];
set<vector<int>> sets;

void getBack(int num){

    if(num == M){
        vector<int> temp;
        for(int i =0;i<M;i++){
            temp.push_back(arr[i]);
        }
        sets.insert(temp);
        return ;
    }

    for(int i =0; i<N; i++){
        arr[num] = vec[i];
        getBack(num+1);
    }
}

void printAlls(){
    for(auto it: sets){
        for(int i=0;i<it.size();i++){
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
    for(int i=0;i<N;i++){
        cin >> number;
        vec.push_back(number);
    }

    
    getBack(0);
    printAlls();
}