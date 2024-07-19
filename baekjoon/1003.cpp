#include <iostream>

using namespace std;

long long int dp0[41];
long long int dp1[41];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //testcase의 개수를 입력받는다.
    int test;
    int inputs;
    cin >> test; 
    //이렇게 작성하거나 아니면 구조체나 class로 생성해서 만들어도 된다.
    dp0[0] = 1;
    dp1[0] = 0;
    dp0[1] = 0;
    dp1[1] = 1;
    
    for(int i =0;i<test;i++){
        cin >> inputs;
        for(int p = 2;p<=inputs;p++){
            dp0[p] = dp0[p-1] + dp0[p-2];
            dp1[p] = dp1[p-1] + dp1[p-2];
        }
        cout << dp0[inputs] << " " << dp1[inputs] << "\n";
    }
    return 0;
}