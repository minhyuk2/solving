#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> vec;
vector<int> two;
//강의 그대로 클론 코딩한거라 담에 다시 꼭 풀어보기

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for(int i=0;i<N;i++){
        int number;
        cin >> number;
        vec.push_back(number);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<N;i++){
        for(int t=i;t<N;t++){
            two.push_back(vec[i] + vec[t]);
        }
    }
    sort(two.begin(),two.end());
    for(int i=N-1; i>0;i--){
        for(int t=0;t<N;t++){
            if(binary_search(two.begin(),two.end(),vec[i]-vec[t])){
                cout << vec[i] << "\n"; //존재하면 그 3개를 더 한 것을 출력하는 것이니까
                return 0;
            }
        }
    }
}