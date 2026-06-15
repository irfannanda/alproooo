#include <iostream>
using namespace std;

struct data {
    string makanan;
    data*next;
};


void printList(data* head) {
    cout << "Linked list: ";
    data* prev = head;
    while (prev != nullptr) {
            cout << prev->makanan << "->"; // Mencetak data node
            prev = prev-> next; // Pindah ke node selanjutnya
    }
    cout << endl;
}

int Search(data* head, string makanan){
    data* current = head;
    int i = 1;
    while (current != nullptr){
        if (current->makanan == makanan) {
            return i;
        }
        current = current->next;
        i++;
    }
    return -1;
}
void deleteData(data*& head, int posisi) {
    data* temp = head;

    //Jika hapus node pertama
    if(posisi == 1){
        cout << "Anda menghapus Node: " << posisi << endl;
        cout << "Hapus menggunakan Delete First" << endl;
        cout << endl;
        head = head->next;
        delete temp;
        return;
    }

    //Jika cari node sebelum posisi
    for(int i = 1; temp != nullptr && i < posisi - 1; i++) {
        temp = temp->next;
    }

    cout << "Anda menghapus Node: " << posisi << endl;
    cout << "Hapus menggunakan Delete After" << endl;
    cout << endl;

    data* nodeHapus = temp->next;
    temp->next = nodeHapus->next;

    delete nodeHapus;
}

int main (){
    string hapusdata;
    int posisi;

    data* head = new data;
    head->makanan = "lontong";
    head->next = new data;
    head->next->makanan = "naspad";
    head->next->next = new data;
    head->next->next->makanan = "soto";
    head->next->next->next = nullptr;

    printList(head);

    cout << " masukan makanan yang ingin diblacklist "; cin >> hapusdata ;
    cout << endl;
    cout << " makanan yang telah diblacklist : " << hapusdata << endl;

    posisi =  Search(head, hapusdata);

    if(Search(head, hapusdata) == -1){
        cout << " makanan tidak tersedia bang" << endl;
    }else{
        deleteData(head, posisi);
    }

    cout << " makanan yang tersedia " << endl;
    printList(head);


    
}

