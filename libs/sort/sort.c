#include "sort.h"


void sort_bubble(void** src,unsigned len,greater_than greater){
    unsigned i,j;
    void *tmp;
    if(len<2)return;
    for(i=0;i<len;++i){
        for(j=i+1;j<len;++j){
            if(greater(src[j],src[i])){
                //exchange
                tmp = src[j];
                src[j]=src[i];
                src[i]=tmp;
            }
        }

    }
}
