#include <bits/stdc++.h>

using namespace std;

string st1,st2;

int arr[1010][1010];
int nums[1010][1010];
// vector<int> arrs[1010][1010];

//역추적이라는 개념을 사용해야하는거구나

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> st1 >> st2;

    //LCS는 어떤 알고리즘 써야했었는지 왜 기억이 안나지,,흠

    //1000 * 1000은 100만인데 백만이면 1초에 1억 0.1초면 1000만인데
    for(int i=1; i<=st1.size();i++){
        for(int t= 1 ;t <=st2.size();t++){
            //어차피 무조건 다음 글자를 볼거니까 이렇게 보는 것이다.
            if(st1[i-1] == st2[t-1]){
                //문자열을 다 읽은다음에 붙혀야하기 때문에 문제가 발생하는 것이다.
                nums[i][t] = nums[i-1][t-1] + 1;
                arr[i][t] = 1;
            }else{
                if(nums[i][t-1] > nums[i-1][t]){
                    arr[i][t] = 2;
                    nums[i][t] = nums[i][t-1];
                }else{
                    arr[i][t] =3; //끝까지 이동한 것을 전달하는 것이기에 문제가 되는 것이다 그래서 겹치는게 존재하는 것이다.
                    nums[i][t] = nums[i-1][t];
                }
            }
        }
    }

    int i = st1.size();
    int j = st2.size();
    string temper = "";
    while(i>0 && j >0){
        if(arr[i][j] == 1){
            temper  += st1[i-1];
            i--;
            j--;
        }else if(arr[i][j] ==2){
            j--;
        }else{
            i--;
        }
    }
    reverse(temper.begin(),temper.end());
    cout << temper.size() << "\n" << temper << "\n";

}