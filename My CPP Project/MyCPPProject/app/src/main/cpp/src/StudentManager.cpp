//
// Created by ACER on 13/02/2025.
//
#include "../includes/StudentManager.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <ostream>

using namespace std;

void StudentManager::tambahMahasiswa(const char* nama, int nim, float ipk, float nilai[]) {
    if(jumlahMahasiswa < 100) {
        strcpy(mahasiswaList[jumlahMahasiswa].nama, nama);
        mahasiswaList[jumlahMahasiswa].nim = nim;
        mahasiswaList[jumlahMahasiswa].ipk = ipk;

        for (int i = 0; i < 5; i++) {
            mahasiswaList[jumlahMahasiswa].nilaiMataKuliah[i] = nilai[i];
        }

        jumlahMahasiswa++;
    }
}

string StudentManager::tampilkanMahasiswa() {
    ostringstream output;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        output  << "Nama   : " << mahasiswaList[i].nama
                << ", NIM   : " << mahasiswaList[i].nim
                << ", IPK   : " << mahasiswaList[i].ipk << endl;
    }

    return output.str();
}

void StudentManager::sortingMahasiswa() {
    for (int i = 0; i < jumlahMahasiswa - 1; i++) {
        for (int j = 0; j < jumlahMahasiswa - 1; j++) {
            if (mahasiswaList[j].ipk < mahasiswaList[j + 1].ipk) {
                swap(mahasiswaList[j], mahasiswaList[j + 1]);
            }
        }
    }
}

int StudentManager::cariMahasiswaRekursif(int left, int right, int nim) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    if (mahasiswaList[mid].nim == nim) return mid;
    if (mahasiswaList[mid].nim > nim) return cariMahasiswaRekursif(left, mid - 1, nim);
    return cariMahasiswaRekursif(mid + 1, right, nim);
}

string StudentManager::searchingMahasiswa(int nim){
    int index = cariMahasiswaRekursif(0, jumlahMahasiswa - 1, nim);
    if (index != -1) {
        ostringstream output;
        output  << "Nama    : " << mahasiswaList[index].nama
                << ", NIM   : " << mahasiswaList[index].nim
                << ", IPK   : " << mahasiswaList[index].ipk;
        return output.str();
    }
    return "Mahasiswa tidak ditemukan";
}

void StudentManager::simpanKeFile(){
    ofstream file("mahasiswa.txt");
    for (int i = 0; i < jumlahMahasiswa; i++) {
        file << mahasiswaList[i].nama << " " << mahasiswaList[i].ipk;
    }

    file.close();
}

void StudentManager::bacaDariFile(){
    ifstream file("mahasiswa.txt");
    jumlahMahasiswa = 0;
    while (file >> mahasiswaList[jumlahMahasiswa].nama
                >> mahasiswaList[jumlahMahasiswa].nim
                >> mahasiswaList[jumlahMahasiswa].ipk
                ){
        jumlahMahasiswa++;
    }

    file.close();
}





