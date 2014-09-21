#include <stdio.h>
#include <stdlib.h>

//计算主要元素——出现概率大于一半
int get_main_num( int *src, int len ){
    int i, j = -1;
    for( i = 0; i < len; i+=2 ){
        if( i + 1 < len ){
            if( *(src + i) == *(src + i + 1) ){
                *(src + ++j) = *(src + i + 1);
            }
        }else{
            *(src + ++j) = *(src + i);
        }
    }

    if(j < 0){
        //no main number
        return -1;
    }else if(!j){
        //the only is the one
        return *src;
    }else{
        return get_main_num( src, 1 + j );
    }
}

int main( int argc, char *argv[] )
{
    int src[] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 ,4};
    int main_num = get_main_num( src, 9 );
    if( -1 == main_num ){
        printf("No main number found\n");
    }else{
        printf("Main number found:%d\n", main_num);
    }
    return 0;
}