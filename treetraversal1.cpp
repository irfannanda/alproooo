#include <iostream>
using namespace std;

struct ListNode {
    char val;
    ListNode* prev;  // anak kiri
    ListNode* next;  // anak kanan

    ListNode(char x) : val(x), prev(nullptr), next(nullptr) {}
};

// ─── QUEUE sederhana tanpa library ────────────────────────────────────────
// BFS butuh queue, tapi kita buat manual pakai array
struct Queue {
    ListNode* data[100];
    int front;
    int rear;

    Queue() : front(0), rear(0) {}

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(ListNode* node) {
        data[rear++] = node;
    }

    ListNode* dequeue() {
        return data[front++];
    }
};

class traversal {
private:
    void bfs(ListNode* root) {
    if (root == nullptr) return;

    Queue q;
    q.enqueue(root);           // mulai dari root

    int level = 0;

    while (!q.isEmpty()) {
        // hitung berapa node di level sekarang
        int nodeCount = q.rear - q.front;

        cout << "Level " << level << " : ";

        // proses semua node di level ini
        for (int i = 0; i < nodeCount; i++) {
            ListNode* current = q.dequeue();
            cout << current->val << " ";

            // masukkan anak-anak ke queue untuk level berikutnya
            if (current->prev != nullptr) q.enqueue(current->prev);
            if (current->next != nullptr) q.enqueue(current->next);
        }

        cout << endl;
        level++;
    }
}

// ─── PREORDER : Root → Kiri → Kanan ──────────────────────────────────────
void preorder(ListNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    preorder(node->prev);
    preorder(node->next);
}

// ─── INORDER : Kiri → Root → Kanan ───────────────────────────────────────
void inorder(ListNode* node) {
    if (node == nullptr) return;
    inorder(node->prev);
    cout << node->val << " ";
    inorder(node->next);
}

// ─── POSTORDER : Kiri → Kanan → Root ─────────────────────────────────────
void postorder(ListNode* node) {
    if (node == nullptr) return;
    postorder(node->prev);
    postorder(node->next);
    cout << node->val << " ";
}

    

public:
  void tree (ListNode* root) {
    bfs (root);
  }

  
  void preO(ListNode* root){
    preorder(root);
  }

   void InO(ListNode* root){
    inorder(root);
  }

  void postO(ListNode* root){
    postorder(root);
  }
    
};

int main() {
    traversal tr;
    /*
     * Struktur tree yang dibangun manual:
     *
     *         H              <- Level 0 (root)
     *        / \
     *       A   K            <- Level 1
     *        \
     *         C              <- Level 2 (leaf)
     */

    ListNode* head       = new ListNode('H');
    head->prev           = new ListNode('A');
    head->next           = new ListNode('K');
    head->prev->next     = new ListNode('C');

    cout << "=== Struktur Tree ===" << endl;
    cout << "Root            : " << head->val             << endl;
    cout << "Child kiri  (A) : " << head->prev->val       << endl;
    cout << "Child kanan (K) : " << head->next->val       << endl;
    cout << "Leaf        (C) : " << head->prev->next->val << endl;

    cout << "\n=== Traversal ===" << endl;

    cout << "Preorder  (Root-L-R) : ";
    tr.preO(head);   // H A C K
    cout << endl;

    cout << "Inorder   (L-Root-R) : ";
    tr.InO(head);    // A C H K
    cout << endl;

    cout << "Postorder (L-R-Root) : ";
    tr.postO(head);  // C A K H
    cout << endl;

    cout << "\n=== BFS / Level Order ===" << endl;
    tr.tree(head);
    /*
     * Level 0 : H
     * Level 1 : A K
     * Level 2 : C
     */

    // Bebaskan memori
    delete head->prev->next;
    delete head->prev;
    delete head->next;
    delete head;

    return 0;
}

