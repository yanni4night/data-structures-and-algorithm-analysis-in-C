#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ( ((a)>(b)) ? (a):(b) )
#define MIN(a,b) ( ((a)>(b)) ? (b):(a) )

int maxSubSum(const int *src,int left,int right){
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum = 0, maxRightBorderSum = 0;
    int leftBorderSum = 0, rightBorderSum = 0;
    int center, i;

    if(left == right){
        return *(src + left) ;
    }

    center = (right + left)/2;
    maxLeftSum = maxSubSum(src, left ,center);
    maxRightSum = maxSubSum(src, center + 1,right);

    maxLeftBorderSum = *(src + center);
    for (i = center; i >= left; --i)
    {
        if((leftBorderSum += *(src + i)) > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    maxRightBorderSum = *(src + center + 1);
    for (i = center + 1; i <= right; ++i)
    {

        if((rightBorderSum += *(src + i)) > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return MAX((maxLeftBorderSum + maxRightBorderSum), MAX(maxLeftSum, maxRightSum));
}

//最大子序列的和，时间--O(N*logN)，空间--0
int maxSubsequenceSum(const int *src, int len){
    return maxSubSum(src, 0, len - 1);
}
//最大子序列的和，时间--O(N*N)，空间--0
int maxSubsequenceSum2(const int *src, int len){
    int i, j;
    int maxSum,lineSum;

    if(len < 2){
        return *src;
    }

    maxSum = *src;
    for(i = 0; i< len; ++i){
        lineSum = *(src + i);
        if(lineSum > maxSum){
            maxSum = lineSum;
        }
        for(j = 1 + i; j < len; ++j){
            lineSum += *(src + j);
            if(lineSum > maxSum){
                maxSum = lineSum;
            }
        }
    }
    return maxSum;
}
//最大子序列的和，时间--O(N)，空间--0
int maxSubsequenceSum3(const int *src, int len){
    int i = 0;
    int sum = 0, maxSum = 0;

    if(len < 2){
        return *src;
    }

    maxSum = *src;
    for(; i < len; ++i){
        sum += *(src + i);
        
        if(sum > maxSum){
            maxSum = sum;
        }

        if(sum < 0){
            sum = 0;
        }
    }

    return maxSum;
}
//最大子序列的和，动态规划，时间--O(N)，空间--O(N)
int maxSubsequenceSum4(const int *src, int len){
    int i, maxSum;
    int *max;

    if(len < 2){
        return *src;
    }

    max = (int*)malloc(sizeof(int) * len);
    maxSum = *max = *src;

    for( i = 1; i < len; ++i){
        *(max + i) = *(max + i - 1) >= 0 ? (*(src + i) + *(max + i - 1)) : *(src + i);
        if(*(max + i) > maxSum)
        {
            maxSum = *(max + i);
        }
    }

    free(max);
    return maxSum;
}
//最小子序列的和--O(N)
int minSubsequenceSum(const int *src, int len){
    int i = 0;
    int sum = 0, minSum = 0;

    if(len < 2){
        return *src;
    }

    minSum = *src;
    for(; i < len; ++i){
        sum += *(src + i);
        if(sum < minSum){
            minSum = sum;
        }

        if(sum > 0){
            sum = 0;
        }
    }

    return minSum;
}

//最小正子序列的和--O(N)
int minPosSubsequenceSum(const int *src, int len){
    int i, j;
    int minSum,lineSum;

    if(len < 2){
        return *src;
    }

    minSum = *src;
    for(i = 0; i< len; ++i){
        lineSum = *(src + i);
        if(lineSum < minSum && lineSum > 0){
            minSum = lineSum;
        }
        for(j = 1 + i; j < len; ++j){
            lineSum += *(src + j);
            if(lineSum < minSum && lineSum > 0){
                minSum = lineSum;
            }
        }
    }
    return MAX(minSum, 0);
}

int maxSubsequenceMul(const int *src, int len){
    int i, j;
    int maxMul,lineMul;

    if(len < 2){
        return *src;
    }

    maxMul = *src;
    for(i = 0; i< len; ++i){
        lineMul = *(src + i);
        if(lineMul > maxMul){
            maxMul = lineMul;
        }
        for(j = 1 + i; j < len; ++j){
            lineMul *= *(src + j);
            if(lineMul > maxMul){
                maxMul = lineMul;
            }
        }
    }
    return maxMul;
}

int main(int argc, char *argv[]){

    int seq[] = {5, 6, 4, -3, 7, -3, 9, -5, 8, 5}, LEN = 10;

    printf("MAX SUM=%d\n", maxSubsequenceSum(seq, LEN));
    printf("MAX SUM=%d\n", maxSubsequenceSum2(seq, LEN));
    printf("MAX SUM=%d\n", maxSubsequenceSum3(seq, LEN));
    printf("MAX SUM=%d\n", maxSubsequenceSum4(seq, LEN));
    printf("MIN SUM=%d\n", minSubsequenceSum(seq, LEN));
    printf("MIN PSUM=%d\n", minPosSubsequenceSum(seq, LEN));
    printf("MAX MUL=%d\n", maxSubsequenceMul(seq, LEN));

    return 0 ;
}