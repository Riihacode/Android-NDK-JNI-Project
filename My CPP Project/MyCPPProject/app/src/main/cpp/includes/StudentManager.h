#ifndef MY_CPP_PROJECT_STUDENTMANAGER_H
#define MY_CPP_PROJECT_STUDENTMANAGER_H

#include <string>
using namespace std;

struct Mahasiswa {
    char nama[50];
    int nim;
    float ipk;
    float nilaiMataKuliah[5];  // Menyimpan nilai 5 mata kuliah
};

class StudentManager {
public:
    Mahasiswa mahasiswaList[100];
    int jumlahMahasiswa = 0;

    void tambahMahasiswa(const char* nama, int nim, float ipk, float nilai[]);
    string tampilkanMahasiswa();
    void sortingMahasiswa();
    int cariMahasiswaRekursif(int left, int right, int nim);
    string searchingMahasiswa(int nim);
    void simpanKeFile();
    void bacaDariFile();
};

#endif //MY_CPP_PROJECT_STUDENTMANAGER_H
