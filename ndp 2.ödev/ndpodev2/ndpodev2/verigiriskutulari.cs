using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;                                           //MERT GENÇ
using System.Linq;                                              //B161210045
using System.Text;                                              //NDP 2.ÖDEV
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;


namespace ndpodev2
{


    public partial class verigiriskutulari : Form
    {

        public verigiriskutulari()
        {
            InitializeComponent();
            //YeniDegiskenler();
        }
       
        public void YeniDegiskenler()
        
        {
            //Class1 Kisi = new Class1(); 
            //Kisi.Ad = textBox1.Text;
            //Kisi.Soyad = textBox2.Text;
            //Kisi.No = textBox3.Text;
            
        }

        private void verigiriskutulari_Load(object sender, EventArgs e)
        {
            comboBox1.Items.Add("Kırmızı"); //comboboxlara yeni item ekliyoruz bunu properties koleksiyon kısmındanda yapabiliriz
            comboBox1.Items.Add("Mavi");
            comboBox1.Items.Add("Yeşil");
            comboBox2.Items.Add("Kırmızı");
            comboBox2.Items.Add("Mavi");
            comboBox2.Items.Add("Yeşil");
            comboBox3.Items.Add("Kırmızı");
            comboBox3.Items.Add("Mavi");
            comboBox3.Items.Add("Yeşil");
        }

       
        
        private void button1_Click(object sender, EventArgs e)
        {


            if((comboBox1.SelectedIndex==0||comboBox1.SelectedIndex==1||comboBox1.SelectedIndex==2)&&(comboBox2.SelectedIndex==0||comboBox2.SelectedIndex==1||comboBox2.SelectedIndex==2)&&(comboBox3.SelectedIndex==0||comboBox3.SelectedIndex==1||comboBox3.SelectedIndex==2))
            {
                comboBox1.Items[0] = "k"; //eğer comboboxlarda bu seçenekler seçiliyse seçenekleri tek harfe çeviriyor
                comboBox1.Items[1] = "m";
                comboBox1.Items[2] = "y";
                comboBox2.Items[0] = "k";
                comboBox2.Items[1] = "m";
                comboBox2.Items[2] = "y";
                comboBox3.Items[0] = "k";
                comboBox3.Items[1] = "m";
                comboBox3.Items[2] = "y";
            }                                                           //verileri veriler.txt ye yazdırıyoruz 'file' system.io kütüphanesindendir 
            var yaz = File.AppendText("veriler.txt");                   //streamreader ve streamwriter kullandım onun için system.io kütüphanesini çagırdım
            yaz.WriteLine(comboBox1.Text + comboBox2.Text + comboBox3.Text + (" ")+textBox1.Text + (" ") + textBox2.Text + (" ") + textBox3.Text);
            yaz.Close();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedItem == null && comboBox2.SelectedItem == null && comboBox3.SelectedItem == null && textBox1.Text == null && textBox2.Text == null && textBox3.Text == null)
            {

                MessageBox.Show("Veri girmelisiniz"); //burada temizle butonuna bastığımızda temizliyor fakat zaten veri yoksa uyarı vermesini sağlıyoruz


            }
            else if (textBox1.Text == null && textBox2.Text == null && textBox3.Text == null)
            {

                MessageBox.Show("Renk Seçmediniz!");//aynı şekilde ad soyad numara girip renk seçmediyse başka bir mesaj vermesini sağladım
            }

            else
            { 
                textBox1.Text = String.Empty; //burada ise bütün veriler(ad,soyad,numara,renk seçimi) dolu ise verileri temizlemesini sağlıyoruz
                textBox2.Text = String.Empty;
                textBox3.Text = String.Empty;
                comboBox1.SelectedIndex = 0;
                comboBox2.SelectedIndex = 0;
                comboBox3.SelectedIndex = 0;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Hide(); //geri tuşuna bastığımızda formumuzu gizliyor bir nevi kapatıyor close da kullanabilirdik
            
        }
    }

}



