#include <iostream>
using namespace std;

struct ListNode {
    char val;
    
    ListNode* prev;
    ListNode* next;

    ListNode(char x) : val(x), prev(nullptr), next(nullptr) {}
};

int main() {
    ListNode* head = new ListNode('H'); //root
    head->prev = new ListNode('A'); //child left
    head->next = new ListNode('K'); //child right
    head->prev->next = new ListNode('C'); //right child of A
    head->prev->next->prev = new ListNode('B'); //left child of A
    head->next->prev = new ListNode('J'); //left child of K
    head->next->next = new ListNode('L'); //right child of K

    cout<< "root : "<< head->val << endl;
    cout<< "child 1 (left) : "<< head->prev->val << endl;
    cout<< "child 2 (right) : "<< head->next->val << endl;
    cout<< "leaf kiri 1 : "<< head->prev->next->val << endl;
    cout<< "leaf kiri 2 : "<< head->prev->next->prev->val << endl;
    cout<< "leaf kanan 1 : "<< head->next->prev->val << endl;
    cout<< "leaf kanan 2 : "<< head->next->next->val << endl;

    return 0;
}