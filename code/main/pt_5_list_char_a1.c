#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
   Print List
*/

static void print_list (const List *list) {
    ListNode *node;
    int i;
    char *data;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "list.node[%03d]=%c, %p -> %p \n", i, *data, node, node->next);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

   return;
}


int main (int argc, char **argv) {
    List list;
    ListNode *node;

    int  i;
    char *data, letra='n';

    // Initialize the linked list
    list_init(&list, free);

    // Fill the linked list 
    node = list_head(&list);
    for (i = 20; i > 10; i--) {

        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;

        *data = letra;
        letra++;
        
        if (list_ins_next(&list, NULL, data) != 0)
            return 1;
    }

    print_list(&list);

    node = list_head(&list);

    for (i = 0; i < 6; ++i)
        node = list_next(node);

    data = list_data(node);
    fprintf(stdout, "\nRemoving a node after the one containing %c\n", *data);

    if (list_rem_next(&list, node, (void**)&data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nInserting A at the tail of the list\n");
    *data = 'A';
    if (list_ins_next(&list, list_tail(&list), data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nRemoving a node after the third node\n");
    
	node = list_head(&list);

    for (i = 0; i < 3; ++i)
        node = list_next(node);

    data = list_data(node);
    
    if (list_rem_next(&list, node, (void**)&data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nRemoving a node at the head of the list\n");
    if (list_rem_next(&list, NULL, (void**)&data) != 0)
        return 1;
    print_list(&list);    
    
    fprintf(stdout, "\nInsert W at the head of the list\n");
    *data = 'W'; //
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;
    print_list(&list);    

    fprintf(stdout, "\nRemoving the eight node\n");
    
    node = list_head(&list);
    
    for (i = 0; i < 6; i++)
    	node = list_next(node);
    
    data = list_data(node);
    
	if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nInserting T after the first node\n");
    *data = 'T'; 
    if (list_ins_next(&list, list_head(&list), data) != 0)
        return 1;
    print_list(&list); 
    
    node = list_head(&list);

    for (i = 0; i < 4; ++i)
        node = list_next(node);

    *data = 'M';
    fprintf(stdout, "\nInserting M after the fifth node\n", *data);

    if (list_ins_next(&list, node, data) != 0)
        return 1;

    print_list(&list);

    i = list_is_head(&list, list_head(&list));
    fprintf(stdout, "\nTesting list_is_head... value=%d (1=OK)\n", i);
    i = list_is_head(&list, list_tail(&list));
    fprintf(stdout, "Testing list_is_head... value=%d (1=OK)\n", i);
    i = list_is_tail(list_tail(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    i = list_is_tail(list_head(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    

    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);

    return 0;
}
