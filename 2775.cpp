#include <iostream>


using namespace std;

long long dp[15][15];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //초기값을 설정해준다.
    for(int i =1;i<15;i++){
        dp[0][i] = i;
    }
    //test case의 개수를 입력받는다
    int test;
    cin >> test;
    int k, n;
    for(int p = 1;p<=14;p++){
        for(int q = 1; q<15;q++){
            for(int x = 1; x<=q; x++){
                dp[p][q] += dp[p-1][x];
            }
        }
    }
    for(int i =0; i < test; i++){
        cin >> k;
        cin >> n;
        cout << dp[k][n] << "\n";
    }

}