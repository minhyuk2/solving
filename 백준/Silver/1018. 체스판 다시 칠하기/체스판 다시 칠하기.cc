#include <bits/stdc++.h>

using namespace std;

vector<string> answer;
vector<string> answer2;
int realA = 100000000;
int N, M;
void checks(vector<string> temp,int st, int st2){
    int tempC1= 0;
    int tempC2 = 0;
    for(int i = 0;i<8;i++){
        for(int t=0;t<8;t++){
            if(st+i >= N || st2+t >=M) return;
            // cout << temp[i+st][t+st2] << " " <<  answer[i][t] << "\n";
            if(temp[i+st][t+st2] != answer[i][t]){
                tempC1++;
            }   
            if(temp[i+st][t+st2] != answer2[i][t]){
                tempC2++;
            }
        }
    }

    if(tempC1 > tempC2){
        if(realA > tempC2){
            realA = tempC2;
        }
    }else{
        if(realA > tempC1){
            realA = tempC1;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> M;

   
    answer.push_back("BWBWBWBW");
    answer.push_back("WBWBWBWB");
    answer.push_back("BWBWBWBW");
    answer.push_back("WBWBWBWB");
    answer.push_back("BWBWBWBW");
    answer.push_back("WBWBWBWB");
    answer.push_back("BWBWBWBW");
    answer.push_back("WBWBWBWB");


    answer2.push_back("WBWBWBWB");
    answer2.push_back("BWBWBWBW");
    answer2.push_back("WBWBWBWB");
    answer2.push_back("BWBWBWBW");
    answer2.push_back("WBWBWBWB");
    answer2.push_back("BWBWBWBW");
    answer2.push_back("WBWBWBWB");
    answer2.push_back("BWBWBWBW");


    vector<string> vec;

    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;
        vec.push_back(temp);
    }



    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            checks(vec,i,t);
        }
    }
    cout << realA << "\n";

}