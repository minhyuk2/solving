#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int N;
ll answer;

vector<int> A;
vector<int> B;
// vector<ll> answer;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int number;
    for(int i=0;i<N;i++){
        cin >> number;
        A.push_back(number);
    }
    
    for(int i=0;i<N;i++){
        cin >> number;
        B.push_back(number);
    }

    //next_permutation은 무조건 정렬된 상태에서 시작해야함
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    for(int i=0;i<N;i++){
        answer += A[i]*B[i];
    }

    // do{
    //     ll temp = 0;
    //     for(int i =0;i<N;i++){
    //         // cout << A[i];
    //         temp += A[i]*B[i]; 
    //     }
    //     // cout << "\n";
    //     // cout << temp << "\n";
    //     if(temp < answer){
    //         answer = temp;
    //     }
    // }while(next_permutation(A.begin(),A.end()));
    //순서대로만 바뀌면 안된다.?
    //N!이기 때문에 시간초과가 발생하게 된다.
    cout << answer << "\n";
}