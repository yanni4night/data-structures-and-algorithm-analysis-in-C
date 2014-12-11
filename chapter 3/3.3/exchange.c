#include "../link.h"

int main(int argc, char* argv[]){
    node_t head = create_link();
    node_t node1 = create_node(5);
    node_t node2 = create_node(8);

    link_push(head, node1);
    link_push(head, node2);

    print_link(head);

    if(node1->prev){
        node1->prev->next = node2;
    }
    
    if(node2->next){
        node2->next->prev = node1;
    }

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;

    print_link(head);

    return 0;
}