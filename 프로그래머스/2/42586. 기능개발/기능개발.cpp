#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    stack<int> countDay;
    int temp;
    int tempDay;
    for(int i= 0; i<progresses.size();i++){
        temp = 100 - progresses[i];
        tempDay = temp/speeds[i];
        if(temp%speeds[i]!=0){
            tempDay++;
        }
        days.push_back(tempDay);
    }
    for(auto it = days.rbegin();it!=days.rend();++it){
        countDay.push(*it);
        cout << *it << "\n";
    }
    
    while(!countDay.empty()){
        int temper = countDay.top();
        int count = 1;
        countDay.pop();
        while(!countDay.empty()){
            if(countDay.top() <= temper){
                count ++;
                countDay.pop();
            }else{
                break;
            }
        }
        answer.push_back(count);
    }
    
    return answer;
}