#include <iostream>
#include <algorithm>
using namespace std;

// using ll = long long;

long long int recursions(long long int a, long long int b,long long int c){

    if(b==1){
        return a%c;
    }
    long long int ans;
    long long int um;
    if(b%2==0){
        //짝수인 경우
        um = recursions(a,b/2,c);
        ans = (um * um)%c;
        return ans;
    }else{
        um = recursions(a,b/2,c);
        ans = (um*um%c*a)%c; //여기서 먼저 한 번 나눠줘야할 듯 원래도 한 번 나눠서 해야하는거니까 나머지 구해야지
        return ans;
    }
}


int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long  int a,b,c;
    cin >> a >> b >> c;

    //홀수 짝수에 대해서 나눠서 하면 된다.
    long long int ans;
    //짝수인 경우
    ans = recursions(a,b,c);
    cout << ans << "\n";

}