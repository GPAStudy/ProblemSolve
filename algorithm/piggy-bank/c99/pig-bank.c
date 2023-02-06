#include <stdio.h>

#define INPUT "INPUT.txt"
#define OUTPUT "OUTPUT.txt"

//#define [함수형태] [조건문] ? (참) : (거짓)
#define max(x, y) (x) > (y) ? (x) : (y) //-> x, y중에 큰값 반환
#include <stdlib.h>

int main(void) {
    //freopen
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);

    int e,f,n;
    //2 line input
    scanf("%d %d", &e,&f);
    scanf("%d",&n);

    //f - e -> weight
    f-=e; //저금통(꽉찬)-빈 저금통 = 동전의 무게

    int sz = max(2,f+1); //2 아니면 101 (동전에 무게 + 1)
    int *d = (int*)calloc(sz, sizeof(int)); //int형식으로 sz만큼 동적할 당 후 0으로 초기화

    for(int i=0; i<n; i++) {
        int p,w;
        scanf("%d %d", &p, &w);
        if(d[w]==0 || d[w]>p) d[w] = p;
        for(int j = w; j <= f; j++) {
            if(d[j-w]!=0) {
                int calc = d[j-w]+p;
                if(d[j]==0 || d[j]>calc) d[j] = calc;
            }
        }
    }

    int l = d[max(f,0)];
    printf("%d", (l==0?-1:l));

    return 0;
}