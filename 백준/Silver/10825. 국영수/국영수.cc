#include <bits/stdc++.h>

using namespace std;


vector<pair<string,vector<int>>> vec;


bool comp(pair<string,vector<int>> A, pair<string,vector<int>> B){
    if(A.second[0] > B.second[0]){
        return true;
    }else if(A.second[0] == B.second[0]){
        if(A.second[1] < B.second[1]){
            return true;
        }else if(A.second[1] ==  B.second[1]){
            if(A.second[2] > B.second[2]){
                return true;
            }else if(A.second[2] == B.second[2]){
                return A.first < B.first;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int N;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    string temp;
    int num1;
    int num2;
    int num3;
    for(int i=0;i<N;i++){
        cin >> temp >> num1 >> num2 >> num3;
        vector<int> tempers;
        tempers.push_back(num1);
        tempers.push_back(num2);
        tempers.push_back(num3);

        vec.push_back({temp,tempers});
    }

    sort(vec.begin(),vec.end(),comp);
    for(auto it : vec){
        cout << it.first <<  "\n";
    }
}