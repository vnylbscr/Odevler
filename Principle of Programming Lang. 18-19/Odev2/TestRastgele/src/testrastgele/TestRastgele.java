package testrastgele;

import RastgeleKarakter.RastgeleKarakter;

/*
 © Sakarya Üniversitesi © 
 @Ad Soyad: Mert Genç 
 @NO: B161210045 
 @mail: mert.genc1@ogr.sakarya.edu.tr


 */
public class TestRastgele {

    // Test programi
    public static void main(String[] args) {

        RastgeleKarakter rk = new RastgeleKarakter();

        System.out.println("Rastgele Karakter : " + rk.RastgeleChar());

        rk.RastgeleParametreliUret(5);

        rk.AraDegerParametreli(2, 'a', 'k');

        System.out.println("");

        rk.AraDegerParametreli(2, 'k', 'a');

        System.out.println("");
        
        rk.KullaniciGirisineGoreCharlar(7, 'a', 'n', 'p');

        System.out.println("");
        
        
        rk.CumleUret(4);
        
        System.out.println("");
        
        rk.CumleUret(7);
        
        System.out.println("");
        
    }

}
