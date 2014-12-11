#include "../link.h"
#include <stdio.h>


int main(int argc, char* argv[]){
    node_t link = create_link(), head;
    int i;
    for(i = 0;i<10;++i){
        node_t node = create_node(i);
        link_push(link, node);
    }

    head = link->next;

    while(head){
        printf("%d\n", head->payload);
        head = head->next;
    }

    return 0;
}