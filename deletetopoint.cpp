#include <iostream>

using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    cout << "Informasi tentang setiap node:" << endl;
    while (temp != nullptr) {
        cout << temp->data << "<->" ;
        temp = temp->next;
    }
    cout << endl;
}

void insertLast(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode; // Jika linked list kosong, node baru menjadi head
    } else {
        Node* temp = head;
        // Mencari posisi terakhir dalam linked list
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Menyisipkan node baru setelah posisi terakhir
        temp->next = newNode; // Mengatur next dari posisi terakhir menjadi node baru
        newNode->prev = temp; // Mengatur prev dari node baru
         // Menampilkan informasi tentang setiap node dalam linked list
    }

}void deleteToPoint(Node* head, int valueTodeleteToPoint) {
    // Jika linked list kosong
    if (head == nullptr) {
        cout << "Linked list kosong, tidak ada yang dihapus" << endl;
        return;
    }

    Node* temp = head;

    // Mencari node dengan nilai yang sesuai
    while (temp != nullptr && temp->data != valueTodeleteToPoint) {
        temp = temp->next;
    }



    cout << temp->data << endl;

    if (temp == nullptr){
        cout << "Data" << valueTodeleteToPoint << "tidak ditemukan" ;
        return;
    }

    if(temp == head){
        head = temp->next;

        if(head != nullptr){
            head->prev = nullptr;
        }
    } else {
        temp->prev->next = temp->next;

        if(temp->next != nullptr){
            temp->next->prev = temp->prev;
        }
    }

    delete temp;



}

int main (){
    Node* head = nullptr;
    insertLast(head, 8);
    insertLast(head, 2);
    insertLast(head, 4);
    insertLast(head, 1);
    displayList(head);
    deleteToPoint(head,4);
    displayList(head);

    return 0;
}