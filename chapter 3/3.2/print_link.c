#include "../link.h"
#include <stdio.h>


int main(int argc, char* argv[]){
    node_t L = create_link(), P = create_link(), head;
    int i, j;
    for(i = 0,j = 0;i < 20;i+=2, ++j){
        link_push(L, create_node(i));
        link_push(P, create_node(j));
    }

    head = L->next;
    P = P->next;
    i = j = 0;

    while(P){
        int t = P->payload;

        while(i<t && head){
            head = head->next;
            ++i;
        }
        if(head)
        {
            printf("%d\n", head->payload);
        }

        P = P->next;
    }

    return 0;
}