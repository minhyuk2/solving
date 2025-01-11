#include <bits/stdc++.h>

using namespace std;

int N;
long long int answer;
stack<int> building;



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int number;
    int counting = -1;
    for(int i =0; i< N;i ++){
        cin >> number;
        building.push(number);
    }

    stack<pair<int,int>> sta2;
    //최소 기준값을 위해서 이렇게 큰 값을 넣는 것이다.
    sta2.push({1000000001,N+1});
    for(int t = N; t>=1; t--){
        number = building.top();
        building.pop();

        while(sta2.top().first < number){
            sta2.pop();
        }
        
        answer += ((sta2.top().second - t) -1);
        sta2.push({number,t});
    }
    
    cout << answer << "\n";
}