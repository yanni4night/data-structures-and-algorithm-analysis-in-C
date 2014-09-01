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
        return *(src + left) > 0 ? *(src + left) : 0;
    }

    center = (right + left)/2;
    maxLeftSum = maxSubSum(src, left ,center);
    maxRightSum = maxSubSum(src, center + 1,right);

    for (i = center; i >= left; --i)
    {
        if((leftBorderSum += *(src + i)) > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    for (i = center + 1; i <= right; ++i)
    {
        if((rightBorderSum += *(src + i)) > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return MAX((maxLeftBorderSum + maxRightBorderSum), MAX(maxLeftSum, maxRightSum));
}

//最大子序列的和--O(N*logN)
int maxSubsequenceSum(const int *src, int len){
    return maxSubSum(src, 0, len - 1);
}
//最大子序列的和--O(N*N)
int maxSubsequenceSum2(const int *src, int len){
    int i, j;
    int maxSum,lineSum;

    if(len < 2){
        return *src;
    }

    for(i = 0; i< len; ++i){
        lineSum = *(src + i);
        if(!i){maxSum = lineSum;}
        if(lineSum > maxSum){maxSum = lineSum;}
        for(j = 1 + i; j < len; ++j){
            lineSum += *(src + j);
            if(lineSum > maxSum){
                maxSum = lineSum;
            }
        }
    }
    return maxSum;
}
//最大子序列的和--O(N)
int maxSubsequenceSum3(const int *src, int len){
    int i = 0;
    int sum = 0, maxSum = 0;

    if(len < 2){
        return *src;
    }

    for(;i<len;++i){
        sum += *(src + i);
        if(sum > maxSum){
            maxSum = sum;
        }else if(sum < 0){
            sum = 0;
        }
    }

    return maxSum;
}

int main(int argc, char *argv[]){

    int seq[] = {5, -2, 1, -3, 7, -1, 0, -1, 2, -5};

    printf("%d\n", maxSubsequenceSum(seq, 10));
    printf("%d\n", maxSubsequenceSum2(seq, 10));
    printf("%d\n", maxSubsequenceSum3(seq, 10));

    return 0 ;
}