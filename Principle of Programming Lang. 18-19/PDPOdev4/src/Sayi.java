
import java.util.ArrayList;


/**
 *
 * @author MertGenç~~
 * @author Emirhan Erdoğu
 *
 */
public class Sayi {
//txt dosyasındaki her satırdaki sayilari aktarabileceğim arraylistler tanımlanıyor.
    private int index = 0;
    protected ArrayList<Integer> birlerBasamagi = new ArrayList<Integer>();
    protected ArrayList<Integer> onlarBasamagi = new ArrayList<Integer>();
    protected ArrayList<Integer> yuzlerBasamagi = new ArrayList<Integer>();
    protected ArrayList<Integer> binlerBasamagi = new ArrayList<Integer>();
//dosyadan gelen satirlar dizisinin her elemanı bir satırı ifade ediyor. buradaki metod o satırı alıp arrayliste aktarıyor.
    protected void stringiElemanlaraAta(ArrayList<String> satirString) {
        for (int i = 0; i < satirString.size(); i++) {
            String satir = satirString.get(index);
            binlerBasamagi.add(index, satir.charAt(0) - 48);
            yuzlerBasamagi.add(index, satir.charAt(1) - 48);
            onlarBasamagi.add(index, satir.charAt(2) - 48);
            birlerBasamagi.add(index, satir.charAt(3) - 48);
            index++;
        }

    }
//sayılar toplanıyor ve ekrana yazılıyor.
    private String stringToplam() {
        String toplam;
        toplam = Integer.toString(Sum(birlerBasamagi))
                + Integer.toString(Sum(onlarBasamagi))
                + Integer.toString(Sum(yuzlerBasamagi))
                + Integer.toString(Sum(binlerBasamagi));

        return toplam;
    }

    protected void EkranaYaz() {

        //string toplamı.. 
        System.out.println("Sonuç:" + this.stringToplam());
    }

    //arraylist elemanlarını toplayan metodS
    private static int Sum(ArrayList<Integer> aList) {
        int sum = 0;
        for (Integer i : aList) {
            sum += i;
        }
        return sum;
    }

}
