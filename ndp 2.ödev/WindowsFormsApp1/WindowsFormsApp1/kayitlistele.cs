using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class kayitlistele : Form
    {
        public kayitlistele()
        {
            InitializeComponent();
            Yazdir(Oku());
        }
        private List<kisi> Oku()//veriler.txt yi okuyup generic list'e atan metot
        {
            string line;
            List<kisi> okunanKisi = new List<kisi>();
            // Read the file and display it line by line.  
            StreamReader file = new StreamReader(@"veriler.txt");
            while ((line = file.ReadLine()) != null)//Satır satır okuma yapıyoruz .Burada using bloğu da kullanılabilir kişi ekleyle aynı olsun diyorsan using koyup f.le.Close() kaldırabilirsin
            {
               
                string[] okunan = line.Split(' ');
                okunanKisi.Add(new kisi { Renk = okunan[0], Ad = okunan[1], Soyad = okunan[2], Numara = okunan[3] });//Okuduğumuz verileri yeni bir kişi nesnesi içinde listeye atıyoruz
                
            }

            
            file.Close();

            return okunanKisi;
        
        }

        private void Yazdir(List<kisi> okunanListe)//Alınan kişi listesini richtextboxa yazan fonksiyon
        {
            
            for (int i = 0; i < okunanListe.Count; i++)//Ben for ile yaptım ama foreachlede yapılabilir foreach le yaparsan ayriyetten bir sayaç değişken lazım olabilir
            {
                if (i % 2 == 0)//okunan değer eğer tekli satırlar ise fontu bold olsun
                {
                    rch_listele.SelectionFont = new Font(FontFamily.GenericSerif,12, FontStyle.Bold);
                }
                else//değilse regular olsun
                {
                    rch_listele.SelectionFont = new Font(FontFamily.GenericSerif,12, FontStyle.Regular);
                }
                Color yaziRenk = new Color();//gelen verilerin renkleri tutacak değişken
                char[] renkler = okunanListe[i].Renk.ToCharArray();//veriler.txt de tutulan renkleri char diziye atadık teker teker kontrolü için
                for (int j = 0; j < renkler.Length; j++)
                {

                    if (renkler[j] == 'k')//renklerin kontrolünü yapıyoruz
                    {
                        yaziRenk = Color.Red;
                    }
                    else if (renkler[j] == 'm')
                    {
                        yaziRenk = Color.Blue;
                    }
                    else if (renkler[j] == 'y')
                    {
                        yaziRenk = Color.Green;
                    }
                    rch_listele.SelectionColor = yaziRenk;//rich textboxun rengini atadık
                    if (j == 0)
                    {
                        rch_listele.AppendText(okunanListe[i].Ad + " ");//AppendText() metodu richtextbox a teker teker atama yapmamıza yarıyor
                    }
                    else if (j == 1)
                    {
                        rch_listele.AppendText(okunanListe[i].Soyad + " ");
                    }
                    else
                    {
                        rch_listele.AppendText(okunanListe[i].Numara + "\r\n");
                    }
                }
            
                
                
            }
        }
    }
}
