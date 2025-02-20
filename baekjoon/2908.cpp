#include <bits/stdc++.h>

using namespace std;

string  A, B;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> A >> B;

    string inversA, inversB;
    for(int i=2;i>=0;i--){
        inversA.push_back(A[i]);
        inversB.push_back(B[i]);
    }

    if(stoi(inversA) >= stoi(inversB)){
        cout << stoi(inversA) << "\n";
    }else{
        cout << stoi(inversB) << "\n";
    }


}