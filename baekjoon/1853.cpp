#include <iostream>
#include <deque>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    //N개를 입력받는다.
    deque<int> deques;
    deques.push_back(N);
    for(int i = N-1; i > 0 ; i--){
        //구하기 위해서 역순으로 접근하는 것이다.
        deques.push_front(i);
        for(int p = 0; p<i; p++){
            deques.push_front(deques.back());
            deques.pop_back();
        }
    }

    for(int i = 0 ; i < N; i ++){
        cout << deques.front() << " ";
        deques.pop_front();
    }
    cout <<"\n";
}