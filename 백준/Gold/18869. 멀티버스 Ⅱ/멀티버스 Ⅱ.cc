#include <bits/stdc++.h>

using namespace std;

int N ,M;
vector<int> uni[110];
vector<int> vec[110];
vector<int> forAns[110];


bool solve(int mid, vector<int> temp, int finds){
    return temp[mid] <= finds;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;

    for(int i=0;i<M;i++){
        int number;
        for(int t=0;t< N;t++){
            cin >> number;
            vec[i].push_back(number);
        }
    }
    //M*(2NlogN+N)
    //MNlogN인데 왜 틀림 개빡침
    //총 3억이 되네,,흠 -> ㅇㅎ

    for(int i=0;i<M;i++){
        vector<int> temp;
        temp = vec[i];
        sort(temp.begin(),temp.end()); //NlogN
        temp.erase(unique(temp.begin(),temp.end()),temp.end());//N
        //이제 이분탐색으로 해당하는 숫자를 찾아야 함.
        //NlogN
        for(int t=0;t<N;t++){
            uni[i].push_back(lower_bound(temp.begin(),temp.end(),vec[i][t])-temp.begin());
        }
    }
    int answer = 0;
    //M^2 * 10000 = 10000 * 10000 = 100000000 -> 1억
    for(int i=0;i<M-1;i++){
        for(int t=i+1;t<M;t++){
            if(uni[i] == uni[t]){
                answer++;
            }
        }
    }

    cout << answer <<"\n";

}