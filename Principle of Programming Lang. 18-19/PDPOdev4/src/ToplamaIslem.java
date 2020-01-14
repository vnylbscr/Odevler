
import java.util.ArrayList;



 /*
/**
 *
 * @author MERT GENÇ b161210045@sakarya.edu.tr
 * @author EMIRHAN ERDOGU 
 */
public class ToplamaIslem implements Runnable {

    private String toplam = "";
    private ArrayList<Integer> birler = new ArrayList<>();
    private ArrayList<Integer> onlar = new ArrayList<>();
    private ArrayList<Integer> yuzler = new ArrayList<>();
    private ArrayList<Integer> binler = new ArrayList<>();
    private int birlerToplam = 0;
    private int onlarToplam = 0;
    private int yuzlerToplam = 0;
    private int binlerToplam = 0;

    public ToplamaIslem(Sayi sayi) {

        this.binler = sayi.binlerBasamagi;
        this.yuzler = sayi.yuzlerBasamagi;
        this.onlar = sayi.onlarBasamagi;
        this.birler = sayi.birlerBasamagi;

    }
//toplama işlemni paralel olarak yapan run metodu
    @Override
    public void run() {

        for (Integer sayi : birler) {
            birlerToplam += sayi;
        }

        for (Integer sayi : onlar) {
            onlarToplam += sayi;
        }

        for (Integer sayi : yuzler) {
            yuzlerToplam += sayi;
        }

        for (Integer sayi : binler) {
            binlerToplam += sayi;
        }

    }



}
