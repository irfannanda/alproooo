#include <iostream>

using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Fungsi membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi insert di awal
void insertFirst(Node*& head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Fungsi insert BEFORE
void insertBefore(Node*& head, int valueToInsertBefore, int data) {

    // Mulai pencarian dari head
    Node* current = head;

    // Cari node target
    while (current != nullptr && current->data != valueToInsertBefore) {
        current = current->next;
    }

    // Jika tidak ditemukan
    if (current == nullptr) {
        cout << "Node dengan nilai "
             << valueToInsertBefore
             << " tidak ditemukan" << endl;
        return;
    }

    // Buat node baru
    Node* newNode = createNode(data);

    // Jika insert sebelum head
    if (current == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        // Hubungkan node baru
        newNode->next = current;
        newNode->prev = current->prev;

        // Update node sebelumnya
        current->prev->next = newNode;

        // Update prev current
        current->prev = newNode;
    }
}

// Fungsi display
void displayList(Node* head) {
    Node* current = head;

    cout << "Informasi tentang setiap node:" << endl;

    while (current != nullptr) {
        cout << "Alamat: " << current << endl;
        cout << "Nilai: " << current->data << endl;
        cout << "Alamat prev: " << current->prev << endl;
        cout << "Alamat next: " << current->next << endl << endl;

        current = current->next;
    }

    cout << "---------------------------------------" << endl;
}

int main() {

    Node* head = nullptr;

    // Node pertama
    head = createNode(5);
    displayList(head);

    // Tambah di depan
    insertFirst(head, 7);
    displayList(head);

    // Insert BEFORE angka 5
    insertBefore(head, 5, 8);

    // Tampilkan hasil
    displayList(head);

    return 0;
}