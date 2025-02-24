#include <bits/stdc++.h>

using namespace std;

vector<pair<long long int ,int>> vec;

int N;
long long int C;

bool comp(pair<long long int,int> p1, pair<long long int,int> p2){
    return p1.second > p2.second;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //counting sort이고 이를 토대로 정렬하게끔 만드는 것이다.
    //크기가 무슨 10억짜리냐;; 그러면 map을 사용해서 풀이를 해야하는 건가?
    //배열로만 counting sort구현하면 너무 쉬우니까 10억이라는 제한을 준 것이다.
    //그러면 vector보단 map을 이용하는 게 좋겠네 아니다 vector pair조합 n^2해야지 얼마 안크다.
    cin >> N >> C;
    bool findss = 0;
    for(int i =0;i<N;i++){
        long long int number;
        findss = 0;
        cin >> number;
        for(int t= 0;t<vec.size();t++){
            if(vec[t].first == number){
                vec[t].second = vec[t].second + 1;
                findss = 1;
                break;
            }
        }
        if(!findss)
            vec.push_back({number,1});
    }

    stable_sort(vec.begin(),vec.end(),comp);

    for(int i =0;i<vec.size();i++){
        for(int t=0;t<vec[i].second;t++){
            cout << vec[i].first << " ";
        }
    }

    cout << "\n";
    
}