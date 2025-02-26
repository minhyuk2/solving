#include <bits/stdc++.h>

using namespace std;

int N, M;
int answer;
string answerString = "";
vector<string> vec;
char arr[4] = {'A','C','G','T'};

void getAnswer(){
    // int nows = 0;
    for(int i=0;i<M;i++){
        int nowNum =2000;
        char nowChar;
        for(int p=0;p<4;p++){
            int tempCount=0;
            for(int t=0;t<N;t++){
                if(vec[t][i]!=arr[p]){
                    tempCount++;
                }
            }
            if(nowNum > tempCount){
                nowNum = tempCount;
                nowChar = arr[p];
            }
        }
        answerString += nowChar;
        answer += nowNum;
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    string temp;
    for(int i= 0; i<N;i++){
        cin >> temp;
        vec.push_back(temp);
    }

    getAnswer();
    cout << answerString << "\n";
    cout << answer << "\n";
}