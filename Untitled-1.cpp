#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* doubleIt(ListNode* head) {
    ListNode* pointer = head;
    ListNode newHead(1, head);
    ListNode* myptr = &newHead;
    int check = 0;
    if (head->val * 2 >= 10)
    {
        check = 1;
    }
    
    while (pointer->next != nullptr)
    {
        if (pointer->next->val * 2 >= 10)
        {
            pointer->val = (pointer->val * 2 + 1)%10;
        }
        else
        {
            pointer->val = (pointer->val*2)%10;
        }
        pointer = pointer->next;
    }
    pointer->val = (pointer->val*2)%10;

    if (check == 1)
    {
        return myptr;
    }
    
    return head;

}

int main()
{
    ListNode third(7, nullptr);
    ListNode second(3, &third);
    ListNode first(7, &second);
    
    ListNode* t = doubleIt(&first);
    ListNode* mpointer = t;

    while (mpointer->next != nullptr)
    {
        cout << mpointer->val;
        mpointer = mpointer->next;
    }
    

    return 0;
}