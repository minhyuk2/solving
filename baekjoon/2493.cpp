#include <bits/stdc++.h>

using namespace std;

int N;
stack<int> answer;


// //자신의 왼쪽에 있는 것중에서 자기보다 큰 것에 대해서 받아들이게 함
// void makeTower(stack<int> &sta,vector<int> &vec){
//     int number;
//     int check = 0 ;
//     for(int i =0; i < N;i++){
//         number = sta.top();
//         sta.pop();
//         check = 0;
//         for(int t = N-2-i;t>=0;t--){
//             if(vec[t] >= number){
//                 answer.push(t+1);
//                 check =1 ;
//                 break;
//             }
//         }
//         if(check == 0){
//             answer.push(0);
//         }
//     }   

//     for(int i=0; i< N; i++){
//         cout << answer.top() << " ";
//         answer.pop();
//     }
//     cout << "\n";
// }

// //스택이네 가장 마지막에 들어온 애가 가장 먼저 레이저를 발사하기 때문에 선입후출의 스택이다.

// int main(void){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     cin >> N;
    
//     stack<int> sta;
//     vector<int> vec;
//     int number;
//     int maxVal = 0;
//     int counting = 0;
//     for(int i =0; i < N;i++){
//         cin >> number;

//         // sta.push(number);
//         if(number > maxVal){
//             maxVal = number;
//             cout << 0 << " ";
//         }else{
//             for(int t = counting-1; t >=0; t--){
//                 if(vec[t] > number){
//                     cout << t+1 << " ";
//                     break;
//                 }
//             }
//         }
//         vec.push_back(number);
//         counting++;
//     }
//     cout << "\n";

// }

//이 문제는 해설을 봤기 때문에 다음 문제도 풀 수 있도록 해야 한다.
stack<pair<int,int>> sta;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int number;
    cin >> N;

    sta.push({100000001,0});
    for(int i =1 ; i <=N ; i++){
        cin >> number;
        //새로 들어온 애가 더 크면 지금까지의 것을 갖고 있을 필요가 없으니까 pair로 인덱싱을 저장함으로써 가능해짐
        while(sta.top().first < number)
            sta.pop();
        //그 중에 제일 마지막에 들어온 큰 애의 인덱스를 해주면 나보다 큰 애 중에서 가장 마지막에 들어 온 애를 만나게 된다.
        //그렇기에 스택을 사용한 것이다.
        cout << sta.top().second << " ";
        sta.push({number,i});
    }
    cout <<"\n";

}