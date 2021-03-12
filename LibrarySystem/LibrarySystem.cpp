#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;
class Kutuphane { //B�t�n de�i�kenleri kolay kullan�m i�in K�t�phane adl� classta toplad�m.
public:
    int secim;
    char cevap = 'e';
    //Okuyucu de�i�kenleri
    string Okuyucu_Adi;
    string Okuyucu_Soyadi;
    long long Tc;
    long long Tel;
    int Uye_No;
    int dogum_gun;
    int dogum_ay;
    int dogum_yil;
    string gorev;
    int Kitap_Sayisi;

    //Kitap de�i�kenleri
    long long isbn;
    string kitap_isim;
    string yazar_isim;
    string yazar_soyisim;
    string konu;
    string tur;
    int sayfa_sayisi;

    //Fonksiyonlarda kullanaca��m ge�i�i de�i�kenler
    long long gecici_isbn;
    long long gecici_tc;
    char nokta = '.';
    long long gecici1tc = 0;
    long long gecici1isbn = 0;

    //�d�n� ve iade de�i�kenleri
    int odunc_gun;
    int odunc_ay;
    int odunc_yil;
    int iade_gun;
    int iade_ay;
    int iade_yil;

};

class Okuyucular :public Kutuphane {//De�i�kenleri kullanmak i�in K�t�phane class� ile kal�t�m kulland�m.
public:

    void okuyucuGirisi();
    void okuyucuGuncelleme();  //Kar���kl��� gidermek i�in fonksiyonlar� burada tan�mlay�p d��ar�da ��z�mledim.
    void okuyucuSilme();
};

void Okuyucular::okuyucuGirisi() {

    ofstream DosyaYaz;
    DosyaYaz.open("Okuyucu.txt", ios::app); //Okuyucu giri�i i�in yazma(app) modunda okuyucu.txt dosyas�n� a�t�m.

    do //Kullan�c� e(evet) veya h(hay�r) harfini girmesine ba�l� olan bir d�ng� olu�turdum.
    {
        //Kullan�c�dan okuyucu bilgilerini girmesini istedim.
        cout << "\n Okuyucu TC                                 : "; cin >> Tc;
        cout << "\n Okuyucu adi                                : "; cin >> Okuyucu_Adi;
        cout << "\n Okuyucu soyadi                             : "; cin >> Okuyucu_Soyadi;
        cout << "\n �ye numaras�                               : "; cin >> Uye_No;
        cout << "\n Telefon                                    : "; cin >> Tel;
        cout << "\n Do�um tarihi(g�n.ay.y�l �eklinde giriniz)  : "; cin >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil;
        cout << "\n G�revi                                     : "; cin >> gorev;
        cout << "\n Alabilece�i kitap say�s�                   : 5";
        //Alabilece�i kitap say�s�n� 5ile s�n�rlad�m bu y�zden onu kendim yazd�m.
        Kitap_Sayisi = 5;
        //Dosyaya bilgileri yazd�rd�m.
        DosyaYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
            << Uye_No << setw(20) << Tel << setw(20)
            << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";


        cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;
    } while (!(cevap == 'h'));

    cout << "\n Okuyucu kayd� tamamland�. " << endl;
    DosyaYaz.close(); //Kullan�c� h harfini girdi�i i�in kay�t tamamland� ve dosyay� kapatt�m.

}

void Okuyucular::okuyucuGuncelleme() {

    ifstream dosyaOku("Okuyucu.txt");//Okuyucu bilgilerini okumak i�in dosyay� a�t�m.
    ofstream dosyaYaz("Gecici.txt");//Sonra ismini de�i�tirmek ve yeni okuyucu bilgilerini girmek �zere ge�ici bir dosya olu�turdum.

    cout << "G�ncellemek istedi�iniz okuyucunun Tc'sini giriniz:" << endl;
    cin >> gecici_tc; //Okuyucular dosyas�n� okuttu�umda Tc ile e�leyebilmek i�in kullan�c�dan ald���m bilgiyi ge�ici Tc olarak okuttum.

    //Dosyay�n�n b�t�n sat�rlar�n� okumas� i�in while d�ng�s�n� kulland�m.
    while (dosyaOku >> Tc >> Okuyucu_Adi >> Okuyucu_Soyadi >> Uye_No >> Tel >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil >> gorev >> Kitap_Sayisi) {

        if (gecici_tc == Tc) {//E�er kullan�c�dan ald���m ge�ici tc ile okutulan tc uyu�uyorsa istenen okuyucuyu bulmu� oluyorum.
            cout << "Okuyucunun eski bilgileri:" << endl;//Okuyucunun eski bilgilerini g�rmek isteyebilir diye yazd�rd�m.

            cout << "\n Okuyucu TC              :" << Tc << endl;
            cout << "\n Okuyucu adi             :" << Okuyucu_Adi << endl;
            cout << "\n Okuyucu soyadi          :" << Okuyucu_Soyadi << endl;
            cout << "\n �ye numaras�            :" << Uye_No << endl;
            cout << "\n Telefon                 :" << Tel << endl;
            cout << "\n Do�um tarihi            :" << dogum_gun << nokta << dogum_ay << nokta << dogum_yil << endl;
            cout << "\n G�revi                  :" << gorev << endl;
            cout << "\n Alabilece�i kitap say�s�:" << Kitap_Sayisi << endl;
            cout << "*******************************************************" << endl;
            cout << "Yeni bilgileri giriniz:" << endl;//Okuyucunun g�ncellenecek bilgilerini istedim.
            cout << "\n Okuyucu TC                :"; cin >> Tc;
            cout << "\n Okuyucu adi               :"; cin >> Okuyucu_Adi;
            cout << "\n Okuyucu soyadi            :"; cin >> Okuyucu_Soyadi;
            cout << "\n �ye numaras�              :"; cin >> Uye_No;
            cout << "\n Telefon                   :"; cin >> Tel;
            cout << "\n Do�um tarihi(g�n.ay.y�l)  :"; cin >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil;
            cout << "\n G�revi                    :"; cin >> gorev;
            cout << "\n Alabilece�i kitap say�s�  :"; cin >> Kitap_Sayisi;

            //Ge�ici dosyaya g�ncellenen bilgileri yazd�rd�m.
            dosyaYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                << Uye_No << setw(20) << Tel << setw(20)
                << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

        }
        else // E�er tc ler uyu�muyorsa burasu �al���yor ve ge�ici dosyaya g�ncellenmeyecek olan okuyucular�n bilgileri yaz�l�yor.
        {

            dosyaYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                << Uye_No << setw(20) << Tel << setw(20)
                << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

        }
    }
    //Dosyalar� kapat�yorum.
    dosyaOku.close();
    dosyaYaz.close();
    cout << "\n\nG�ncelleme i�lemi tamamland�." << endl;

    remove("Okuyucu.txt");//Okuyucu dosyas�n� siliyorum.
    rename("Gecici.txt", "Okuyucu.txt");//Art�k yeni dosyalar ge�ici dosyada oldu�u i�in onun ismini Okuyucu ile de�i�tiriyorum.

}

void Okuyucular::okuyucuSilme() {

    ofstream dosyaYaz;
    dosyaYaz.open("Gecici.txt", ios::app); //Silinmi� olan okuyucunun bilgileri d���ndaki bilgileri girmek i�in ge�ici dosya a��yorum.

    ifstream dosyaOku;
    dosyaOku.open("Okuyucu.txt", ios::in); //Okuyucu bilgilerini okumak i�in in modunda okuyucu dosyas�n� a��yorum.

    cout << "Silmek istedi�iniz okuyucunun Tc' sini giriniz: " << endl;
    cin >> gecici_tc; //Silinecek ki�inin tc siyle kar��la�t�raca��m ge�ici tc yi istiyorum.

     //Dosyay�n�n b�t�n sat�rlar�n� okumas� i�in while d�ng�s�n� kulland�m.
    while (dosyaOku >> Tc >> Okuyucu_Adi >> Okuyucu_Soyadi >> Uye_No >> Tel >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil >> gorev >> Kitap_Sayisi) {

        if (gecici_tc == Tc) // Tc ler uyu�uyorsa ekrana bilgilerini bast�r�p dosyaya yazd�rm�yorum.
        {
            cout << "Okuyucunun bilgileri:" << endl;

            cout << "\n Okuyucu TC                 :" << Tc << endl;
            cout << "\n Okuyucu adi                :" << Okuyucu_Adi << endl;
            cout << "\n Okuyucu soyadi             :" << Okuyucu_Soyadi << endl;
            cout << "\n �ye numaras�               :" << Uye_No << endl;
            cout << "\n Telefon                    :" << Tel << endl;
            cout << "\n Do�um tarihi(g�n.ay.y�l)   :" << dogum_gun << nokta << dogum_ay << nokta << dogum_yil << endl;
            cout << "\n G�revi                     :" << gorev << endl;
            cout << "\n Alabilece�i kitap say�s�   :" << Kitap_Sayisi << endl;
        }
        else//Silinecek ki�inin d���ndaki ki�ilerin bilgilerini ge�i�i dosyaya yazd�r�yorum.
        {

            dosyaYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                << Uye_No << setw(20) << Tel << setw(20)
                << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

        }
    }
    //Dosyalar� kapat�yorum.
    dosyaOku.close();
    dosyaYaz.close();
    cout << "\nSilme i�lemi tamamland�." << endl;

    remove("Okuyucu.txt");//Eski dosyay� siliyorum.
    rename("Gecici.txt", "Okuyucu.txt");//Ge�ici dosyan�n ismini de�i�tiriyorum ve yeni okuyucu dosyas� oluyor.
}

class Kitaplar :public Kutuphane {//De�i�kenleri kullanmak i�in K�t�phane class� ile kal�t�m kulland�m.
public:

    void KitapGirisi();
    void KitapGuncelleme();     //Kar���kl��� gidermek i�in fonksiyonlar� burada tan�mlay�p d��ar�da ��z�mledim.
    void KitapSilme();
};

void Kitaplar::KitapGirisi() {

    ofstream DosyaYaz;
    DosyaYaz.open("Kitaplar.txt", ios::app); //Kitaplar dosyas�n� yazma moduyla a�t�m.

    do //Ba�ka kay�tlarda yapabbilmesi i�in evet hay�r d�ng�s� kurdum.
    {
        cout << "\n Kitap ISBN        : "; cin >> isbn;
        cout << "\n Kitap ismi        : "; cin >> kitap_isim;
        cout << "\n Yazar ad�         : "; cin >> yazar_isim;
        cout << "\n Yazar soyad�      : "; cin >> yazar_soyisim;
        cout << "\n Konu              : "; cin >> konu;
        cout << "\n T�r               : "; cin >> tur;
        cout << "\n Sayfa say�s�      : "; cin >> sayfa_sayisi;

        //Bilgileri dosyaya yazd�rd�m.
        DosyaYaz << isbn << setw(20) << kitap_isim << setw(20) << yazar_isim << setw(20)
            << yazar_soyisim << setw(20) << konu << setw(20)
            << tur << setw(20) << sayfa_sayisi << "\n";

        cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;

    } while (!(cevap == 'h'));

    cout << "Kitap giri�i tamamland�. ";
    DosyaYaz.close(); //Dosyay� kapad�m.
}

void Kitaplar::KitapGuncelleme() {

    ifstream dosyaOku("Kitaplar.txt", ios::in); //Okuma moduyla kitaplar dosyas�n� a�t�m.
    ofstream dosyaYaz("gecici.txt", ios::app); //Yeni bilgileri girece�im ge�ici dosyay� yazma modunda a�t�m.

    cout << "G�ncellemek istedi�iniz kitab� giriniz:  ";

    cin >> gecici_isbn; //Dosyadaki isbn lerle kar��la�t�rmak i�in ge�ici isbn olarak okuttum. 

    //Dosyay�n�n b�t�n sat�rlar�n� okumas� i�in while d�ng�s�n� kulland�m.
    while (dosyaOku >> isbn >> kitap_isim >> yazar_isim >> yazar_soyisim >> konu >> tur >> sayfa_sayisi)
    {
        if (gecici_isbn == isbn) {//E�er isbn ler uyu�uyorsa kitab�n eski bilgilerini ekrana bast�rd�m.
            cout << "Kitab�n bilgileri:" << endl << endl;
            cout << "\n Kitap ISBN        : " << isbn;
            cout << "\n Kitap ismi        : " << kitap_isim;
            cout << "\n Yazar ad�         : " << yazar_isim;
            cout << "\n Yazar soyad�      : " << yazar_soyisim;
            cout << "\n Konu              : " << konu;
            cout << "\n T�r               : " << tur;
            cout << "\n Sayfa say�s�      : " << sayfa_sayisi;
            //yeni bilgileri istedim.
            cout << "\nYeni kitap bilgilerini giriniz." << endl;
            cout << "\n Kitap ISBN        : "; cin >> isbn;
            cout << "\n Kitap ismi        : "; cin >> kitap_isim;
            cout << "\n Yazar ad�         : "; cin >> yazar_isim;
            cout << "\n Yazar soyad�      : "; cin >> yazar_soyisim;
            cout << "\n Konu              : "; cin >> konu;
            cout << "\n T�r               : "; cin >> tur;
            cout << "\n Sayfa say�s�      : "; cin >> sayfa_sayisi;

            //Yeni bilgilerini ge�ici dosyaya yazd�rd�m.
            dosyaYaz << isbn << setw(20) << kitap_isim << setw(20) << yazar_isim << setw(20)
                << yazar_soyisim << setw(20) << konu << setw(20)
                << tur << setw(20) << sayfa_sayisi << "\n";

        }
        else {//De�i�meyecek olan kitap bilgilerini de isbn ler uyu�mad��� i�in burada ge�ici dosyaya yazd�rd�m. 
            dosyaYaz << isbn << setw(20) << kitap_isim << setw(20) << yazar_isim << setw(20)
                << yazar_soyisim << setw(20) << konu << setw(20)
                << tur << setw(20) << sayfa_sayisi << "\n";

        }
    }
    cout << endl;
    cout << "Kitap g�ncellemesi tamamlanm��t�r." << endl;
    //Dosyalar� kapatt�m.
    dosyaOku.close();
    dosyaYaz.close();
    remove("Kitaplar.txt"); //Bilgiler eskidi�i i�in dosyay� sildim.
    rename("gecici.txt", "Kitaplar.txt"); //Yeni bilgileri i�eren dosyan�n ismini de�i�tirdim.
}

void Kitaplar::KitapSilme() {
    ifstream dosyaOku("Kitaplar.txt", ios::in); //Kitaplar dosyas�n� okuma modunda a�t�m.
    ofstream dosyaYaz("gecici.txt", ios::app); //Yeni bilgileri girmek i�in ge�ici dosya olu�turdum.

    cout << "Silmek istedi�iniz kitap ISBN'sini giriniz:  ";

    cin >> gecici_isbn; //Silmek istenen bilgilerle kar��la�t�rmak i�in ge�ici isbn olarak okuttum. 

     //Dosyay�n�n b�t�n sat�rlar�n� okumas� i�in while d�ng�s�n� kulland�m.
    while (dosyaOku >> isbn >> kitap_isim >> yazar_isim >> yazar_soyisim >> konu >> tur >> sayfa_sayisi)
    {
        if (gecici_isbn == isbn) {//�sbn ler uyu�uyorsa kitab�n eski bilgilerini bas�p ge�ici doyaya yazd�rmad�m.
            cout << "Kitab�n bilgileri:" << endl << endl;
            cout << "\n Kitap ISBN        : " << isbn;
            cout << "\n Kitap ismi        : " << kitap_isim;
            cout << "\n Yazar ad�         : " << yazar_isim;
            cout << "\n Yazar soyad�      : " << yazar_soyisim;
            cout << "\n Konu              : " << konu;
            cout << "\n T�r               : " << tur;
            cout << "\n Sayfa say�s�      : " << sayfa_sayisi;
            break;

        }
        else { //�sbn ler uyu�mad��� i�in silinmeyecek olan dosyalar� ge�ici dosyaya yazd�rd�m.
            dosyaYaz << isbn << setw(20) << kitap_isim << setw(20) << yazar_isim << setw(20)
                << yazar_soyisim << setw(20) << konu << setw(20)
                << tur << setw(20) << sayfa_sayisi << "\n";

        }
    }
    cout << endl;
    cout << "Kitap silimi tamamland�." << endl;
    //Dosyalar� kapatt�m.
    dosyaOku.close();
    dosyaYaz.close();
    remove("Kitaplar.txt");//Eski bilgilere sahip dosyay� sildim.
    rename("gecici.txt", "Kitaplar.txt");//Ge�ici dosyan�n ismini de�i�tirdim.

}

class Odunc :public Kutuphane {//De�i�kenleri kullanmak i�in K�t�phane class� ile kal�t�m kulland�m.
public:


    void oduncKitapGiris();
    void iadeKitapDonus();     //Kar���kl��� gidermek i�in fonksiyonlar� burada tan�mlay�p d��ar�da ��z�mledim.
    void okuyucuVeKitaplar();

};

void Odunc::oduncKitapGiris()
{
    ofstream dosyaYaz("Odunc.txt", ios::app);//�d�n� al�nacak kitaplar i�in Odunc dosyas�n� yazma modunda a�t�m.

    ifstream okuyucuOku("Okuyucu.txt", ios::in);//Girilecek Tc bilgisnin do�rulu�una bakmak i�in okuyucu dosyas�n� okuma modunda a�t�m.
    ifstream kitapOku("Kitaplar.txt");//Girilecek ISBN bilgisinin do�rulu�una bakmak i�in okuyucu dosyas�n� okuma modunda a�t�m.


    cout << "�d�n� al�nacak kitab�n ISBN'sini ve alacak okuyucunun TC'sini giriniz. " << endl;
    //Temel bilgiler olan tc ve isbn yi kullan�c�dan istedim.
    cout << "Okuyucu TC:  "; cin >> gecici_tc;
    cout << "Kitap ISBN:  "; cin >> gecici_isbn;

    //Tc bilgisini kontrol etmek i�in while d�ng�s�yle okuyucu dosyas�n� dosyan�n sonuna (eof) kadar okuttum.
    while (!okuyucuOku.eof())
    {
        okuyucuOku >> Tc >> Okuyucu_Adi >> Okuyucu_Soyadi >> Uye_No >> Tel >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil >> gorev >> Kitap_Sayisi;
        if (gecici_tc == Tc)
        {
            dosyaYaz << Tc;//E�er Tc ler uyu�uyorsa Tc yi Odunc dosyas�na yazd�rd�m.
            gecici1tc = gecici_tc; // Girilen tc bilgisi her okuyucu dosyas�n� okumada de�i�ece�i i�in burada gecici1tc ile onu ald�m.
            break;
        }

    }
    //ISBN bilgisini kontrol etmek i�in while d�ng�s�yle kitaplar dosyas�n� okuttum.
    while (!kitapOku.eof())
    {
        kitapOku >> isbn >> kitap_isim >> yazar_isim >> yazar_soyisim >> konu >> tur >> sayfa_sayisi;

        // Hem isbn bilgisini hem de gecici1tc nin de�er al�p almamas� ile bundan �nceki if in �al���rl���n� sorgulad�m.
        if (gecici_isbn == isbn && gecici_tc == gecici1tc)//E�er bundan �nceki if �al��m��sa yani tcler uyu�mu�sa bu if �al���r.
        {

            dosyaYaz << setw(20) << isbn; //�sbn bilgisi ve tc bilgisi do�ruysa isbn yi de Odunc dosyas�na yazd�rd�m.

            gecici1isbn = gecici_isbn; // Burada bir sonraki if else i�in ve kitapokuma d�ng�s�nde s�rekli isbn de�i�ece�i i�in uyu�an isbnyi gecici1isbn ile tuttum.
            break;
        }

    }
    //��lem kar���kl���n� �nlemek ve e�er tc veya isbn yanl��sa program�n devam etmesini �nlemek i�in bir if else daha olu�turdum. 
    if (gecici_isbn == gecici1isbn && gecici_tc == gecici1tc) //E�er bu if �al���rsa asl�nda k�t�phane class �nda 0 a e�itledi�im gecici1isbn ile gecici1tc ye
                                                              //de�er atand���n� ve yukar�daki iflerin �al��t���n� g�r�r�z.Yani tc ile isbn do�rudur.
    {
        cout << "�d�n� alma tarihi g�n.ay.y�l �eklinde giriniz: " << endl;//Kullan�c�dan �d�n� alma tarihini istedim.

        cin >> odunc_gun >> nokta >> odunc_ay >> nokta >> odunc_yil;

        //Son iade tarihini 15 g�n sonras� yapt�m ve buna g�re iflerle ay y�l ve g�nlerin artmas�n� kontrol ettim.
        if (odunc_ay < 12) {//E�er Kullan�c� ay� 12 den k���k girdiyse bir sonraki y�la atlayamad��� i�in sadece g�n ve ay de�erlerini de�i�tirdim.

            if ((odunc_gun <= 15) && (odunc_gun > 0)) //�d�n� g�n� 15 ten k���kse iade g�n�ne 15 eklenir, ay ve y�l �d�n�tekilere e�it olur.
            {
                iade_gun = odunc_gun + 15;
                iade_ay = odunc_ay;
                iade_yil = odunc_yil;
            }
            else if (odunc_gun > 15)//�d�n� g�n� 15 ten b�y�kse ay bir artar, y�l ayn� kal�r g�n ise bir sonraki aya d�nd��� i�in 15 eksilir.
            {
                iade_ay = odunc_ay + 1;
                iade_gun = odunc_gun - 15;
                iade_yil = odunc_yil;
            }
        }
        else if (odunc_ay == 12) {////E�er Kullan�c� ay� 12 girdiyse bir sonraki y�la atlayabilece�i i�in y�l� da kontrol ederim.

            if ((odunc_gun <= 15) && (odunc_gun > 0)) //12.ayda da olsa �d�n� g�n� 15 ten k���k girilirse bir sonraki aya veya y�la atlayamaz ve sadece g�ne 15 eklenir.
            {
                iade_gun = odunc_gun + 15;
                iade_ay = odunc_ay;
                iade_yil = odunc_yil;
            }
            else if (odunc_gun > 15)//12.ay oldu�undan 15 ten b�y�k g�n girilirse y�l bir artar ve ay Ocak'a d�ner.
            {
                iade_ay = 01;
                iade_gun = odunc_gun - 15;
                iade_yil = odunc_yil + 1;
            }

        }
        //Kitap �d�n� tarihini ekrana da bast�r�yorum.
        cout << "\nKitap iade tarihi 15 g�n sonrad�r ==>  " << iade_gun << nokta << iade_ay << nokta << iade_yil << "\n�d�n� alma i�lemi tamamland�." << endl;

        //Son olarak kitap �d�n� tarihini Odunc dosyas�na yazd�r�yorum.
        dosyaYaz << setw(20) << odunc_gun << ' ' << nokta << ' ' << odunc_ay << ' ' << nokta << ' ' << odunc_yil << setw(20) << iade_gun << ' ' << nokta << ' ' << iade_ay << ' ' << nokta << ' ' << iade_yil << endl;


        //Okuyucu kitap �d�n� ald��� i�in alabilece�i kitap say�s�n� azaltmam�z gerekiyor.
        ifstream OkuyucuOku("Okuyucu.txt"); //Okuyucu dosyas�n� okuma modunda a��yorum.

        ofstream yeniOkuyucuYaz("gecici.txt", ios::out);//Kitap say�s� de�i�kenini de�i�tirdi�imiz i�in ge�ici dosya olu�turup yazma modunda a��yorum.

        //While d�ng�s�yle okuyucu dosyas�n� okutuyorum.
        while (OkuyucuOku >> Tc >> Okuyucu_Adi >> Okuyucu_Soyadi >> Uye_No >> Tel >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil >> gorev >> Kitap_Sayisi) {


            if (gecici_tc == Tc) {//E�er tc ler uyu�uyorsa ge�ici kitap say�s�n� 1 eksiltip dosyaya ve ekrana bast�r�yorum.

                int gecici_kitapSayi = Kitap_Sayisi - 1;
                yeniOkuyucuYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                    << Uye_No << setw(20) << Tel << setw(20)
                    << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << gecici_kitapSayi << "\n";
                cout << "\nOkuyucunun " << gecici_kitapSayi << " tane kitap alma hakk� kalm��t�r." << endl;
            }
            else //else e d���yorsa okuyucu kitap almam�� demektir bu y�zden bilgileri direkt yazd�r�yorum ge�ici dosyaya.
            {

                yeniOkuyucuYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                    << Uye_No << setw(20) << Tel << setw(20)
                    << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

            }

        }
        //Okuyucuyla i�imiz bitti�i i�in dosyalar� kapat�yorum.
        yeniOkuyucuYaz.close();
        OkuyucuOku.close();

    }
    else {//En son da isbn veya tc uyu�muyorsa bunu ekrana yazd�r�p program� sonland�r�yorum.
        cout << "Yanl�� TC veya ISBN.";
        system("PAUSE");

    }
    //Dosyalar� kapat�yorum.
    dosyaYaz.close();
    okuyucuOku.close();
    kitapOku.close();

    remove("Okuyucu.txt");//Okuyucu dosyas�ndaki Kitap_sayisi de�i�ti�i i�in dosyay� siliyorum.
    rename("gecici.txt", "Okuyucu.txt");//Ge�ici dosyadaki yeni bilgiler oldu�u i�in ismini de�i�tiriyorum.


}

void Odunc::okuyucuVeKitaplar() {

    cout << "Okuyucunun TC'sini giriniz: ";
    cin >> gecici_tc;

    ifstream dosyaOku("Odunc.txt", ios::in);//Gerekli bilgileri okumak i�in Odunc dosyas�n� a��yorum.
    ifstream kitapOku("Kitaplar.txt", ios::in);//Gerekli bilgileri okumak i�in Kitaplar dosyas�n� a��yorum.

    //While d�ng�s�yle Odunc dosyas�n� okutuyorum.
    while (!dosyaOku.eof()) {

        dosyaOku >> Tc >> isbn >> odunc_gun >> nokta >> odunc_ay >> nokta >> odunc_yil >> iade_gun >> nokta >> iade_ay >> nokta >> iade_yil;

        gecici_isbn = isbn; //Kitap dosyas�n� okuttu�umda isbn tekrar de�i�ece�i i�in ge�ici isbn yi Odunc dosyas�ndan ald���m isbn ye e�itliyorum.

        if (gecici_tc == Tc)//Odunc dosyas�nda girilen Tc den varsa e�itleniyor ve ko�ul sa�lan�yor.
        {
            //Kitaplar dosyas�ndaki bilgileri girebilmek i�in kitaplar dosyas�n� while d�ng�s�nde sat�r sat�r okutuyorum.
            while (kitapOku >> isbn >> kitap_isim >> yazar_isim >> yazar_soyisim >> konu >> tur >> sayfa_sayisi) {

                if (gecici_isbn == isbn)//E�er odunc dosyas�ndaki isbn ile kitaplar dosyas�ndaki isbn uyu�uyorsa ko�ul sa�lan�r ve bilgiler girilir.
                {
                    cout << "\nKitap ISBN:         " << gecici_isbn;
                    cout << "\nKitap ismi:         " << kitap_isim;
                    cout << "\n�d�n� alma tarihi:  " << odunc_gun << nokta << odunc_ay << nokta << odunc_yil;
                    cout << "\n�ade tarihi:        " << iade_gun << nokta << iade_ay << nokta << iade_yil << endl;
                    break;
                }

            }

        }
    }
    //Dosyalar� kapat�yorum�
    dosyaOku.close();
    kitapOku.close();
}

void Odunc::iadeKitapDonus() {
    ifstream dosyaOku("Odunc.txt", ios::in);//Gerekli bilgileri okumak i�in Odunc dosyas�n� in modunda a�t�m.
    ofstream dosyaYaz("iade.txt", ios::app); //�ade edilip geri d�nen kitab� Odunc dosyas�ndan silece�imiz i�in iade dosyas� olu�turdum.

    ifstream okuyucuKitapokuma("Okuyucu.txt", ios::in); //Gerekli bilgiler i�in okuyucu dosyas�n� a�t�m.
    ofstream okuyucukitapekleme("yedek.txt", ios::app); //Okuyucu kitab� iade etti�inde alabilece�i kitap say�s� artaca�� i�in yeni okuyucu dosyas� olu�turuyorum.

    cout << "�ade edilecek kitab�n ISBN'sini giriniz:  ";

    cin >> gecici_isbn;

    //Odunc al�nan kitab�n varl���n� sorgulamak i�in while d�ng�s�nde Odunc dosyas�n� okuttum.
    while (dosyaOku >> Tc >> isbn >> odunc_gun >> nokta >> odunc_ay >> nokta >> odunc_yil >> iade_gun >> nokta >> iade_ay >> nokta >> iade_yil)
    {
        if (gecici_isbn == isbn) //E�leniyorsa kitab�n �d�n� al�nd��� do�rudur, program devam eder.//Ayn� zamanda kitab� �d�n� listesinden silmek i�in dosyaya yazd�rm�yorum.
        {
            //Bilgilerini ekrana bast�rd�m.
            cout << "\nKitab� alan ki�inin TC'si :  " << Tc;
            cout << "\n�d�n� tarihi              :  " << odunc_gun << nokta << odunc_ay << nokta << odunc_yil;
            cout << "\nSon iade tarihi           :  " << iade_gun << nokta << iade_ay << nokta << iade_yil;

            gecici_tc = Tc; //�d�n� alan ki�inin TC sini tutabilmek i�in ge�ici tc ye e�itledim.

            //�d�n kitab� alan okuyucuyu bulabilmek i�in Okuyucu dosyas�n� while d�ng�s�yle okuttum.
            while (okuyucuKitapokuma >> Tc >> Okuyucu_Adi >> Okuyucu_Soyadi >> Uye_No >> Tel >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil >> gorev >> Kitap_Sayisi) {
                if (gecici_tc == Tc)//Tc ler uyu�uyorsa kitap say�s�n� bir artt�rd�m ��nk� kitab� iade eden ki�iyi bulmu� oluyoruz.
                {
                    Kitap_Sayisi++;
                    //Yeni kitap say�s� bilgili halini ge�ici dosyaya yazd�rd�m. 
                    okuyucukitapekleme << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                        << Uye_No << setw(20) << Tel << setw(20)
                        << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

                }
                else //E�er kitab� �d�n� alan ki�i de�ilse direkt bilgilerini yeni dosyaya yazd�rd�m.
                {
                    okuyucukitapekleme << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                        << Uye_No << setw(20) << Tel << setw(20)
                        << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

                }
            }

        }
        else//�ade edilmemi� yani geri d�nmeyen kitaplar� yeni �d�n� dosyas�na yazd�r�yorum.
        {
            dosyaYaz << Tc << setw(20) << isbn << setw(20) << odunc_gun << ' ' << nokta << ' ' << odunc_ay << ' ' << nokta << ' ' << odunc_yil << setw(20) << iade_gun << ' ' << nokta << ' ' << iade_ay << ' ' << nokta << ' ' << iade_yil << endl;

        }
    }
    cout << endl;
    cout << "Kitap iadesi al�nd�." << endl;
    //Dosyalar� kapat�yorum.
    okuyucukitapekleme.close();
    okuyucuKitapokuma.close();
    dosyaOku.close();
    dosyaYaz.close();

    //Bilgileri de�i�en eski dosyalar� silip yenilerinin isimlerini de�i�tiriyorum.
    remove("Okuyucu.txt");
    rename("yedek.txt", "Okuyucu.txt");

    remove("Odunc.txt");
    rename("iade.txt", "Odunc.txt");


}

int main()
{
    setlocale(LC_ALL, "Turkish");

    //Sistem saatini almak i�in gerekli de�i�kenleri giriyorum.
    time_t giris = time(nullptr);
    cout << "Giri� zaman�n�z: " << ctime(&giris);//Ekrana bast�r�yorum.

    //Giri� ve ��k�� saatlerini, kullan�c� ad�n�, �ifreyi kullan�c� dosyas�na kaydedebilmek i�in de�i�kenleri tan�ml�yorum.   
    string girisGun, girisgun, girisAy, girisYil;

    string cikisGun, cikisgun, cikisAy, cikisYil;

    int saat, dakika, saniye;

    char ikinokta;

    string kullaniciAdi, sifre;


    cout << "\n*************************************************************" << endl << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^KULLANICI G�R���^^^^^^^^^^^^^^^^^^^^^^^^ " << endl << endl;


    ifstream dosyaOku("kullanicilar.txt", ios::in);//Okuma modunda kullan�c�lar dosyas�n� a�t�m.
    ofstream dosyaYaz("kullanicilar.txt", ios::app);//Yazma modunda kullan�c�lar dosyas�n� a�t�m.

    string kAdi1, kadi, sfre;

    cout << "\n\nKullan�c� ad�: "; cin >> kadi;  //Kullan�c� ad�n� ve �ifreyi ge�i�i olacak �ekilde okuttum.
    cout << "\n�ifre       : "; cin >> sfre;

    //Kullan�c�lar dosyas�ndaki d�zene g�re while d�ng�s�yle dosyay� sat�r sat�r okuttum.
    while (!dosyaOku.eof()) {
        dosyaOku >> kullaniciAdi >> sifre >> girisGun >> girisAy >> girisgun >> saat >> ikinokta >> dakika >> ikinokta >> saniye >> girisYil;
        dosyaOku >> cikisGun >> cikisAy >> cikisgun >> saat >> ikinokta >> dakika >> ikinokta >> saniye >> cikisYil;
        if (kadi == kullaniciAdi) //Kullan�c� ad� kullan�c�n�n girdi�iyle uyu�uyorsa ko�ul �al���r.
        {
            kAdi1 = kadi; //Ko�ulun �al��t���n� g�stermesi i�in kadi yi kAdi1 e e�itliyorum ki bunu di�er if te kullanabileyim.

        }
        if (kAdi1 == kadi && sfre == sifre) //Bu ko�ulun sa�lanmas� bir �nceki if in �al��t���n� g�sterir ��nk� kAdi1 e bir de�er tan�mlamam��t�m.
        {                               //B�ylece hem �ifreyi hem de kullan�c� ad�n� kontrol etmi� oldum.
            cout << "\nGiri� ba�ar�l�." << endl;
            dosyaYaz << endl << kadi << setw(10) << sfre; //Dosyaya kullan�c� ad�n� ve �ifreyi yazd�r�yorum.
            break;

        }

    }
    if (kAdi1 != kadi && sfre != sifre) //Bu ko�ul yukar�daki iki if in de �al��mad���n� yani kullan�c� ad� veya(ve) �ifrenin yanl�� oldu�unu g�steriyor.
    {
        cout << "\nGiri� ba�ar�s�z." << endl;

        time_t hataliCikis = time(nullptr);

        cout << "\n��k�� zaman�n�z: " << ctime(&hataliCikis); //��k�� saatini ekrana yazd�r�yorum.

        system("PAUSE");
        return EXIT_SUCCESS;
    }


    int secim = 1;
    char cevap = 'e';

    //Kullan�c� giri�i ba�ar�l� olursa k�t�phane sistemine giriyoruz ve se�im yapmas�n� istiyorum kullan�c�dan.
    do {
        cout << "^^^^^^^^^^^^K�T�PHANE S�STEM�NE HO�GELD�N�Z^^^^^^^^^^^^^^^" << endl << endl << endl;
        cout << "             Ne yapmak istiyorsunuz ? " << endl << endl;
        cout << "             1) Okuyucu kayd� " << endl;
        cout << "             2) Okuyucu kayd� g�ncelleme  " << endl;
        cout << "             3) Okuyucu silme " << endl;
        cout << "             4) Okuyucu �zerindeki kitaplar listesi" << endl;
        cout << "             5) Okuyucu kitap �d�n� alma" << endl;
        cout << "             6) Okuyucu kitap iadesi" << endl;
        cout << "             7) Kitap ekleme" << endl;
        cout << "             8) Kitap g�ncelleme" << endl;
        cout << "             9) Kitap silme" << endl << endl;
        cout << "��lem se�iniz.........  ";
        cin >> secim;
    } while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9);

    Okuyucular okuyucu; //Okuyucular class �ndaki fonksiyonlar i�in nesne olu�turuyorum.

    if (secim == 1) {
        okuyucu.okuyucuGirisi();
    }
    if (secim == 2) {
        okuyucu.okuyucuGuncelleme();
    }
    if (secim == 3) {
        okuyucu.okuyucuSilme();
    }
    Odunc odunc;//Odunc class �ndaki fonksiyonlar i�in nesne olu�turuyorum.
    if (secim == 4) {
        odunc.okuyucuVeKitaplar();
    }

    if (secim == 5) {
        odunc.oduncKitapGiris();
    }

    if (secim == 6) {
        odunc.iadeKitapDonus();
    }
    Kitaplar kitap;//Kitaplar class �ndaki fonksiyonlar i�in nesne olu�turuyorum.

    if (secim == 7) {
        kitap.KitapGirisi();
    }
    if (secim == 8) {
        kitap.KitapGuncelleme();
    }
    if (secim == 9) {
        kitap.KitapSilme();
    }


    dosyaYaz << setw(30) << ctime(&giris); //En ba�taki giri� zaman�n� Kullanicilar dosyas�na kaydediyorum.

    //Tekrar sistem zaman�n� istiyorum ve ekrana bast�r�yorum.
    time_t cikis = time(nullptr);
    cout << "\n��k�� zaman�n�z: " << ctime(&cikis) << endl;


    dosyaYaz << setw(30) << ctime(&cikis) << endl;//��k�� zaman�n� da Kullanicilar dosyas�na kaydediyorum.

    //Dosyalar� kapat�yorum.
    dosyaOku.close();
    dosyaYaz.close();

    system("PAUSE");
    return EXIT_SUCCESS;
}


