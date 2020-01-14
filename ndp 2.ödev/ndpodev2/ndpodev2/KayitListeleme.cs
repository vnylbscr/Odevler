using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;                                                                   //MERT GENÇ
using System.Linq;                                                                      //B161210045
using System.Text;                                                                      //NDP 2.ÖDEV
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;


namespace ndpodev2
{
    public partial class KayitListeleme : Form
    {
        public KayitListeleme()
        {
            InitializeComponent();
        }

        private void KayitListeleme_Load(object sender, EventArgs e)
        {


            richTextBox1.ReadOnly = true;


        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(File.Exists("veriler.txt"))//okuma işlemi yapıyoruz exist metodu system.io kütüphanesindendir 
            {
                richTextBox1.Clear();
                StreamReader Okuma = new StreamReader("veriler.txt");
                string metin = Okuma.ReadLine();
                while (metin != null)
                {
                    richTextBox1.Text = richTextBox1.Text + "\n" +metin;
                    metin = Okuma.ReadLine();
                }
                Okuma.Close();
              
            }


           else 
            {
                MessageBox.Show("Veri bulunamadı");
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide(); 
        }
    }
}
