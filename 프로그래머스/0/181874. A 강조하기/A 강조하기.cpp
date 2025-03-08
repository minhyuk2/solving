#include<bits/stdc++.h>

using namespace std;

string changeWord(string myString){
    string answer = "";
    for(auto it : myString){
        if(it == 'a'){
            answer += 'A';
        }else if(it == 'A'){
            answer += 'A';
        }else{
            char words = tolower(it);
            answer += words;
        }
    }
    return answer;
}

string solution(string myString) {
    string answer = "";
    
    answer = changeWord(myString);
    
    
    return answer;
}