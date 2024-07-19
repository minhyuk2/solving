// #include <iostream>
// using namespace std;


// void  print_arr(int num[], int size){

//     for(int i=0;i<size;i++){
//         cout << num[i] << " ";
//     }
//     cout << "\n";
// } // 이렇게 함수로 처리하면 내가 원하는 출력을 쉽게 구현할 수 있다.

// void swapping (int num[], int front, int back){
//     int temp;
//     temp = num[front];
//     num[front] = num[back];
//     num[back] = temp;    
// }
// void permutation(int num[],int N,int M,int depth){
//     if(depth ==M){
//         print_arr(num,M);
//         return;
//     }

//     for(int i=depth;i<N;i++){
//         swapping(num,i,depth);
//         permutation(num,N,M,depth+1);
//         swapping(num,i,depth);

//     }


// }


// int main(void){
//     ios_base :: sync_with_stdio(false);
//     cin.tie(NULL);
//     int N,M;

//     cin >> N >> M;
  
//     int* array = new int[N];
    
//     for(int i=0;i<N;i++){
//         array[i] = i+1;
      
//     }
  
//     permutation(array,N,M,0);
// }
#include <iostream>
using namespace std;

void print_arr(int num[], int size) {
    for(int i = 0; i < size; i++) {
        cout << num[i] << " ";
    }
    cout << "\n";
}

void permutation(int num[], bool visited[], int N, int M, int depth) {
    if(depth == M) {
        print_arr(num, M);
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            num[depth] = i + 1;
            permutation(num, visited, N, M, depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int *array = new int[N];
    bool *visited = new bool[N]; // 숫자의 방문 여부를 나타내는 배열입니다.
    fill(visited, visited + N, false); // visited 배열을 모두 false로 초기화합니다.

    permutation(array, visited, N, M, 0);

    delete[] array; // 동적 할당된 메모리를 해제합니다.
    delete[] visited;
    return 0;
}
