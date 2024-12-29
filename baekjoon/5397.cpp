// #include <iostream>
// #include <algorithm>
// #include <list>

// //일다 벡터로 구현하고 안되면 그때 list로 다시 구현하자.

// using namespace std;

// int main(void){
//     ios_base :: sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     //list를 써서 하나의 인덱싱을 이용하면서 사용해야 한다.
//     //포인터를 사용하는 연산을 통해서 풀 수 있어야 한다.
    
//     list<char> mylist;
//     //iterator와 list 생성
//     list<char>::iterator it = mylist.begin();


//     //몇 번 반복할 것인지 입력받는 것이다.
//     int times;
//     cin >> times;


//     //여러 번 반복하면 링크드리스트를 정말 많이 만들어야 하기 때문에 고민을 해봐야하네,,

//     //한 단어씩 받기보단 걍 다 저장해두고 하면 되나? 어차피 출력은 한 번에 해줄건데 하나에 하나씩이 아니라 한 번에 할거니까 만약에 내가 생각한대로 하면 하나에 하나씩이니까
//     //근데 그러면 메모리상에 손해를 보는게 아닌가? 다 저장하고 있으면 어차피 cin, cout 끊어놔서 아무 상관없지 않나? 

//     string input;

//     //아니지 list가 출력을 하거니가
   
//     for(int i = 0 ; i  < times; i++){
//         //리스트와 iterator를 초기화
//         cin >> input;
//         mylist.clear();
//         it = mylist.begin();
//         for (unsigned int p = 0; p < input.length(); p++){
//             //문자열의 한 글자씩 접근 2중 for문이어도 어차피 반복되어야 하는 작업이기 때문에 아무상관없다.
//             if(input[p]=='<' && (!mylist.empty())){
//                 cout << "HERE\n";
//                 if(it!=mylist.begin()){
//                     --it;
//                     //iterator를 한 칸 땡긴다.
//                 }
//             }
//             else if(input[p]=='>' && (!mylist.empty())){
//                 if(it!=mylist.end()){
//                     ++it;
//                     //iterator를 한 칸 민다
//                 }
//             }
//             else if(input[p]=='-' && (!mylist.empty())){
//                 //-가 나오고 비어있는게 아니면 현재 위치에서 삭제를 해야한다.
//                 //i이 위치하는 위치에 삭제
//                  mylist.erase(it);
//                  --it;
//             }
//             else{
//                 mylist.insert(it,input[p]);
//             }

//         }
//         for (list<char>::const_iterator its = mylist.begin(); its != mylist.end(); ++its) {
//         cout << *its;
//     }
//     cout << "\n";
        
//     }

// }
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    list<char> mylist;
    list<char>::iterator it = mylist.begin();

    int times;
    cin >> times;

    for (int i = 0; i < times; i++) {
        string input;
        cin >> input;
        mylist.clear();
        it = mylist.begin();

        for (char c : input) {
            if (c == '<') {
                if (it != mylist.begin()) {
                    --it;
                }
            } else if (c == '>') {
                if (it != mylist.end()) {
                    ++it;
                }
            } else if (c == '-') {
                if (it != mylist.begin()) {
                    // 이터레이터가 가리키는 이전 위치를 삭제 후, 삭제된 요소 다음 위치로 이동
                    it = mylist.erase(--it);
                }
            } else {
                // 문자 삽입 후 이터레이터는 삽입된 위치를 가리키므로, 자동으로 다음으로 이동
                mylist.insert(it, c);
            }
        }

        for (char ch : mylist) {
            cout << ch;
        }
        cout << "\n";
    }

    return 0;
}
