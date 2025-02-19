#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    vector<int> temp;
    for(int i =0; i < commands.size();i++){
        temp.clear();
        for(int t = commands[i][0]-1;t < commands[i][1]; t++){
            temp.push_back(array[t]);
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp[commands[i][2]-1]);
    }
    
    return answer;
}