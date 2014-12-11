#ifndef __LINK_H__
#define __LINK_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct node* node_t;
struct node{
    int payload;
    node_t next;
    node_t prev;
};


node_t create_node(int payload){
    node_t node = (node_t)malloc(sizeof(struct node));
    node->payload = payload;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

node_t create_link(){
    return create_node(-1);
}

node_t link_push(node_t head, node_t node){
    node_t tail = head;
    
    while(NULL != tail->next)
    {
        tail = tail->next;
    }

    tail->next = node;
    node->prev = tail;
    node->next = NULL;
    return head;
}

void print_link(node_t head){
    node_t node = head->next;
    while(node){
        printf("%d ", node->payload);
        node = node->next;
    }
    printf("\n");
}

#endif
