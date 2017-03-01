#include "linked_list.h"


unsigned length(linked_list* lst)
{
    unsigned result = 0;

    while (lst != nullptr)
    {
        lst = (*lst).next;
        ++result;
    }

    return result;
}

bool has_cycle(linked_list* lst)
{
    if (lst == nullptr)
    {
        return false;
    }
    else
    {
        linked_list* turtle = lst;
        linked_list* hare = (*lst).next;

        while (turtle != hare)
        {
            if (hare == nullptr || hare->next == nullptr)
            {
                return false;
            }
            else
            {
                turtle = (*turtle).next;
                hare = (*(*hare).next).next;
            }
        }

        return true;
    }
}
