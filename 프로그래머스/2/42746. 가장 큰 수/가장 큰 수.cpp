#include<bits/stdc++.h>

using namespace std;
//자릿수를 구할 때 to_string을 쓰고 size로 구하는 초식도 있다.
bool comp(int A, int B){
//     //
    string temp1 = to_string(A);
    string temp2 = to_string(B);
    if(A == 1000){
        if(B!=0){
            return false;
        }else{
            return true;
        }
    }
    if(B == 1000){
        if(A!=0){
            return true;
        }else{
            return false;
        }
    }
    return temp1+temp2 > temp2+temp1;
    
//     //1000일 때 해결완료
//     // 2자리와 1자리  2자리와 3자리 1자리와 3자리 
//     if(temp1.size() == temp2.size()){
//         return A > B;
//     }
//     //3자리와 1자리
//     if(temp1.size()==3&&temp2.size()==1){
//         if(A/100 == B){
//            if((A%100)/10 == B){
//                 if(A%10 < B)
//                     return false;
//                 else if(A%10 == B){
//                     return false;
//                 }else{
//                     return true;
//                 }
//            }else if((A%100)/10 > B){
//                 return true;
//         }else
//             return false;
//     }else if(A/100 > B){
//             return true;
//     }else{
//             return false;
//         }
//     }
    
//     if(temp2.size()==3&&temp1.size()==1){
//         if(B/100 == A){
//            if((B%100)/10 == A){
//                  if(B%10 < A)
//                     return true;
//                 else if(B%10 == A){
//                     return true;
//                 }else{
//                     return false;
//                 }
//            }else if((B%100)/10 > A){
//                 return false;
//         }else
//             return true;
//     }else if(B/100 > A){
//             return false;
//     }else{
//             return true;
//      }
//     }
//     //2자리와 1자리
//     if(temp1.size()==2 && temp2.size()==1){
//         if(A/10 == B){
//             if( A%10 < B){
//                 return false;
//             }else if(A%10 == B){
//                return false;
//             }else{
//                 return true;
//             }
//         }else if(A/10 > B){
//             return true;
//         }else{
//             return false;
//         }
//     }
//     if(temp2.size()==2 && temp1.size()==1){
//         if(B/10 == A){
//             if( B%10 < A){
//                 return true;
//             }else if(B%10 == A){
//                 return true;
//             }else{
//                 return false;
//             }
//         }else if (B/10 > A){
//             return false;
//         }else{
//             return true;
//         }
//     }
    
//     //3자리와 2자리
//      if(temp1.size()==3 && temp2.size()==2){
//         if(A/100 == B/10){
//             if((A%100)/10 == B%10){
//                 if( A%10 < B%10){
//                     return false;
//                 }else if(A%10 == B%10){
//                     return false;
//                 }else{
//                     return true;
//                 }
//             }else if((A%100)/10 < B%10){
//                 return false;
//             }else{
//                 return true;
//             }
//         }else if(A/100 < B/10){
//             return false;
//         }else{
//             return true;
//         }
//     }
    
//      if(temp2.size()==3 && temp1.size()==2){
//         if(B/100 == A/10){
//             if((B%100)/10 == A%10){
//                 if( B%10 < A%10){
//                     return true;
//                 }else if (B%10 == A%10){
//                     return true;
//                 }else{
//                     return false;
//                 }
//             }else if ((B%100)/10 < A%10){
//                 return true;
//             }else{
//                 return false;
//             }
//         }else if(B/100 < A/10){
//             return true;
//         }else{
//             return false;
//         }
//     }
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),comp);
    for(int i =0; i<numbers.size();i++){
        string temp = to_string(numbers[i]);
        for(auto it : temp){
            answer.push_back(it);
        }
    }
    
    if(answer[0]== '0'){
            answer = "0";
    }
    return answer;
}