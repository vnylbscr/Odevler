using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        //Ben iki buton şeklinde yaptım sen istersen değiştirebilirsin
        private void btn_kayitgir_Click(object sender, EventArgs e)//Kayıt eklemeyi çağıran buton
        {
            kayitekle ekle = new kayitekle();//kayitekle formundan nesne oluşturdum
            ekle.Show();//kayitekle formu çağırdım
        }

        private void btn_kayitlistele_Click(object sender, EventArgs e)//Kayıt listelemeyi çağıran buton
        {
            kayitlistele liste = new kayitlistele();//kayitlistele formundan nesne oluşturdum
            liste.Show();//kayitlistele formu çağırdım

        }
    }
}
