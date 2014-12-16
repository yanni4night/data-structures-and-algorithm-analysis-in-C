#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//递归求幂
int _pow1(int N,int M){
    int P = M >> 1, Q = M - P;
    if(1 == M)return N;
    return _pow1(N, P) * _pow1(N, Q);
}

//循环求幂
int _pow2(int N,int M){
    int pw = 1 , n = N;
     while (M > 0) {
        if (M & 1) // M%2
            pw *= n;
        n *= n;
        M >>= 1; // M/=2
    }

    return pw;
}


int main(int argc, char* argv[])
{
    int N = 10, M = 5;

    if(2 <= argc){
        N = atoi(argv[1]);
        if(2 < argc){
            M = atoi(argv[2]);
        }
    }

    printf("pow(%d,%d)=%d\n", N, M, _pow1(N, M));
    printf("pow(%d,%d)=%d\n", N, M, _pow2(N, M));

    return 0;
}