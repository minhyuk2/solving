#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string temp;
    string temp2;
    vector<string> vec;
    set<string> sets;
    bool ss = false;
    for(int i=0;i<N;i++){
        cin >> temp >> temp2;
        if(temp == "ChongChong"||temp2 == "ChongChong"){
            sets.insert(temp);
            sets.insert(temp2);
            ss = true;
            continue;
        }

        if(ss){
            for(auto it : sets){
                if(it == temp){
                    sets.insert(temp2);
                }else if(it == temp2){
                    sets.insert(temp);
                }
            }
        }
    }
    cout << sets.size() << "\n";
}