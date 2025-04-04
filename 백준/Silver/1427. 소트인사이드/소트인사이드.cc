#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string number;
    cin >> number;
    sort(number.begin(),number.end(),greater<>());

    for(auto it : number)
        cout << it;

    cout << "\n";

}