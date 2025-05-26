#include<bits/stdc++.h>

using namespace std;

map<string,string> maps;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    string temp1, temp2;
    for(int i=0;i<N;i++){
        cin >> temp1 >> temp2;
        maps.insert({temp1,temp2});
    }

    for(int i=0;i<M;i++){
        cin >> temp1;
        cout << maps[temp1] << "\n";
    }

}