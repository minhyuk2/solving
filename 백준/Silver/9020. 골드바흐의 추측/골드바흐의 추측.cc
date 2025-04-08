#include<bits/stdc++.h>

using namespace std;

vector<int> primes;
void getPrime(){
    vector<bool> state(10010,true);
    state[1] = false;

    for(int i =2 ; i <=10002;i++){
        if(!state[i]) continue;
        for(int t= i*2; t<=10002;t+=i){
            state[t] = false;
        }
    }

    for(int i=2;i<=10002;i++){
        if(state[i]){
            primes.push_back(i);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    getPrime();

    int number;
    for(int i=0;i<N;i++){
        cin >> number;
        vector<pair<int,int>> vecs;
        
        for(int t=0;t<primes.size();t++){
            if(binary_search(primes.begin(),primes.end(),number-primes[t])){
                if(primes[t] <= number-primes[t]){
                    vecs.push_back({primes[t],number-primes[t]});
                }
            }
        }
        cout << vecs[vecs.size()-1].first << " " << vecs[vecs.size()-1].second << "\n";
    }

}