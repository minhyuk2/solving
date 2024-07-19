#include <iostream>
#include <vector>
using namespace std;

typedef struct block{
    int a;
    int c;
    
}block;
int counting;

void recursion(vector<block> &v,int n, int a, int b, int c){
    
    if(n==1){
        counting++;
        block blk;
        blk.a = a;
        blk.c = c;
        v.push_back(blk);
        return;
    }
    recursion(v,n-1,a,c,b);
    recursion(v,1,a,b,c);
    recursion(v,n-1,b,a,c);
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<block> v;
    counting = 0;

    int  N;
   
    cin >> N;
    recursion(v,N,1,2,3);
    cout << counting <<"\n";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << it->a << " " << it->c << "\n";
    }
    return 0;
}