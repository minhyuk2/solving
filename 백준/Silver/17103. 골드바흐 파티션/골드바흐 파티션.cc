#include <bits/stdc++.h>

using namespace std;

vector<int> getPrime(){
    vector<int> primes;
    vector<bool> state(1000001,true);

    state[1] = false;

    for(int i=2;i<=1000000;i++){
        if(!state[i]) continue;
        for(int t = i*2;t<=1000000;t+=i){
            state[t] = false;
        }
    }

    for(int i=1;i<=1000000;i++){
        if(state[i]) primes.push_back(i);
    }
    return primes;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec = getPrime();

    int N;
    cin  >> N;
    int number;
    for(int i =0;i<N;i++){
        map<int,int> maps;
        cin >> number;
        for(int t=0;t<vec.size();t++){
            if(binary_search(vec.begin(),vec.end(),number - vec[t])){
                // cout << vec[t] << "\n";
                // if(vec[t] != number-vec[t]){
                    if(vec[t] <= (number - vec[t])){
                        maps.insert({vec[t],number-vec[t]});
                    }
                // }
            }
        }
        cout << maps.size() << "\n";
    }



}