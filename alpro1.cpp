#include <iostream>
using namespace std;



class Searching{
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

    void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {          // Loop untuk setiap elemen
        int minIndex = i;                    // Asumsikan elemen terkecil adalah elemen ke-i
        for (int j = i+1; j < n; j++) {     // Cari elemen terkecil dari sisa array
            if (arr[j] < arr[minIndex]) {
                minIndex = j;               // Update indeks elemen terkecil
            }
        }
        if (minIndex != i) {                 // Jika elemen terkecil bukan elemen ke-i
            cout << "   Tukar " << arr[i] << " dan " << arr[minIndex] << ": ";
            swap(arr[i], arr[minIndex]);     // Tukar elemen menggunakan swap bawaan
            printArray(arr, n);             // Tampilkan array setelah penukaran
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
   int arr[] = {10,9,8,6,7,3,5,2,1,4};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 1;

   Searching obj;

   cout << "Array sebelum diurutkan: ";
  obj.printArray(arr, n);  // Tampilkan array sebelum diurutkan

   cout << "\nProses Selection Sort ASC:\n";
  obj.selectionSort(arr, n);  // Panggil fungsi Selection Sort

   cout << "\nArray setelah diurutkan: ";
   obj.printArray(arr, n);  // Tampilkan array setelah diurutkan
   int result =obj.binarySearch(arr, 0, n - 1, x);
   if(result == -1) {
      cout << "Element not found in the array" << endl;
   }
   return 0;
}
