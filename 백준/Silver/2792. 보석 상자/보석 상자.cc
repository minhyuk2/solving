#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    vector<int> vec;
    for(int i=0;i<M;i++){
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(),vec.end());

    int l= 1;
    int r = vec[M-1];
    int answ;
    while(l<=r){
        int mid = (l+r)/2;

        int cnt = 0;

        for(int i=0;i<M;i++){
            cnt += vec[i] / mid;
            if(vec[i] % mid != 0) cnt++;
        }

        if(cnt <= N){
            r = mid -1;
            answ = mid;
        }else{
            l = mid+1;
        }


    }
    
    cout << answ <<"\n";

}