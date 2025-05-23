#include<bits/stdc++.h>


using namespace std;

int getSol(vector<int> vec[105],int n){
    queue<int> que;
   bool gets[105] ={0,};
    if(vec[1].size() == 0){
        gets[2] = 1;
        que.push(2);
    }else{
         que.push(1);   
         gets[1] = 1;
    }

 
    int num = 0;
    
    while(!que.empty()){
        int temp = que.front();
        que.pop();
        num++;
        
        for(int i=0;i<vec[temp].size();i++){
            if(gets[vec[temp][i]] == true){
                continue;
            }
            gets[vec[temp][i]] = true;
            que.push(vec[temp][i]);   
            
        }
    }
    // cout << num << "\n";
    if(n- 2*num < 0){
        return 2*num - n;
    }
    return n-2*num;
    
    
}



int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    //값 입력해서 넣어주기
    for(int i=0;i<n-1;i++){
        vector<int> temp[105];
        for(int t=0;t<n-1;t++){
            if(t==i){
                continue;
            }
            temp[wires[t][0]].push_back(wires[t][1]);
            temp[wires[t][1]].push_back(wires[t][0]); 
        }
       answer = min(getSol(temp,n),answer);
    }
    
    return answer;
}