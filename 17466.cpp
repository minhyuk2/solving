#include <iostream>

using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    //꼭 하나의 계산을 다 끝낸 다음에 다음의 계산을 하는 것이 아니라 한 가지 과정을 하면서 다른 과정도 같이 할 수 있다고 생각하는게 중요하네
    long long N, R=1, P;
    cin >> N >> P;
    for(int i = 1; i < N+1 ; i++){
        R = R * i % P;
    }
    cout << R;

    
}