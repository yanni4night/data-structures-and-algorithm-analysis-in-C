#include "../link.h"

int main(int argc, char* argv[]){
    int val1[] = {1,1,4,6,9,10};
    int val2[] = {2,4,4,8,10,11};
    const int len = 6;
    int i;
    
    node_t link1 = create_link();
    node_t link2 = create_link();
    node_t inter = create_link();
    
    
    for(i = 0;i<len;++i){
        link_push(link1, create_node(val1[i]));
        link_push(link2, create_node(val2[i]));
    }

    node_t p1 = link1->next, p2 = link2->next;
    int last = -1;

    while(p1 && p2){
        if(p1->payload < p2->payload){
            if(p1->payload>last)
            {
                link_push(inter, create_node(p1->payload));
                last = p1->payload;
            }
            p1=p1->next;
        }else if(p1->payload > p2->payload){
            if(p2->payload>last)
            {
                link_push(inter, create_node(p2->payload));
                last = p2->payload;
            }
            p2=p2->next;
        }else{
            if(p1->payload>last)
            {
                link_push(inter, create_node(last = p1->payload));
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    print_link(inter);

    return 0;
}