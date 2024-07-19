#include <iostream>
#include <algorithm>

using namespace std;

void qsort(int *num, int start, int end){
    if(start>=end){
        return;
    }
    int pivot= start;
    int temp;
    int i = pivot +1;
    int j = end;
    while(i<=j){
        	while (i <= end && (num[i] <= num[pivot])) { // 피봇보다 큰 값을 찾을 때까지
			i++;
		}
		    while (j > start && (num[j] >= num[pivot])) { // 피봇보다 작은 값을 찾을 때까지
			j--;
		}
        if(i>j){ //겹쳤을 때는 
            temp = num[j];
            num[j] = num[pivot];
            num[pivot] = temp;
        }else{
            temp= num[i]; //i랑j랑 만나지 않고 멈췄을 때는 둘이 바꿔주는게 필요하고
            num[i] = num[j];
            num[j] = temp;
        }
    }
    qsort(num,start,j-1);
    qsort(num,j+1,end);   
} //이렇게 qsort알고리즘을 작성 마무리하면 된다.
//qsort알고리즘 작성
//이분 탐색도 작성해서 다 찾아보면 되는 것이다.
void binary_search(int *num, int find,int start,int end){
    int middle = (start+end)/2;
    int left = start;
    int right = end;
    // if(find>num[middle]){
    //     binary_search(num,find,middle+1,end);
    // }
    // else if(find == num[middle])
    // {
    //     cout << "1\n";
    //     return ;
    // }
    // else if(find<num[middle]){
    //     binary_search(num,find,start,middle-1);
    // }
    // return ;
    while(left<=right){
        if(find ==num[middle]){
            cout << "1\n";
            return;
        }else if(find>num[middle]){
            left = middle+1;
            middle = (left+right)/2;
        }else{
            right = middle-1;
            middle = (left+right)/2;
        }
    }
    cout << "0\n";
    return;
    //없어서 무한반복되겠는데?
    //아니 이렇게까지 멍청해져도 되는건가 싶네 진짜 ㅋㅋㅋ이게 뭐노..
}
//n번 돌리는건 괜찮겠지 뭐
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count1;
    cin >> count1;
    int array1[count1];
    for(int i=0; i<count1 ;i++){
        cin >> array1[i];
    }
    //여기에 이제 qsort를 먼저 해주는거지   
    sort(array1, array1+count1);
    //우선 정렬해주고 
    int count2;
    cin >> count2;
    int target;
    for(int i=0;i<count2;i++){
        cin >> target;
        binary_search(array1,target,0,count1);
    }
    //이제 이분탐색 사용하면 된다.
}