#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> arr; //숫자
vector<int> vec; //연산자의 각 개수
vector<char> oper; 
int maxs = INT_MIN;
int mins = INT_MAX;

void go(vector<char> oper){
    int temp = arr[0];
    for(int i=1;i<N;i++){
        if(oper[i-1] == 'A'){
            temp = temp + arr[i];
        }else if(oper[i-1] == 'B'){
            temp = temp - arr[i];

        }else if(oper[i-1] == 'C'){
            temp = temp * arr[i];
        
        }else if(oper[i-1] == 'D'){
            temp = temp / arr[i];
        }

    }
    if(temp > maxs){
        maxs = temp;
    }
    if(temp < mins){
        mins = temp;
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int temp;
    for(int i=0;i<N;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    for(int i=0;i<4;i++){
        cin >> temp;
        vec.push_back(temp);
    }

    for(int i=0;i<4;i++){
        for(int t=0;t<vec[i];t++){
            oper.push_back(i+'A');
        }
    }

    sort(oper.begin(),oper.end());

    do{
        go(oper);
        
    }while(next_permutation(oper.begin(),oper.end()));

    cout << maxs << "\n";
    cout << mins << "\n";

}