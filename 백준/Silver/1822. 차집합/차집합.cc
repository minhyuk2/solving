#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int A,B;
vector<ll> vec1;
vector<ll> vec2;

vector<ll> answer;
ll counts;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B;
    ll number;
    for(int i=0;i<A;i++){
        cin >> number;
        vec1.push_back(number);
    }
    for(int i=0;i<B;i++){
        cin >> number;
        vec2.push_back(number);
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    
    for(auto it : vec1){
        if(!binary_search(vec2.begin(),vec2.end(),it)){
            counts++;
            answer.push_back(it);
        }
    }

    cout << counts << "\n";
    for(auto it : answer){
        cout << it << " ";
    }
    cout << "\n";

}