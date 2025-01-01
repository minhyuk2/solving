#include <bits/stdc++.h>

using namespace std;

void maxHeapInsert(vector<long long int>& vec, long long int number){

    //유효한 값이 한 개도 들어있지 않을 때가 1이니까 이렇게 진행하면 되는 것이다.
    long long int current = vec.size();
    vec.push_back(number);
    while(current != 1 && vec[current/2] < number){
        vec[current] = vec[current/2];
        current = current/2;
    }
    vec[current] = number;

}

void maxHeapDelete(vector<long long int>& vec){
    cout << vec[1] << "\n";
    
    vec[1] = vec[vec.size()-1];
    long long int last = vec[1];
    vec.pop_back();
    long long int current = 1;
    long long int child = 2;
    //맨 위로 다시 올려야하니까
    
    while(child <= vec.size()-1){
        //오른쪽 왼쪽 어떤 child랑 비교할지 선택
        if(child < vec.size()-1 && vec[child+1] > vec[child]) child ++;

        //last가 더 커야지 그 위치에 정착하게 되는 것이니까
        if(vec[child] < last)break;

        //이제 점점 내려가야하니까
        vec[current] = vec[child];
        current = child;
        child = child * 2;
    }
    vec[current] = last;
}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //테스트 케이스 개수만큼 수행한다.
    int testCase;
    cin >> testCase;

    long long int number;
    vector<long long int> vec;
    vec.push_back(-1);
    //하나를 임시로 넣어서 인덱스 접근을 쉽게 만든다.
    for(int i = 0 ; i < testCase; i++){
         cin >> number;
         if(number == 0){
            if(vec.size() == 1){
                cout << 0 << "\n";
            }else{
                //vector가 비어있지 않은 경우
                maxHeapDelete(vec);
            }
         }else{
            //0이 아닌 다른 양수가 들어온 경우
            maxHeapInsert(vec,number);
         }
    }


}