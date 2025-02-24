#include <bits/stdc++.h>

using namespace std;

vector<string> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string temp;
    cin >> temp;

    for(int i =0;i<temp.size();i++){
        string tempss = temp.substr(i,temp.size());
        vec.push_back(tempss);
    }
    sort(vec.begin(),vec.end());

    for(auto it : vec){
        cout << it << "\n";
    }

}