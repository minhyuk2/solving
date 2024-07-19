#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int dp[32][32];
//얘도 시간나면 한 번 다시 풀어보기

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cases;
    cin >> cases;
    long long int result = 1;
    //재귀적으로 dp를 사용해야하나?
    for(int i = 0 ; i < cases; i++){
        //전의 것이 같아질 때까지 만들어 가는 것이다.
        int N, M, res = 1, tmp = 1;
        std::cin >> N >> M;

        for (int i = M; i > M - N; --i) {
            res = res * i;
            res = res / tmp++;
        }

        std::cout << res << "\n";
    }
}

