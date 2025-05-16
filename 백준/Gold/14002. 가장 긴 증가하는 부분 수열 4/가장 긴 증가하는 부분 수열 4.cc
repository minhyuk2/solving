#include <bits/stdc++.h>

using namespace std;

int dp[1010];
vector<int> ans[1010];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> vec;
    int temp;
    for(int i=0;i<N;i++){
        cin >> temp;
        vec.push_back(temp);
    }
    
    for(int i = N-1;i>=0;i--){
        dp[i]++;
        ans[i].push_back(vec[i]);
        int temper = vec[i];
        for(int t = i; t < N;t++){
            if(vec[t] > temper){
                // cout << vec[t] << "\n";
                if(dp[i] <=dp[t]){
                    dp[i] = dp[t] + 1;
                    vector<int> tempV;
                    tempV.push_back(vec[i]);
                    for(auto it : ans[t]) tempV.push_back(it);
                    ans[i] = tempV;
                }
            }
        }
    }

    int maxs = -1;
    int idx = 0;
    for(int i=0;i<N;i++){
        
        if(dp[i] > maxs){
            maxs = dp[i];
            idx = i;
        }
    }

    cout << maxs << "\n";
    for(auto it : ans[idx]){
        cout << it << " ";
    }
    cout << "\n";
}