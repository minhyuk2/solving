#include <bits/stdc++.h>

using namespace std;

// char first[10002];
// char second[10002];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    // fill(first,first+10002,'-1');
    // fill(second,second+10002,'-1');
    string first,second;
    cin >> first >> second;
    string answer;
    //string으로 하는 순간 한 글자에 대한 처리가 애매해진다.
    // cout << first << " " << second << "\n";
    if(first.length() >= second.length()){
        int extra = 0;
        int minuss = first.length() - second.length();
        for(int i = second.length()-1 ; i >= 0 ; i --){
            int num = second[i] - '0' + first[i+minuss] - '0' + extra;
            // cout << second[i] << "   " << first[i] << " " << num << " " << minuss << "\n";
            if(num >= 10 ){
                extra = 1;
                string inNum = to_string(num%10);
                answer.insert(0,inNum);
                // cout << answer << "\n";
            }else{
                extra = 0;
                string inNum = to_string(num%10);
                answer.insert(0,inNum);       
                // cout << answer << "\n";        
            }
        }
        if(extra ==1){
            for(int i = first.length()-second.length()-1;i>=0; i--){
                int num = first[i] - '0' + extra;
                if(num >= 10 ){
                    extra = 1;
                    string inNum = to_string(num%10);
                    answer.insert(0,inNum);
                    // cout << answer << "\n";
                }else{
                    extra = 0;
                    string inNum = to_string(num%10);
                    answer.insert(0,inNum);     
                    // cout << answer << "\n";          
                }
            }
            if(extra == 1){
                answer.insert(0,"1");
            }
        }else{
            for(int i = first.length()-second.length()-1;i>=0; i--){
                int num = first[i] - '0';
                string inNum = to_string(num%10);
                answer.insert(0,inNum);     
                // cout << answer << "\n";         
            }
        }
   
    }else{
        int extra = 0;
        int minuss = second.length() - first.length();
        for(int i = first.length()-1 ; i >= 0 ; i --){
            int num = second[i+minuss] - '0' + first[i] - '0' + extra;
            if(num >= 10 ){
                extra = 1;
                string inNum = to_string(num%10);
                answer.insert(0,inNum);
            }else{
                extra = 0;
                string inNum = to_string(num%10);
                answer.insert(0,inNum);               
            }
        }
        if(extra ==1){
            for(int i = second.length()-first.length()-1;i>=0; i--){
                int num = second[i] - '0' + extra;
                if(num >= 10 ){
                    extra = 1;
                    string inNum = to_string(num%10);
                    answer.insert(0,inNum);
                }else{
                    extra = 0;
                    string inNum = to_string(num%10);
                    answer.insert(0,inNum);               
                }
            }
            if(extra == 1){
                answer.insert(0,"1");     
            }
        }else{
            for(int i = second.length()-first.length()-1;i>=0; i--){
                int num = second[i] - '0';
                string inNum = to_string(num%10);
                answer.insert(0,inNum);              
            }
        }

    }
    cout << answer <<"\n";
}