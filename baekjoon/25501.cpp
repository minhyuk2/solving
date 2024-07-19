#include <iostream>
#include <string>
using namespace std;


int forCount = 0;

int recursion(string &s, int l, int r){
    forCount++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(string &s){
    return recursion(s, 0, s.length()-1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int count = 0;
    
    cin >> count;
    
    string test[count]; //이러면 count만큼의 크기를 할당받게 되는건가?
    //그렇네 count만큼의 배열을 만드는게 아니라 count만큼의 길이를 배정받는 거네
   //char *는 선언할 때 초기화해줘야한느건가?

    //count 값만큼 문자열 배열 생성
    for (int i =0;i<count ;i++){
        forCount = 0;
        cin >> test[i];
        cout << isPalindrome(test[i]) << " ";
        cout << forCount <<"\n";
    }
  
}
