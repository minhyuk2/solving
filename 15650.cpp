// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(void){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int N,M;
//     vector<int> v;
//     cin >> N >> M;
//     vector



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
        for(int i = 0; i < M-1;i++){
            if(num[i] > num[i+1]){
                return;
            }
        }
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