#include <stdio.h>
#include <stdlib.h>
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

int binary(int N){
    return (int)ceil(log(N+1)/log(2));
}

int main(int argc,char* argv[])
{   
    int N = 999,l;
    if(argc > 1){
        N = atoi(argv[1]);
    }

    if(l = isPrime(N)){
        printf("%d is NOT a prime number(%d)\n", N, l);
    }else{
        printf("%d IS a prime number\n", N);
    }

    printf("%d=>binary(%d)\n", N, binary(N));

    return 0;
}