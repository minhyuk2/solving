#include <bits/stdc++.h>
using namespace std;


int N;
// vector<pair<char,int>> vec;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int answer = 0;
    int answer2 = 0;
    char whos;
    // pair<char,int> ;
    int number;
    for(int i=0;i<N;i++){
        cin >> number;
        if(number%30 == 0){
            answer += (number/30+1);
        }else{
            answer += (number/30 + 1);
        }
        if(number%60 == 0){
            answer2 += (number/60+1);
        }else{
            answer2 += (number/60 + 1);
        }
    }

    if(answer*10 < answer2*15){
        cout << "Y "  << answer*10 << "\n";
    }else if(answer*10 == answer2*15){
        cout << "Y M " << answer2*15 << "\n";
    }else{
        cout << "M " << answer2*15 << "\n";
    }
}