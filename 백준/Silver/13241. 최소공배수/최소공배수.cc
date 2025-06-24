#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

ll gcb(ll A, ll B){
    

  
    if(B ==0){
        return A;
    }
    ll C = A % B;

    return gcb(B,C);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //유클리드 호재법이 뭔데
    //일단 재귀적으로 작성해서 하는 것이다.

    ll A, B;

    cin >> A >> B;

    ll gcb2 = gcb(A,B);


    cout << A*B/gcb2 << "\n";

}