#include <stdio.h>
#include <stdlib.h>
#define INPUT "INPUT.txt"
#define OUTPUT "OUTPUT.txt"
void solve(int idx, int weight, int K, int* arr, int* cntTable) {
    if(idx == K) {
        if(weight > 0) cntTable[weight-1] = 1;
        return;
    }
    solve(idx+1, weight + arr[idx], K, arr, cntTable);
    solve(idx+1, weight - arr[idx], K, arr, cntTable);
    solve(idx+1, weight, K, arr, cntTable);
}

int main(void) {

    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);

    int K=0, S=0, cnt=0;
    scanf("%d", &K);
    int* arr = (int*)calloc(K, sizeof(int)); //int형식으로 K만큼 동적할 당 후 0으로 초기화

    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
        S+= arr[i];
    }

    int* cntTable = (int*) calloc(S, sizeof(int)); //int 형식으로 K만큼 할당 후 0으로 초기화
    solve(0,0, K, arr, cntTable);

    for (int i = 0; i < S; i++) {
        if(!cntTable[i]) cnt++;
    }

    printf("%d", cnt);


    return 0;
}