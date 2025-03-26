#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
int N;
ll answer;
vector<int> vec;
vector<int> vec2;
//일단 음수는 음수끼리만 묶어야 하고 0은 음수가 홀수인 경우만 곱하고 그렇지 않은 경우에는 곱하면 안됨
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int number;
    for(int i=0;i<N;i++){
        cin >> number;
        if(number > 0){
            vec2.push_back(number);
        }else{
            vec.push_back(number);
        }
    }
    sort(vec.begin(),vec.end());
    sort(vec2.begin(),vec2.end());
    ll temp =0;
    for(int i=0;i<vec.size();i++){
        if(vec[i] < 0){
            //음수인 경우
            if(temp == 0){
                temp = vec[i];
            }else{
                temp *= vec[i];
                answer += temp;
                temp = 0;
            }
        }else if(vec[i] == 0){
            if(temp <=0){
                temp =0;
            }else{
                temp =0;
            }
        }
    }
    answer += temp;
    temp = 0;
    // cout << vec2.size() << "\n";
    for(int i = vec2.size()-1;i>=0;i--){
        if(vec2[i] == 1){
            answer += temp;
            temp = vec2[i];
            continue;
        }

        if(temp ==0){
            temp = vec2[i];
        }else if(temp == 1){
            // cout << "here\n";
            answer += temp;
            temp = vec2[i];
        }else{
            temp *= vec2[i];
            answer += temp;
            temp =0;
        }
    }
    answer += temp;
    cout << answer << "\n";


}