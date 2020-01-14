using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    public class kisi//Kişileri nesne olarak oluşturmamız için kişi nesnesi oluşturulan sınıf
    {
        public string Ad { get; set; }
        public string Soyad { get; set; }
        public string Numara { get; set; }
        public string Renk { get; set; }
    }
    public class ComboboxItem//Renkleri comboboxlara nesne olarak atmamız için gereken sınıf
    {
        public string Text { get; set; }
        public string Value { get; set; }

    }

}
