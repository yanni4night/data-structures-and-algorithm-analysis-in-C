#ifndef __LINK_H__
#define __LINK_H__

#include <stdlib.h>

typedef struct node* node_t;
struct node{
    int payload;
    node_t next;
    node_t prev;
};


node_t create_node(int payload){
    node_t node = (node_t)malloc(sizeof(node_t));    
    node->payload = payload;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

node_t create_link(){
    return create_node(-1);
}

node_t link_push(node_t head, node_t node){
    node_t tmp = head;
    
    while(NULL != tmp->next)
    {
        tmp = tmp->next;
    }

    tmp->next = node;
    node->prev = tmp;
    return head;
}

#endif
