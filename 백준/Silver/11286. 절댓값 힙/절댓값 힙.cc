#include <bits/stdc++.h>

using namespace std;

struct cmp{

    bool operator()(int A, int B){

        if(abs(A) > abs(B)){
            return true;
        }else if(abs(A) == abs(B)){
            return A > B;
        }else{
            return false;
        }
    }
};


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N;
    int temp;
    priority_queue<int,vector<int>,cmp> que;

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> temp;

        if(temp == 0 ){
            if(que.empty()){
                cout << 0 << "\n";
                continue;
            }
            cout << que.top() << "\n";
            que.pop();
        }else{
            que.push(temp);
        }
    }
 

}