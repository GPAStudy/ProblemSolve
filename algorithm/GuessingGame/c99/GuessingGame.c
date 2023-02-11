#include <stdio.h>
#include <string.h>
#define INPUT "INPUT.txt"
#define OUTPUT "OUTPUT.txt"

int main(void) {
    freopen(INPUT, "r", stdin);
//    freopen(OUTPUT, "w", stdout);

    int guessingNumber = 0, answer=0;
    int min=0 ,max = 10;
    char hint[10];

    while (1) {
        scanf("%d\n", &guessingNumber); //10입력 후 \n문자가 입력되기에 거기까지 인식
        scanf("%[^\n]", hint); // \n scanf 인수를 활용하여 \n인식

        if(hint[strlen(hint)-1]=='h' && max>answer) {
            max=guessingNumber;
        }
        else if(hint[strlen(hint)-1]=='w' && min<answer) {
            min=guessingNumber;
        }
        else if(hint[strlen(hint)-1]=='n') {
            answer=guessingNumber;
            break;
        }
    }

    if((max> answer && answer>min))
        printf("Stan may be honest");
    else
        printf("Stan is dishonest");


    return 0;
}