#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[]){
    int SIZE = 4,DIC_LEN = 4;
    char table[4][4] = {{'t','h','i','s'},{'w','a','t','s'},{'o','a','h','g'},{'f','g','d','t'}};
    char *dic[4] = {"that","this","two","fat"};
    //realloc
    int len = (SIZE * SIZE + 2) * 2,cnt=0;
    int i,j,k,seglen = sizeof(char)*SIZE + 1;

    char **all_str = (char**)malloc(sizeof(char*)*len);
    memset(all_str,0,sizeof(char*)*len);

    //ROWS&COLS
    for (i = 0; i < SIZE; ++i)
    {   
        char * row = (char*)malloc(seglen);
        memset(row,0,seglen);
        char * col = (char*)malloc(seglen);
        memset(col,0,seglen);

        char * rowrev = (char*)malloc(seglen);
        memset(rowrev,0,seglen);
        char * colrev = (char*)malloc(seglen);
        memset(colrev,0,seglen);
        
        for (j = 0,k = SIZE - 1; j < SIZE,k>=0; ++j,--k)
        {
            row[j] = table[i][j];
            rowrev[k] = table[i][j];
            col[j] = table[j][i];
            colrev[k] = table[j][i];
        }

        all_str[cnt++] = row;
        all_str[cnt++] = rowrev;
        all_str[cnt++] = col;
        all_str[cnt++] = colrev;
    }
    //CROSS
    char * cross1 = (char*)malloc(seglen);
    memset(cross1,0,seglen);
    char * cross2 = (char*)malloc(seglen);
    memset(cross2,0,seglen);
    char * cross3 = (char*)malloc(seglen);
    memset(cross3,0,seglen);
    char * cross4 = (char*)malloc(seglen);
    memset(cross4,0,seglen);

    for(i=0;i<SIZE;++i){
        cross1[i] = table[i][i];
        cross2[i] = table[i][SIZE-i-1];
        cross3[i] = table[SIZE-i-1][i];
        cross4[i] = table[SIZE-i-1][SIZE-i-1];
    }

    all_str[cnt++] = cross1;
    all_str[cnt++] = cross2;
    all_str[cnt++] = cross3;
    all_str[cnt++] = cross4;

    for(i=0;i<cnt;++i){
        for (j = 0; j < DIC_LEN; ++j)
        {
            if(strstr(*(all_str+i),dic[j])!=NULL){
                 printf("'%s' found\n",dic[j]);
            }
        }
    }

    free(all_str);
    return 0;
}