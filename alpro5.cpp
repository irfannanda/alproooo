#include <iostream>
#include <utility>  // Untuk menggunakan fungsi swap bawaan
using namespace std;

// Fungsi prosedur untuk menampilkan array
class book {
    public:
     int publicAttribute; // variabel
        void publicMethod() { // fungsi atau prosedur
            // Dapat mengakses publicAttribute di sini karena berada dalam kelas yang sama
            publicAttribute = 10;
            cout<<publicAttribute;
        }
    void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Cetak setiap elemen array
    }
    cout << endl;
}

        // Fungsi prosedur untuk melakukan Bubble Sort dan menampilkan step perpindahan
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {          // Loop untuk setiap elemen
        cout << "Langkah " << i+1 << ":" << endl;
        for (int j = 0; j < n-i-1; j++) {    // Loop untuk membandingkan elemen
            if (arr[j] > arr[j+1]) {         // Jika elemen saat ini lebih besar dari elemen berikutnya
                cout << "   Tukar " << arr[j] << " dan " << arr[j+1] << ": ";
                swap(arr[j], arr[j+1]);      // Tukar elemen menggunakan swap bawaan
                printArray(arr, n);         // Tampilkan array setelah penukaran
            }
        }
    }
}int binarySearch(int arr[], int l, int r, int x) {
   while(l <= r) {  // 0 <= 9
      int mid = l + (r - l) / 2; // 0 + (9-0) / 2  = 4
      if(arr[mid] == x) {
         cout << "Element found at index " << mid << endl;
         return mid;
      }
      else if(arr[mid] < x) { // 4 < 7
         cout << "Checking right half of the array." << endl;
         l = mid + 1;
      }
      else {
         cout << "Checking left half of the array." << endl;
         r = mid - 1;
      }
   }
   return -1;
}
    };

   

int main() {
      int arr[] = {100,450,200,150,103,600};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 100;
   
   book obj;

    
    cout << "Array sebelum diurutkan: ";
    obj.printArray(arr, n);  // Tampilkan array sebelum diurutkan

    cout << "\nProses Bubble Sort ASC:\n";
    obj.bubbleSort(arr, n);  // Panggil fungsi Bubble Sort

    cout << "\nArray setelah diurutkan: ";
     obj.printArray(arr, n);  // Tampilkan array setelah diurutkan

   int result = obj.binarySearch(arr, 0, n - 1, x);
   if(result == -1) {
      cout << "Element not found in the array" << endl;
   }

   return 0;
}