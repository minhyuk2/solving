#include <bits/stdc++.h>

using namespace std;

int S;
int N;
int arr[21];
bool isused[21];
int sum;
int counts;
//시간이 2초 제한이기 때문에 재귀나, 반복문이 많이 쓰이는 문제인가보네
//모든 21개의 정수밖에 주어지지 않았으니 모든 경우의 수를 다 처리하는 것 같음
//이게 모든 경우의 수를 구하는 것이기 때문에 0 0 0 0 0을 더해도 0이 된다는 것과 같은 케이스를 빼면 안된다.
void func1(int num){
    //한 개일때부터 계속 처리해나가는 형태
    //아니면 배열의 첫번째꺼부터 더하고 2번째꺼 더하고 하는 형태?
    for(int i = num ; i < N; i++){
        if(!isused[i]){
            if((sum+arr[i])==S){
                counts++;
                // cout << sum<< " " << i <<"\n";
                // continue;
            }
            sum += arr[i];
            isused[i] = true;
            func1(i+1);
            sum -= arr[i];
            isused[i] = false;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> S;
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    func1(0);
    cout << counts << "\n";

}