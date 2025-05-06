#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A;
    vector<int> B;

    int temp;
    for(int i=0;i<N;i++){
        cin >> temp;
        A.push_back(temp);
    }

    for(int i=0;i<M;i++){
        cin >> temp;
        B.push_back(temp);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int checks = 0;
    int answer = 0;
    for(int i=0;i<N;i++){
       if(binary_search(B.begin(),B.end(),A[i])){
            checks ++;
       }
    }
    answer = A.size() - checks;
    checks = 0;
    for(int i=0;i<M;i++){
        if(binary_search(A.begin(),A.end(),B[i])){
             checks ++;
        }
    }
    answer += (B.size() - checks);
    cout << answer << "\n";
}