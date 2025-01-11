#include <bits/stdc++.h>

using namespace std;

int N;

//재귀로 만들 수 있는 것은 반복문으로도 만들 수 있다.
void makeCase(){
    queue<int> que;
    for(int i =1; i <= N;i++){
        que.push(i);
    }
    int temp;
    for(int i = 0; ; i++){
        if(que.size() == 1){
            temp = que.front();
            cout << temp << "\n";
            break;
        }
        if(i%2 == 0){
            que.pop();
        }else{
            temp = que.front();
            que.pop();
            que.push(temp);
        }


    }
    
}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    makeCase();

}