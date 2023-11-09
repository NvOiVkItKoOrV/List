#include "list_func.h"

size_t LIST_SIZE = 50;

list_t* list_ctor()
{
    list_t* lst;
    lst = (list_t*)calloc(LIST_SIZE, sizeof(list_t));

    for(int counter = 2; counter < LIST_SIZE; counter++)
    {
        lst[counter].next = counter + 1;
        lst[counter].prev = -1;
    }
    lst[LIST_SIZE - 1].next = 0;
    lst[LIST_SIZE - 1].prev = -1;

    lst[1].next = 2;
    lst[1].prev = 0;

    lst[0].data = 1;
    lst[0].next = 1;
    lst[0].prev = 0;
    return lst;
}


void list_dtor(list_t* lst)
{
    assert(lst);

    free(lst);
    lst = nullptr;
}


void list_dump(list_t* lst)
{
    FILE* file_adress = fopen("Graph_dump.dot", "w");

    fprintf(file_adress,"digraph List {\n");
    fprintf(file_adress,"   rankdir = TB;\n");
    fprintf(file_adress,"   rankdir = LR;\n");
    fprintf(file_adress,"\n");
    fprintf(file_adress,"	 0 [shape = record, label = \" 0 | {| FREE lst[0].data | <1> TAIL lst[0].prev | <2> HEAD lst[0].next}\"];\n");

    for(int lst_counter = 1; lst_counter < LIST_SIZE; lst_counter++)
    {
        fprintf(file_adress, "	 %d [shape = record, label = \" %d | {| %d | <1> %d | <2> %d}\"];\n", lst_counter, lst_counter, lst[lst_counter].data, lst[lst_counter].next, lst[lst_counter].prev);
    }

    for(int lst_counter = 1; lst_counter < LIST_SIZE; lst_counter++)
    {
        fprintf(file_adress, "%d: <1> -> %d: <1>[color=\"green\"];\n", lst_counter, lst[lst_counter].next);
    }

    for(int lst_counter = 1; lst_counter < LIST_SIZE; lst_counter++)
    {
        if(lst[lst_counter].prev != -1)
        fprintf(file_adress, "%d: <2> -> %d: <2>[color=\"red\"];\n", lst_counter, lst[lst_counter].prev);
    }
    fprintf(file_adress,"}\n");
    fclose(file_adress);
}


void insert2end(list_t* lst, int val)
{
    assert(lst);

    if(lst[lst[0].data].next == 0)
        list_resize_up(&lst);

    int cur_elem = lst[0].prev;
    lst[cur_elem].next = lst[0].data;

    lst[0].prev = lst[0].data;

    lst[lst[0].data].prev = cur_elem;
    lst[lst[0].data].data = val;

    int new_elem = lst[lst[0].data].next;
    lst[lst[0].data].next = 0;
    lst[0].data = new_elem;
}


void insert_between_elements(list_t* lst, int pos, int val)
{
    assert(lst);

    if(lst[lst[0].data].next == 0)
        list_resize_up(&lst);

    if(lst[pos].prev == -1)
    {
        printf("Went from the list!!!\n");
        exit(0);
    }

    int prev_for_new_elem = lst[pos].prev;
    lst[pos].prev = lst[0].data;
    lst[prev_for_new_elem].next = lst[0].data;


    lst[0].data = lst[lst[prev_for_new_elem].next].next;

    lst[lst[prev_for_new_elem].next].prev = prev_for_new_elem;
    lst[lst[prev_for_new_elem].next].next = pos;
    lst[lst[prev_for_new_elem].next].data = val;

}


void rm_elem_from_spec_pos(list_t* lst, int pos)
{
    assert(lst);

    int elem_before_cur = lst[pos].prev;
    int elem_after_cur  = lst[pos].next;

    lst[elem_before_cur].next = elem_after_cur;
    lst[elem_after_cur].prev = elem_before_cur;

    lst[pos].prev = -1;
    lst[pos].next = lst[0].data;
    lst[0].data = pos;
}


void list_resize_up(list_t** lst)
{
    assert(lst);
    assert(*lst);

    int list_old_sz = LIST_SIZE;
    LIST_SIZE *= 2;

    *lst = (list_t*)realloc(*lst, LIST_SIZE * sizeof(list_t));

    for(int counter = list_old_sz - 1; counter < LIST_SIZE - 1; counter++)
    {
        (*lst)[counter].next = counter + 1;
        (*lst)[counter].prev = -1;
    }
    (*lst)[LIST_SIZE - 1].next = 0;
    (*lst)[LIST_SIZE - 1].prev = -1;

}
