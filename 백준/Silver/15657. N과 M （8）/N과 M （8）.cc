#include <bits/stdc++.h>

using namespace std;

int N,M;

vector<int> vec;
int arr[10];
bool isUsed[10];

void getBack(int num){

    if(num == M){
        int prevs = arr[0];
        bool isOk = true;

        for(int i =0;i<M;i++){
            if(prevs <=arr[i]){
                prevs = arr[i];
            }else{
                isOk = 0;
                break;
            }
        }
        if(isOk){
            for(int i =0;i<M;i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        return ;
    }

    for(int i=0;i<N;i++){
        // if(!isUsed[i]){
        //     isUsed[i] = 1;
            arr[num] = vec[i];
            getBack(num+1);
        //     isUsed[i] = 0;
        // }
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    int numbers;
    for(int i= 0; i<N;i++){
        cin >> numbers;
        vec.push_back(numbers);
    }
    sort(vec.begin(),vec.end());
    getBack(0);
}