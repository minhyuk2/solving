#include <bits/stdc++.h>

using namespace std;

long long int vecSize;
//이 문제는 최소힙을 공부하면서 풀고 수도코드를 봤기 때문에 다시 한 번 풀어보거나 공부를 해야하는 부분이다.

void minHeapInsert(vector<long long int>& vec,long long int number){
    //벡터에 새로운 것을 추가할 때 사용하는 것
    //일단 새로운 것을 사이즈를 굳이 늘리는 것은 나중에 해도 되고
    //이러면 딱 1로서 안정적이게 되는 것이지
    long long int current = vecSize; //얘의 위치는 사이즈의 개수와도 같지 0부터 진행할테니까
    vec.push_back(number);
    vecSize++;
    // cout << "여기2" << current << "\n";
    //원하는 위치에 넣고 나머지를 재정렬하는 느낌으로 가는게 맞는게 아닌가?
    while(current != 1 && vec[current/2] > number){
       //반복문안에서 조건을 줄 필요없이 while문에서 조건을 전부 처리하는 형태가 되는 것이다.
       //이 조건을 만족하는 경우에는
       vec[current] = vec[current/2];
       current = current/2;        
    }
    vec[current] = number;
    // cout << "여기 " << current << "\n";
}

void minHeapDelete(vector<long long int>& vec){
    //벡터에서 삭제할 때 사용하는 것
    //일단 삭제할 때 루트의 값을 출력하는 것은 해야 할듯 ㅇㅋ
    //그렇네 굳이 바로 집어넣어서 바꿔줄 필요없이 모든 과정이 끝나고 위치를 찾은 다음에 집어넣는 형식으로 구현해도 되겠네 ㅇㅋ 암기하자
    cout << vec[1] << "\n";
    vec[1] = vec[vecSize-1];
    long long int last = vec[1];
    vec.pop_back();
    vecSize--;
    int current = 1;
    int child = 2;
    while(child <= vecSize-1){
        if(child < vecSize-1 && vec[child] > vec[child+1]) child++;
        if(vec[child] > last) break;
        vec[current] = vec[child];
        current = child;
        child = child  * 2;
    }
    vec[current] = last;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //일단은 10만이기에 동적할당 vector를 쓰는게 맞겠다는 생각이 드네
    //그리고 벡터에서도 min_element를 쓸 수 있구나
    vector<long long int> vec;
    //0번 인덱스를 채우기 위한 더미 데이터를 넣어둔다.
    vec.push_back(-1);
    vecSize++;
    int testCase;
    cin >> testCase;
    long long int number;
    //이게 10만인데
    //그러면 넣을 때 가장 작은 것인지 확인하고 넣어주는 식으로 해야겠네 애초에
    long long int minVal;
    long long int minDex = 0;
    for(int i = 0 ; i < testCase;i++){
        cin >> number;
        if(number == 0){
            if(vecSize == 1){
                cout << 0 << "\n";
            }else{
                minHeapDelete(vec);
            }
        }else{
            minHeapInsert(vec,number);
        }
    }
}