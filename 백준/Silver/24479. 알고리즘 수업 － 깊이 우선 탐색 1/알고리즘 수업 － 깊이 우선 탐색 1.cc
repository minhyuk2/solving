#include <bits/stdc++.h>

using namespace std;

//깊이 우선 탐색은 큐를 사용하면 됨


int N, M, St;

set<int, std::greater<int>> vec[100005];
int arr[100005];
bool visited[100005];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> St;
    int temp1 , temp2;
    for(int i=0;i<M;i++){
        cin >> temp1 >> temp2;
        vec[temp1].insert(temp2);
        vec[temp2].insert(temp1);
    }

    stack<int> st;
    st.push(St);
    int count = 1;

    while(!st.empty()){
        int now = st.top();
        st.pop();
        if(visited[now] !=1){
            arr[now] = count;
            count ++;
            visited[now] = 1;
            for(auto it : vec[now]){
                int newOne = it;
                if(visited[newOne] != 1){
                    st.push(newOne);
                }
            }
        }
    }   
    
    for(int i =1; i<=N;i++){
        cout << arr[i] << "\n";
    }

}