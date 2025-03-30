#include <bits/stdc++.h>

using namespace std;

bool isOk[1010];
vector<int> vec;

int N,K;

void getPrime(){
    for(int i=2;i<=N;i++){
        for(int t = i;t<=N; t+=i){
            if(isOk[t]==0){
                isOk[t] = 1;
                vec.push_back(t);
            }
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    getPrime();
    cout << vec[K-1] << "\n";

}