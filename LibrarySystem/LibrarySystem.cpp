#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;
class Kutuphane { //Bütün deðiþkenleri kolay kullaným için Kütüphane adlý classta topladým.
public:
    int secim;
    char cevap = 'e';
    //Okuyucu deðiþkenleri
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

    //Kitap deðiþkenleri
    long long isbn;
    string kitap_isim;
    string yazar_isim;
    string yazar_soyisim;
    string konu;
    string tur;
    int sayfa_sayisi;

    //Fonksiyonlarda kullanacaðým geçiçi deðiþkenler
    long long gecici_isbn;
    long long gecici_tc;
    char nokta = '.';
    long long gecici1tc = 0;
    long long gecici1isbn = 0;

    //Ödünç ve iade deðiþkenleri
    int odunc_gun;
    int odunc_ay;
    int odunc_yil;
    int iade_gun;
    int iade_ay;
    int iade_yil;

};

class Okuyucular :public Kutuphane {//Deðiþkenleri kullanmak için Kütüphane classý ile kalýtým kullandým.
public:

    void okuyucuGirisi();
    void okuyucuGuncelleme();  //Karýþýklýðý gidermek için fonksiyonlarý burada tanýmlayýp dýþarýda çözümledim.
    void okuyucuSilme();
};

void Okuyucular::okuyucuGirisi() {

    ofstream DosyaYaz;
    DosyaYaz.open("Okuyucu.txt", ios::app); //Okuyucu giriþi için yazma(app) modunda okuyucu.txt dosyasýný açtým.

    do //Kullanýcý e(evet) veya h(hayýr) harfini girmesine baðlý olan bir döngü oluþturdum.
    {
        //Kullanýcýdan okuyucu bilgilerini girmesini istedim.
        cout << "\n Okuyucu TC                                 : "; cin >> Tc;
        cout << "\n Okuyucu adi                                : "; cin >> Okuyucu_Adi;
        cout << "\n Okuyucu soyadi                             : "; cin >> Okuyucu_Soyadi;
        cout << "\n Üye numarasý                               : "; cin >> Uye_No;
        cout << "\n Telefon                                    : "; cin >> Tel;
        cout << "\n Doðum tarihi(gün.ay.yýl þeklinde giriniz)  : "; cin >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil;
        cout << "\n Görevi                                     : "; cin >> gorev;
        cout << "\n Alabileceði kitap sayýsý                   : 5";
        //Alabileceði kitap sayýsýný 5ile sýnýrladým bu yüzden onu kendim yazdým.
        Kitap_Sayisi = 5;
        //Dosyaya bilgileri yazdýrdým.
        DosyaYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
            << Uye_No << setw(20) << Tel << setw(20)
            << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";


        cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;
    } while (!(cevap == 'h'));

    cout << "\n Okuyucu kaydý tamamlandý. " << endl;
    DosyaYaz.close(); //Kullanýcý h harfini girdiði için kayýt tamamlandý ve dosyayý kapattým.

}

void Okuyucular::okuyucuGuncelleme() {

    ifstream dosyaOku("Okuyucu.txt");//Okuyucu bilgilerini okumak için dosyayý açtým.
    ofstream dosyaYaz("Gecici.txt");//Sonra ismini deðiþtirmek ve yeni okuyucu bilgilerini girmek üzere geçici bir dosya oluþturdum.

    cout << "Güncellemek istediðiniz okuyucunun Tc'sini giriniz:" << endl;
    cin >> gecici_tc; //Okuyucular dosyasýný okuttuðumda Tc ile eþleyebilmek için kullanýcýdan aldýðým bilgiyi geçici Tc olarak okuttum.

    //Dosyayýnýn bütün satýrlarýný okumasý için while döngüsünü kullandým.
    while (dosyaOku >> Tc >> Okuyucu_Adi >> Okuyucu_Soyadi >> Uye_No >> Tel >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil >> gorev >> Kitap_Sayisi) {

        if (gecici_tc == Tc) {//Eðer kullanýcýdan aldýðým geçici tc ile okutulan tc uyuþuyorsa istenen okuyucuyu bulmuþ oluyorum.
            cout << "Okuyucunun eski bilgileri:" << endl;//Okuyucunun eski bilgilerini görmek isteyebilir diye yazdýrdým.

            cout << "\n Okuyucu TC              :" << Tc << endl;
            cout << "\n Okuyucu adi             :" << Okuyucu_Adi << endl;
            cout << "\n Okuyucu soyadi          :" << Okuyucu_Soyadi << endl;
            cout << "\n Üye numarasý            :" << Uye_No << endl;
            cout << "\n Telefon                 :" << Tel << endl;
            cout << "\n Doðum tarihi            :" << dogum_gun << nokta << dogum_ay << nokta << dogum_yil << endl;
            cout << "\n Görevi                  :" << gorev << endl;
            cout << "\n Alabileceði kitap sayýsý:" << Kitap_Sayisi << endl;
            cout << "*******************************************************" << endl;
            cout << "Yeni bilgileri giriniz:" << endl;//Okuyucunun güncellenecek bilgilerini istedim.
            cout << "\n Okuyucu TC                :"; cin >> Tc;
            cout << "\n Okuyucu adi               :"; cin >> Okuyucu_Adi;
            cout << "\n Okuyucu soyadi            :"; cin >> Okuyucu_Soyadi;
            cout << "\n Üye numarasý              :"; cin >> Uye_No;
            cout << "\n Telefon                   :"; cin >> Tel;
            cout << "\n Doðum tarihi(gün.ay.yýl)  :"; cin >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil;
            cout << "\n Görevi                    :"; cin >> gorev;
            cout << "\n Alabileceði kitap sayýsý  :"; cin >> Kitap_Sayisi;

            //Geçici dosyaya güncellenen bilgileri yazdýrdým.
            dosyaYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                << Uye_No << setw(20) << Tel << setw(20)
                << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

        }
        else // Eðer tc ler uyuþmuyorsa burasu çalýþýyor ve geçici dosyaya güncellenmeyecek olan okuyucularýn bilgileri yazýlýyor.
        {

            dosyaYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                << Uye_No << setw(20) << Tel << setw(20)
                << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

        }
    }
    //Dosyalarý kapatýyorum.
    dosyaOku.close();
    dosyaYaz.close();
    cout << "\n\nGüncelleme iþlemi tamamlandý." << endl;

    remove("Okuyucu.txt");//Okuyucu dosyasýný siliyorum.
    rename("Gecici.txt", "Okuyucu.txt");//Artýk yeni dosyalar geçici dosyada olduðu için onun ismini Okuyucu ile deðiþtiriyorum.

}

void Okuyucular::okuyucuSilme() {

    ofstream dosyaYaz;
    dosyaYaz.open("Gecici.txt", ios::app); //Silinmiþ olan okuyucunun bilgileri dýþýndaki bilgileri girmek için geçici dosya açýyorum.

    ifstream dosyaOku;
    dosyaOku.open("Okuyucu.txt", ios::in); //Okuyucu bilgilerini okumak için in modunda okuyucu dosyasýný açýyorum.

    cout << "Silmek istediðiniz okuyucunun Tc' sini giriniz: " << endl;
    cin >> gecici_tc; //Silinecek kiþinin tc siyle karþýlaþtýracaðým geçici tc yi istiyorum.

     //Dosyayýnýn bütün satýrlarýný okumasý için while döngüsünü kullandým.
    while (dosyaOku >> Tc >> Okuyucu_Adi >> Okuyucu_Soyadi >> Uye_No >> Tel >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil >> gorev >> Kitap_Sayisi) {

        if (gecici_tc == Tc) // Tc ler uyuþuyorsa ekrana bilgilerini bastýrýp dosyaya yazdýrmýyorum.
        {
            cout << "Okuyucunun bilgileri:" << endl;

            cout << "\n Okuyucu TC                 :" << Tc << endl;
            cout << "\n Okuyucu adi                :" << Okuyucu_Adi << endl;
            cout << "\n Okuyucu soyadi             :" << Okuyucu_Soyadi << endl;
            cout << "\n Üye numarasý               :" << Uye_No << endl;
            cout << "\n Telefon                    :" << Tel << endl;
            cout << "\n Doðum tarihi(gün.ay.yýl)   :" << dogum_gun << nokta << dogum_ay << nokta << dogum_yil << endl;
            cout << "\n Görevi                     :" << gorev << endl;
            cout << "\n Alabileceði kitap sayýsý   :" << Kitap_Sayisi << endl;
        }
        else//Silinecek kiþinin dýþýndaki kiþilerin bilgilerini geçiçi dosyaya yazdýrýyorum.
        {

            dosyaYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                << Uye_No << setw(20) << Tel << setw(20)
                << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

        }
    }
    //Dosyalarý kapatýyorum.
    dosyaOku.close();
    dosyaYaz.close();
    cout << "\nSilme iþlemi tamamlandý." << endl;

    remove("Okuyucu.txt");//Eski dosyayý siliyorum.
    rename("Gecici.txt", "Okuyucu.txt");//Geçici dosyanýn ismini deðiþtiriyorum ve yeni okuyucu dosyasý oluyor.
}

class Kitaplar :public Kutuphane {//Deðiþkenleri kullanmak için Kütüphane classý ile kalýtým kullandým.
public:

    void KitapGirisi();
    void KitapGuncelleme();     //Karýþýklýðý gidermek için fonksiyonlarý burada tanýmlayýp dýþarýda çözümledim.
    void KitapSilme();
};

void Kitaplar::KitapGirisi() {

    ofstream DosyaYaz;
    DosyaYaz.open("Kitaplar.txt", ios::app); //Kitaplar dosyasýný yazma moduyla açtým.

    do //Baþka kayýtlarda yapabbilmesi için evet hayýr döngüsü kurdum.
    {
        cout << "\n Kitap ISBN        : "; cin >> isbn;
        cout << "\n Kitap ismi        : "; cin >> kitap_isim;
        cout << "\n Yazar adý         : "; cin >> yazar_isim;
        cout << "\n Yazar soyadý      : "; cin >> yazar_soyisim;
        cout << "\n Konu              : "; cin >> konu;
        cout << "\n Tür               : "; cin >> tur;
        cout << "\n Sayfa sayýsý      : "; cin >> sayfa_sayisi;

        //Bilgileri dosyaya yazdýrdým.
        DosyaYaz << isbn << setw(20) << kitap_isim << setw(20) << yazar_isim << setw(20)
            << yazar_soyisim << setw(20) << konu << setw(20)
            << tur << setw(20) << sayfa_sayisi << "\n";

        cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;

    } while (!(cevap == 'h'));

    cout << "Kitap giriþi tamamlandý. ";
    DosyaYaz.close(); //Dosyayý kapadým.
}

void Kitaplar::KitapGuncelleme() {

    ifstream dosyaOku("Kitaplar.txt", ios::in); //Okuma moduyla kitaplar dosyasýný açtým.
    ofstream dosyaYaz("gecici.txt", ios::app); //Yeni bilgileri gireceðim geçici dosyayý yazma modunda açtým.

    cout << "Güncellemek istediðiniz kitabý giriniz:  ";

    cin >> gecici_isbn; //Dosyadaki isbn lerle karþýlaþtýrmak için geçici isbn olarak okuttum. 

    //Dosyayýnýn bütün satýrlarýný okumasý için while döngüsünü kullandým.
    while (dosyaOku >> isbn >> kitap_isim >> yazar_isim >> yazar_soyisim >> konu >> tur >> sayfa_sayisi)
    {
        if (gecici_isbn == isbn) {//Eðer isbn ler uyuþuyorsa kitabýn eski bilgilerini ekrana bastýrdým.
            cout << "Kitabýn bilgileri:" << endl << endl;
            cout << "\n Kitap ISBN        : " << isbn;
            cout << "\n Kitap ismi        : " << kitap_isim;
            cout << "\n Yazar adý         : " << yazar_isim;
            cout << "\n Yazar soyadý      : " << yazar_soyisim;
            cout << "\n Konu              : " << konu;
            cout << "\n Tür               : " << tur;
            cout << "\n Sayfa sayýsý      : " << sayfa_sayisi;
            //yeni bilgileri istedim.
            cout << "\nYeni kitap bilgilerini giriniz." << endl;
            cout << "\n Kitap ISBN        : "; cin >> isbn;
            cout << "\n Kitap ismi        : "; cin >> kitap_isim;
            cout << "\n Yazar adý         : "; cin >> yazar_isim;
            cout << "\n Yazar soyadý      : "; cin >> yazar_soyisim;
            cout << "\n Konu              : "; cin >> konu;
            cout << "\n Tür               : "; cin >> tur;
            cout << "\n Sayfa sayýsý      : "; cin >> sayfa_sayisi;

            //Yeni bilgilerini geçici dosyaya yazdýrdým.
            dosyaYaz << isbn << setw(20) << kitap_isim << setw(20) << yazar_isim << setw(20)
                << yazar_soyisim << setw(20) << konu << setw(20)
                << tur << setw(20) << sayfa_sayisi << "\n";

        }
        else {//Deðiþmeyecek olan kitap bilgilerini de isbn ler uyuþmadýðý için burada geçici dosyaya yazdýrdým. 
            dosyaYaz << isbn << setw(20) << kitap_isim << setw(20) << yazar_isim << setw(20)
                << yazar_soyisim << setw(20) << konu << setw(20)
                << tur << setw(20) << sayfa_sayisi << "\n";

        }
    }
    cout << endl;
    cout << "Kitap güncellemesi tamamlanmýþtýr." << endl;
    //Dosyalarý kapattým.
    dosyaOku.close();
    dosyaYaz.close();
    remove("Kitaplar.txt"); //Bilgiler eskidiði için dosyayý sildim.
    rename("gecici.txt", "Kitaplar.txt"); //Yeni bilgileri içeren dosyanýn ismini deðiþtirdim.
}

void Kitaplar::KitapSilme() {
    ifstream dosyaOku("Kitaplar.txt", ios::in); //Kitaplar dosyasýný okuma modunda açtým.
    ofstream dosyaYaz("gecici.txt", ios::app); //Yeni bilgileri girmek için geçici dosya oluþturdum.

    cout << "Silmek istediðiniz kitap ISBN'sini giriniz:  ";

    cin >> gecici_isbn; //Silmek istenen bilgilerle karþýlaþtýrmak için geçici isbn olarak okuttum. 

     //Dosyayýnýn bütün satýrlarýný okumasý için while döngüsünü kullandým.
    while (dosyaOku >> isbn >> kitap_isim >> yazar_isim >> yazar_soyisim >> konu >> tur >> sayfa_sayisi)
    {
        if (gecici_isbn == isbn) {//Ýsbn ler uyuþuyorsa kitabýn eski bilgilerini basýp geçici doyaya yazdýrmadým.
            cout << "Kitabýn bilgileri:" << endl << endl;
            cout << "\n Kitap ISBN        : " << isbn;
            cout << "\n Kitap ismi        : " << kitap_isim;
            cout << "\n Yazar adý         : " << yazar_isim;
            cout << "\n Yazar soyadý      : " << yazar_soyisim;
            cout << "\n Konu              : " << konu;
            cout << "\n Tür               : " << tur;
            cout << "\n Sayfa sayýsý      : " << sayfa_sayisi;
            break;

        }
        else { //Ýsbn ler uyuþmadýðý için silinmeyecek olan dosyalarý geçici dosyaya yazdýrdým.
            dosyaYaz << isbn << setw(20) << kitap_isim << setw(20) << yazar_isim << setw(20)
                << yazar_soyisim << setw(20) << konu << setw(20)
                << tur << setw(20) << sayfa_sayisi << "\n";

        }
    }
    cout << endl;
    cout << "Kitap silimi tamamlandý." << endl;
    //Dosyalarý kapattým.
    dosyaOku.close();
    dosyaYaz.close();
    remove("Kitaplar.txt");//Eski bilgilere sahip dosyayý sildim.
    rename("gecici.txt", "Kitaplar.txt");//Geçici dosyanýn ismini deðiþtirdim.

}

class Odunc :public Kutuphane {//Deðiþkenleri kullanmak için Kütüphane classý ile kalýtým kullandým.
public:


    void oduncKitapGiris();
    void iadeKitapDonus();     //Karýþýklýðý gidermek için fonksiyonlarý burada tanýmlayýp dýþarýda çözümledim.
    void okuyucuVeKitaplar();

};

void Odunc::oduncKitapGiris()
{
    ofstream dosyaYaz("Odunc.txt", ios::app);//Ödünç alýnacak kitaplar için Odunc dosyasýný yazma modunda açtým.

    ifstream okuyucuOku("Okuyucu.txt", ios::in);//Girilecek Tc bilgisnin doðruluðuna bakmak için okuyucu dosyasýný okuma modunda açtým.
    ifstream kitapOku("Kitaplar.txt");//Girilecek ISBN bilgisinin doðruluðuna bakmak için okuyucu dosyasýný okuma modunda açtým.


    cout << "Ödünç alýnacak kitabýn ISBN'sini ve alacak okuyucunun TC'sini giriniz. " << endl;
    //Temel bilgiler olan tc ve isbn yi kullanýcýdan istedim.
    cout << "Okuyucu TC:  "; cin >> gecici_tc;
    cout << "Kitap ISBN:  "; cin >> gecici_isbn;

    //Tc bilgisini kontrol etmek için while döngüsüyle okuyucu dosyasýný dosyanýn sonuna (eof) kadar okuttum.
    while (!okuyucuOku.eof())
    {
        okuyucuOku >> Tc >> Okuyucu_Adi >> Okuyucu_Soyadi >> Uye_No >> Tel >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil >> gorev >> Kitap_Sayisi;
        if (gecici_tc == Tc)
        {
            dosyaYaz << Tc;//Eðer Tc ler uyuþuyorsa Tc yi Odunc dosyasýna yazdýrdým.
            gecici1tc = gecici_tc; // Girilen tc bilgisi her okuyucu dosyasýný okumada deðiþeceði için burada gecici1tc ile onu aldým.
            break;
        }

    }
    //ISBN bilgisini kontrol etmek için while döngüsüyle kitaplar dosyasýný okuttum.
    while (!kitapOku.eof())
    {
        kitapOku >> isbn >> kitap_isim >> yazar_isim >> yazar_soyisim >> konu >> tur >> sayfa_sayisi;

        // Hem isbn bilgisini hem de gecici1tc nin deðer alýp almamasý ile bundan önceki if in çalýþýrlýðýný sorguladým.
        if (gecici_isbn == isbn && gecici_tc == gecici1tc)//Eðer bundan önceki if çalýþmýþsa yani tcler uyuþmuþsa bu if çalýþýr.
        {

            dosyaYaz << setw(20) << isbn; //Ýsbn bilgisi ve tc bilgisi doðruysa isbn yi de Odunc dosyasýna yazdýrdým.

            gecici1isbn = gecici_isbn; // Burada bir sonraki if else için ve kitapokuma döngüsünde sürekli isbn deðiþeceði için uyuþan isbnyi gecici1isbn ile tuttum.
            break;
        }

    }
    //Ýþlem karýþýklýðýný önlemek ve eðer tc veya isbn yanlýþsa programýn devam etmesini önlemek için bir if else daha oluþturdum. 
    if (gecici_isbn == gecici1isbn && gecici_tc == gecici1tc) //Eðer bu if çalýþýrsa aslýnda kütüphane class ýnda 0 a eþitlediðim gecici1isbn ile gecici1tc ye
                                                              //deðer atandýðýný ve yukarýdaki iflerin çalýþtýðýný görürüz.Yani tc ile isbn doðrudur.
    {
        cout << "Ödünç alma tarihi gün.ay.yýl þeklinde giriniz: " << endl;//Kullanýcýdan ödünç alma tarihini istedim.

        cin >> odunc_gun >> nokta >> odunc_ay >> nokta >> odunc_yil;

        //Son iade tarihini 15 gün sonrasý yaptým ve buna göre iflerle ay yýl ve günlerin artmasýný kontrol ettim.
        if (odunc_ay < 12) {//Eðer Kullanýcý ayý 12 den küçük girdiyse bir sonraki yýla atlayamadýðý için sadece gün ve ay deðerlerini deðiþtirdim.

            if ((odunc_gun <= 15) && (odunc_gun > 0)) //Ödünç günü 15 ten küçükse iade gününe 15 eklenir, ay ve yýl ödünçtekilere eþit olur.
            {
                iade_gun = odunc_gun + 15;
                iade_ay = odunc_ay;
                iade_yil = odunc_yil;
            }
            else if (odunc_gun > 15)//Ödünç günü 15 ten büyükse ay bir artar, yýl ayný kalýr gün ise bir sonraki aya döndüðü için 15 eksilir.
            {
                iade_ay = odunc_ay + 1;
                iade_gun = odunc_gun - 15;
                iade_yil = odunc_yil;
            }
        }
        else if (odunc_ay == 12) {////Eðer Kullanýcý ayý 12 girdiyse bir sonraki yýla atlayabileceði için yýlý da kontrol ederim.

            if ((odunc_gun <= 15) && (odunc_gun > 0)) //12.ayda da olsa ödünç günü 15 ten küçük girilirse bir sonraki aya veya yýla atlayamaz ve sadece güne 15 eklenir.
            {
                iade_gun = odunc_gun + 15;
                iade_ay = odunc_ay;
                iade_yil = odunc_yil;
            }
            else if (odunc_gun > 15)//12.ay olduðundan 15 ten büyük gün girilirse yýl bir artar ve ay Ocak'a döner.
            {
                iade_ay = 01;
                iade_gun = odunc_gun - 15;
                iade_yil = odunc_yil + 1;
            }

        }
        //Kitap ödünç tarihini ekrana da bastýrýyorum.
        cout << "\nKitap iade tarihi 15 gün sonradýr ==>  " << iade_gun << nokta << iade_ay << nokta << iade_yil << "\nÖdünç alma iþlemi tamamlandý." << endl;

        //Son olarak kitap ödünç tarihini Odunc dosyasýna yazdýrýyorum.
        dosyaYaz << setw(20) << odunc_gun << ' ' << nokta << ' ' << odunc_ay << ' ' << nokta << ' ' << odunc_yil << setw(20) << iade_gun << ' ' << nokta << ' ' << iade_ay << ' ' << nokta << ' ' << iade_yil << endl;


        //Okuyucu kitap ödünç aldýðý için alabileceði kitap sayýsýný azaltmamýz gerekiyor.
        ifstream OkuyucuOku("Okuyucu.txt"); //Okuyucu dosyasýný okuma modunda açýyorum.

        ofstream yeniOkuyucuYaz("gecici.txt", ios::out);//Kitap sayýsý deðiþkenini deðiþtirdiðimiz için geçici dosya oluþturup yazma modunda açýyorum.

        //While döngüsüyle okuyucu dosyasýný okutuyorum.
        while (OkuyucuOku >> Tc >> Okuyucu_Adi >> Okuyucu_Soyadi >> Uye_No >> Tel >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil >> gorev >> Kitap_Sayisi) {


            if (gecici_tc == Tc) {//Eðer tc ler uyuþuyorsa geçici kitap sayýsýný 1 eksiltip dosyaya ve ekrana bastýrýyorum.

                int gecici_kitapSayi = Kitap_Sayisi - 1;
                yeniOkuyucuYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                    << Uye_No << setw(20) << Tel << setw(20)
                    << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << gecici_kitapSayi << "\n";
                cout << "\nOkuyucunun " << gecici_kitapSayi << " tane kitap alma hakký kalmýþtýr." << endl;
            }
            else //else e düþüyorsa okuyucu kitap almamýþ demektir bu yüzden bilgileri direkt yazdýrýyorum geçici dosyaya.
            {

                yeniOkuyucuYaz << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                    << Uye_No << setw(20) << Tel << setw(20)
                    << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

            }

        }
        //Okuyucuyla iþimiz bittiði için dosyalarý kapatýyorum.
        yeniOkuyucuYaz.close();
        OkuyucuOku.close();

    }
    else {//En son da isbn veya tc uyuþmuyorsa bunu ekrana yazdýrýp programý sonlandýrýyorum.
        cout << "Yanlýþ TC veya ISBN.";
        system("PAUSE");

    }
    //Dosyalarý kapatýyorum.
    dosyaYaz.close();
    okuyucuOku.close();
    kitapOku.close();

    remove("Okuyucu.txt");//Okuyucu dosyasýndaki Kitap_sayisi deðiþtiði için dosyayý siliyorum.
    rename("gecici.txt", "Okuyucu.txt");//Geçici dosyadaki yeni bilgiler olduðu için ismini deðiþtiriyorum.


}

void Odunc::okuyucuVeKitaplar() {

    cout << "Okuyucunun TC'sini giriniz: ";
    cin >> gecici_tc;

    ifstream dosyaOku("Odunc.txt", ios::in);//Gerekli bilgileri okumak için Odunc dosyasýný açýyorum.
    ifstream kitapOku("Kitaplar.txt", ios::in);//Gerekli bilgileri okumak için Kitaplar dosyasýný açýyorum.

    //While döngüsüyle Odunc dosyasýný okutuyorum.
    while (!dosyaOku.eof()) {

        dosyaOku >> Tc >> isbn >> odunc_gun >> nokta >> odunc_ay >> nokta >> odunc_yil >> iade_gun >> nokta >> iade_ay >> nokta >> iade_yil;

        gecici_isbn = isbn; //Kitap dosyasýný okuttuðumda isbn tekrar deðiþeceði için geçici isbn yi Odunc dosyasýndan aldýðým isbn ye eþitliyorum.

        if (gecici_tc == Tc)//Odunc dosyasýnda girilen Tc den varsa eþitleniyor ve koþul saðlanýyor.
        {
            //Kitaplar dosyasýndaki bilgileri girebilmek için kitaplar dosyasýný while döngüsünde satýr satýr okutuyorum.
            while (kitapOku >> isbn >> kitap_isim >> yazar_isim >> yazar_soyisim >> konu >> tur >> sayfa_sayisi) {

                if (gecici_isbn == isbn)//Eðer odunc dosyasýndaki isbn ile kitaplar dosyasýndaki isbn uyuþuyorsa koþul saðlanýr ve bilgiler girilir.
                {
                    cout << "\nKitap ISBN:         " << gecici_isbn;
                    cout << "\nKitap ismi:         " << kitap_isim;
                    cout << "\nÖdünç alma tarihi:  " << odunc_gun << nokta << odunc_ay << nokta << odunc_yil;
                    cout << "\nÝade tarihi:        " << iade_gun << nokta << iade_ay << nokta << iade_yil << endl;
                    break;
                }

            }

        }
    }
    //Dosyalarý kapatýyorumç
    dosyaOku.close();
    kitapOku.close();
}

void Odunc::iadeKitapDonus() {
    ifstream dosyaOku("Odunc.txt", ios::in);//Gerekli bilgileri okumak için Odunc dosyasýný in modunda açtým.
    ofstream dosyaYaz("iade.txt", ios::app); //Ýade edilip geri dönen kitabý Odunc dosyasýndan sileceðimiz için iade dosyasý oluþturdum.

    ifstream okuyucuKitapokuma("Okuyucu.txt", ios::in); //Gerekli bilgiler için okuyucu dosyasýný açtým.
    ofstream okuyucukitapekleme("yedek.txt", ios::app); //Okuyucu kitabý iade ettiðinde alabileceði kitap sayýsý artacaðý için yeni okuyucu dosyasý oluþturuyorum.

    cout << "Ýade edilecek kitabýn ISBN'sini giriniz:  ";

    cin >> gecici_isbn;

    //Odunc alýnan kitabýn varlýðýný sorgulamak için while döngüsünde Odunc dosyasýný okuttum.
    while (dosyaOku >> Tc >> isbn >> odunc_gun >> nokta >> odunc_ay >> nokta >> odunc_yil >> iade_gun >> nokta >> iade_ay >> nokta >> iade_yil)
    {
        if (gecici_isbn == isbn) //Eþleniyorsa kitabýn ödünç alýndýðý doðrudur, program devam eder.//Ayný zamanda kitabý ödünç listesinden silmek için dosyaya yazdýrmýyorum.
        {
            //Bilgilerini ekrana bastýrdým.
            cout << "\nKitabý alan kiþinin TC'si :  " << Tc;
            cout << "\nÖdünç tarihi              :  " << odunc_gun << nokta << odunc_ay << nokta << odunc_yil;
            cout << "\nSon iade tarihi           :  " << iade_gun << nokta << iade_ay << nokta << iade_yil;

            gecici_tc = Tc; //Ödünç alan kiþinin TC sini tutabilmek için geçici tc ye eþitledim.

            //Ödün kitabý alan okuyucuyu bulabilmek için Okuyucu dosyasýný while döngüsüyle okuttum.
            while (okuyucuKitapokuma >> Tc >> Okuyucu_Adi >> Okuyucu_Soyadi >> Uye_No >> Tel >> dogum_gun >> nokta >> dogum_ay >> nokta >> dogum_yil >> gorev >> Kitap_Sayisi) {
                if (gecici_tc == Tc)//Tc ler uyuþuyorsa kitap sayýsýný bir arttýrdým çünkü kitabý iade eden kiþiyi bulmuþ oluyoruz.
                {
                    Kitap_Sayisi++;
                    //Yeni kitap sayýsý bilgili halini geçici dosyaya yazdýrdým. 
                    okuyucukitapekleme << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                        << Uye_No << setw(20) << Tel << setw(20)
                        << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

                }
                else //Eðer kitabý ödünç alan kiþi deðilse direkt bilgilerini yeni dosyaya yazdýrdým.
                {
                    okuyucukitapekleme << Tc << setw(20) << Okuyucu_Adi << setw(20) << Okuyucu_Soyadi << setw(20)
                        << Uye_No << setw(20) << Tel << setw(20)
                        << dogum_gun << ' ' << nokta << ' ' << dogum_ay << ' ' << nokta << ' ' << dogum_yil << setw(20) << gorev << setw(20) << Kitap_Sayisi << "\n";

                }
            }

        }
        else//Ýade edilmemiþ yani geri dönmeyen kitaplarý yeni ödünç dosyasýna yazdýrýyorum.
        {
            dosyaYaz << Tc << setw(20) << isbn << setw(20) << odunc_gun << ' ' << nokta << ' ' << odunc_ay << ' ' << nokta << ' ' << odunc_yil << setw(20) << iade_gun << ' ' << nokta << ' ' << iade_ay << ' ' << nokta << ' ' << iade_yil << endl;

        }
    }
    cout << endl;
    cout << "Kitap iadesi alýndý." << endl;
    //Dosyalarý kapatýyorum.
    okuyucukitapekleme.close();
    okuyucuKitapokuma.close();
    dosyaOku.close();
    dosyaYaz.close();

    //Bilgileri deðiþen eski dosyalarý silip yenilerinin isimlerini deðiþtiriyorum.
    remove("Okuyucu.txt");
    rename("yedek.txt", "Okuyucu.txt");

    remove("Odunc.txt");
    rename("iade.txt", "Odunc.txt");


}

int main()
{
    setlocale(LC_ALL, "Turkish");

    //Sistem saatini almak için gerekli deðiþkenleri giriyorum.
    time_t giris = time(nullptr);
    cout << "Giriþ zamanýnýz: " << ctime(&giris);//Ekrana bastýrýyorum.

    //Giriþ ve çýkýþ saatlerini, kullanýcý adýný, þifreyi kullanýcý dosyasýna kaydedebilmek için deðiþkenleri tanýmlýyorum.   
    string girisGun, girisgun, girisAy, girisYil;

    string cikisGun, cikisgun, cikisAy, cikisYil;

    int saat, dakika, saniye;

    char ikinokta;

    string kullaniciAdi, sifre;


    cout << "\n*************************************************************" << endl << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^KULLANICI GÝRÝÞÝ^^^^^^^^^^^^^^^^^^^^^^^^ " << endl << endl;


    ifstream dosyaOku("kullanicilar.txt", ios::in);//Okuma modunda kullanýcýlar dosyasýný açtým.
    ofstream dosyaYaz("kullanicilar.txt", ios::app);//Yazma modunda kullanýcýlar dosyasýný açtým.

    string kAdi1, kadi, sfre;

    cout << "\n\nKullanýcý adý: "; cin >> kadi;  //Kullanýcý adýný ve þifreyi geçiçi olacak þekilde okuttum.
    cout << "\nÞifre       : "; cin >> sfre;

    //Kullanýcýlar dosyasýndaki düzene göre while döngüsüyle dosyayý satýr satýr okuttum.
    while (!dosyaOku.eof()) {
        dosyaOku >> kullaniciAdi >> sifre >> girisGun >> girisAy >> girisgun >> saat >> ikinokta >> dakika >> ikinokta >> saniye >> girisYil;
        dosyaOku >> cikisGun >> cikisAy >> cikisgun >> saat >> ikinokta >> dakika >> ikinokta >> saniye >> cikisYil;
        if (kadi == kullaniciAdi) //Kullanýcý adý kullanýcýnýn girdiðiyle uyuþuyorsa koþul çalýþýr.
        {
            kAdi1 = kadi; //Koþulun çalýþtýðýný göstermesi için kadi yi kAdi1 e eþitliyorum ki bunu diðer if te kullanabileyim.

        }
        if (kAdi1 == kadi && sfre == sifre) //Bu koþulun saðlanmasý bir önceki if in çalýþtýðýný gösterir çünkü kAdi1 e bir deðer tanýmlamamýþtým.
        {                               //Böylece hem þifreyi hem de kullanýcý adýný kontrol etmiþ oldum.
            cout << "\nGiriþ baþarýlý." << endl;
            dosyaYaz << endl << kadi << setw(10) << sfre; //Dosyaya kullanýcý adýný ve þifreyi yazdýrýyorum.
            break;

        }

    }
    if (kAdi1 != kadi && sfre != sifre) //Bu koþul yukarýdaki iki if in de çalýþmadýðýný yani kullanýcý adý veya(ve) þifrenin yanlýþ olduðunu gösteriyor.
    {
        cout << "\nGiriþ baþarýsýz." << endl;

        time_t hataliCikis = time(nullptr);

        cout << "\nÇýkýþ zamanýnýz: " << ctime(&hataliCikis); //Çýkýþ saatini ekrana yazdýrýyorum.

        system("PAUSE");
        return EXIT_SUCCESS;
    }


    int secim = 1;
    char cevap = 'e';

    //Kullanýcý giriþi baþarýlý olursa kütüphane sistemine giriyoruz ve seçim yapmasýný istiyorum kullanýcýdan.
    do {
        cout << "^^^^^^^^^^^^KÜTÜPHANE SÝSTEMÝNE HOÞGELDÝNÝZ^^^^^^^^^^^^^^^" << endl << endl << endl;
        cout << "             Ne yapmak istiyorsunuz ? " << endl << endl;
        cout << "             1) Okuyucu kaydý " << endl;
        cout << "             2) Okuyucu kaydý güncelleme  " << endl;
        cout << "             3) Okuyucu silme " << endl;
        cout << "             4) Okuyucu üzerindeki kitaplar listesi" << endl;
        cout << "             5) Okuyucu kitap ödünç alma" << endl;
        cout << "             6) Okuyucu kitap iadesi" << endl;
        cout << "             7) Kitap ekleme" << endl;
        cout << "             8) Kitap güncelleme" << endl;
        cout << "             9) Kitap silme" << endl << endl;
        cout << "Ýþlem seçiniz.........  ";
        cin >> secim;
    } while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9);

    Okuyucular okuyucu; //Okuyucular class ýndaki fonksiyonlar için nesne oluþturuyorum.

    if (secim == 1) {
        okuyucu.okuyucuGirisi();
    }
    if (secim == 2) {
        okuyucu.okuyucuGuncelleme();
    }
    if (secim == 3) {
        okuyucu.okuyucuSilme();
    }
    Odunc odunc;//Odunc class ýndaki fonksiyonlar için nesne oluþturuyorum.
    if (secim == 4) {
        odunc.okuyucuVeKitaplar();
    }

    if (secim == 5) {
        odunc.oduncKitapGiris();
    }

    if (secim == 6) {
        odunc.iadeKitapDonus();
    }
    Kitaplar kitap;//Kitaplar class ýndaki fonksiyonlar için nesne oluþturuyorum.

    if (secim == 7) {
        kitap.KitapGirisi();
    }
    if (secim == 8) {
        kitap.KitapGuncelleme();
    }
    if (secim == 9) {
        kitap.KitapSilme();
    }


    dosyaYaz << setw(30) << ctime(&giris); //En baþtaki giriþ zamanýný Kullanicilar dosyasýna kaydediyorum.

    //Tekrar sistem zamanýný istiyorum ve ekrana bastýrýyorum.
    time_t cikis = time(nullptr);
    cout << "\nÇýkýþ zamanýnýz: " << ctime(&cikis) << endl;


    dosyaYaz << setw(30) << ctime(&cikis) << endl;//Çýkýþ zamanýný da Kullanicilar dosyasýna kaydediyorum.

    //Dosyalarý kapatýyorum.
    dosyaOku.close();
    dosyaYaz.close();

    system("PAUSE");
    return EXIT_SUCCESS;
}


