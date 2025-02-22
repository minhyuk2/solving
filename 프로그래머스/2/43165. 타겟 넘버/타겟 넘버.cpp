#include <bits/stdc++.h>


using namespace std;

int arr[3] = {-1,1};

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    //되는 모든 경우에 대한 것을 작성해야 한다.
    //브루트 포스이지만, 이걸 BFS로 어떻게 풀 수 있을지를 고민해봐야겠다.
    //큐에 값을 넣는 것을 이용하면 된다.
    queue<int> que;
    que.push(-numbers[0]);
    // cout << -numbers[0] << "\n";
    que.push(numbers[0]);
    for(int i= 1; i<numbers.size();i++){
        queue<int> newQ;
        while(!que.empty()){
          int temp = que.front();
          que.pop();
          for(int t=0; t<2;t++){
            int newNum = temp + (arr[t] * numbers[i]);
            newQ.push(newNum);
           }
        }
        que = newQ;
    }
    while(!que.empty()){
        int temp = que.front();
        // cout << temp<<"\n";
        que.pop();
        if(temp == target){
            answer++;
        }
    }
    return answer;
}