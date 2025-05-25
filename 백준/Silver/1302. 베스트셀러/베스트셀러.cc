#include <bits/stdc++.h>

using namespace std;

map<string,int> maps;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string temp;

    for(int i=0;i<N;i++){
        cin >> temp;
        if(maps.find(temp)!=maps.end()){
            //존재하는 경우
            maps[temp]++;
        }else{
            maps.insert({temp,0});
        }
    }
    int maxNum = -1;
    for(auto it : maps){
        if(it.second > maxNum){
            maxNum = it.second;
        }
    }

    for(auto it : maps){
        if(it.second == maxNum){
           cout << it.first << "\n";
            break;
        }
    }
    
}