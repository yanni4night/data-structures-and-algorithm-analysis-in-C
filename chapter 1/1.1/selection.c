#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


//typeof int 

void sort_desc(int* src,unsigned len){
    unsigned i,j;
    int tmp;
    if(len<2)return;
    for(i=0;i<len;++i){
        for(j=i+1;j<len;++j){
            if(src[j]>src[i]){
                //exchange
                tmp = src[j];
                src[j]=src[i];
                src[i]=tmp;
            }
        }

    }
}

void print_array(int *src,unsigned len){
    unsigned i=0;
    for(;i<len;++i){
        printf("%d ", src[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    unsigned N=100,k;
    int *arr,*tmp;
    int i=0,j,m;

    struct timeval start,end;

    if(argc>1){
        N=atoi(argv[1]);
    }

    k=N/2;

    gettimeofday(&start,NULL);
    printf("N=%u,k=%u\n", N,k);

    arr = (int*)malloc(N*sizeof(int));

    for(i=0;i<N;++i){
        srand(i*i);
        arr[i]=rand()%1000;
    }

    //source array initializing completed

    tmp = (int*)malloc(k*sizeof(int));
    for(i=0;i<k;++i){
        tmp[i]= arr[i];
    }

    //sort
    sort_desc(tmp,k);

    for(i=k;i<N;++i){
        if(arr[i]>tmp[k-1]){
            //find the correct position
            int pos = 0;
            for(j=k-1;j>=0;--j){
                if(tmp[j]>arr[i]){
                    pos = j+1;
                    break;
                }
            }
            //move
            for(m=k-1;m>=pos+1;--m){
                tmp[m]=tmp[m-1];
            }
            tmp[pos]=arr[i];
        }
    }

    //print_array(arr,N); 
    //print_array(tmp,k); 
    printf("%d\n",tmp[k-1]);

    gettimeofday(&end,NULL);

    printf("costs %lfms\n", 1e3f*(end.tv_sec-start.tv_sec)+((end.tv_usec-start.tv_usec)/1e3f));
    return 0;
}