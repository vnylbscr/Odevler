
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author Mert Genç
 * @author Emirhan Erdoğu
 *
 */
public class DosyaOkuma {

    private Sayi sayi = new Sayi();
    public ArrayList<String> satirlar;

    //dosya okuma işlemi yapılıyor
    public DosyaOkuma(File dosya) throws IOException {
        this.satirlar = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(dosya))) {
            String hepsi;
            int i = 0;
            while ((hepsi = br.readLine()) != null) {
                satirlar.add(i, hepsi); //txt dosyası satırlara bölünerek her satır dizinin elamnına aktarılıyor.
                i++;
            }
            br.close(); //açılan dosya kapatılıyor
        }
    }

    public void DosyaOku() {
//satirlar arrayliste aktarılıyor.
        sayi.stringiElemanlaraAta(satirlar);

    }
//ekrana basılıyor.
    public void EkranaYaz() {
        sayi.EkranaYaz();
    }
}
