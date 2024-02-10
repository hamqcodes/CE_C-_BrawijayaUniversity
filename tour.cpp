#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

string getCurrentDate();
string getCurrentTime();
void pemesanan();
int hargasewa(int tipejasa);
void notatagihan();

string namapemesan, alamatpemesan, teleponpemesan, emailpemesan, rutekendaraan, kendaraan, tanggalperjalanan;
int tipejasa, rute, pilihkendaraan, jumlahtiket, jam, uangcustomer;

string getCurrentDate() {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    ostringstream oss;
    oss << put_time(localTime, "%Y-%m-%d");
    return oss.str();
}

string getCurrentTime() {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    ostringstream oss;
    oss << put_time(localTime, "%H:%M:%S");
    return oss.str();
}

struct Mobil
{
    string tipe;
    string plat;
    string warna;
    string merk;
    string tahun;
};

void pemesanan() {
    cout << "======================================================================\n";
    cout << "\t\t\tMENU PEMESANAN FILKOM TOUR\t\t\t" << endl;
    cout << "\t\tPerjalanan Anda Menjadi Menyenangkan\t\t\t" << endl;
    cout << "\t\t Jalan Bismillah Pemdas dapet A-4.0\t\t" << endl;
    cout << "\t\t\tTlp.08123456789\t\t\t" << endl;
    cout << "======================================================================\n";
    cout << "\t\tPengisian Data Diri Pemesan\t\t\t" << endl;
    cout << "======================================================================\n";
    cout << "Masukan nama Anda\t: ";
    getline(cin, namapemesan);
    cout << "Masukan alamat Anda\t: ";
    getline(cin, alamatpemesan);
    cout << "Masukan telepon Anda\t: ";
    getline(cin, teleponpemesan);
    cout << "Masukan email Anda\t: ";
    getline(cin, emailpemesan);
    cout << "======================================================================\n";
    char konfirmasi;
    cout << "\nApakah data di atas sudah benar? (Y/N): "; cin >> konfirmasi;
    if (konfirmasi == 'N' || konfirmasi == 'n') {
        string dummy;
        getline(cin, dummy);
        pemesanan();
    } else {
        cout << "Terima kasih atas konfirmasinya. Data Anda telah tersimpan." << endl;
    }
}

void data_mobil(Mobil arr[], int &x)
{
    int opsi;
    while (true)
    {

        cout << "======================================================================\n";
        cout << "\t\t\t   FILKOM TOUR\t\t\t" << endl;
        cout << "\t\tPerjalanan Anda Menjadi Menyenangkan\t\t\t" << endl;
        cout << "\t\t Jalan Bismillah Pemdas dapet A-4.0\t\t" << endl;
        cout << "\t\t\t Tlp.08123456789\t\t\t" << endl;
        cout << "======================================================================\n";
        cout << "\t\t\t Administrasi Kendaraan\n";
         cout << "======================================================================\n";
        cout << "\n1). Input data kendaraan\n2). Cetak data kendaraan \n0). Keluar\nMasukkan pilihan anda : ";
        cin >> opsi;

        switch (opsi)
        {
        case 1:
            cout << "======================================================================\n";
            cout << "\t\t\t   FILKOM TOUR\t\t\t" << endl;
            cout << "\t\tPerjalanan Anda Menjadi Menyenangkan\t\t\t" << endl;
            cout << "\t\t Jalan Bismillah Pemdas dapet A-4.0\t\t" << endl;
            cout << "\t\t\t Tlp.08123456789\t\t\t" << endl;
            cout << "======================================================================\n";
            cout <<"Silahkan menginput informasi kendaraan\n"<<endl;
            x++;
            cout << "Masukkan merk mobil\t\t: ";
            cin >> arr[x].merk;
            cout << "Masukkan tipe mobil\t\t: ";
            cin >> arr[x].tipe;
            cout << "Masukkan warna mobil\t\t: ";
            cin >> arr[x].warna;
            cout << "Masukkan nomor plat mobil\t: ";
            cin.ignore();
            getline(cin, arr[x].plat);
            cout << "Masukkan tahun keluaran mobil\t: ";
            cin >> arr[x].tahun;
            break;

        case 2:
            cout << "======================================================================\n";
            cout << "\t\t\t   FILKOM TOUR\t\t\t" << endl;
            cout << "\t\tPerjalanan Anda Menjadi Menyenangkan\t\t\t" << endl;
            cout << "\t\t Jalan Bismillah Pemdas dapet A-4.0\t\t" << endl;
            cout << "\t\t\t Tlp.08123456789\t\t\t" << endl;
            cout << "======================================================================\n";
            cout << "                    INFORMASI BAGASI KENDARAAN                        \n";
            cout << "======================================================================\n";
            if (x < 0) cout << "Data mobil masih kosong!\n";
            else
            {
                for (int i = 0; i <= x; i++)
                {
                    cout << "Data Mobil ke-" << i + 1 << ":\n";
                    cout << "Merk\t\t: " << arr[i].merk << endl;
                    cout << "Tipe\t\t: " << arr[i].tipe << endl;
                    cout << "Warna\t\t: " << arr[i].warna << endl;
                    cout << "Plat\t\t: " << arr[i].plat << endl;
                    cout << "Tahun\t\t: " << arr[i].tahun << endl << endl;
                         
                }
            }
            break;

        case 0:
            cout << "Kembali ke main menu\n";
            return;

        default:
            cout << "Opsi tidak ditemukan\n";
            break;
        }
    }
}

int hargasewa(int tipejasa) {
    int biaya = 0;
    if (tipejasa == 1) {
        kendaraan = "Travel";
        switch (rute){
            case 1 :
            biaya = 100000*jumlahtiket;
            rutekendaraan = "Surabaya - Malang"; 
            break;
            case 2 :
            biaya = 200000*jumlahtiket;
            rutekendaraan = "Madura - Malang";
            break;
            case 3 :
            biaya = 250000*jumlahtiket;
            rutekendaraan = "Banyuwangi - Malang";
            break;
            case 4 :
            biaya = 175000*jumlahtiket;
            rutekendaraan = "Situbondo - Malang";
            break;
            case 5:
            biaya = 125000*jumlahtiket;
            rutekendaraan = "Tulungagung - Malang";
            break;
        }
     } else if (tipejasa == 2) {
        if ( jam == 5){
            biaya = 500000;
        }
        else if (jam < 5){
            biaya = 400000;
        } else if (jam > 5){
            
            biaya = 500000 + (150000*(jam-5));
        }
    }
    return biaya;
}

void notatagihan() {
    cout << "======================================================================\n";
    cout << "\t\t\tFILKOM TOUR\t\t\t" << endl;
    cout << "\t\tPerjalanan Anda Menjadi Menyenangkan\t\t\t" << endl;
    cout << "\t\t Jalan Bismillah Pemdas dapet A-4.0\t\t" << endl;
    cout << "\t\t\tTlp.08123456789\t\t\t" << endl;
    cout << "======================================================================\n";
    cout << "\t\t\tDATA DIRI PEMESAN\t\t\t" << endl;
    cout << "======================================================================\n";
    cout << "Nama\t\t: " << namapemesan << endl;        
    cout << "Alamat\t\t: " << alamatpemesan << endl;
    cout << "Telepon\t\t: " << teleponpemesan << endl;
    cout << "E-mail\t\t: " << emailpemesan << endl;
    cout << "Tanggal Pesan\t: " << getCurrentDate() <<endl;
    cout << "Waktu Pesan\t: "<< getCurrentTime() <<endl;
    cout << "======================================================================\n";
    cout << "\t\t\tData Perjalanan\t\t\t" << endl;
    cout << "======================================================================\n";
    cout << "TANGGAL\t\t\tJENIS KENDARAAN\t\t\tDESTINASI" << endl;
    if (tipejasa == 1) {
        cout << tanggalperjalanan << "\t\t  " << kendaraan << "\t\t\t" << rutekendaraan << endl;
        cout << "======================================================================\n";
        cout << "\t\t\tINFORMASI TIKET\t\t\t" << endl;
        cout << "======================================================================\n";
        cout << "JUMLAH TIKET\t\tBIAYA\t\t\t\tSTATUS" << endl;
        cout << jumlahtiket << "\t\t\tRp." << hargasewa(tipejasa) << "\t\t\tLunas" << endl;
    } else if (tipejasa == 2) {
        cout << tanggalperjalanan << "\t\t  " << kendaraan << "\t\t\t\t" << rutekendaraan << endl;
        cout << "======================================================================\n";
        cout << "\t\t\tINFORMASI SEWA\t\t\t" << endl;
        cout << "======================================================================\n";
        cout << "JAM SEWA\t\tBIAYA\t\t\t\tSTATUS" << endl;
        cout << jam << "\t\t\tRp." << hargasewa(tipejasa) << "\t\t\tLunas" << endl;
    }
}

void fungsipemesanan() {
    cout << "======================================================================\n";
    cout << "\t\t\tFILKOM TOUR\t\t\t" << endl;
    cout << "\t\tPerjalanan Anda Menjadi Menyenangkan\t\t\t" << endl;
    cout << "\t\t Jalan Bismillah Pemdas dapet A-4.0\t\t" << endl;
    cout << "\t\t\tTlp.08123456789\t\t\t" << endl;
    cout << "======================================================================\n";
    cout << "1). Travel\n2). Sewa Kendaraan\n0). Keluar\n";
    cout << "Silakan pilih tipe jasa kami\t: ";
    cin >> tipejasa;
    string dummy;
    getline(cin, dummy);
    cout << "======================================================================\n";
    cout << "Silakan input data diri anda dengan benar!" << endl;
    pemesanan();
    if (tipejasa == 1) {
        do {
            string dummy;
            getline(cin, dummy);
            cout << "======================================================================\n";
            cout << "PEMILIHAN DESTINASI\n";
            cout << "No.\t\tKEBERANGKATAN\t\tKEDATANGAN\t\tBIAYA" << endl;
            cout << "1).\t\tSurabaya\t\tMalang\t\tRp.100.000" << endl;
            cout << "2).\t\tMadura  \t\tMalang\t\tRp.200.000" << endl;
            cout << "3).\t\tBanyuwangi\t\tMalang\t\tRp.250.000" << endl;
            cout << "4).\t\tSitubondo\t\tMalang\t\tRp.175.000" << endl;
            cout << "5).\t\tTulungangung\t\tMalang\t\tRp.125.000" << endl << endl;
            cout << "Silahkan pilih destinasi Anda\t: ";
            cin >> rute;
            if (rute < 1 || rute > 5) {
                cout << "Input tidak valid. Pilih nomor rute yang tersedia." << endl;
            }
        } while (rute < 1 || rute > 5);
        cout << "======================================================================\n";
        cout << "Anda memilih destinasi nomor\t\t: " << rute << endl;
        cout << "Tanggal perjalanan Anda (DD/MM/YY)\t: "; cin >> tanggalperjalanan;
        cout << "Jumlah tiket yang Anda pesan\t\t: ";
        cin >> jumlahtiket;

    } else if (tipejasa == 2) {
        do {
            string dummy;
            getline(cin, dummy);
            cout << "======================================================================\n";
            cout << "PEMILIHAN JENIS KENDARAAN" << endl;
            cout << "1). Sedan" << endl;
            cout << "2). MPV" << endl;
            cout << "3). Minibus" << endl;
            cout << "Silahkan pilih jenis kendaraan yang Anda inginkan\t: ";
            cin >> pilihkendaraan;
            if (pilihkendaraan < 1 || pilihkendaraan > 3) {
                cout << "Input tidak valid. Pilih nomor jenis kendaraan yang tersedia." << endl;
            }
        } while (pilihkendaraan < 1 || pilihkendaraan > 3);
        cout << "Anda memilih jenis kendaraan nomor " << pilihkendaraan << endl;
        switch (pilihkendaraan) {
        case 1:
            kendaraan = "Sedan";
            break;
        case 2:
            kendaraan = "MPV";
            break;
        case 3:
            kendaraan = "Minibus";
            break;
        }
        cout << "Tanggal perjalanan Anda (DD/MM/YY)\t\t:"; cin >> tanggalperjalanan;
        cout << "Berapa jam Anda menyewa kendaraan\t\t:"; cin >> jam;
        cout << "Kemana anda ingin membawa kendaraan ini?\t:"; cin >> rutekendaraan;
        cout << "======================================================================\n";
    }
    bool lunas = false;
    cout << "======================================================================\n";
    cout << "Total biaya Anda adalah\t: Rp." << hargasewa(tipejasa) << endl;
    do {
        cout << "Uang Anda\t\t: Rp.";
        cin >> uangcustomer;
        if (uangcustomer < hargasewa(tipejasa)) {
            cout << "Maaf, uang yang dimasukkan tidak mencukupi. Silakan masukkan jumlah yang mencukupi." << endl;
        } else {
            lunas = true;
        }
    } while (!lunas);
    int kembalian = uangcustomer - hargasewa(tipejasa);
    if (kembalian > 0) {
        cout << "Kembalian\t\t: Rp." << kembalian << endl;
    }
    cout << "Terima kasih! Berikut adalah informasi tiket pemesanan Anda" << endl;
    notatagihan();
}

struct Karyawan
{
    string nama;
    string alamat;
    string kelamin;
    string telepon;
    string status;
    string kategori;
};

void gaji_travel()
{
    int opsi,x,gaji;
    string tipe;
    bool log = 1;

    while (log)
    {
        cout << "======================================================================\n";
        cout << "\t\t\tFILKOM TOUR\t\t\t" << endl;
        cout << "\t\tPerjalanan Anda Menjadi Menyenangkan\t\t\t" << endl;
        cout << "\t\t Jalan Bismillah Pemdas dapet A-4.0\t\t" << endl;
        cout << "\t\t\tTlp.08123456789\t\t\t" << endl;
        cout << "======================================================================\n";
        cout << "\t\t\tSIMULASI GAJI\t\t\t\n";
        cout << "======================================================================\n";
        cout << "\n1). Supir Travel\n2). Supir Rentcar\n3). Admin\nMasukkan tipe karyawan \t: ";
        cin >> opsi;
        if (opsi > 0 && opsi < 4) log = 0;
        else cout << "Opsi tidak ditemukan!\n\n";
    }

    cout << "Masukkan jam lembur \t\t:";
    cin >> x;

    switch (opsi)
    {
    case 1:
        gaji = (1500000 + 50000*x)*(1-0.05);
        cout << "Gaji supir travel adalah\t: Rp" << gaji << endl;
        break;

    case 2:
        gaji = (1750000 + 45000*x)*(1-0.06);
        cout << "Gaji supir rentcar adalah\t: Rp" << gaji << endl;
        break;

    case 3:
        gaji = (2000000 + 40000*x)*(1-0.07);
        cout << "Gaji admin adalah\t: Rp" << gaji << endl;
        break;
        
    default:
        cout << "error";
        break;
    }
    cout << "NOTE\t: Gaji karyawan sudah termasuk pajak"<<endl;
    cout << "======================================================================\n";
}

void administrasi_karyawan(Karyawan no[], int &z)
{
    bool log = true;
    string opsi;

    while (log)
    {
        cout << "======================================================================\n";
        cout << "\t\t\tFILKOM TOUR\t\t\t" << endl;
        cout << "\t\tPerjalanan Anda Menjadi Menyenangkan\t\t\t" << endl;
        cout << "\t\t Jalan Bismillah Pemdas dapet A-4.0\t\t" << endl;
        cout << "\t\t\tTlp.08123456789\t\t\t" << endl;
        cout << "======================================================================\n";
        cout << "\t\t\tADMINISTRASI KARYAWAN\n";
        cout << "======================================================================\n";
        cout << "1). Input data karyawan\n2). Cetak data karyawan\n3). Simulasi gaji\n0). Main menu\n\nMasukkan pilihan: ";
        cin >> opsi;
        cin.ignore();
        cout << "======================================================================\n\n";
        switch (opsi[0])
        {
        case '1':
        {
            z++;
            cout << "Masukkan nama karyawan\t\t: ";
            cin >> ws;
            getline(cin, no[z - 1].nama);

            cout << "Masukkan alamat karyawan\t: ";
            cin >> ws;
            getline(cin, no[z - 1].alamat);

            cout << "Masukkan nomor telepon karyawan\t: ";
            cin >> no[z - 1].telepon;

            cout << "Masukkan status karyawan\t: ";
            cin >> no[z - 1].status;

            int tes1 = 1;
            while (tes1)
            {
                tes1 = 0;
                cout << "1. Pria\n2. Wanita\nMasukkan jenis kelamin karyawan: ";
                cin >> no[z - 1].kelamin;

                if (no[z - 1].kelamin != "1" && no[z - 1].kelamin != "2")
                {
                    cout << "Opsi tidak valid!\n\n";
                    tes1 = 1;
                }
                else
                {
                    no[z - 1].kelamin = (no[z - 1].kelamin == "1") ? "Pria" : "Wanita";
                }
            }

            int tes2 = 1;
            while (tes2)
            {
                tes2 = 0;
                cout << "1. Supir travel\n2. Supir rentcar\n3. Admin\nMasukkan kategori karyawan: ";
                cin >> no[z - 1].kategori;

                if (no[z - 1].kategori != "1" && no[z - 1].kategori != "2" && no[z - 1].kategori != "3")
                {
                    cout << "Opsi tidak valid!\n\n";
                    tes1 = 1;
                }
                else
                {
                    no[z - 1].kategori = (no[z - 1].kategori == "1") ? "Supir Travel" : (no[z - 1].kategori == "2") ? "Supir Rentcar" : "Admin";
                }
            }
            cout << "\n\t\tDATA KARYAWAN TELAH TERSIMPAN!\n";
            break;
        }
        case '2':
            if (z < 1)
                cout << "Data karyawan kosong!\n\n";
            for (int i = 0; i < z; i++)
            {
                cout << "\nData Karyawan ke-" << i + 1 << ":\n";
                cout << "Nama\t\t: " << no[i].nama << endl;
                cout << "Alamat\t\t: " << no[i].alamat << endl;
                cout << "Telepon\t\t: " << no[i].telepon << endl;
                cout << "Status\t\t: " << no[i].status << endl;
                cout << "Kelamin\t\t: " << no[i].kelamin << endl;
                cout << "Kategori\t: " << no[i].kategori << endl << endl;
            }
            break;

        case '3':
            gaji_travel();
            break;

        case '0':
            log = false;
            break;

        default:
            cout << "Opsi tidak valid!\n";
            break;
        }
    }
}

int main()
{
    Karyawan data[99];
    Mobil data2[99];
    int mobil = -1, opsi, karyawan = 0;
    bool log = 1;
    
    while (log)
    {
        cout << "======================================================================\n";
        cout << "\t\t\t   FILKOM TOUR\t\t\t" << endl;
        cout << "\t\tPerjalanan Anda Menjadi Menyenangkan\t\t\t" << endl;
        cout << "\t\t Jalan Bismillah Pemdas dapet A-4.0\t\t" << endl;
        cout << "\t\t\t Tlp.08123456789\t\t\t" << endl;
        cout << "======================================================================\n";
    
        cout << "1). Administrasi Karyawan\n2). Administrasi Kendaraan\n3). Pemesanan Jasa\n0). Keluar\nMasukkan pilihan anda\t: ";
        cin >> opsi;
        cout << endl;
        switch (opsi)
        {
        case 1:
            administrasi_karyawan(data, karyawan);
            break;

        case 2:
            data_mobil(data2, mobil);
            break;

        case 3:
            fungsipemesanan();
            break;

        case 0:
            cout << "Selamat tinggal";
            log = 0;
            break;

        default:
            cout << "Opsi tidak ditemukan!";
            break;
        }
    }
}
