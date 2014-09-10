#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//是否是素数，时间--O(N½)，空间--0
int isPrime(int N){
    int i = 3;
    int end = (int)sqrt(N);

    if(!(N%2)){
        return 2;
    }

    for(;i < end;i += 2){
        if(!(N%i)){
            return i;
        }
    }

    return 0;
}

//整数N的二进制表示法的位数
int binary(int N){
    return (int)ceil(log(N + 1) / log(2));
}


//厄拉多塞筛法，输出N以内所有素数，时间--O(NloglogN)
void Erastothenes(int N,int *primes ,int *len){
    int i, j, sqrtN = (int)ceil(sqrt(N)), k;
    int *table = (int*)malloc(sizeof(int) * N);

    //初始化表
    for (i = 0;i < N; ++i){
        *(table + i) = i;
    }

    i = 2;
    while(i < sqrtN){
        k = 1;
        while(k * i < N){
            *(table + k * i) = -1;
            k++;
        }

        for(j=2;j<N;++j){
            if(*(table + j) != -1){
                i = j;
                break;
            }
        }

    }

    i = 2;
    k = -1;

    for(;i<N;++i){
        if(*(table + i) > -1){
            *(primes + ++k) = i;
        }
    }

    *len = k;
    free(table);
}

int main(int argc,char* argv[])
{   
    int N = 999,l;
    int i;

    if(argc > 1){
        N = atoi(argv[1]);
    }

    if(l = isPrime(N)){
        printf("%d is NOT a prime number(%d)\n", N, l);
    }else{
        printf("%d IS a prime number\n", N);
    }

    printf("%d=>binary(%d)\n", N, binary(N));

    int *primes = (int*)malloc(sizeof(int) * N);
    int len = 0;
    memset(primes, 0, N * sizeof(int));

    Erastothenes(N, primes, &len);

    for(i = 0;i < len; ++i){
        printf("%d\n",*(primes + i) );
    }

    free(primes);

    return 0;
}