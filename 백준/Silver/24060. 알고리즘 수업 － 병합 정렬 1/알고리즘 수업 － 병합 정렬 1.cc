#include<bits/stdc++.h>

using namespace std;

int N, K;
vector<int> arr;
int counts;
vector<int> answer;

void merges(int p, int q, int r){
    int i = p;
    int j = q+1;
    int t = 0;
    int tmp[500005];
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]){
            tmp[t] = arr[i];
            t++;
            i++;
        }else{
            tmp[t] = arr[j]; 
            t++;
            j++;
        }
    
    }
    while (i <= q){
        tmp[t] = arr[i];
        t++;
        i++;
    }
    while (j <= r){
        tmp[t] = arr[j];
        t++;
        j++;
    }
    i = p; 
    t = 0;
    while (i <= r){
        arr[i] = tmp[t]; 
        answer.push_back(arr[i]);
        // cout << arr[i] << "\n";
        t++;
        i++;
    }

}


void merge_sorts(int p,int r){
    if(p<r){
        int q = (p+r)/2;
        merge_sorts(p,q);
        merge_sorts(q+1,r);
        merges(p,q,r);
    }
}




int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //정렬시키고 머지소트를 진행하는 것이다.
    cin >> N >> K;

    int temp;


    for(int i=0;i<N;i++){
        cin >> temp;
        arr.push_back(temp);
    }   

    merge_sorts(0,N-1);

    if(answer.size() < K){
        cout << -1 << "\n";
    }else{
        cout << answer[K-1] << "\n";
    }


}