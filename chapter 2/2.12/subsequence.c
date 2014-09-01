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

    return (int)MAX((maxLeftBorderSum + maxRightBorderSum), MAX(maxLeftSum, maxRightSum));
}

//最大子序列的和-O(NlogN)
int maxSubsequenceSum(const int *src, int len){
    return maxSubSum(src, 0, len-1);
}

int main(int argc, char *argv[]){

    int seq[] = {2, -3, 1, -3, 5, 7, 0, -1, 2, 3};

    printf("%d\n", maxSubsequenceSum(seq, 10));

    return 0 ;
}