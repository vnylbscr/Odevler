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
    public partial class Form1 : Form
    {
        

        public Form1()
        {
            InitializeComponent();
        }
        

        private void button1_Click(object sender, EventArgs e)//kayıt ekle butonuna bastığımızda kayıt ekleme formunu çağırıyoruz
        {
            verigiriskutulari a = new verigiriskutulari();
            a.Show();
        }

        private void button3_Click(object sender, EventArgs e)//çıkış butonuna bastığımızda uygulamamızdan çıkış yapıyoruz
        {
            this.Close(); 
            
        }

        private void button2_Click(object sender, EventArgs e)//kayıt listeleme butonuna bastığımızda kayıt listeleme formunu çağırıyorz
        {
            KayitListeleme b = new KayitListeleme();
            b.Show();
        }
    }
}
