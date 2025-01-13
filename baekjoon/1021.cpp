#include <bits/stdc++.h>

using namespace std;

int N, M;

long long int answer;
vector<int> vec;
int number;
long long int timer;

//백트랙킹은 2의 50승이 나올 수 있어서 실패
// void getCase(deque<int> &deq,long long int counting){
//     deque<int> newDeq;
//     long long int ct1 =0, ct2=0;
//     if(number == M){
//         if(answer > counting){
//             answer = counting;
//         }
//         return;
//     }

//     for(int i =0; i<2;i++){
//         //왼쪽으로 돌리던지 오른쪽으로 돌리던지
//         if(i==0){
//             //왼쪽으로 돌림
//             newDeq = deq;
//             for(int t =0; t<newDeq.size();t++){
//                 timer++;
//                 if(vec[number] == newDeq.front()){
//                     newDeq.pop_front();
//                     number++;
//                     getCase(newDeq,counting+ct1);
//                     number--;
//                     newDeq.clear();
//                     break;
//                 }
//                 newDeq.push_back(newDeq.front());
//                 newDeq.pop_front();
//                 ct1++;
//             }
//         }else{
//             newDeq = deq;
//             for(int t =0; t<newDeq.size();t++){
//                 timer++;
//                 if(vec[number] == newDeq.front()){
//                     newDeq.pop_front();
//                     number++;
//                     getCase(newDeq,counting+ct2);
//                     number--;
//                     newDeq.clear();
//                     break;
//                 }
//                 newDeq.push_front(newDeq.back());
//                 newDeq.pop_back();
//                 ct2++;
//             }
//         }
//     }
// }

//그리디로 푸는 방법
void getCase(deque<int> &deq){
    int count = 0;
    for(int i =0; i< M;i++){
        for(int t =0; t<deq.size();t++){
            if(vec[i] == deq[t]){
                count = t;
                break;
            }
        }

        if(count <= deq.size()/2){
            //왼쪽으로 돌리기
            for(int t =0; t <deq.size();t++){
                if(vec[i] == deq.front()){
                    deq.pop_front();
                    break;
                }
                deq.push_back(deq.front());
                deq.pop_front();
                answer ++;
            }
        }else{
            //오른쪽으로 돌리
            for(int t =0; t <deq.size();t++){
                if(vec[i] == deq.front()){
                    deq.pop_front();
                    break;
                }
                deq.push_front(deq.back());
                deq.pop_back();
                answer ++;
            }
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    deque<int> deq;
    for(int i =1; i <=N; i++){
        deq.push_back(i);
    }
    int num;
    for(int i = 0; i<M;i++){
        cin >> num;
        vec.push_back(num);
    }
    getCase(deq);
    cout << answer << "\n";
}