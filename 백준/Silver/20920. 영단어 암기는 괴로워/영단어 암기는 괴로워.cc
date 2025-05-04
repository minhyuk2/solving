#include <bits/stdc++.h>

using namespace std;

bool customS( pair<string,int> p1, pair<string,int> p2){
    if(p1.second > p2.second){
        return true;
    }else if (p1.second == p2.second){
        if(p1.first.size() > p2.first.size()){
            return true;
        }else if(p1.first.size() == p2.first.size()){
            return p1.first < p2.first;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    map<string,int> maps;
    string temp;
    for(int i=0;i<N;i++){
        cin >> temp;
        if(temp.size() >= M ){
           if( maps.find(temp) != maps.end()){
                maps.at(temp)++;
           }else{
                maps.insert({temp,1});
           }
        }
    }

    vector<pair<string, int>> vec(maps.begin(),maps.end());

    sort(vec.begin(),vec.end(),customS);

    for(auto it : vec){
        cout << it.first << "\n";
    }


    
}