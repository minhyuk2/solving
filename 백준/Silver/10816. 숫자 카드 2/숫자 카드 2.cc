#include <iostream>
#include <algorithm>
using namespace std;

vector<int> vec;
int N, M;


int upper_idx(int num,int len){
    int st= 0;
    int en = len;
    //역전 되거나 같으면 종료 그래야지 가장 오른쪽 아니까 
    while(st < en){
        int mid = (st+en)/2;
        if(vec[mid] > num){
            en = mid;
        }else{
            st = mid +1;
        }
    }

    return st;
}
//길이를 알려줘야 끝을 알 수 있으니까 len은 필수
int lower_idx(int num,int len){
    int st =0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(vec[mid] >= num){
            en = mid;
        }else{
            st = mid + 1;
        }
    }

    return st;
}
//상한 인덱스 - 하한 인덱스 => 개수

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0;i<N;i++){
        int number;
        cin >> number;
        vec.push_back(number);
    }

    sort(vec.begin(),vec.end());
    //항상 이분 탐색은 먼저 정렬부터 해준다.
    cin >> M;
    for(int i=0;i<M;i++){
        int target;
        cin >> target;
        cout << upper_idx(target,N) - lower_idx(target,N) << " " ;
    }
    cout << "\n";

}