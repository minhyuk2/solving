#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //원형 링크드리스트로 만들면 된다.
    //c++은 기본 자료구조에 list가 존재해서 그걸 사용하면 된다.
    list<int> circle; //list를 생성한다.
    //list로 원형링크드 리스트를 구현해서 만들면 된다.
    int N,K;
    cin >> N  >>  K; //N과 K를 입력받는다.
    
    for(int i = 1 ; i <= N; i++){
        circle.push_back(i); //1부터 하나씩 순서대로 넣어준다.
    }
    //원형 링크드리스트를 어떤 식으로 구현해볼 수 있을지 생각해야한다.
    //K로 들어온 숫자만큼 빼고 그렇게 빼고 나서 마지막에 그걸 다시 넣어주면 된다.
    cout << "<" ;
    int index;
    for(int i=1;;i++){

        if(i == K){
            cout << circle.front(); //첫번째 것을 꺼내주고
            circle.pop_front();
            i = 0;
            if(!circle.empty()){
                cout <<", ";
            }
        }else{
            // cout << circle.front() <<" ";
            index = circle.front();
            circle.pop_front();
            circle.push_back(index);
        }

        if(circle.empty()){
            break;
        }
    }
    cout << ">\n";

}