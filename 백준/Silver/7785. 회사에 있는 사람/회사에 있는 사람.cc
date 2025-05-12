#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //키 값으로 사람을 찾아야 하기 때문에,  map
    map<string,bool,greater<string>> maps;

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string temp, status;
        cin >> temp >> status;
        if(maps.find(temp)==maps.end()){
            if(status == "enter"){
                maps.insert({temp,true});
            }
        }else{
            if(status ==  "leave"){
                maps.at(temp) = false;
            }else if(status == "enter"){
                maps.at(temp) = true;
            }

        }
    }

    for(auto it : maps){
        if(it.second == true){
            cout << it.first << "\n";
        }
    }


}