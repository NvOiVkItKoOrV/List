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
    free(lst);
    lst = nullptr;
}


void list_dump(list_t* lst)
{
    printf("-------------------\n");
    printf("list head - <%d>\n", lst[0].next);
    printf("list tail - <%d>\n", lst[0].prev);
    printf("list free - <%d>\n", lst[0].data);
    printf("-------------------\n");

    for(int lst_counter = 0; lst_counter < LIST_SIZE; lst_counter++)
    {
        printf("%-7.d     ", lst_counter);
        printf("\033[0;33m data value - %-7.d \033[0;37m", lst[lst_counter].data);
        printf("\033[0;32m next value - %-7.d \033[0;37m", lst[lst_counter].next);
        printf("\033[0;31m prev value - %-7.d\n \033[0;37m", lst[lst_counter].prev);
    }
}


void insert2end(list_t* lst, int val)
{
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
