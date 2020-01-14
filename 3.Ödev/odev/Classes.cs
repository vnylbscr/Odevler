using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Classes
    {
        public enum MotorDurumu { Calisiyor, Calismiyor }
        public enum KontakDurumu { Acik, Kapali }
        public enum GazPedali { Basildi, Basilmadi }
        public enum FrenPedali { Basildi, Basilmadi }
        public enum Direksiyon { SagaDondur, SolaDondur, Duz }



        public class ElektronikBeyin
        {
            private readonly KontakDurumu _kontakAnahtari;
            private readonly IMotor _motor;



        }
        public interface IMotor
        {
            MotorDurumu Durum { get; set; }




        }
        public abstract class Motor
        {
            public MotorDurumu Durum { get; private set; }
            public int HizlanmaMiktari { get; set; }
            public int Hizlandir { get; set; }
            public int Yavaslat { get; set; }
            public int SuAnkiHiz
            {
                get { return (Hizlandir+HizlanmaMiktari)-Yavaslat;}
                
            }
            public int DondurmeDerecesi { get; set; }
            protected Motor()
            {
                Durum = MotorDurumu.Calismiyor;
            }
            public void Calistir()
            {
                if (Durum == MotorDurumu.Calisiyor)
                    return;
                Durum = MotorDurumu.Calisiyor;

            }
        }
        public class DizelMotor : Motor
        {
            public DizelMotor()
            {
                HizlanmaMiktari = 8;
                Hizlandir = 8;

               
            }
            
        }
        public class BenzinliMotor : Motor
        {

            public BenzinliMotor()
            {
                HizlanmaMiktari = 10;
                Hizlandir = 8;
            }

        }
        public class KontakAnahtari
        {
            public KontakDurumu Durum { get; private set; }
            public event EventHandler KontakAcikEventHandler;
            public KontakAnahtari()
            {
                Durum = KontakDurumu.Kapali;
            }
            public void Ac()
            {
                if (Durum == KontakDurumu.Kapali) return;

                Durum = KontakDurumu.Acik;
                if (KontakAcikEventHandler == null) return;
                KontakAcikEventHandler(this, new EventArgs());
            }
            public class GazPedaliDurumu
            {
                public GazPedali Durum2 { get; private set; }
                public event EventHandler GazPedaliBasildiEventHandler;
                public void Hizlandir()
                {

                }
                public GazPedaliDurumu()
                {
                    if (Durum2 == GazPedali.Basildi) return;
                    
                    
                    if (GazPedaliBasildiEventHandler == null) return;
                    GazPedaliBasildiEventHandler(this, new EventArgs());
                }
            }
                
            public class FrenPedaliDurumu
            {
                public FrenPedali Durum3 { get; private set; }
                public event EventHandler FrenPedaliBasildiEventHandler;
                public void Yavaslat()
                {
                    
                }
               
                public FrenPedaliDurumu()
                {
                    if (Durum3 == FrenPedali.Basildi) return;

                    if (FrenPedaliBasildiEventHandler == null)  return;
                    FrenPedaliBasildiEventHandler(this, new EventArgs());
                }
            }
            public class DireksiyonDurumu
            {
                public DireksiyonDurumu Durum4 { get; private set; }
                public event EventHandler DireksiyonCevrildiEventHandler;
                public int DireksiyonDondurmeDerecesi;
                public DireksiyonDurumu()
                {
                    if (Durum4 == Direksiyon.Duz)
                    
                    {
                        return;
                    }
                    else if (Durum4 == Direksiyon.SagaDondur)
                    {
                        DireksiyonDondurmeDerecesi = 5;
                    }
                    else (Durum4 == Direksiyon.SolaDondur)
                            {
                                DireksiyonDondurmeDerecesi = 5;   
                            }
                }

            }
             
        }

    }
}
