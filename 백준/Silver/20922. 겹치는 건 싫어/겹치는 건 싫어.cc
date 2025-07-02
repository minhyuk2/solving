#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
map<int,int> maps;
int N, K;
int answer;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> K;

    int temp;
    for(int i=0; i<N;i++){
        cin >> temp;
        vec.push_back(temp);
    }

    int st = 0, en = 0;
    int count = 0;
    for(st = 0 ; st<N;st++){
        if(st != 0){
            maps[vec[st-1]]--;
            count -- ;
        }

        while(en < N){
            
            if(maps[vec[en]]+1 > K){
                // cout << maps[vec[en]] << "\n";
                break;
            }
            maps[vec[en]] ++;
            count ++;
            en ++;

        }

        answer = max(count,answer);
    }


    cout << answer << "\n";

}
