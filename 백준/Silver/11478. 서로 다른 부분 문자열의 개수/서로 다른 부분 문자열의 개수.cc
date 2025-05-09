#include <bits/stdc++.h>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> sets;

    string temp;
    cin >> temp;
    int leng = temp.size();
    for(int i=0;i<leng;i++){
        string temper = "";
        for(int t= i;t<leng;t++){
            temper += temp[t];
            sets.insert(temper);
        }
    }

    cout << sets.size() << "\n";
}