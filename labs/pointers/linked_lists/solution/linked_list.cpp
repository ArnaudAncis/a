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

linked_list* penultimate(linked_list* lst)
{
    if (lst == nullptr || (*lst).next == nullptr)
    {
        return nullptr;
    }
    else
    {
        linked_list* p = lst;
        linked_list* q = (*lst).next;

        while ((*q).next != nullptr)
        {
            p = (*p).next;
            q = (*q).next;
        }

        return p;
    }
}

// linked_list* longest()

void make_cyclic(linked_list* lst)
{
    linked_list* head = lst;

    while ((*lst).next != nullptr)
    {
        lst = (*lst).next;
    }

    (*lst).next = head;
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
