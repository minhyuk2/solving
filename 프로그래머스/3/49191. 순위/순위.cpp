#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph (n+1,vector<bool>(n+1,false));
    //그냥 n+1까지인 이유는 1부터 인덱싱을 해야하니까
    
    for(auto it : results){
        graph[it[0]][it[1]] = true;
    }
    
    //거치는 인덱스
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            for(int t=1 ; t<=n;t++){
                if(graph[k][i] && graph[i][t]) graph[k][t] = true;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int cnt =0;
        for(int t=1;t<=n;t++){
            if(graph[i][t] || graph[t][i]) cnt++;
        }
        if(cnt == n-1) answer ++;
    }
    
    
    return answer;
}