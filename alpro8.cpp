#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    cout << "Linked list: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* linearSearch(Node* head, int x) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << "Checking: " << temp->data << endl;
        if (temp->data == x) {
            cout << "Data ditemukan: " << temp->data << endl;
            return temp;
        }
        temp = temp->next;
    }

    cout << "Data tidak ditemukan.\n";
    return nullptr;
}

void deleteByValue(Node*& head, int value) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Data berhasil dihapus.\n";
}

int main() {
    
    Node* head = new Node;
    head->data = 100;
    head->next = new Node;
    head->next->data = 84;
    head->next->next = new Node;
    head->next->next->data = 70;
    head->next->next->next = nullptr;

    
    cout << "Linked list sebelum penghapusan:\n";
    printList(head);

    
    int x;
    cout << "\nMasukkan data yang ingin dihapus: ";
    cin >> x;

    
    Node* found = linearSearch(head, x);

    
    if (found != nullptr) {
        deleteByValue(head, x);
    }

    
    cout << "\nLinked list setelah penghapusan:\n";
    printList(head);

    return 0;
}