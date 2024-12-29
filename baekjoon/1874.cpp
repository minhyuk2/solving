#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    //vector에 결과를 넣어서 출력하고 하나라도 안되는게 있을 때는 걍 NO로 벡터 초기화시키면 됨.

    //n개를 순서대로 넣어주는데 이 n개를 이용해서 입력된 수열을 만들 수 있는지 묻는 것이다.

    //입력하는 것 중에서 안되는 케이스를 알고 있으면 좀 쉽게 접근하고 만약에 +랑 - 개수를 세서 그 페어가 안 맞으면 안되게끔 코드를 작성하면 될 듯

    //어떻게 케이스를 분류해서 짤 수 있을까?
    
    //넣는게 달라지는 걸까?

    vector<char> vecs;
    stack<int> stas;
    int countPlus = 0;
    int countMin = 0 ;
    int N;
    cin  >> N;
    

    int rows[N];

    for(int i =0; i< N ; i++){
        cin >> rows[i];
    } //입력받은 값들을 배열에 하나씩 넣기? 일단 저장을 위해서? 근데 한 줄 씩 준 이유가 있을 것 같긴해서 그냥 바로 한 줄씩 판단해도 나쁘지 않을 것 같은데
    //어떻게 해야할지가 고민이네 일단 스택구조를 떠올리면 결과값을 토대로 얘가 나올 수 있는건지 판단하면 제일 큰 값이 들어오고 그 후로는 역전이 되면 안되는듯?
    //첫번쨰 숫자만큼 push하고 그 후로 pop하고 또 커지는 값이 생기면 push하는 식으로 하면 되는게 아닌가? pop이 나올 때까지?
    //다음 수가 더 작으면 pop이고 아니면 push하는 식으로 그 다음에 pop할 수 있도록 걍 스택이라는 것을 이용해서 구현해봐야겠다.
    //첫번째 것을 기준으로

    int stackCount = rows[0];
    //일단 첫번째 것에 대한 결과.
    for(int i =0; i < rows[0] ; i++){
        vecs.push_back('+');
        countPlus ++;
        stackCount++;
        stas.push(i+1);
    }
    vecs.push_back('-');
    countMin++;
    stackCount--;
    stas.pop();
    //이러면 첫번째 것에 대한 처리가 끝났고,
    int current = rows[0];


    //이제 전 것보다 작으면 pop해서 해당하는게 바로 나오는지 아닌지 체크해서 넣는 식으로 하면 된다.
    for(int i = 1 ; i < N ; i++){
        if(rows[i] > current){
            int alve = rows[i]-countPlus;
            int tempPl = countPlus;
            if(alve < 0){
                cout << "NO\n";
                return 0;
            }
            if(stackCount < 0){
                cout << "NO\n";
                return 0;
            }
            for(int p=0; p<alve; p++){
                vecs.push_back('+');
                countPlus ++;
                stackCount ++;
                stas.push(tempPl+p+1);
            }  
            vecs.push_back('-');
            countMin ++;
            stackCount--;
            current = rows[i];
            if( stas.top() != rows[i]){
                cout << "NO\n";
                return 0;
            }else{
                stas.pop();
            }
        }else{
            if (stackCount > 0) {
                vecs.push_back('-');
                countMin++;
                stackCount--;
                current = rows[i];
                if( stas.top() != rows[i]){
                    cout << "NO\n";
                    return 0;
                }else{
                    stas.pop();
                }
            } else {
                cout << "NO\n";
                return 0;
            }
        }
    }

    if(stackCount < 0){
        cout << "NO\n";
    }else{
        for (std::vector<char>::iterator it = vecs.begin(); it != vecs.end(); ++it) {
                cout << *it << "\n";
            }
    }


}