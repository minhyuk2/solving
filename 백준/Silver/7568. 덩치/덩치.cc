#include <bits/stdc++.h>

using namespace std;

int num;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num;

    vector<pair<int,int>> vec;

    for(int i=0;i<num;i++){
        pair<int,int> pairs;
        cin >> pairs.first >> pairs.second;
        vec.push_back(pairs);
    }
    vector<int> answer;
    for(int i=0;i<num;i++){
        int numbers = 0;
        for(int t = 0; t<num;t++){
            if(t==i) continue;
            if(vec[i].first < vec[t].first){
                if(vec[i].second < vec[t].second){
                    numbers ++;
                }
            }
        }
        answer.push_back(numbers+1);
    }

    for(auto it : answer){
        cout << it << " ";
    }
    cout << "\n";

}