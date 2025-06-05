#include <bits/stdc++.h>

using namespace std;
using ll= long long int;

int N;
vector<ll> vec;
ll answer1 , answer2;
ll sums = 1000000004;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N;
    ll temp ;
    for(int i =0; i<N;i++){
        cin >> temp;
        vec.push_back(temp);
    }
    //이러면 일단 모든 값에 대해서 넣음

    //어떤 느낌으로 투포인터라고 하는지 알겠다. // 앞쪽과 뒷쪽을 이동시키면서 구하는거임
    
    //일단 이진탐색이든 투포인터든 사용하려면 정렬되어 있어야 한다.
    sort(vec.begin(),vec.end());


    //절댓값으로 비교하면 되는 것이다.
    //두 개 중에서 더 작은 것에 대해서 선택하면서 이동시키면 되는 것이다.

    int st = 0, en = N-1;
    ll nowS;
    ll nowS2;
    
    nowS = llabs(vec[st] + vec[en]);
    sums = nowS;
    answer1 = vec[st];
    answer2 = vec[en];

    while(st < en){
        nowS = llabs(vec[st] + vec[en-1]);
        nowS2 = llabs(vec[st+1] + vec[en]);

        if(nowS < nowS2){
            en--;
            if(llabs(sums) > nowS&& st!= en){
                answer1 = vec[st];
                answer2 = vec[en];
                sums = nowS;
            }
        }else{
            st ++;
            if(llabs(sums) > nowS2 && st!=en){
                answer1 = vec[st];
                answer2 = vec[en];
                sums = nowS2;
            }
        }

    }


    cout << answer1 << " " << answer2 << "\n";

}