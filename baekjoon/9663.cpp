#include <bits/stdc++.h>

using namespace std;
//이 문제는 영상을 보고 풀이를 알게되었음으로 다시 풀어보는게 좋아보임
bool isused1[15];
bool isused2[30];
bool isused3[30];

int counts;
int N;
void func1(int K){

    if(K==N){
        counts++;
        return;
    }
    

        //한 행에 대해서 처리하기 시작하는 것이다.
            //해당 행이 가능한 경우에는 대각선에 대한 검사를 진행한다.
        for(int t =0 ; t < N; t++){
            //열에 대한 증가
            if(!isused1[t]){
                //열에 대해서 되는지 확인해야하니까
                if(!isused2[K+t]){
                    if(!isused3[K-t+N-1]){
                        isused1[t] = true;
                        isused2[K+t] = true;
                        isused3[K-t+N-1] = true;
                        func1(K+1);
                        isused1[t] = false;
                        isused2[K+t] = false;
                        isused3[K-t+N-1] = false;
                }
            }
        }
    }
}







int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //10초 제한이기에 10억 개의 연산까지 가능함 재귀를 쓰는 문제라고 생각할 수 있겠다.


    cin >> N;
    
    func1(0);
    cout << counts << "\n";
}