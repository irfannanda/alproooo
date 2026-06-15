#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;

    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};


int main() {

    ListNode* head = new ListNode(29); //root

    head->prev = new ListNode(19); //Sibling left
    head->prev->prev = new ListNode(7); //Children B
    head->prev->next = new ListNode(24); //Children B
    head->next = new ListNode(45); //Sibling right

    head->prev->prev->next = new ListNode(16); //Children D
    head->next->prev = new ListNode(31); //Children C
 

    cout<< "root : "<< head->val << endl;
    cout << endl;
    // Left
    cout<< "Parent 1 (left) : "<< head->prev->val << endl;
    cout<< "Children 2 (left) : "<< head->prev->prev->val << endl;
    cout<< "Children 1 (left) : "<< head->prev->next->val << endl;
    cout<< "Leaf 1 (right) : "<< head->prev->prev->next->val << endl;
    cout << endl;
    // Right
    cout<< "Parent 2 (right) : "<< head->next->val << endl;
    cout<< "Children 1 (left) : "<< head->next->prev->val << endl;

    return 0;
}