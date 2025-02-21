#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int minX = 0;
    int minY = 0;
    for(int i=0;i<sizes.size();i++){
        sort(sizes[i].begin(),sizes[i].end());
        if(minX < sizes[i][0]){
            minX = sizes[i][0];
        }
        if(minY < sizes[i][1]){
            minY = sizes[i][1];
        }
    }
    answer = minX * minY;
    return answer;
}