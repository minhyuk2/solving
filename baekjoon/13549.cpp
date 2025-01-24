#include <bits/stdc++.h>

using namespace std;

int N,K;
long long int answer;
long long int arr[100001] = {0,};


void catchSister(){
    queue<long long int> que;
    que.push(N);
    arr[N] = 1;
    while(!que.empty()){
        long long int newNum = que.front();
        que.pop();
        // cout << newNum << "\n";
        if(newNum == K){
            cout << arr[newNum]-1 << "\n";
            return;
        }
        for(int i=0;i<3;i++){
            if(i == 0){
                long long int realNew = newNum * 2;
                if(realNew < 0 || realNew > 100000)continue;
                if(arr[realNew] > 0) continue;
                arr[realNew] = arr[newNum];
                que.push(realNew);
            }else if(i ==1){
                long long int realNew = newNum - 1;
                if(realNew < 0 || realNew > 100000)continue;
                if(arr[realNew] > 0) continue;
                arr[realNew] = arr[newNum] + 1;
                que.push(realNew);
            }else if(i==2){
                long long int realNew = newNum + 1;
                if(realNew < 0 || realNew > 100000)continue;
                if(arr[realNew] > 0) continue;
                arr[realNew] = arr[newNum] + 1;
                que.push(realNew);
            }
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    catchSister();
}