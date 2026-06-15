#include<iostream>
using namespace std;

class buku{
    private:
    void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Cetak setiap elemen array
    }
    cout << endl;
}
int binarySearch(int arr[], int l, int r, int x) {
   while(l <= r) {  // 0 <= 9
      int mid = l + (r - l) / 2; // 0 + (9-0) / 2  = 4
      if(arr[mid] == x) {
        int count = 0;
//mencari satu index di array yang sudah terurut
        //cek kiri
        int i = mid;
        while (i>=0 && arr[i]==x){
        cout << " ketemu di index : " << i << endl;
        count++;
        i--;
        }

        //cek kanan
        int j = mid + 1;
        while (j <= r && arr[j]== x){
            cout << " ketemu di index : " << j << endl;
            count++;
            j++;
        }

        return count;
      
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
}

public:
void cetakArray (int arr[], int n){
    printArray(arr,n);
}

void shorting (int arr[], int n){
    bubbleSort(arr,n);
}

int CariJumlahData(int arr[], int l, int r, int x){
    return binarySearch(arr, l, r, x);
}


};



int main(){
buku obj;
int buku ;    
int panjang_array;
cout << "data :" << endl;
cin >> panjang_array;


int halaman_buku[panjang_array] = {};

for (int i = 0; i < panjang_array; i++) {
    cout << "masukkan jumlah halaman buku" << i + 1 << ": ";
    cin >> halaman_buku[i] ;
}

obj.cetakArray (halaman_buku,panjang_array);
obj.shorting (halaman_buku,panjang_array);

cout << "hasil " ;
obj.cetakArray(halaman_buku,panjang_array);

cout << endl;
cout << "mau mencari halaman berapa : " << endl;
cin >> buku;

int hasil = obj.CariJumlahData (halaman_buku,0, panjang_array -1 ,buku);

if(hasil == -1){
    cout << "Halaman buku tidak tersedia" <<endl;
}else{
    cout << " halaman " << buku << " ada : " << hasil;
}




return 0;
}