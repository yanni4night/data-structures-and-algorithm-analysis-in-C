#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

typedef struct Demo{
    int level;
} Demo_st;

typedef Demo_st* Demo_t;


int demo_compare(void* p,void* n){
    Demo_t s = (Demo_t)p;
    Demo_t m = (Demo_t)n;

    if(s->level>m->level)return 1;
    return 0;
}

int main(){
    int LEN = 10;
    int i=0;
    Demo_t *src = (Demo_t*)malloc(sizeof(Demo_t)*LEN);
    for(;i<LEN;++i){
        Demo_t d = (Demo_t)malloc(sizeof(Demo_st));
        d->level = rand()%100;
        *(src+i) =d;
    }

    sort_bubble((void**)src,LEN,demo_compare);

    for(i=0;i<LEN;++i){
        printf("%d\n", (*(src+i))->level);
    }
    
    return 0;
}