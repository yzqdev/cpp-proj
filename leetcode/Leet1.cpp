//
// Created by yanni on 2019/6/21.
//
#include <iostream>
using  namespace std;
#include "Leet1.h"
ListNode* reverseList(ListNode* head)
{
    if(NULL == head || NULL == head->next)
        return head;
    ListNode * p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return p;
}