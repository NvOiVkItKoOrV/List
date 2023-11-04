#ifndef LIST_FUNC_H
#define LIST_FUNC_H

#include <stdio.h>
#include <stdlib.h>

struct list_t
{
    int data;
    int next;
    int prev;

};


enum list_err
{
    LIST_NULL_PTR,
    DATA_NULL_PTR,
    NEXT_NULL_PTR,
    PREV_NULL_PTR
};

void list_dump(list_t* lst);
list_t* list_ctor();
void list_dtor(list_t* lst);
void insert2end(list_t* lst, int val);
void insert_between_elements(list_t* lst, int pos, int val);
void rm_elem_from_spec_pos(list_t* lst, int pos);
void list_resize_up(list_t** lst);

#endif /* LIST_FUNC_H */
