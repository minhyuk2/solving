#include <bits/stdc++.h>

using namespace std;

int N;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i =0 ;i<N;i++){
        int C,D;
        cin >> C >> D;
        cout << "Case #" <<i+1 << ": " << C << " + " << D << " = "<< C+D << "\n";
    }
}