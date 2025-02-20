#include <bits/stdc++.h>

using namespace std;

int arr[10000];
int temp[10000];

void merge(int st,int en){
    int mid = (st+en)/2;
    int rightIndex = mid; // 그냥 mid해버리네
    int leftIndex = st;
    //en은 도달하지 않는 곳 -> 즉 그래서 n은 배열의 개수다 인덱스가 아니라 끝에만 인덱로 암기!!!!
    for(int i =st; i<en;i++){
        if(rightIndex == en) temp[i] = arr[leftIndex++]; //오른쪽이 다 먼저 들어간 경우
        else if(leftIndex == mid) temp[i] = arr[rightIndex++];
        else if(arr[rightIndex] >= arr[leftIndex]) temp[i] = arr[leftIndex++]; //이렇게 Left부터 채워야지 stable sort가 되는 것이다.
        else temp[i] = arr[rightIndex++];
    }

    for(int i =st; i<en;i++){
        arr[i] = temp[i];
    }
}

//처음에 주는 인자는 인덱스들이다.
void merge_sort(int st, int en){
    //인자는 시작과 끝의 인덱스다.
    if(en == st + 1 ){
        //2개짜리는 의미가 없기 때문에 이렇게 처리하는 듯
        return;
    }
    int mid = (st+en)/2;
    merge_sort(st,mid);
    merge_sort(mid,en); //끝에 인덱스에 안가기에 이렇게 쓰게 되는 것이다 en까지 안가서
    //잘게 잘게 쪼갠 다음에 이제 합치기 시작하면 된다 작은 것부터 ㅇㅇ
    //그래서 재귀적으로 쓰는 거구나 잘게 잘게 쪼개고 합쳐야하니까
    merge(st,en);
}

int main(void){

    arr[0] = 1;
    arr[1] = 4;
    arr[2] = 6;
    arr[3] = 7;
    arr[4] = 2;

    merge_sort(0,5);

    for(int i=0;i<5;i++)
        cout << arr[i] << " ";
    cout << "\n";
}