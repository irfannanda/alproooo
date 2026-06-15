#include <iostream>
using namespace std;

struct ListNode {
    char val;
    ListNode* prev;
    ListNode* next;

    ListNode(char x) : val(x), prev(nullptr), next(nullptr) {}
};


int main() {
    ListNode* head = new ListNode('A'); //root
    head->prev = new ListNode('B'); //Sibling left
    head->prev->prev = new ListNode('D'); //Children B
    head->prev->prev->next = new ListNode('G'); //Children D

    head->next = new ListNode('C'); //Sibling right
    head->next->prev = new ListNode('E'); //Children C
    head->next->next = new ListNode('F'); //Children C
    head->next->prev->next = new ListNode('I'); //Children E
    head->next->prev->prev = new ListNode('H'); //Children E
 



    cout<< "root : "<< head->val << endl;
    cout<< "Parent 1 (left) : "<< head->prev->val << endl;
    cout<< "Children B (left) : "<< head->prev->prev->val << endl;
    cout<< "Children D (right) : "<< head->prev->prev->next->val << endl;

    cout<< "Parent 2 (right) : "<< head->next->val << endl;
    cout<< "Children C (left) : "<< head->next->prev->val << endl;
    cout<< "Children C (right) : "<< head->next->next->val << endl;
    cout<< "Children E (right) : "<< head->next->prev->next->val << endl;
    cout<< "Children E (left) : "<< head->next->prev->prev->val << endl;

    return 0;
}