#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    string temp;
    set<string> sets;
    int answer = 0;
    for(int i=0;i<N;i++){
        cin >> temp;
        if(temp == "ENTER"){
            answer += sets.size();
            sets.clear();
            continue;
        }
        sets.insert(temp);
    }
    answer += sets.size();
    
    cout << answer << "\n";
}