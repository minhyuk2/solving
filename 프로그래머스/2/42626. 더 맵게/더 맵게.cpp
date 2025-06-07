#include <bits/stdc++.h>


using namespace std;

int solution(vector<int> scoville, int K) {
    int answer =0;
    sort(scoville.begin(),scoville.end());
    priority_queue<int,vector<int>,greater<int>> heaps;

    for(auto it : scoville){
        heaps.push(it);
    }
    
    while(1){
        int temp = heaps.top();
        heaps.pop();
        int second = 0;
        if(!heaps.empty()){
            second = heaps.top();
            heaps.pop();
        }else{
            if(temp >= K){
                break;
            }else{
                return -1;
            }
        }

        if(temp >= K){
            break;
        }else{
            temp = temp + second *2;
            heaps.push(temp);
            answer++;
        }
    }
    
    
    return answer;
}