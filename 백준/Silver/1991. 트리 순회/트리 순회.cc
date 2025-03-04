#include <bits/stdc++.h>

using namespace std;

int N;

int arr[1010];
int lc[1010];
int rc[1010];

//맞네 재귀를 이용하는 것인데 현재 위치를 통해서 값을 구해내는 과정이 그냥 순서대로 A,B,C,D니까 이를 이용하면 되는 것이다.
void preOrder(int num){
    //약간 백트랙킹처럼 코드가 형태가 그렇게 될 것 같긴하다.
    cout << char(num + 'A' -1);
    if(lc[num] !=0) preOrder(lc[num]);
    if(rc[num] !=0) preOrder(rc[num]);
}

void inOrder(int num){
    if(lc[num]!=0) inOrder(lc[num]);
    cout << char(num + 'A' -1);
    if(rc[num]!=0) inOrder(rc[num]);
}

void postOrder(int num){
    if(lc[num]!=0) postOrder(lc[num]);
    if(rc[num]!=0) postOrder(rc[num]);
    cout << char(num + 'A' -1);

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    //트리에 대한 처리를 진행.
    //트리에 대한 처리를 어떻게 할지 고민.
    char c,l,r;
    // int idx = 1;
    for(int i=0;i<N;i++){
        cin >> c >> l >> r;

        if(l!='.')lc[c-'A'+1] = l-'A'+1;
        if(r!='.')rc[c-'A'+1] = r-'A'+1;
    }

    //전위 순회부터 하나씩 처리를 해보면, 전위 순회는 DFS처럼 처리하면 된다.
    preOrder(1);
    cout << "\n";
    inOrder(1);
    cout << "\n";
    postOrder(1);
    cout << "\n";
}