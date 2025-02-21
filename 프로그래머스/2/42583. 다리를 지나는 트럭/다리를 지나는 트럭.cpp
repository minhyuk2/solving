#include<bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int index = 0;
    int tempWeight= 0;
    int tempCar = 0;
    queue<int> que;
    while(1){
        
        if(index == truck_weights.size()){
            answer += bridge_length;
            break;
        }
        answer ++; // 시간이 지남
        //0을 올리더라도 다 채워버리면 그 길이만큼을 다 채우면 이제 한 번 flush
        if(que.size() == bridge_length){
            tempWeight -= que.front();
            tempCar--;
            que.pop();
        }
        
        
        if(truck_weights[index] + tempWeight <= weight && tempCar + 1 <= bridge_length){
            que.push(truck_weights[index]);
            tempWeight += truck_weights[index];
            tempCar++;
            index++;
        }else{
            que.push(0); //0을 넣어서 시간은 흐르고 무게 상의 부담은 없애는 방법
        }
        
    }
    
    
    
    return answer;
}