#include <iostream>
using namespace std;

struct ListNode {
    char val;
    ListNode* prev;
    ListNode* next;

    ListNode(char x) : val(x), prev(nullptr), next(nullptr) {}
};

int main() {
    
    ListNode* root = new ListNode('A');
    
    root->prev = new ListNode('B');   // child left A
    root->next = new ListNode('C');   // child right A
    root->prev->prev = new ListNode('D');  // child left B
    root->prev->next = new ListNode('E');  // child right B
    root->next->prev = new ListNode('F');  // child left C
    root->next->next = new ListNode('G');  // child right C
    root->prev->next->prev = new ListNode('H');  // child left E
    root->next->prev->prev = new ListNode('I');  // child left F


    cout << "root               : " << root->val << endl;

    cout << "child kiri  (B)    : " << root->prev->val << endl;
    cout << "child kanan (C)    : " << root->next->val << endl;
    cout << "child kiri  B (D)  : " << root->prev->prev->val << endl;
    cout << "child kanan B (E)  : " << root->prev->next->val << endl;
    cout << "child kiri  C (F)  : " << root->next->prev->val << endl;
    cout << "child kanan C (G)  : " << root->next->next->val << endl;
    cout << "child kiri  E (H)  : " << root->prev->next->prev->val << endl;
    cout << "child kiri  F (I)  : " << root->next->prev->prev->val << endl;

    return 0;
}