#include <bits/stdc++.h>

using namespace std;

int N;
//처리하는 함수에 대해서는 따로 제공
//어차피 vector쓸거라 number는 딱히,
//앞과 뒤에서 둘 다 버릴 수 있어야하니까 덱을 사용하는거네 이렇게 앞 
//string 인덱스로 접근할 수 있다는 것을 잊지말자.
void solveCase(string func, string arr,int number){
    string newArr = arr.substr(1,arr.size()-2);
    stringstream stream(newArr);
    string nums2;
    deque<int> deq;
    bool frontBack = 0;
    while(getline(stream,nums2,',')){
        deq.push_back(stoi(nums2));
    }
    int error =0;
    for(int i=0; i<func.size();i++){
        if(func[i] =='R'){
            frontBack = !frontBack;
        }else{
            if(deq.empty()){
                error = 1;
                break;
            }else{
                if(frontBack == 0){
                    deq.pop_front();
                }else{
                    deq.pop_back();
                }
            }
        }
    }

    if(error == 1){
        cout << "error\n";
    }else{
        cout << "[";
        if(frontBack == 0){
            while(!deq.empty()){
                cout << deq.front() ;
                if(deq.size()!=1){
                    cout << ",";
                }
                deq.pop_front();
            }
        }else{
        while(!deq.empty()){
            cout << deq.back() ;
            if(deq.size()!=1){
                 cout << ",";
            }
            deq.pop_back();
        }
        }

        cout << "]\n";
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string func;
    string arr;
    int number;
    for(int i =0; i < N; i++){
        cin >> func;
        cin >> number;
        cin >> arr;
        solveCase(func,arr,number);
    }
}