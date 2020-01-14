package javaapplication1;

// @Mert Genç @mail: mertgenc8@gmail.com
// No: B161210045
// Programlama Dillerinin Prensipleri 1.Ödev
// 1.Öğretim A GRUBU
// 01.03.18

import java.io.*;
import java.util.ArrayList;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class JavaApplication1 {

    public static void main(String[] args) throws IOException {
        
        // Fonksiyonların isimlerini tutacağım arraylist tanımlaması
        ArrayList<String> intFonk = new ArrayList<String>();
        ArrayList<String> charFonk = new ArrayList<String>();
        ArrayList<String> boolFonk = new ArrayList<String>();
        ArrayList<String> doubleFonk = new ArrayList<String>();
        ArrayList<String> floatFonk = new ArrayList<String>();
        ArrayList<String> parametreArrayList = new ArrayList<String>();

        // Her c kodunda bir tane main fonskiyonu olacağı için manuel olarak ekledim.
        intFonk.add("int main");

        ArrayList<String> voidFonk = new ArrayList<>();
        // Dosyayı okuyorum
        File file = new File("program.c");
        FileInputStream fileStream = new FileInputStream(file);
        InputStreamReader input = new InputStreamReader(fileStream);
        try (BufferedReader reader = new BufferedReader(input)) {
            String okunan_dosya;

            int operatorSayisi = 0;

            // Regex pattern tasarlıyoruz
            String regex_int = "int ([A-Z])\\w+";
            String regex_void = "void ([A-Z])\\w+";
            String regex_double = "double ([A-Z])\\w+";
            String regex_bool = "bool ([A-Z])\\w+";
            String regex_float = "float ([A-Z])\\w+";
            String regex_char = "char ([A-Z])\\w+";
            String regex_parametre = "\\(([^,\\s\\)]+)(?:\\s*,\\s*([^,\\s\\)]+))*\\)";

            while ((okunan_dosya = reader.readLine()) != null) {

                Pattern desen = Pattern.compile(regex_int);
                Pattern desen2 = Pattern.compile(regex_void);
                Pattern desen3 = Pattern.compile(regex_parametre);
                Pattern desen4 = Pattern.compile(regex_char);
                Pattern desen5 = Pattern.compile(regex_bool);
                Pattern desen6 = Pattern.compile(regex_float);
                Pattern desen7 = Pattern.compile(regex_double);

                Matcher eslesme = desen.matcher(okunan_dosya);
                Matcher eslesme2 = desen2.matcher(okunan_dosya);
                Matcher eslesme3 = desen3.matcher(okunan_dosya);
                Matcher eslesme4 = desen4.matcher(okunan_dosya);
                Matcher eslesme5 = desen5.matcher(okunan_dosya);
                Matcher eslesme6 = desen6.matcher(okunan_dosya);
                Matcher eslesme7 = desen7.matcher(okunan_dosya);
                
                // dizgenin operatör içerdiğine dair bulunan kontrol bloğu 
                if (okunan_dosya.contains("+=") || okunan_dosya.contains("*=") || okunan_dosya.contains("/=") || okunan_dosya.contains("-=")) {
                    operatorSayisi += 2;

                } else if (okunan_dosya.contains("+") || okunan_dosya.contains("-") || okunan_dosya.contains("*") || okunan_dosya.contains("&") || okunan_dosya.contains("/") || okunan_dosya.contains("=") || okunan_dosya.contains("||") || okunan_dosya.contains("!=") || okunan_dosya.contains("==") || okunan_dosya.contains("&&") || okunan_dosya.contains("++") || okunan_dosya.contains("--") || okunan_dosya.contains("<") || okunan_dosya.contains(">") || okunan_dosya.contains("<=") || okunan_dosya.contains(">=")) {

                    operatorSayisi++;
                }
                // regex ile eşletiğinde elemanları arrayliste aktaran kısım
                if (eslesme.find()) {

                    intFonk.add(eslesme.group());

                } else if (eslesme2.find()) {
                    voidFonk.add(eslesme2.group());

                } else if (eslesme3.find()) {

                    parametreArrayList.add(eslesme3.group());

                } else if (eslesme4.find()) {

                    charFonk.add(eslesme4.group());

                } else if (eslesme5.find()) {

                    boolFonk.add(eslesme5.group());

                } else if (eslesme6.find()) {

                    floatFonk.add(eslesme6.group());

                } else if (eslesme7.find()) {

                    doubleFonk.add(eslesme7.group());

                }
            }

            // size metodu ile arraylistin eleman sayısını değişkene atıyorum
            int void_FonksiyonSayisi = voidFonk.size();
            int int_FonksiyonSayisi = intFonk.size();
            int bool_FonksiyonSayisi = boolFonk.size();
            int double_FonksiyonSayisi = doubleFonk.size();
            int float_FonksiyonSayisi = floatFonk.size();
            int char_FonksiyonSayisi = charFonk.size();

            // Operator sayısını ekrana yazdırma
            System.out.println("Toplam operatör sayısı : " + operatorSayisi);

            // Fonskiyon sayısını ekrana yazdırma
            int toplam_fonksiyon_sayisi = void_FonksiyonSayisi + int_FonksiyonSayisi + bool_FonksiyonSayisi + double_FonksiyonSayisi + float_FonksiyonSayisi + char_FonksiyonSayisi;
            System.out.println("Toplam fonksiyon sayısı : " + toplam_fonksiyon_sayisi);
            // parametre sayısını ekrana yazdırma

            System.out.println("Toplam parametre sayısı : " + parametreArrayList.size());

            // Fonskiyon isimlerini ekrana yazdırıyorum
            System.out.println("Fonksiyon isimleri: \n  "+ intFonk + voidFonk + charFonk + floatFonk + doubleFonk + boolFonk);
            
        }
    }
}
