#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> vec;
vector<int> smalls;
map<int,int> maps;
long long int sums;
set<int> finds;
int biggests = -4060;
int smallss = 4050;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int number ;
    for(int i=0;i<N;i++){   
        cin >> number;
        sums+=number;
        if(maps.find(number)!=maps.end()){
            //찾는게 있는 경우
            maps[number]++; // 이렇게 빈도 늘리기
        }else{
            maps.insert({number,1});
        }
        
        if(number > biggests){
            biggests = number;
        }
        if(number < smallss){
            smallss = number;
        }
        vec.push_back(number);
    }
    sort(vec.begin(),vec.end());
    double average = (double)sums/N;
    if(round(average) == -0){
        cout << 0 << "\n";
    }else{
        cout << round(average) << "\n";
    }
    cout << vec[N/2] << "\n";
    int mosts = 0;
    int mostsNum = 0;
    for(auto it : maps){
        if(it.second > mosts){
            mosts = it.second;
        }
    }

    for(auto it : maps){
        if(it.second == mosts){
            smalls.push_back(it.first);
        }
    }

    sort(smalls.begin(),smalls.end());

    if(smalls.size() == 1){
        cout << smalls[0] << "\n";
    }else{
        cout << smalls[1] << "\n";
    }
    cout << biggests - smallss << "\n";
}