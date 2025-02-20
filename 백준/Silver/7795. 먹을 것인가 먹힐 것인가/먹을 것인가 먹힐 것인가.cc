#include <bits/stdc++.h>

using namespace std;
int T,N,M;
vector<int> arr;
vector<int> arr2;
int dp[20010];



void getValue(){
    sort(arr.begin(),arr.end());
    sort(arr2.begin(),arr2.end());
    long long int answer =0;
    for(auto it = arr.rbegin();it != arr.rend();++it){
        for(auto ti = arr2.begin();ti != arr2.end();++ti){
            if(*it > *ti)
                answer++;
            else
                break;
        }
    }
    cout << answer << "\n";
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    int number;
    for(int i =0;i<T;i++){
        cin >> N >> M;
        arr.clear();
        arr2.clear();
        for(int t=0;t<N;t++){
            cin >> number;
            arr.push_back(number);
        }
        for(int t=0;t<M;t++){
            cin >> number;
            arr2.push_back(number);
        }
        getValue();

    }
}