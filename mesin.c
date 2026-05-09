#include "header.h"

int idx;
int wlen;
char cw[100];

//berhenti pada saat ketemu eop
int eop (char pita[]){
    if (pita [idx] == '#'){
        return 1;
    } else {
        return 0;
    }
}

//memulai proeses membaca query dengan mesin kata
void start (char pita[]){
    idx = 0;
    wlen = 0;

    while (pita[idx] == ' '){
        idx++;
    }

    while ((pita[idx] != ' ') && (eop (pita) == 0)){
        cw[wlen] = pita[idx];
        wlen++;
        idx++;
    }
    cw[wlen] = '\0';
}

//mereset dari kata sekarang menjadi tidak ada apa pun
void reset (){
    wlen = 0;
    cw[wlen] = '\0';
}

//melanjutkan ke kata sebelumnya dan melewati spasi
void inc (char pita[]){
    wlen = 0;

    while (pita[idx] == ' '){
        idx++;
    }

    while ((pita[idx] != ' ') && (eop (pita) == 0)){
        cw[wlen] = pita[idx];
        wlen++;
        idx++;
    }
    cw[wlen] = '\0';
}

//untuk mendapatkan kata sekarang
char* getcw (){
    return cw;
}

//untuk mendapatkan panjang kata sekarang
int getlen (){
    return wlen;
}

//sebagai pesan saat dbms muali dijalankan
void pesan (){
    printf("=================================================\n");
    printf("||  ||     ||||||    |||||||    ||||||||    |||||||\n");
    printf("||  ||   ||      ||  ||     ||  ||      ||  ||     \n");
    printf("||||||   ||      ||  |||||||    ||||||||    |||||||\n");
    printf("||  ||   ||      ||  ||   ||    ||      ||       ||\n");
    printf("||  ||     ||||||    ||    ||   ||      ||  |||||||\n");
    printf("=================================================\n");
    printf ("----------------------------------------------------------------------\n");
    printf ("-------SELAMAT DATANG DI PROGRAM MENCARI MAHASISWA YANG TERBAIK-------\n");
    printf ("----------------------------------------------------------------------\n");
    printf ("\n");
    printf ("GUIDE  :\n");
    printf ("INPUT  :MEMASUKKAN DATA BARU\n");
    printf ("UPDATE :MEMPERBAIKI DATA YANG SUDAH ADA\n");
    printf ("DELETE :MENGHAPUS DATA YANG SUDAH ADA\n");
    printf ("SHOW   :MENAMPILKAN DATA\n");
    printf ("\n");
    printf ("SILAHKAN MEMASUKKAN KALIMAT -besok ayao kita pergi makan- UNTUK KELUAR DARI PROGRAM\n");
    printf ("----------------------------------------------------------------------\n");
    printf ("---------------------------SELAMAT MENCOBA----------------------------\n");
    printf ("----------------------------------------------------------------------\n");
}

//untuk menulis di tabel skill
void writeskill (int n, tskill sumber[], char namafile[]){
    FILE *ftemp;
    ftemp = fopen (namafile, "w");
    
    if(ftemp == NULL){
        printf("TIDAK BISA MEMBUKA FILE %s\n", namafile);
        return;
    }
    
    for (int i = 0; i < n; i++){
        fprintf (ftemp, "%s %s %s %s %s\n", sumber[i].nim, sumber[i].nama, sumber[i].kodeS, sumber[i].skill, sumber[i].deskripsi);
    }
    fprintf (ftemp, "%s %s %s %s %s\n", "####", "####", "####", "####", "####");
    fclose (ftemp);
}

//menulis di tabel pelatihan
void writepelatihan (int n, tpelatihan sumber[], char namafile[]){
    FILE *ftemp;
    ftemp = fopen (namafile, "w");
    
    if(ftemp == NULL){
        printf("TIDAK BISA MEMBUKA FILE %s\n", namafile);
        return;
    }

    for (int i = 0; i < n; i++){
        fprintf (ftemp, "%s %s %s\n", sumber[i].nim, sumber[i].kodeP, sumber[i].pelatihan);
    }

    fprintf (ftemp, "%s %s %s\n", "####", "####", "####");
    fclose (ftemp);
}

//menulis di tabel lomba
void writelomba (int n, tlomba sumber[], char namafile[]){
    FILE *ftemp;
    ftemp = fopen (namafile, "w");
    
    if(ftemp == NULL){
        printf("TIDAK BISA MEMBUKA FILE %s\n", namafile);
        return;
    }

    for (int i = 0; i < n; i++){
        fprintf (ftemp, "%s %s %s %s\n", sumber[i].nim, sumber[i].kodeL, sumber[i].lomba, sumber[i].prestasi);
    }
    fprintf (ftemp, "%s %s %s %s\n", "####", "####", "####", "####");
    fclose (ftemp);
}

//membaca tabel skill
void readskill (int *n, tskill sumber[], char namafile[]){
    FILE *ftemp;
    ftemp = fopen (namafile, "r");
    *n = 0;
    //kalau filenya tidak ketemu
    if (ftemp == NULL){
        printf("TIDAK BISA MEMBUKA FILE %s\n", namafile);
        return;
    }
    
    int returnval = fscanf (ftemp, "%s %s %s %s %s", sumber[*n].nim, sumber[*n].nama, sumber[*n].kodeS, sumber[*n].skill, sumber[*n].deskripsi);
    //akan terus membaca hingga banyak datanya sudah sampai 5 variabel dan hingga ketemu #### 
    while (returnval == 5 && strcmp(sumber[*n].nim, "####") != 0 ){ 
        (*n)++;
        returnval = fscanf (ftemp, "%s %s %s %s %s", sumber[*n].nim, sumber[*n].nama, sumber[*n].kodeS, sumber[*n].skill, sumber[*n].deskripsi);
    }
    fclose (ftemp);
}

//membaca tabel pelatihan
void readpelatihan (int *n, tpelatihan sumber[], char namafile[]){
    FILE *ftemp;
    ftemp = fopen (namafile, "r");
    
    *n = 0;
    //kalau filenya tidak ketemu
    if(ftemp == NULL){
        printf("TIDAK BISA MEMBUKA FILE %s\n", namafile);
        return;
    }

    int returnval = fscanf (ftemp, "%s %s %s", sumber[*n].nim, sumber[*n].kodeP, sumber[*n].pelatihan);
    //akan terus membaca hingga banyak datanya sudah sampai 3 variabel dan hingga ketemu #### 
    while (returnval == 3 && strcmp (sumber[*n].nim, "####") != 0 ){
        (*n)++;
        returnval = fscanf (ftemp, "%s %s %s", sumber[*n].nim, sumber[*n].kodeP, sumber[*n].pelatihan);
    }
    fclose (ftemp);
}

//membaca tabel lomba
void readlomba (int *n, tlomba sumber[], char namafile[]){
    FILE *ftemp;
    ftemp = fopen (namafile, "r");

    *n = 0;
    //kalau filenya tidak ketemu
    if(ftemp == NULL){
        printf("TIDAK BISA MEMBUKA FILE %s\n", namafile);
        return;
    }
    
    int returnval = fscanf (ftemp, "%s %s %s %s", sumber[*n].nim, sumber[*n].kodeL, sumber[*n].lomba, sumber[*n].prestasi);
    //akan terus membaca hingga banyak datanya sudah sampai 4 variabel dan hingga ketemu #### 
    while (returnval == 4 && strcmp (sumber[*n].nim, "####") != 0 ){
        (*n)++;
        returnval =  fscanf (ftemp, "%s %s %s %s", sumber[*n].nim, sumber[*n].kodeL, sumber[*n].lomba, sumber[*n].prestasi);
    }
    fclose (ftemp);
}

//untuk menghapus data 
void deleteskill (){
    tskill s [100];//   menampung semua isi file skill
    int ns = 0;//sebagai banyak baris data pada tabel skill

    //membaca file skill
    readskill (&ns, s, "Skill.txt");

    char cariS[51];
    //memasukkan data yang ingin dihapus
    printf ("Masukkan data yang ingin dihapus:[Kode Skill]\n");
    scanf ("%s", cariS);

    //untuk menemukan apakah ada data yang sama antara data pada file dan yang ingin dihapus
    int found = 0;//sebagai flag ketemu atau tidak
    for (int i = 0; i < ns; i++){
        if (strcmp (s[i].kodeS, cariS) == 0){
            found = 1;//kalau ada kesamaan maka berubah menjadi 1
        }
    }

    //kalau tidak ditemukan kesamaan
    if (!found){
        printf ("KODE %s TIDAK DAPAT DITEMUKAN, MAHASISWA TIDAK MEMILIKI SKILL\n", cariS);
        return;
    }

    //kalau ada ditemukan kesamaan maka geser array hinngga data yang dicari kehapus
    for (int i = 0; i < ns; i++){
        if(strcmp (s[i].kodeS, cariS) == 0){
            for (int j = i; j < ns - 1; j++){
                s[j] = s[j+1];
            }
            ns--;//menyebabkan jumlah data juga bekurang
        }
    }
    //tuliskan pada file skill
    writeskill (ns, s, "Skill.txt");
    printf ("Data berhasil dihapus\n");
}

void deletepelatihan (){
    tpelatihan p [100];//menampung semua isi file pelatihan
    int np = 0;//banyaknya bari data pada pelatihan

    readpelatihan (&np, p, "Pelatihan.txt");

    char cariP[51];
    //memasukkan data yang ingin dihapus
    printf ("Masukkan data yang ingin dihapus:[Kode Pelatihan]\n");
    scanf ("%s", cariP);

    //mencari kesamaaan antara data yang ingin dihapus dengan data di dalam tabel
    int found = 0;
    for (int i = 0; i < np; i++){
        if (strcmp (p[i].kodeP, cariP) == 0){
            found = 1;
        }
    }
    
    //kalau tidak ada kemiripan
    if (!found){
        printf ("KODE PELATIHAN %s TIDAK DAPAT DITEMUKAN, MAHASISWA TIDAK PERNAH MENGIKUTI PELATIHAN\n", cariP);
        return;
    }

    //kalau ada kemiripan maka geser array hingga datanya terhabus
    for (int i = 0; i < np; i++){
        if(strcmp (p[i].kodeP, cariP) == 0){
            for (int j = i; j < np - 1; j++){
                p[j] = p[j+1];
            }
            np--;//banyaknya data pada file pelatihan
        }
    }

    writepelatihan (np, p, "Pelatihan.txt");//tulis ke dalam file pelatihan
    printf ("Data berhasil dihapus\n");
}

void deletelomba (){
    tlomba l [100];//menampung semua isi file lomba
    int nl = 0;//menampung banyaknya data pada file lomba

    readlomba (&nl, l, "Lomba.txt");

    char cariL[51];
    //memasukkan data yang ingin dihapus
    printf ("Masukkan data yang ingin dihapus:[Kode Lomba]\n");
    scanf ("%s", cariL);

    //menemukan kemiripan antara data yang ingin dihapus dengan data yang sudah ada
    int found = 0;
    for (int i = 0; i < nl; i++){
        if (strcmp (l[i].kodeL, cariL) == 0){
            found = 1;
        }
    }

    //kalau tidak ditemukan kesamaan
    if (!found){
        printf ("KODE %s TIDAK DAPAT DITEMUKAN, MAHASISWA TIDAK PERNAH MENGIKUTI LOMBA\n", cariL);
        return;
    }

    //kalau ditemukan kesamaan maka geser array  hingga datnya terhpus
    for (int i = 0; i < nl; i++){
        if(strcmp (l[i].kodeL, cariL) == 0){
            for (int j = i; j < nl - 1; j++){
                l[j] = l[j+1];
            }
            nl--;
        }
    }
    writelomba (nl, l, "Lomba.txt");
    printf ("Data berhasil dihapus\n");
}

void insertskill (){
    tskill temp [100];//menampung data skill
    tskill baru;//data skill yang baru
    int ns = 0;//menampung banyak data pada baris file

    readskill (&ns, temp, "Skill.txt");
    //memasukkan data baru
    printf ("MASUKKAN DATA BARU SKILL: [NIM] [NAMA] [KODE SKILL] [SKILL] [DESKRIPSI]\n");
    scanf ("%s %s %s %s %s", baru.nim, baru.nama, baru.kodeS, baru.skill, baru.deskripsi);

    //melihat kemiripan antara kode skiill dan nim dengan data yang baru
    for (int i = 0; i < ns; i++){
        if (strcmp (temp[i].kodeS, baru.kodeS) == 0 && strcmp (temp[i].nim, baru.nim) == 0){
            printf ("KODE SKILL DAN NIM SUDAH ADA, MASUKKAN DATA LAIN!\n");
            return;
        }
    }

    //melakukan sorting berdasarkan besar dan kecilnya angka nim
    int posisi = 0;
    //diletakkan menjadi data pertama jika nilainya paling kecil
    if (ns == 0 || strcmp (baru.nim,temp[0].nim) < 0){
        for (int i = ns - 1; i >= 0; i--){
            temp [i + 1] = temp [i];
        }
        temp[0] = baru;
        ns++;
        //jika data nim yang baru akan diletkkan paling akhir
    } else if (strcmp (baru.nim, temp[ns - 1].nim) > 0){
        temp[ns] = baru;
        ns++;
    } else {
        //kalau data nim akan diletkkan ditengah
        int i = 0;
        int stop = 0;//sebgai penanda apakah perlu dilakukan sorting lagi atau tidak
        while ((i < ns) && (stop == 0)){
            if (strcmp (temp[i].nim, baru.nim) > 0){
                stop = 1;
                posisi = i;
            } else {
                i++;
            }
        }
        //untuk memasukkan data yang baru ke dalam array temp pada indeks posisi
        for (int j = ns - 1; j >= posisi; j--){
            temp [j + 1] = temp [j];
        }
        temp [posisi] = baru;
        ns++;
    }
    writeskill (ns, temp, "Skill.txt");
    printf ("DATA BERHASIL DITAMBAHKAN\n");
}

void insertpelatihan (){
    tpelatihan temp [100];//menampung data pelatihan
    tpelatihan baru;//menampung data pelatihan yang baru
    int np = 0;//menampung banyaknya data pada file pelatihan

    readpelatihan (&np, temp, "Pelatihan.txt");
    //memasukkan data yang baru
    printf ("MASUKKAN DATA BARU SKILL: [NIM] [KODE PELATIHAN] [PELATIHAN]\n");
    scanf ("%s %s %s", baru.nim, baru.kodeP, baru.pelatihan);

    //melihat kesamaan anatar kode pelatihan dan nim dengan data baru
    for (int i = 0; i < np; i++){
        if (strcmp (temp[i].kodeP, baru.kodeP) == 0 && strcmp (temp[i].nim, baru.nim) == 0){
            printf ("KODE PELATIHAN DAN NIM SUDAH ADA, MASUKKAN DATA LAIN!\n");
            return;
        }
    }

    //untuk melakukan sorting data yang baru di dalama file
    int posisi = 0;
    //kalau datanya akan diletkkan paling awal
    if (np == 0 || strcmp (baru.nim,temp[0].nim) < 0){
        for (int i = np - 1; i >= 0; i--){
            temp [i + 1] = temp [i];
        }
        temp[0] = baru;
        np++;
        //kalau datanya akan diltekkan paling akhir
    } else if (strcmp (baru.nim, temp[np - 1].nim) > 0){
        temp[np] = baru;
        np++;
    } else {
        //kalu datanya akan disisipkan paling akhir
        int i = 0;
        int stop = 0;//penanda lanjut sorting atau tidak
        while ((i < np) && (stop == 0)){
            if (strcmp (temp[i].nim, baru.nim) > 0){
                stop = 1;//kalau misalnya data tempnya lebih besar dibanding data baru maka sorting akan berhenti
                posisi = i;
            } else {
                i++;
            }
        }//untuk memasukkan data yang baru ke dalam array temp pada indeks posisi
        for (int j = np - 1; j >= posisi; j--){
            temp [j + 1] = temp [j];
        }
        temp [posisi] = baru;
        np++;
    }
    writepelatihan (np, temp, "Pelatihan.txt");
    printf ("DATA BERHASIL DITAMBAHKAN\n");
}

void insertlomba (){
    tlomba temp [100];//data pada file lomba
    tlomba baru;//menyimpan data baru lomba
    int nl = 0;//banyaknya data pada file lomba

    readlomba (&nl, temp, "Lomba.txt");
    //memasukkan data
    printf ("MASUKKAN DATA BARU SKILL: [NIM] [KODE LOMBA] [LOMBA] [PRESTASI]\n");
    scanf ("%s %s %s %s", baru.nim, baru.kodeL, baru.lomba, baru.prestasi);

    //melihat kesamaan antara nim dan kode lomba dengan data yang baru
    for (int i = 0; i < nl; i++){
        if (strcmp (temp[i].kodeL, baru.kodeL) == 0 && strcmp (temp[i].nim, baru.nim) == 0){
            printf ("KODE LOMBA DAN NIM SUDAH ADA, MASUKKAN DATA LAIN!\n");
            return;
        }
    }

    //melakukkan sorting berdasarkan nim
    int posisi = 0;
    //kalau data baru akan diletakkan pada awal file
    if (nl == 0 || strcmp (baru.nim,temp[0].nim) < 0){
        for (int i = nl - 1; i >= 0; i--){
            temp [i + 1] = temp [i];
        }
        temp[0] = baru;
        nl++;
        //kalau data baru akan diletakkan pada akhir file
    } else if (strcmp (baru.nim, temp[nl - 1].nim) > 0){
        temp[nl] = baru;
        nl++;
    } else {
        //kalau file akan disisipkan di tengah file
        int i = 0;
        int stop = 0;
        while ((i < nl) && (stop == 0)){//selama i lebih kecil dari banyak data dan stop masih nol
            if (strcmp (temp[i].nim, baru.nim) > 0){//berjalan hingga darta temp lebih besar dari pada data nim
                stop = 1;//akan memberhentikan proses sorting
                posisi = i;
            } else {
                i++;
            }
        }//untuk memasukkan data yang baru ke dalam array temp pada indeks posisi
        for (int j = nl - 1; j >= posisi; j--){
            temp [j + 1] = temp [j];
        }
        temp [posisi] = baru;
        nl++;
    }
    writelomba (nl, temp, "Lomba.txt");
    printf ("DATA BERHASIL DITAMBAHKAN\n");
}

void updateskill (){
    tskill s [100];
    int ns = 0;//menampung banyaj data pada file skill

    readskill (&ns, s, "Skill.txt");
    //menyimpan variabel data data baru
    char nimbaru [51], namabaru [51], kodeSbaru[51], skillbaru [51], deskripsibaru [51]; 
    //memasukkan data mana yang akan diganti
    printf ("NIM yang ingin diupdate:\n");
    scanf ("%s", nimbaru);

    int found  = 0;//mencari kesamaan data dengan data yang baru
    for (int i = 0; i < ns; i++){
        if (strcmp(s[i].nim, nimbaru) == 0){//kalau ada kesamaan antara nim data dengan nim yang ingin diganti
            found = 1;//found menjadi valid dan proses update dapat dilaksanakan

            printf ("Masukkan data-data yang baru:\n");//memasukkan data data baru
            printf ("[NIM] [NAMA] [KODE SKILL] [SKILL] [DESKRIPSI]\n");
            scanf ("%s %s %s %s %s", nimbaru, namabaru, kodeSbaru, skillbaru, deskripsibaru);
            //mengganti data yang ada pada dalam file menjadi data yang baru
            strcpy (s[i].nim, nimbaru);
            strcpy (s[i].nama, namabaru);
            strcpy (s[i].kodeS, kodeSbaru);
            strcpy (s[i].skill, skillbaru);
            strcpy (s[i].deskripsi, deskripsibaru);

            writeskill (ns, s, "Skill.txt");
            printf ("Selamat data berhasil berubah\n");
            return;
        }
    }//kalau tidak ditemukan kesamaan kodea
    printf ("GAGAL DIPERBARUI, NIM %s TIDAK DAPAT DITEMUKAN\n", nimbaru);
}

void updatepelatihan (){
    tpelatihan p [100];
    int np = 0;//menyimpan banyaknya file pada data pelatiahn

    readpelatihan (&np, p, "Pelatihan.txt");
    //menyimpan variabel data baru pelatihan
    char nimbaru [51], kodePbaru[51], pelatihanbaru [51]; 

    //memasukkan data mana yang ingin diganti
    printf ("NIM yang ingin diupdate:\n");
    scanf ("%s", nimbaru);

    //penanda proses dapat dilanjutkan atau tidak
    int found  = 0;
    for (int i = 0; i < np; i++){
        if (strcmp(p[i].nim, nimbaru) == 0){//selama ditemukan ada data yang sama
            found = 1;//found menjadi valid dan datnya dapat diupdate

            printf ("Masukkan data-data yang baru:\n");//memasukkan data data baru
            printf ("[NIM] [KODE PELATIHAN] [PELATIHAN]\n");
            scanf ("%s %s %s", nimbaru, kodePbaru,pelatihanbaru);
            
            //memindahkan data yang ada pada file menjadi data yang baru
            strcpy (p[i].nim, nimbaru);
            strcpy (p[i].kodeP, kodePbaru);
            strcpy (p[i].pelatihan, pelatihanbaru);

            //menuliskannya pada file pelatihan
            writepelatihan (np, p, "Pelatihan.txt");
            printf ("Selamat data berhasil berubah\n");
            return;
        }
    }//kalau tidak ditemukan kesamaan
    printf ("GAGAL DIPERBARUI, NIM %s TIDAK DAPAT DITEMUKAN\n", nimbaru);
}

void updatelomba (){
    tlomba l [100];
    int nl = 0;//menyimoan banyaknya file pada data lomba

    readlomba (&nl, l, "Lomba.txt");//membaca file lomba

    //menyimpan variabel data baru
    char nimbaru [51], kodeLbaru[51], lombabaru [51], prestasibaru [51]; 
    //memasukkan data mana yang akan diganti
    printf ("NIM yang ingin diubah:\n");
    scanf ("%s", nimbaru);

    int found  = 0;
    for (int i = 0; i < nl; i++){
        if (strcmp(l[i].nim, nimbaru) == 0){//selama ada kesamaan antara data baru dan data pda file
            found = 1;//maka proses update menjadi valid

            //memasukkan data data baru
            printf ("Masukkan data-data yang baru:\n");
            printf ("[NIM] [KODE LOMBA] [LOMBA] [PRESTASI]\n");
            scanf ("%s %s %s %s", nimbaru, kodeLbaru, lombabaru, prestasibaru);
            
            //memindahkna data yang lama menjadi dat yang baru
            strcpy (l[i].nim, nimbaru);
            strcpy (l[i].kodeL, kodeLbaru);
            strcpy (l[i].lomba, lombabaru);
            strcpy (l[i].prestasi, prestasibaru);

            writelomba (nl, l, "Lomba.txt");//tulis pada file lomba
            printf ("Selamat data berhasil berubah\n");
            return;
        }
    }//kalau tidak ditemukan kesamaan
    printf ("GAGAL DIPERBARUI, KODE %s TIDAK DAPAT DITEMUKAN\n", kodeLbaru);
}

void showskill (){
    tskill s [100];//menampung data pada file skill
    int ns = 0;//banyaknya data file skill

    readskill (&ns, s, "Skill.txt");

    if (ns == 0){//kalau datanya kosong
        printf ("DATA KOSONG");
        return;
    }

    //sebgai judul untuk membuat tabel
    char *judul [] = {"NIM", "NAMA", "KODE SKILL", "SKILL", "DESKRIPSI"};
    int len [5];

    //panjang awal adalah panjang judul
    for (int i = 0; i < 5; i++){
        len [i] =  strlen (judul[i]);
    }

    //membandingkan panjang kata antara judul dengan isi pada masing masing variabel
    for (int i = 0; i < ns; i++){
        if (strlen(s[i].nim) > len [0]){
            len [0] = strlen (s[i].nim);//membadinngkan panjang kata nim dengan data yang ada pada array nim
        }
        if (strlen(s[i].nama) > len [1]){
            len [1] = strlen (s[i].nama);//membadinngkan panjang kata nama dengan data yang ada pada array nama
        }
        if (strlen (s[i].kodeS) > len [2]){
            len [2] = strlen (s[i].kodeS);//membadinngkan panjang kata kode skill dengan data yang ada pada array kode skill
        }
        if (strlen (s[i].skill) > len [3]){
            len [3] = strlen (s[i].skill);//membadinngkan panjang kata skill dengan data yang ada pada array skill
        }
        if (strlen (s[i].deskripsi) > len [4]){
            len [4] = strlen (s[i].deskripsi);//membadinngkan panjang kata deskripsi dengan data yang ada pada array deskripsi
        }
    }

    //mecetak garis atas judul
    printf ("+");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < len [i] + 2; j++){//pluss 2 untuk spasi kiri dan kanan
            printf ("-");
        }
        printf ("+");
    }
    printf ("\n");

    //menceteka garis untuk judul
    printf ("|");
    for (int i = 0; i < 5; i++){
        printf (" %s", judul[i]);//cetak teks
        for (int j = 0; j < len [i] - strlen(judul [i]); j++){
            printf (" ");//menambah spasi pada rata kiri
        }
        printf (" |");
    }
    printf ("\n");

    //mencetak garis pemisah pada judul dengan isi
    printf ("+");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < len[i] + 2; j++){
            printf ("-");
        }
        printf ("+");
    }
    printf ("\n");

    //mencetak garis bawah setiap baris
    for (int i = 0; i < ns; i++){
        printf ("| ");
        printf ("%s", s[i].nim);

        for (int j = 0; j < len [0] - strlen (s[i].nim); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("%s", s[i].nama);

        for (int j = 0; j < len [1] - strlen (s[i].nama); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("%s", s[i].kodeS);

        for (int j = 0; j < len [2] - strlen (s[i].kodeS); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("%s", s[i].skill);

        for (int j = 0; j < len [3] - strlen (s[i].skill); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("%s", s[i].deskripsi);

        for (int j = 0; j < len [4] - strlen (s[i].deskripsi); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("\n");

        printf ("+");
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < len[i] + 2; j++){
                printf ("-");
            }
            printf ("+");
        }
        printf ("\n");
    }
}

void showpelatihan (){
    tpelatihan p [100];//menampung data pada file pelatihan
    int np = 0;//banyaknya data file pelatihan

    readpelatihan (&np, p, "Pelatihan.txt");

    if (np == 0){//kalau datanya kosong
        printf ("DATA KOSONG\n");
        return;
    }

    //sebgai judul untuk membuat tabel
    char *judul [] = {"NIM", "KODE PELATIHAN", "PELATIHAN"};
    int len [3];

    //panjang awal adalah panjang judul
    for (int i = 0; i < 3; i++){
        len [i] =  strlen (judul[i]);
    }

    //membandingkan panjang kata antara judul dengan isi pada masing masing variabel
    for (int i = 0; i < np; i++){
        if (strlen(p[i].nim) > len [0]){
            len [0] = strlen (p[i].nim);//membadinngkan panjang kata nim dengan data yang ada pada array nim
        }
        if (strlen (p[i].kodeP) > len [1]){
            len [1] = strlen (p[i].kodeP);//membadinngkan panjang kata kode pelatihan dengan data yang ada pada array kode pelatihan
        }
        if (strlen (p[i].pelatihan) > len [2]){
            len [2] = strlen (p[i].pelatihan);//membadinngkan panjang kata pelatihan dengan data yang ada pada array pelatihan
        }
    }

    //mencetak garis atas judul
    printf ("+");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < len [i] + 2; j++){
            printf ("-");
        }
        printf ("+");
    }
    printf ("\n");

    //menceteka garis untuk judul yang dipisahkan dengan garis |
    printf ("|");
    for (int i = 0; i < 3; i++){
        printf (" %s", judul [i]);
        for (int j = 0; j < len [i] - strlen(judul [i]); j++){
            printf (" ");
        }
        printf (" |");
    }
    printf ("\n");

    //mencetak garis bawah
    printf ("+");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < len[i] + 2; j++){
            printf ("-");
        }
        printf ("+");
    }
    printf ("\n");

     //mencetak garis pemisah antara data sebelahnya
    for (int i = 0; i < np; i++){
        printf ("| ");
        printf ("%s", p[i].nim);

        for (int j = 0; j < len [0] - strlen (p[i].nim); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("%s", p[i].kodeP);

        for (int j = 0; j < len [1] - strlen (p[i].kodeP); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("%s", p[i].pelatihan);

        for (int j = 0; j < len [2] - strlen (p[i].pelatihan); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("\n");

        printf ("+");
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < len[i] + 2; j++){
                printf ("-");
            }
            printf ("+");
        }
        printf ("\n");
    }
}

void showlomba (){
    tlomba l [100];//menampung data pada file lomba
    int nl = 0;//banyaknya data file lomba

    readlomba (&nl, l, "Lomba.txt");

    if (nl == 0){//kalau isi satnya kosong
        printf ("DATA KOSONG\n");
        return;
    }

    //sebgai judul untuk membuat tabel
    char *judul [] = {"NIM", "KODE LOMBA", "LOMBA", "PRESTASI"};
    int len [4];

    //panjang awal adalah panjang judul
    for (int i = 0; i < 4; i++){
        len [i] =  strlen (judul[i]);
    }

    //membandingkan panjang kata antara judul dengan isi pada masing masing variabel
    for (int i = 0; i < nl; i++){
        if (strlen(l[i].nim) > len [0]){
            len [0] = strlen (l[i].nim);//membadinngkan panjang kata nim dengan data yang ada pada array nim
        }
        if (strlen(l[i].kodeL) > len [1]){
            len [1] = strlen (l[i].kodeL);//membadinngkan panjang kata kode latihan dengan data yang ada pada array kode latihan
        }
        if (strlen (l[i].lomba) > len [2]){
            len [2] = strlen (l[i].lomba);//membadinngkan panjang kata lomba dengan data yang ada pada array lomba
        }
        if (strlen (l[i].prestasi) > len [3]){
            len [3] = strlen (l[i].prestasi);//membadinngkan panjang kata prestasi dengan data yang ada pada array presatsi
        }
    }

    //mencetak garis atas judul
    printf ("+");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < len [i] + 2; j++){
            printf ("-");
        }
        printf ("+");
    }
    printf ("\n");

    //menceteka garis untuk judul yang dipisahkan dengan garis |
    printf ("|");
    for (int i = 0; i < 4; i++){
        printf (" %s", judul[i]);
        for (int j = 0; j < len [i] - strlen(judul [i]); j++){
            printf (" ");
        }
        printf (" |");
    }
    printf ("\n");

    //mencetak garis bawah
    printf ("+");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < len[i] + 2; j++){
            printf ("-");
        }
        printf ("+");
    }
    printf ("\n");

    //mencetak garis pemisah antara data sebelahnya
    for (int i = 0; i < nl; i++){
        printf ("| ");
        printf ("%s", l[i].nim);

        for (int j = 0; j < len [0] - strlen (l[i].nim); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("%s", l[i].kodeL);

        for (int j = 0; j < len [1] - strlen (l[i].kodeL); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("%s", l[i].lomba);

        for (int j = 0; j < len [2] - strlen (l[i].lomba); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("%s", l[i].prestasi);

        for (int j = 0; j < len [3] - strlen (l[i].prestasi); j++){
            printf (" ");
        }
        printf (" | ");
        printf ("\n");

        printf ("+");
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < len[i] + 2; j++){
                printf ("-");
            }
            printf ("+");
        }
        printf ("\n");
    }
}

void joinsemua() {
    tskill s[100];//meyimpan data pada skil;
    tpelatihan p[100];//meyimpan data pada pelatihan;
    tlomba l[100];//meyimpan data pada lomba;

    int ns = 0;//meyimpan banyaknya data skill
    int np = 0;//meyimpan banyaknya data pelatihan
    int nl = 0;//meyimpan banyaknya data lomba

    readskill(&ns, s, "Skill.txt");
    readpelatihan(&np, p, "Pelatihan.txt");
    readlomba(&nl, l, "Lomba.txt");

    //untuk judul tabel
    char *judul[7] = {"NIM", "NAMA", "SKILL", "DESKRIPSI", "PELATIHAN", "LOMBA", "PRESTASI"};
    int len[7];

    //panjang awal adalah panjang judul
    for (int i = 0; i < 7; i++) {
        len[i] = strlen(judul[i]);
    }

    //sebagai index skill, index pelatihan, index lomba
    int a = 0, b = 0, c = 0;

    while (a < ns || b < np || c < nl) {
        char nimkosong[20] = "zzzzzzzz";//nim kosong pasti lebih besar dari nim apapun
        //untuk mengambil nim terkecil dari skill. pelatihan, dan lomba
        if (a < ns && strcmp(s[a].nim, nimkosong) < 0) {
            strcpy(nimkosong, s[a].nim);
        }
        if (b < np && strcmp(p[b].nim, nimkosong) < 0) {
            strcpy(nimkosong, p[b].nim);
        }
        if (c < nl && strcmp(l[c].nim, nimkosong) < 0) {
            strcpy(nimkosong, l[c].nim);
        }

        //meyimpan data kalau misalnya kosong maka akan menjadi -
        char nama[100] = "-";
        char skill[200] = "-";
        char deskripsi[200] = "-";
        char pelatihan[200] = "-";
        char lomba[200] = "-";
        char prestasi[200] = "-";

        //temp index untuk skill, pelatihan, dan lomba
        int ta = a, tb = b, tc = c;
        //index string tiap katanya untuk skill, deskripsi, pelatihan, lomba, dan prestasi
        int ks = 0, kd = 0, kp = 0, kl = 0, kpr = 0;
        //flag untuk data pertama
        int masuk;

        if (ta < ns && strcmp(s[ta].nim, nimkosong) == 0) {
            strcpy(nama, s[ta].nama);
        }//untuk mengcopy nama karena ada pada skill

        masuk = 1;
        //lakukan proses selama nim sama
        while (ta < ns && strcmp(s[ta].nim, nimkosong) == 0) {
            if (!masuk) {
                //kalau lebih dari satu skill pisahkan dengan koma
                skill[ks] = ',';
                ks++;
                skill[ks] = ' ';
                ks++;
                //kalau lebih dari satu deskripsi maka akan dipisahkan oleh koma
                deskripsi[kd] = ',';
                kd++;
                deskripsi[kd] = ' ';
                kd++;
            }

            int i = 0;
            //selama belum menccapai indesc terakhir 
            while (s[ta].skill[i] != '\0') {
                //coppy huruf dari skill untuk masuk ke array gabungan skill
                skill[ks] = s[ta].skill[i];
                ks++;//pindag ke tempat kosong berikutnya pada string gabungan
                i++;//pindah ke huruf selanjutunya
            }

            i = 0;
            //selama belum menccapai index terakhir 
            while (s[ta].deskripsi[i] != '\0') {
                //coppy huruf dari deskripsi untuk masuk ke array gabungan deskripsi
                deskripsi[kd] = s[ta].deskripsi[i];
                kd++;//pindah ke tempat kosong berikutnya pada string gabungan
                i++;//pindah ke huruf selanjtunya
            }
            masuk = 0;//reset data pertama
            ta++;//pindag ke baris selanjutnya
        }
        if (ks > 0) {
            skill[ks] = '\0';
        }//kalau ada isi pada skill maka tutup stringnya
        if (kd > 0) {
            deskripsi[kd] = '\0';
        }//kalau ada isi pada deskripsi maka tutup stringnya

        masuk = 1;
        //lakukan proses selama nim sama
        while (tb < np && strcmp(p[tb].nim, nimkosong) == 0) {
            if (!masuk) {
                pelatihan[kp] = ',';
                kp++;
                pelatihan[kp] = ' ';
                kp++;
                 //kalau lebih dari satu pelatihan pisahkan dengan koma
            }

            int i = 0;
            //selama belum menccapai index terakhir 
            while (p[tb].pelatihan[i] != '\0') {
                //coppy huruf dari pelatihan untuk masuk ke array gabungan skill
                pelatihan[kp] = p[tb].pelatihan[i];
                kp++;//pindah ke tempat kosong berikutnya pada string gabungan
                i++;//pindah ke hurud selnajutnya
            }
            masuk = 0;//reset data pertama
            tb++;//pindah ke baris data selanjtunya
        }
        if (kp > 0) {
            pelatihan[kp] = '\0';
        }//kalau ada isi pada pelatihan maka tutup stringnya

        masuk = 1;
        //lakukan proses selama nim sama
        while (tc < nl && strcmp(l[tc].nim, nimkosong) == 0) {
            //kalau lebih dari satu skill pisahkan dengan komdad
            if (!masuk) {
                //kalau lebih dari satu lomba pisahkan dengan koma
                lomba[kl] = ',';
                kl++;
                lomba[kl] = ' ';
                kl++;
                //kalau lebih dari satu prestasi pisahkan dengan koma
                prestasi[kpr] = ',';
                kpr++;
                prestasi[kpr] = ' ';
                kpr++;
            }

            int i = 0;
            //selama belum mencapai index terakhir 
            while (l[tc].lomba[i] != '\0') {
                //coppy huruf dari lomba untuk masuk ke array gabungan lomba
                lomba[kl] = l[tc].lomba[i];
                kl++;//pindah ke tempat kosong berikutnya pada string gabungan
                i++;//pindah ke huruf selanjutnya
            }

            i = 0;
            //selama belum mencapai index terakhir 
            while (l[tc].prestasi[i] != '\0') {
                //copy huruf dari prestasi untuk masuk ke array gabungan prestasi
                prestasi[kpr] = l[tc].prestasi[i];
                kpr++;//pindah ke tempat kosong berikutnya pada string gabungan
                i++;//pindah ke huruf selanjutnya
            }
            masuk = 0;//reset data pertama
            tc++;//pindah ke baris data selanjtunya
        }
        if (kl > 0) {
            lomba[kl] = '\0';
        }//kalau ada isi pada lomba maka tutup stringnya
        if (kpr > 0) {
            prestasi[kpr] = '\0';
        }//kalau ada isi pada prestasi maka tutup stringnya

        //membandingkan panjang kata antara judul dengan isi pada masing masing variabel
        if (strlen(nimkosong) > len[0]) {
            len[0] = strlen(nimkosong);
        }
        if (strlen(nama) > len[1]) {
            len[1] = strlen(nama);
        }
        if (strlen(skill) > len[2]) {
            len[2] = strlen(skill);
        }
        if (strlen(deskripsi) > len[3]) {
            len[3] = strlen(deskripsi);
        }
        if (strlen(pelatihan) > len[4]) {
            len[4] = strlen(pelatihan);
        }
        if (strlen(lomba) > len[5]) {
            len[5] = strlen(lomba);
        }
        if (strlen(prestasi) > len[6]) {
            len[6] = strlen(prestasi);
        }
        a = ta;
        b = tb;
        c = tc;
    }

    //membuat garis unutk atas judul
    for (int i = 0; i < 7; i++) {
        printf("+");
        for (int j = 0; j < len[i] + 2; j++) {
            printf("-");
        }
    }
    printf("+\n");

    //membuat pemisah untuk masing masing juudl ke samping
    printf("| ");
    for (int i = 0; i < 7; i++) {
        printf("%s", judul[i]);
        for (int j = 0; j < len[i] - (int)strlen(judul[i]); j++) {
            printf(" ");
        }
        printf(" | ");
    }
    printf("\n");

    //membuat garis pemisah bawah
    for (int i = 0; i < 7; i++) {
        printf("+");
        for (int j = 0; j < len[i] + 2; j++) {
            printf("-");
        }
    }
    printf("+\n");

    a = 0;
    b = 0;
    c = 0;

    while (a < ns || b < np || c < nl) {
        char nimkosong[20] = "zzzzzzzz";
        //untuk mengambil nim terkecil dari skill. pelatihan, dan lomba
        if (a < ns && strcmp(s[a].nim, nimkosong) < 0) {
            strcpy(nimkosong, s[a].nim);
        }
        if (b < np && strcmp(p[b].nim, nimkosong) < 0) {
            strcpy(nimkosong, p[b].nim);
        }
        if (c < nl && strcmp(l[c].nim, nimkosong) < 0) {
            strcpy(nimkosong, l[c].nim);
        }

        //kalau tidak ada isi maka akan ditulis menjadi -
        char nama[100] = "-";
        char skill[200] = "-";
        char deskripsi[200] = "-";
        char pelatihan[200] = "-";
        char lomba[200] = "-";
        char prestasi[200] = "-";

        //temp index untuk skill, pelatihan, dan lomba
        int ta = a, tb = b, tc = c;
        //index string tiap katanya untuk skill, deskripsi, pelatihan, lomba, dan prestasi
        int ks = 0, kd = 0, kp = 0, kl = 0, kpr = 0;
        //flag untuk data pertama
        int masuk;

        if (ta < ns && strcmp(s[ta].nim, nimkosong) == 0) {
            strcpy(nama, s[ta].nama);
        }//untuk mengcopy nama karena ada pada skill

        masuk = 1;
        while (ta < ns && strcmp(s[ta].nim, nimkosong) == 0) {
            //lakukan proses selama nim sama
            if (!masuk) {
                //kalau ada lebih dari satu skill pisahkan dengan koma
                skill[ks] = ',';
                ks++;
                skill[ks] = ' ';
                ks++;
                //kalau ada ebih dari satu deskripsi maka pisahkan dengan koam
                deskripsi[kd] = ',';
                kd++;
                deskripsi[kd] = ' ';
                kd++;
            }

            int i = 0;
            //selama belum mencapai index terakhir 
            while (s[ta].skill[i] != '\0') {
                //copy huruf dari skill untuk masuk ke array gabungan skill
                skill[ks] = s[ta].skill[i];
                ks++;//pindah ke tempat kosong berikutnya pada string gabungan
                i++;//pindah ke huruf selanjutnya
            }

            i = 0;
            while (s[ta].deskripsi[i] != '\0') {
                //copy huruf dari deskirpsi untuk masuk ke array gabungan deskripis
                deskripsi[kd] = s[ta].deskripsi[i];
                kd++;//pindah ke tempat kosong berikutnya pada string gabungan
                i++;//pindah ke huruf selanjutnya
            }
            masuk = 0;
            ta++;//pindah ke kata selanjtunya
        }
        if (ks > 0) {
            skill[ks] = '\0';
        }//kalau ada isi pada skill maka tutup stringnya
        if (kd > 0) {
            deskripsi[kd] = '\0';
        }//kalau ada isi pada deskripsi maka tutup stringnya

        masuk = 1;
        while (tb < np && strcmp(p[tb].nim, nimkosong) == 0) {
            //lakukan proses selama nim sama
            if (!masuk) {
                //kalau ada lebih dari dua pelatihan pisahkan dengan koma
                pelatihan[kp] = ',';
                kp++;
                pelatihan[kp] = ' ';
                kp++;
            }

            int i = 0;
             //selama belum mencapai index terakhir 
            while (p[tb].pelatihan[i] != '\0') {
                //copy huruf dari pelatihan untuk masuk ke array gabungan pelatihan
                pelatihan[kp] = p[tb].pelatihan[i];
                kp++;//pindah ke tempat kosong berikutnya pada string gabungan
                i++;//ke kata selanjtunya
            }
            masuk = 0;
            tb++;//masukk ke baris selanutnya
        }
        if (kp > 0) {
            pelatihan[kp] = '\0';
        }//kalau ada isi pada pelatihan maka tutup stringnya

        masuk = 1;
        while (tc < nl && strcmp(l[tc].nim, nimkosong) == 0) {
            if (!masuk) {
                //kalau ada lebih dari dua lomba pisahkan dengan koma
                lomba[kl] = ',';
                kl++;
                lomba[kl] = ' ';
                kl++;

                //kalau ada lebih dari dua prestasi pisahkan dengan koam
                prestasi[kpr] = ',';
                kpr++;
                prestasi[kpr] = ' ';
                kpr++;
            }

            int i = 0;
            //selama belum mencapai index terakhir 
            while (l[tc].lomba[i] != '\0') {
                //copy huruf dari lomba untuk masuk ke array gabungan lomba
                lomba[kl] = l[tc].lomba[i];
                kl++;//pindah ke tempat kosong berikutnya pada string gabungan
                i++;//pindah kata selanjutnya
            }

            i = 0;
            //selama belum mencapai index terakhir 
            while (l[tc].prestasi[i] != '\0') {
                //copy huruf dari prestasi untuk masuk ke array gabungan prestasi
                prestasi[kpr] = l[tc].prestasi[i];
                kpr++;//pindah ke tempat kosong berikutnya pada string gabungan
                i++;//pindah ke kata selanjutnya
            }
            masuk = 0;
            tc++;//pindah ke baris selanjutnya
        }
        if (kl > 0) {
            lomba[kl] = '\0';
        }//kalau ada isi pada lomba maka tutup stringnya
        if (kpr > 0) {
            prestasi[kpr] = '\0';
        }//kalau ada isi pada prestasi maka tutup stringnya

        //untuk membuat pemisah antara satu variabel dengan lainnya, yang panjangnya berdasarkan dengan panjang kata terpanjang variabel tersebut
        printf("| %s", nimkosong);
        for (int i = 0; i < len[0] - (int)strlen(nimkosong); i++) {
            printf(" ");
        }
        printf(" | ");

        printf("%s", nama);
        for (int i = 0; i < len[1] - (int)strlen(nama); i++) {
            printf(" ");
        }
        printf(" | ");

        printf("%s", skill);
        for (int i = 0; i < len[2] - (int)strlen(skill); i++) {
            printf(" ");
        }
        printf(" | ");

        printf("%s", deskripsi);
        for (int i = 0; i < len[3] - (int)strlen(deskripsi); i++) {
            printf(" ");
        }
        printf(" | ");

        printf("%s", pelatihan);
        for (int i = 0; i < len[4] - (int)strlen(pelatihan); i++) {
            printf(" ");
        }
        printf(" | ");

        printf("%s", lomba);
        for (int i = 0; i < len[5] - (int)strlen(lomba); i++) {
            printf(" ");
        }
        printf(" | ");

        printf("%s", prestasi);
        for (int i = 0; i < len[6] - (int)strlen(prestasi); i++) {
            printf(" ");
        }
        printf(" |\n");

        for (int i = 0; i < 7; i++) {
            printf("+");
            for (int j = 0; j < len[i] + 2; j++) {
                printf("-");
            }
        }
        printf("+\n");

        a = ta;
        b = tb;
        c = tc;
    }
}

void masukkanquery (char pita []){
    start (pita);//untuk memulai mesin kata
    char perintah [200];
    strcpy (perintah, getcw());
    //untuk memasukkan perintah dari huruf pertama

    //lajut ke kata selanjutnya
    inc (pita);
    char file [30];
    strcpy (file, getcw());
    //memasukkan ke varibael file

    //untuk melakukan show join
    if ((strcmp(perintah,"SHOW")==0 || strcmp(perintah,"show")==0) && (strcmp(file,"JOIN")==0 || strcmp(file,"join")==0)) {
        joinsemua ();
        reset ();
    }

    //untuk melakukan pertintah pada file skill
    if (strcmp (file, "tskill") == 0){
        if (strcmp (perintah, "INPUT")  == 0|| strcmp (perintah, "Input") == 0|| strcmp (perintah,"input") == 0){
            insertskill ();
        } else if (strcmp (perintah, "UPDATE") == 0 || strcmp (perintah, "Upadate") == 0|| strcmp (perintah,"update") == 0){
            updateskill ();
        } else if (strcmp (perintah, "DELETE") == 0 || strcmp (perintah, "Delete") == 0|| strcmp (perintah,"delete") == 0){
            deleteskill ();
        } else if (strcmp (perintah, "SHOW") == 0 || strcmp (perintah, "Show") == 0|| strcmp (perintah,"show") == 0){
            showskill ();
        }

    //untuk melakukan pertintah pada file pelatihan
    } else if (strcmp (file, "tpelatihan") == 0){
        if (strcmp (perintah, "INPUT")  == 0|| strcmp (perintah, "Input") == 0|| strcmp (perintah,"input") == 0){
            insertpelatihan ();
        } else if (strcmp (perintah, "UPDATE") == 0 || strcmp (perintah, "Upadate") == 0|| strcmp (perintah,"update") == 0){
            updatepelatihan ();
        } else if (strcmp (perintah, "DELETE") == 0 || strcmp (perintah, "Delete") == 0|| strcmp (perintah,"delete") == 0){
            deletepelatihan ();
        } else if (strcmp (perintah, "SHOW") == 0 || strcmp (perintah, "Show") == 0|| strcmp (perintah,"show") == 0){
            showpelatihan ();
        }

    //untuk melakukan pertintah pada file lomba
    } else if (strcmp (file, "tlomba") == 0){
        if (strcmp (perintah, "INPUT")  == 0|| strcmp (perintah, "Input") == 0|| strcmp (perintah,"input") == 0){
            insertlomba ();
        } else if (strcmp (perintah, "UPDATE") == 0 || strcmp (perintah, "Upadate") == 0|| strcmp (perintah,"update") == 0){
            updatelomba ();
        } else if (strcmp (perintah, "DELETE") == 0 || strcmp (perintah, "Delete") == 0|| strcmp (perintah,"delete") == 0){
            deletelomba ();
        } else if (strcmp (perintah, "SHOW") == 0 || strcmp (perintah, "Show") == 0|| strcmp (perintah,"show") == 0){
            showlomba ();
        }
    } else {
        printf ("Nama tabel tidak ada di database\n");
    }//kalau nama filenya tidak dikena;
}

int cekeop (char pita[]){
    int i = 0;
    while (pita[i] != '\0'){
        i++;
    }
    return (i > 0 && pita [i - 1] == '#');
}//megecek apakah query ada eop atau tidak