#include <bits/stdc++.h>


using namespace std;
int arr[11];

string solution(string number, int k) {
    string answer = "";
    //자리에 대한 얘기이기 때문에,,
    //제일 작은 값에 대해서 처리
    //중간값에 대한 설정을 하는 것이 중요하다.
    //그러면 일단 지나가면서 앞에서부터 작은 것을 없애야 하는 것이다.
    //일단 각 자리에 대한 값을 처리하고, 그러면 각 값에서 제일 작은거 구하기
    
    //set으로 해결하는게 아니라 내가 볼 땐 개수를 각각 세야할 것 같은데 흠,,
    int n = number.size();
    int temp = k;
    stack<char> sta;
    
    for(int i = 0; i <  n; i ++){
        while(k > 0 && !sta.empty() &&sta.top() < number[i]){
            sta.pop();
            k--;
        }
        
        sta.push(number[i]);
    }
    string nows = "";
    //만약에 k가 남아있는 경우에 대한 처리가 필요하다.
    while(k > 0 && !sta.empty()){
            sta.pop();
            k--;
    }
    
    while(!sta.empty()){
        nows += sta.top();
        sta.pop();
    }
    
    reverse(nows.begin(),nows.end());
    
    answer = nows;
    
    
    return answer;
}