#include "list_func.h"

int main()
{
    list_t* lst = list_ctor();
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);
    rm_elem_from_spec_pos(lst, 2);
        insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 3);
    /*insert_between_elements(lst, 3, 17);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);
    insert2end(lst, 1);*/
    printf("<%d>",sizeof(*lst));
    list_dump(lst);
    list_dtor(lst);
    return 0;
}
