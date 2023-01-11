#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct list_node {
    int data;
    struct list_node* next;
}

struct linked_list {
    struct list_node* root_ptr;
    unsigned int len;
}

struct linked_list* linked_list_new() {
    struct linked_list* new_list;
    new_list = (struct linked_list*) malloc(sizeof(struct linked_list));
    return new_list;
}

struct linked_list* linked_list_from(int* values, int n) {
    struct linked_list* res;
    res = linked_list_new();
    struct linked_list* tmp = res->root_ptr;
    for (int i = 0; i < n; i++) {
        tmp->data = values[i];
        tmp = tmp->next;
        res->len++;
    }
    
    return res;
}

unsigned int linked_list_len(struct linked_list* lst) {
    if (lst != NULL) {
        return lst->len;
    }
    
    return 0;
}
