//
// Created by yanni on 2019/6/21.
//

#ifndef CPP1_LEET1_H
#define CPP1_LEET1_H

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Leet1 {
public:
    ListNode* reverseList(ListNode* head) ;
};


#endif //CPP1_LEET1_H
