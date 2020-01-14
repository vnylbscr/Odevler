package RastgeleKarakter;

import java.util.ArrayList;
/*
 © Sakarya Üniversitesi © 
 @Ad Soyad: Mert Genç 
 @NO: B161210045 
 @mail: mert.genc1@ogr.sakarya.edu.tr


 */

public class RastgeleKarakter {

    //Karakterleri tutacagimiz bir arrayList. Char turunde.
    ArrayList<Character> arrayList = new ArrayList<Character>();

    public char RastgeleChar() {

        char karakter;
        //nanotime'in urettigi sayilar 00 la bittigi icin 100'e boldum, fakat baska bir bilgisayarda boyle uretmiyor. 57+65=122 eder bu da kucuk harflerdeki z harfinin ascii kodudur.
        int rastgele = ((int) System.nanoTime() / 100) % 58 + 65;

        //Burda tek cift kontrolu yapiyorum. bunu 90-97 arasindaki karakterleri atarak da yapabilrdim fakat bu daha basit.
        if (rastgele % 2 == 0) {

            rastgele = (int) System.nanoTime();
            //nanotime negatif sayilar uretebildigi icin bir kontrol yaziyoruz
            if (rastgele < 0) {

                rastgele = rastgele * (-1);

            }

            //Buyuk harflerin ascii kodlari 65-90 arasi oldugu icin.
            rastgele = ((rastgele % 26) + 65);

        } else {

            rastgele = (int) System.nanoTime();
            //nanotime negatif sayilar uretebildigi icin bir kontrol yaziyoruz
            if (rastgele < 0) {
                rastgele = rastgele * (-1);

            }
            //Kucuk harflerin ascii kodlari 97-122 arasi oldugu icin. o aralikta deger uretiyor.    
            rastgele = ((rastgele % 26) + 97);
        }

        karakter = (char) rastgele;

        return karakter;

    }

    public void RastgeleParametreliUret(int girilenSayi) {
        System.out.print("Rastgele " + girilenSayi + " Karakter : ");
        for (int i = 0; i < girilenSayi; i++) {

            System.out.print(RastgeleChar());
        }
        System.out.println("");
    }

    public void AraDegerParametreli(int girilenSayi, char x, char y) {

        
        char geciciRastgele = RastgeleChar();
        
        int intX = (int) x;
        int intY = (int) y;

        // Parametreler büyük harf verilirse onları küçük harfe çeviriyor.
        if (intX < 97) {
            intX = intX + 32;
        }
        if (intY < 97) {

            intY = intY + 32;

        }
        //parametreler ters yazılırsa onları sıraya sokuyor.
        if (intX > intY) {

            int degistir = intX;
            intX = intY;
            intY = degistir;
        }

        System.out.print("Verilen " + girilenSayi + " Karakter " + "(" + x + "," + y + "): ");
        
        int i = 0;
        // girilen parametre kadar while dongusu calisiyor.
        while (i < girilenSayi) {

            
            
            if ((int) geciciRastgele > intX && (int) geciciRastgele < intY) {

                System.out.print(geciciRastgele);
                geciciRastgele = RastgeleChar();
                i++;

            } 
            else {
                geciciRastgele = RastgeleChar();
            }

        }

    }

    public void CumleUret(int kelimeSayisi) {

        //yeterli kelime sayisina ulasildigi zaman donguden cikmamizi saglayan bir sayac.
        int durdur = 0;

        System.out.print("Cumle : ");

        while (durdur < kelimeSayisi) {
            int kelime = (int) System.nanoTime();

            //nanotime negatif sayilar uretebildigi icin bir kontrol yaziyoruz
            if (kelime < 0) {

                kelime = kelime * (-1);

            }
            //kelimelerimiz en az 3 karakter en fazla 10 karakterden olusabiliyor.
            kelime = ((kelime % 6) + 3);

            for (int i = 0; i < kelime; i++) {

                char Rastgele = RastgeleChar();

                if ((int) Rastgele < 97) {

                    //Kelimeleri buyuk yazdirmamak icin bir kontrol blogu.
                    Rastgele = (char) ((int) Rastgele + 32);

                }
                System.out.print(Rastgele);
            }
            //Kelimeler arasi bosluk icin bir kontrol blogu.
            if (durdur + 1 != kelimeSayisi) {

                System.out.print(" ");
            }

            durdur++;

        }

    }

    public void KullaniciGirisineGoreCharlar(int girilenSayi, char... girilenChar) {

        System.out.print("Belirtilen Karakterler(");

        String str = String.valueOf(girilenChar);

        for (char k : str.toCharArray()) {

            arrayList.add(k);
        }

        for (int i = 0; i < arrayList.size(); i++) {
            System.out.print(arrayList.get(i));

            if (i + 1 != arrayList.size()) {
                System.out.print(",");

            }

        }

        System.out.print(") : ");

        for (int i = 0; i < girilenSayi; i++) {
            int geciciRastgele = (int) System.nanoTime();
            if (geciciRastgele < 0) {
                geciciRastgele = geciciRastgele * (-1);

            }
            geciciRastgele = (geciciRastgele % arrayList.size());

            System.out.print(arrayList.get(geciciRastgele));

        }

    }

}
