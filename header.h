#include <stdio.h>
#include <string.h>

/*
    Saya Ingrid Gabryella Nainggolan  dengan NIM 2506442  sebagai manusia yang berTuhan, saya mengerjakan evaluasi Tugas Masa Depan 
    dalam mata kuliah Dasar-dasar Pemrograman untuk keberkahanNya maka saya 
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

extern int idx;//index
extern int wlen;//panjang kata
extern char cw[100];//current word

//variabel pada tabel pertama
typedef struct {
    char nim [100];//variabel nim
    char nama [100];//variabel nama
    char kodeS [100];//variabel kode skill
    char skill [100];//varibael skill
    char deskripsi [100];//variabel deskripsi
}tskill;

//variabel pada tabel kedua
typedef struct {
    char nim [100];//variabel nim
    char kodeP [100];//variabel kode pelatihan
    char pelatihan [100];//variabel tempat pelatihan
}tpelatihan;

//variabel pada tabel kedua
typedef struct {
    char nim [100];//variabel nim
    char kodeL [100];//variabel kode lomba
    char lomba [100];//variable loma yang diikuti
    char prestasi [100];//variabel prestasi
}tlomba;

//untuk mesin kata
int eop (char pita[]);
void start (char pita[]);
void reset ();
void inc (char pita[]);
char* getcw ();
int getlen ();

//membaca file
void writeskill (int n, tskill sumber[], char namafile[]);
void writepelatihan (int n, tpelatihan sumber[], char namafile[]);
void writelomba (int n, tlomba sumber[], char namafile[]);

//menulis file
void readskill (int *n, tskill sumber[], char namafile[]);
void readpelatihan (int *n, tpelatihan sumber[], char namafile[]);
void readlomba (int *n, tlomba sumber[], char namafile[]);

//menghapus data pada tabel
void deleteskill ();
void deletepelatihan ();
void deletelomba ();

//memasukkan data pada tabel
void insertskill ();
void insertpelatihan ();
void insertlomba ();

//mengubah data yang ada pada tabel
void updateskill ();
void updatepelatihan ();
void updatelomba ();

//mengecek eop dan query
int cekeop (char pita[]);
void masukkanquery (char pita []);
void pesan ();