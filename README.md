# PENERAPAN KENDALI GPIO DAN INTERUPSI PADA LAMPU PENYEBERANGAN JALAN (PELICAN CROSSING) DENGAN ARDUINO UNO

## Informasi Mahasiswa
* **Nama**: Muhammad Aziz Ihza Fahriza Salam
* **NIM**: H1H024050
* **Mata Kuliah**: Sistem Mikrokontroler

---

## Deskripsi Proyek
Percobaan ini bertujuan untuk merancang dan mensimulasikan sistem lampu lalu lintas khusus penyeberangan jalan (*pelican crossing*) menggunakan mikrokontroler Arduino Uno melalui platform Tinkercad. Sistem ini dirancang menggunakan fitur interupsi perangkat keras (*hardware interrupt*) melalui masukan tombol tekan (*pushbutton*)

Secara default, lampu untuk kendaraan akan terus menyala hijau dan lampu pejalan kaki menyala merah[cite: 1]. Ketika pejalan kaki menekan tombol di sisi manapun, sistem akan merespon untuk menghentikan laju kendaraan dengan menyalakan lampu merah, dan memberikan hak jalan dengan menyalakan lampu hijau pejalan kaki dalam durasi tertentu sebelum kembali ke kondisi awal. Pemrograman juga menerapkan modularisasi fungsi agar kode berjalan lebih efisien.

---

## Komponen yang Digunakan
* 1 buah Arduino Uno
* 1 buah Breadboard
* 7 buah LED (1 Merah, 1 Kuning, 1 Hijau untuk kendaraan; 2 Merah, 2 Hijau untuk pejalan kaki)
* 7 buah Resistor
* 2 buah Pushbutton
* Kabel Jumper

---

## Konfigurasi Pin

| Bagian | Komponen | Pin Arduino |
| :--- | :--- | :--- |
| **Lampu Kendaraan** | LED Merah | Pin 10 |
| | LED Kuning | Pin 9 |
| | LED Hijau | Pin 8 |
| **Lampu Pejalan Kaki 1** | LED Merah | Pin 7 |
| | LED Hijau | Pin 6 |
| **Lampu Pejalan Kaki 2** | LED Merah | Pin 5 |
| | LED Hijau | Pin 4 |
| **Tombol Penyeberang (Interupsi)** | Tombol 1 | Pin 2 |
| | Tombol 2 | Pin 3 |

---

## Aturan Sistem
* Sistem memanfaatkan fungsi `attachInterrupt` pada pin 2 dan 3 dengan trigger `FALLING` untuk membaca penekanan tombol secara instan tanpa terhambat *delay*].
* Menggunakan variabel `volatile boolean adaPenyeberang` sebagai penanda (*flag*) apakah siklus penyeberangan harus diaktifkan.
* Menggunakan fungsi untuk modularisasi, yaitu `setKondisiAwal()` untuk mengatur ulang lampu, dan `fungsiInterupsiTombol()` untuk menerima aksi input.

---

## Cara Kerja Sistem
1. **Kondisi default**: Sistem memanggil `setKondisiAwal()` saat dimulai. Lampu kendaraan Hijau menyala, sedangkan lampu pejalan kaki 1 dan 2 Merah menyala[cite: 1].
2. Saat tombol 1 atau 2 ditekan, interupsi memicu `fungsiInterupsiTombol` yang segera mengubah status `adaPenyeberang` menjadi `true`.
3. Lampu Hijau kendaraan dimatikan, dan lampu Merah kendaraan dihidupkan untuk menghentikan lalu lintas.
4. Kedua lampu Merah pejalan kaki dimatikan, digantikan oleh lampu Hijau pejalan kaki yang dihidupkan.
5. Waktu penyeberangan (lampu hijau pejalan kaki) diberikan selama 5 detik.
6. Setelah 5 detik selesai, lampu Hijau pejalan kaki dimatikan dan lampu Merah pejalan kaki kembali dihidupkan.
7. Lampu Merah kendaraan dimatikan, diganti ke lampu Kuning kendaraan selama 2 detik sebagai tanda transisi bersiap maju.
8. Lampu Kuning kendaraan dimatikan, lalu sistem memanggil `setKondisiAwal()` untuk kembali ke arus normal.
9. Variabel `adaPenyeberang` dikembalikan ke status `false` menunggu input selanjutnya.

---

## Tautan
* **Simulasi Tinkercad**: https://www.tinkercad.com/things/2d3aDTY4pbd-tugas5sistem-mikrokontroler?sharecode=SGXrN9yAL10We2fhriUZv45v69k6DcolcxToNQ0Bafw
