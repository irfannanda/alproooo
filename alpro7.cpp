#include<iostream>
using namespace std;

class parkir{
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
//mencari suatu index di array yang sudah terurut
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
parkir obj;
int parkir ;    
int panjang_array;
cout << "data :" << endl;
cin >> panjang_array;


int durasi_parkir[panjang_array] = {};

for (int i = 0; i < panjang_array; i++) {
    cout << "masukkan durasi parkir awal" << i + 1 << ": ";
    cin >> durasi_parkir[i] ;
}

obj.cetakArray (durasi_parkir,panjang_array);
obj.shorting (durasi_parkir,panjang_array);

cout << "hasil " ;
obj.cetakArray(durasi_parkir,panjang_array);

cout << endl;
cout << "mau mencari durasi waktu berapa" << endl;
cin >> parkir;

int hasil = obj.CariJumlahData (durasi_parkir,0, panjang_array -1 ,parkir);

if(hasil == -1){
    cout << " tidak ada " <<endl;
}else{
    cout << " yang parkir dengan durasi pendek adalah " << parkir << " jumlah kendaraan : " << hasil;
}




return 0;
}