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
    public partial class kayitekle : Form
    {
        public kayitekle() 
        {
            InitializeComponent();
            Doldur();
        }

        public void Doldur()//Renkleri seçtiğin comboboxları dolduran fonksiyon
        {
            
            cmb_adrenk.Items.Add(new ComboboxItem { Text = "Kırmızı", Value = "k" });
            cmb_adrenk.Items.Add(new ComboboxItem { Text = "Mavi", Value = "m" });
            cmb_adrenk.Items.Add(new ComboboxItem { Text = "Yeşil", Value = "y" });
            cmb_adrenk.DisplayMember = "Text";
            cmb_adrenk.ValueMember = "Value";
            cmb_adrenk.SelectedIndex = 0;
            cmb_soyadrenk.Items.Add(new ComboboxItem { Text = "Kırmızı" ,Value = "k" });
            cmb_soyadrenk.Items.Add(new ComboboxItem { Text = "Mavi", Value = "m" });
            cmb_soyadrenk.Items.Add(new ComboboxItem { Text = "Yeşil", Value = "y" });
            cmb_soyadrenk.DisplayMember = "Text";
            cmb_soyadrenk.ValueMember = "Value";
            cmb_soyadrenk.SelectedIndex = 0;
            cmb_numrenk.Items.Add(new ComboboxItem { Text = "Kırmızı" ,Value ="k" });
            cmb_numrenk.Items.Add(new ComboboxItem { Text = "Mavi", Value = "m" });
            cmb_numrenk.Items.Add(new ComboboxItem { Text = "Yeşil", Value = "y" });
            cmb_numrenk.DisplayMember = "Text";                                                               
            cmb_numrenk.ValueMember = "Value";
            cmb_numrenk.SelectedIndex = 0;

        }
        private void btn_kaydet_Click(object sender, EventArgs e)
        {
            kisi yeni = new kisi();//kisi nesnesi oluşturdum
            List<ComboboxItem> listcmb = new List<ComboboxItem>();//renkleri bir listede tutmak için listcmb oluşturdum
            listcmb.Add((ComboboxItem)cmb_adrenk.SelectedItem);
            listcmb.Add((ComboboxItem)cmb_soyadrenk.SelectedItem);
            listcmb.Add((ComboboxItem)cmb_numrenk.SelectedItem);//comboboxtaki seçili renkleri listcmb listesine attım

            //Burada renkleri tutmak için liste kullandım ama gerek yok gibi kafana takılırsa listesizde yapılabilir

            yeni.Ad = txt_ad.Text;//oluşturdum yeni kişisinin adına txt_ad verdiğim adı atadım
            yeni.Soyad = txt_soyad.Text;
            yeni.Numara = txt_numara.Text;
            yeni.Renk = listcmb[0].Value + listcmb[1].Value + listcmb[2].Value;

            using (var writer = File.AppendText("veriler.txt"))//burada veriler.txt diye dosyaya yazma işlemi yapıyoruz 
            {
                writer.WriteLine(string.Format("{0} {1} {2} {3}", yeni.Renk, yeni.Ad, yeni.Soyad, yeni.Numara));
            }
            Tazele();
           
        }
        private void Tazele()//textbox ve comboboxları temizleyen fonksiyon metot ne dersen
        {
            txt_ad.Text = String.Empty;
            txt_soyad.Text = String.Empty;
            txt_numara.Text = String.Empty;
            cmb_numrenk.SelectedIndex = 0;
            cmb_soyadrenk.SelectedIndex = 0;
            cmb_adrenk.SelectedIndex = 0;
        }
    }
}
