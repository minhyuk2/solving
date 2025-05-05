#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int number;
    deque<pair<int,int>> deq;
    
    // for(int i=1;i<=N;i++){
    //     deq.push_back(i);
    // }
    for(int i=1;i<=N;i++){
        cin >> number;
        deq.push_back({i,number});
    }

    cout << deq.front().first <<" ";
    int nexts = deq.front().second;
    deq.pop_front();
    for(int i=1;i<N;i++){
        if(nexts < 0){
            nexts = -nexts;
            pair<int,int> temp;
            for(int t= 0;t<nexts;t++){
                temp = deq.back();
                deq.pop_back();
                if(t == nexts-1){
                    break;
                }
                deq.push_front(temp);
            }
            cout << temp.first << " ";
            nexts = temp.second;
        }else{
            pair<int,int> temp;
            for(int t= 0;t<nexts;t++){
                temp = deq.front();
                deq.pop_front();
                if(t == nexts-1){
                    break;
                }
                deq.push_back(temp);
            }
            cout << temp.first << " ";
            nexts = temp.second;
        }
    }
    cout << "\n";
}