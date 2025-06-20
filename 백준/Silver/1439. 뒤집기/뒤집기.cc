#include <bits/stdc++.h>

using namespace std;

string S;
vector<pair<int,int>> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S;

    int temp  = S[0] - '0';
    int st = 0;
    int en = 0;
    for(int i =1;i<S.length();i++){
        if(S[i]-'0' == temp){
            en ++;
        }else{
            pair<int,int> newPair;
            newPair.first = st;
            newPair.second = en;
            vec.push_back(newPair);
            st = i;
            en = i;
            temp = S[i]-'0';
        }
    }

    vec.push_back({st,en});

    int sizes = vec.size();

    if(sizes == 1){
        cout << 0 << "\n";
    }else{
        if(sizes%2==0){
            cout << sizes/2 << "\n";
        }else{
            if(sizes==2){
                cout << 1 << "\n";
            }else{
                cout << sizes/2<< "\n";
            }
        }
    }

}