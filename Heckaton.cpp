#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
int arac_sayisi;
int i = 0;
double a[10];
int b;

int main()
{
    cout << "Vesna Enerji Merkezine Hos Geldiniz!" << endl;

    cout << "...................................." << endl;

    cout << "Simulasyonun basarili bir sekilde devam etmesi icin \nsizden istenen verileri eskiksiz bir sekilde tamamlayiniz." << endl;

    cout << "...................................." << endl;

    cout << "Garajda bulunmasini istediginiz arac sayisini giriniz: ";
    cin >> arac_sayisi;
    cout << endl;
    double dongu3 = arac_sayisi;
    int dongu2 = arac_sayisi;
    int dongu1 = arac_sayisi;
    int dongu = arac_sayisi;


    while (dongu > 0 && dongu <= 10) {
        dongu--;
        i++;
        cout << i << " numarali aracin doluluk oranini belirtiniz:";
        cin >> a[i];
        if (a[i] > 100) {
            cout << "Hatali tuslama yaptiniz." << endl;
            return 0;
        }
    }
    
    if (dongu1 <= 0) {
        cout << "garaj bos durumdadir veya negatif bir sayi girdiniz." << endl;
    }
    
    else if (dongu1 > 10) {
        cout << "garajimiz en fazla 10 arac alabilmektedir." << endl;
    }
    
    cout << endl << endl;
    
    while (dongu1 > 0 && dongu1 <= 10) {
        cout <<" | " << dongu1 << "numarali aracin sarj seviyesi %" << a[dongu1] << " | " << endl;
        dongu1--;
    }

    cout << endl << endl;

    if (dongu2 > 0 && dongu2 <= 10) {
        double toplam_ihtiyac = dongu3 * 100 - a[0] - a[1] - a[2] - a[3] - a[4] - a[5] - a[6] - a[7] - a[8] - a[9];
        cout << "cihazlarin toplam ihtiyaclari: "<<toplam_ihtiyac << endl << endl;
        
        double k = 50000 /toplam_ihtiyac;
        cout <<"cihazlara yonlendirilecek oranli akim katsayisi: "<< k << endl << endl;
        if (k * (100 - a[dongu2]) > 22000)
        while (dongu2 > 0 && dongu2 <= 10) {
            if (k * (100 - a[dongu2]) > 22000) {
                k = 28000 / (toplam_ihtiyac + a[dongu2]-100);
                cout << " | " << dongu2 << "numarali araca gidecek olan akim " << 22000 << "W" << " | " << endl;
            }
            else {
                cout << " | " << dongu2 << "numarali araca gidecek olan akim " << k * (100 - a[dongu2]) << " | " << endl;
            }
            
            dongu2--;

        }
     
    }
    return 0;
}
