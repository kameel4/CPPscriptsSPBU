
//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
void addNode(ListNode*& noda, int val){
    ListNode* newNode = new ListNode();
    newNode->val = val;
    noda->next = newNode;
}

ListNode* setHead(ListNode*& l, ListNode*& r){
        if (l->val < r->val){
            ListNode* noda = new ListNode(l->val);
            l = l->next;
            return noda;
        }else{
            ListNode* noda = new ListNode(r->val);
            r = r->next;
            return noda;
        }
}



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
}