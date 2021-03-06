/*
	Program		: queue.h
	Author		: Muhammad Faza Hardiansyah (201524016)
				  Muhammad Fikri Hidayatulloh (201524017)
				  Syahda Afia Dhiya Ulhaq Tajudin (201524030)
	Kelompok	: A9
	Deskripsi	: Aplikasi layanan Dokter Hewan (mendata, menampilkan, dan memanggil antrian)
	Compiler	: DevC++ TDM-GCC 4.9.2 64-bit Release
*/

#ifndef QUEUE_H
#define QUEUE_H

			/* Atribut ADT */
/*========================================*/
typedef struct NodeQueue *addrNQ;
typedef struct InfoPelangganVetService infotype;
typedef struct InfoPenyakit Sakit;

typedef struct InfoPenyakit {
	char penyakit1[20]; 
	char penyakit2[20]; 
	char penyakit3[20]; 
}InfoPenyakit;

typedef struct InfoPelangganVetService{
	char nama[20];
	char* kategori;
	int jumlahPenyakit;
	Sakit penyakit;
	int prioritas;
	int WDatang;
	int WTunggu;
	int WMulai;
	int WService;
	int WSelesai;
} InfoPelangganVetService;

typedef struct NodeQueue{
	infotype info;
	addrNQ next;	
} NodeQueue;

typedef struct Queue{
	addrNQ front;  //menandai antrian depan
	addrNQ rear; //menandai antrian belakang
}Queue;


		   	/* Operasi ADT */
/*========================================*/

/*** MANAJEMEN MEMORI ***/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
   Jika alokasi berhasil, modul mengembalikan P; P->info = X, = NULL.
   P adalah pointer yang menunjuk ke node Queue sebagai hasil alokasi.
   Jika alokasi gagal, modul mengembalikan NULL.
   Author : M.Fikri Hidayatulloh.
 */
addrNQ Alokasi (infotype X);

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node queue).
   I.S. P terdefinisi.
   F.S. P dikembalikan ke sistem.
   Author : M.Fikri Hidayatulloh.
 */
void Dealokasi (addrNQ *P);


/*** Manajemen Queue ***/
/* Membuat sebuah Queue kosong dengan Q.fornt = NULL dan Q.rear = NULL. 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
   Author : M.Fikri Hidayatulloh.
*/
void BuatAntrian (Queue *Q);

/* Mengetahui apakah Queue kosong atau tidak. 
   mengirimkan 1, jika Queue kosong yaitu Q.front = NULL dan Q.rear = NULL.
   mengirimkan 0, jika Queue tidak kosong.
   Author : M.Fikri Hidayatulloh.
*/
int CekAntrianKosong (Queue Q);

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO.
   I.S. Q mungkin kosong atau Q mungkin berisi antrian.
   F.S. info baru telah masuk ke dalam Queue.
   Author : M.Fikri Hidayatulloh.
*/ 
void MasukAntrian (Queue *Q, infotype data);

/* Menghapus node dari Queue dengan aturan FIFO .
   I.S. Q mungkin kosong atau Q mungkin berisi antrian.
   F.S. Node sudah terhapus.
   Author : Syahda Afia.
*/ 
void MulaiService (Queue *Q);

/* Megurutkan daftar antrian sesuai waktu dan prioritas
   I.S. Antrian belum terurut.
   F.S. Antrian sudah terurut.
   Author : Syahda Afia.
*/
void UrutAntrian (Queue *Q, infotype Info);

/* Menukar urutan antrian apabila ada antrian yang diprioritaskan
   I.S. Antrian belum ditukar.
   F.S. Antrian sudah ditukar.
   Author : Syahda Afia.
*/
void UbahAntrian (Queue *Q, addrNQ NewNode, addrNQ x);

#endif
