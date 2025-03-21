#include<bits/stdc++.h>


using namespace std;
//5개 밖에 없어서 백트랙킹 문제다..
char temper[5] = {'A','E','I','O','U'};
int counter = 0;
int answers = 0;

int nowLen = 5;
bool downSt = true;
int pp = 1;
void backT(string temp,string word){
    cout << temp << "\n";
    if(temp==word){
        answers = counter;
        return;
    }
    if(temp.size() >= 5) return;
   
    
    for(int i=0;i<5;i++){
        counter++;

        backT(temp+temper[i],word);
        if(answers!=0){
            return;
        }
    }
    
}



int solution(string word) {
    int answer = 0;
    string temps = "";
    
    backT(temps,word);
    answer = answers;
    
    return answer;
}