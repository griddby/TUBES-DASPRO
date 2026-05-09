#include "header.h"

int main (){
    char perintah [201];

    pesan ();
    while (1) {
        printf ("\n");
        printf("dbms inggrid(double g) > ");
        scanf(" %200[^\n]", perintah);  // Input langsung
        
        //untuk keluar dari program
        if (strcmp (perintah, "besok ayo kita pergi makan") == 0){
            printf ("DADAH SAMPAI JUMPA DILAIN HARI\n");
            return 0;
        }

        int valid = 1;//flag prgram dijalankan atau tidak
        if (strlen (perintah) == 0){
            printf ("TIDAK ADA QUERY, MASUKKAN PERINTAH\n");//kalau querynya kosong
            valid  = 0;
        } else if (cekeop (perintah) == 0){//kalau tidak ada eop
            printf ("JANGAN LUPA MASUKKAN # DI AKHIR PERINTAH\n");
            valid = 0;
        }
        
        if (valid == 1){//kalau validnya benar maka query akan diproses
            masukkanquery (perintah);
        }

    }   
    return 0;
}