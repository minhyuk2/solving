#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> person= {0,0,0};
    vector<int> p1 = {1,2,3,4,5};
    vector<int> p2 = {2,1,2,3,2,4,2,5};
    vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
    for(int i=0;i<answers.size();i++){
        if(answers[i] == p1[i%5]){
            person[0]++;
        }
        if(answers[i] == p2[i%8]){
            person[1]++;
        }
        if(answers[i] == p3[i%10]){
            person[2]++;
        }
    }
    int maxV = -1;
    for(int i=0;i<3;i++){
        if(maxV < person[i]){
            maxV = person[i];
        }
    }
    for(int i=0;i<3;i++){
        if(maxV == person[i]){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}