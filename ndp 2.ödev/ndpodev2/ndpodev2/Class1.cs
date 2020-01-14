using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ndpodev2
{
    public class Class1
    {
        public string Ad { get; set; }
        public string Soyad { get; set; } 
        public string No { get; set; }
        public string Renk { get; set; }
    }
    public class ComboboxItem
    {
        public string Text { get; set; }        //burada get set ile comboboxların içindeki verileri parçalamak istiyordum ama olmadı
        public string Value { get; set; }
    }
}
