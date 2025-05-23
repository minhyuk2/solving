#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    //이 문제는 백트랙킹 입니다.
    sort(dungeons.begin(),dungeons.end());
    do{
        int temp = k;
        int counter = 0;
        for(int i= 0; i<dungeons.size();i++){
            if(temp>=dungeons[i][0]){
                if(temp>=dungeons[i][1]){
                    temp -= dungeons[i][1];
                    counter++;
                }
            }
        }
        // cout << dungeons[0][0] << " " << dungeons[0][1] << "\n";
        
        answer = max(counter,answer);
    }while(next_permutation(dungeons.begin(),dungeons.end()));
    
    return answer;
}