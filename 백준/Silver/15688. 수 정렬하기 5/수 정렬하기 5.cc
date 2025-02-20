#include <bits/stdc++.h>

using namespace std;

long long int N;

// int main(void){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin >>N;
//     vector<long long int> vec;

//     for(int i=0;i<N;i++){
//         long long int number;
//         cin >> number;
//         vec.push_back(number);

//     }

//     sort(begin(vec),end(vec));

//     for(int i=0;i<N;i++){
//         cout << vec[i] << "\n";
//     }

// }

//counting sort로 푸는 방법
int countTable[1000010];
int minusCount[1000010];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>N;

    for(int i=0;i<N;i++){
        int number;
        cin >> number;
        //들어올 수 있는 값이 정수이다.
        //자연수가 아니라... 정수이기 때문에 이걸 고려해야한다...바보다...이걸 놓치네
        //자연수인지 정수인지의 조건은 이젠 틀리지말자
        if(number< 0){
            int changeNum = -number;
            minusCount[changeNum]++;
        }else{
            countTable[number]++;
        }
    }

    for(int i =1000005;i>0;i--){
        if(minusCount[i] !=0){
            for(int t= 0; t< minusCount[i] ;t++) 
                cout << -i << "\n";
        }
    }

    for(int i =0;i<1000005;i++){
        if(countTable[i] !=0){
            for(int t= 0; t< countTable[i] ;t++) 
                cout << i << "\n";
        }
    }
}