#include <bits/stdc++.h>

using namespace std;

vector<int> vec;

int N;
int X;

int answer ;

set<pair<int,int>> sets;
bool solve(int mid,int temp){
    return (temp + vec[mid]) <= X;
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N;

    int number;
    for(int i = 0; i < N; i++){
        cin >> number;
        vec.push_back(number);
    }//숫자 전부 집어넣기

    cin >> X;
    //이분탐색은 반드시 정렬 후에 사용하기

    sort(vec.begin(),vec.end());

    for(int i=0;i<N;i++){
        int temp = vec[i];
        int st = 0;
        int en = N-1;

        while(st<en){
            int mid = (st+en+1) /2;
            if(solve(mid,temp)){
                st = mid;
            }else{
                en = mid -1;
            }
        }
        if(((vec[st] + temp) ==X )&& (st != i)){
            answer ++;
            if(vec[st] > temp){
                sets.insert({vec[st],temp});
            }else{
                sets.insert({temp,vec[st]});
            }
            // cout << st << "\n";
        }
    }
    cout << sets.size() << "\n";
    // cout << answer << "\n";

}