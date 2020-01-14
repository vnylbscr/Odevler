
/*
@author Mert Genç & Emirhan Erdoğu
no:b161210045
mert.genc1@ogr.sakarya.edu.tr
Pdp 4.Ödev
*/

import java.io.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {

    public static void main(String[] args) throws FileNotFoundException, IOException {

        long start = System.nanoTime();
        //dosya okunuyor. txt dosyasında satırların altı boş kalırsa out of range exception istisna fırlatılıyor. txt dosyasına satır eklerken dikkat edilmesi gerek.
        File file = new File("sayilar.txt");

        Sayi sayi = new Sayi();
        
        DosyaOkuma dosyaOkuma = new DosyaOkuma(file);
            
        dosyaOkuma.DosyaOku();
        
        dosyaOkuma.EkranaYaz();
        
        long end_1 = System.nanoTime();
        //süre hesaplanıyor.
        double timeElapsedSeri = (end_1 - start) / 1000000.0;

        System.out.println("\nSeri Hesaplanma Süresi " + String.format("%.2f", timeElapsedSeri) + " milisaniye.");
        
        Runnable run=new ToplamaIslem(sayi);
        
        ExecutorService havuz = Executors.newFixedThreadPool(10); //10 iş parçacığı

        havuz.execute(run);
        //havuz kapatılıyor
        havuz.shutdown();

        while (!havuz.isTerminated()) {}
        
        long end_2 = System.nanoTime();

        double timeElapsedParalel = (end_2 - start) / 1000000.0;
        
        System.out.println("\nParalel Hesaplanma Süresi " + String.format("%.2f", timeElapsedParalel) + " milisaniye.");

    }

}
