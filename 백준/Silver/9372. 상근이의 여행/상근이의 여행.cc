#include <bits/stdc++.h>

using namespace std;

vector<int> arr[1010];

void getAir(int N){
    for(int i=0;i<N;i++){

    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int T;
    int N, M;
    int test1, test2;
    cin >> T;
    //일단 그래프니까 인접행렬이나ㅣ 인접리스틀 만들어야겠다
    //추가로 모든 국가를 여행하기 위해서 필요한 것들에 대한 조건이 빡세긴 하네

    for(int i=0;i<T;i++){
         cin >> N >> M;
         for(int t=0;t<M;t++){
            cin >> test1 >> test2;
            arr[test1].push_back(test2);
            arr[test2].push_back(test1);
        }
        cout << N - 1 << "\n";
        // for(int t=0;t<1010;t++){
        //     arr[t].clear();
        // }
         
    }

}