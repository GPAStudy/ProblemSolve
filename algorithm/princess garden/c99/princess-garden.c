#include <stdio.h>
#include <stdlib.h>
#define INPUT "INPUT.txt"
#define OUTPUT "OUTPUT.txt"
#define FORMAT 4
#define GARDEN 275 //GARDEN이 답이되기위한 조건
/*
 * condition
 * 1. 3.1 ~ 11.30일까지 매월 꽃이 한 가지 이상 피어 있도록 한다.
 * 2. 정원에 심는 꽃의 개수를 가능한 적게 한다.
 *
 * hint
 * 1. 2월은 28일까지, 1월은 31, 12월은 31일로 정의함
 * 2. 해당 의미로 윤년을 고려하지 않는다로 알 수 있음.
 * 3. 따라서 1 2 12월은 총 90일
 * 4. 365 - 90 = 275
 * 4-1. 따라서 275일 이상 꽃이 피어야 해당 문제는 풀린다.
 * 5. 4 6 9 11 -> 30
 * 6. 1 3 5 7 8 10 12 -> 31
 * 7. 2 -> 28
 *
 * input
 * 4 (꽃의 총 개수<종류>) N (1 ≤ N ≤ 100,000)
 * 그 후 N개의 줄은 각 꽃이 피는 날짜와 지는 날짜
 * 1 1 5 31 // 1.1 ~ 5.31
 * 1 1 6 30 // 1.1 ~ 6.30
 * 5 15 8 31 // 5.15 ~ 8.31
 * 6 10 12 10 // 6.10 ~ 12.10
 *
 * output
 * 2
 * 첫째 줄에 선택한 꽃들의 최소 개수를 출력한다. 만약 두 조건을 만족하는 꽃들을 선택할 수 없다면 0을 출력한다.
 * TODO 31 30 등 날짜 수를 반환하는 함수 만들기
 */

//1 3 5 7 8 10 12 -> 31
//4 6 9 11 -> 30

typedef struct FlowerDate {
    int startMonth;
    int startDay;
    int endMonth;
    int endDay;
} FLOWERDATE;

//int dayCounter(int day) {
//
//}


int main(void) {

    freopen(INPUT, "r", stdin);
//    freopen(OUTPUT, "w", stdout);
    int N = 0; //ex : 4

    scanf("%d",&N);
    FLOWERDATE *arr = (FLOWERDATE*)calloc(N, sizeof(FLOWERDATE*)); //flowDate형식의 배열 동적 할당

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d\n", &arr[i].startMonth, &arr[i].startDay, &arr[i].endMonth, &arr[i].endDay); //배열에 할당
    }

    //임시 출력 코드
    for (int i = 0; i < N; i++) {
        printf("%d %d %d %d\n",arr[i].startMonth, arr[i].startDay, arr[i].endMonth, arr[i].endDay);
    }





    return 0;
}