#include "BST.hpp"
#include "iostream"
#include <cmath>

//Mert Genç b161210045--mert.genc1@ogr.sakarya.edu.tr
//Sinan Demir--g141210075
//09.12.2019
//veri yapilari 3.odev
//1A Grubu
BST::BST()
{
	root=nullptr;
}
Dugum* BST::RootDondur()
{
	return root;
}
void BST::RootDegistir(Dugum *degistirilen)
{
	root=degistirilen;
}

void BST::pEkle(int deger,Dugum* agac)
 {

		if(deger < agac->data)
		{
			if(agac->sol != nullptr)
			{
			pEkle(deger, agac->sol);
			agac->soy_Sayisi=agac->soy_Sayisi+1; //soy sayisi artirma
			}
			else
			{
			agac->sol = new Dugum();
			agac->sol->data = deger;
			agac->sol->sol = nullptr;
			agac->sol->sag = nullptr;
			agac->soy_Sayisi=agac->soy_Sayisi+1; //soy sayisi artirma

			}
		}
		else if(deger >= agac->data)
		{
			if(agac->sag != nullptr)
			{
			pEkle(deger, agac->sag);
			agac->soy_Sayisi=agac->soy_Sayisi+1;
			
			}
			else{

			agac->sag = new Dugum();
			agac->sag->data = deger;
			agac->sag->sag = nullptr;
			agac->sag->sol = nullptr;
			agac->soy_Sayisi=agac->soy_Sayisi+1;
		}
	}
}

void BST::Ekle(int deger)
{
     if (root!=nullptr)
     {
          pEkle(deger,root);
     }
     else
     {
          root=new Dugum();
          root->data=deger;
          root->sag=nullptr;
          root->sag=nullptr;
     }
     
}

void BST::DizidenEkle(int *sayiDizisi,int size) //parametre olarak alinan int dizisini agaca ekleyen fonksiyon
{
     for (int i = 0; i < size; i++)
     {
          Ekle(sayiDizisi[i]);
     }
}

void BST::postOrderPrint() //post order traversal 
{
	postOrderPrint(root);
	cout<<"\n";
}
void BST::postOrderPrint(Dugum *agac)
{
	
	if(agac != nullptr){
		postOrderPrint(agac->sol);
		postOrderPrint(agac->sag);
		cout << "<"<<agac->data << ","<<agac->soy_Sayisi<<">";
	}
	
	
}
int BST::ToplamSoySayisi()
{
	return ToplamSoySayisi(root);
}
int BST::ToplamSoySayisi(Dugum *agac) //toplam soy sayisini donduren fonksiyon
{
	if(agac==nullptr) return 0;
	
	return(agac->soy_Sayisi+ToplamSoySayisi(agac->sol)+ToplamSoySayisi(agac->sag));
	
	
}
int BST::SoySayisiBul(Dugum *node)
{
	int res=0;
	if (node!=nullptr)
	{
		return 1+SoySayisiBul(node->sag)+SoySayisiBul(node->sol);
	}
	

}
int BST::findMin() //agactaki min degeri bulan fonskiyon
{
	findMin(root);
}
int BST::findMin(Dugum *agac)
{
	if (agac==nullptr)
	{
		return -1;
	}

	else
	{
		int res=agac->data;

		if (agac->sol!=nullptr)
		{
			res=std::min(res,findMin(agac->sol));
		}
		
		return res;
	}
}
int BST::findMax() 
{
	findMax(root);
}

int BST::findMax(Dugum *agac) //agactaki maximum degeri bulan fonksiyon
{ 

	if (agac==nullptr)
	{
		return -1;
	}

	else
	{
		int res=agac->data;

		if (agac->sag!=nullptr)
		{
			res=std::max(res,findMax(agac->sag));
		}
		
		return res;
	}
	
	
}
void BST::Sil(int key)
{
	Sil(key,root);
}
Dugum* BST::Sil(int x,Dugum *t) //silme fonksiyonu
{
	   Dugum *temp;

		
        if(t == nullptr)
	   {
		   return nullptr;
	   }
            
        else if(x < t->data)
	   {
		   t->sol = Sil(x, t->sol);
	   }
            
        else if(x > t->data)
	   {
		   t->sag = Sil(x, t->sag);
	   }
            //2 cocuklu dugum siliniyor
        else if(t->sol!=nullptr && t->sag!=nullptr)
        {
            temp = Ara(findMax(t->sol)); //sol cocugun en sagina yani max
            t->data = temp->data;
            t->sag = Sil(t->data, t->sag);
        }
        else
        {
            temp = t;
            if(t->sol == nullptr)
                t = t->sag;
            else if(t->sag == nullptr)
                t = t->sol;
            delete temp;
        }

        return t;


}
Dugum* BST::Ara(int key)
{
	Ara(key,root);
}
Dugum* BST::Ara(int key,Dugum *agac) // aranan dugumu bulup donduren fonksiyon
{
	if (root == nullptr)
	{
		return root;
	}
    	
  	else if ((agac->data > key && agac->sol == nullptr) || (agac->data < key && agac->sag == nullptr))
	  {
		  return agac;  
	  }
    	
 	else if (agac->data == key)
	 {
		return agac;
	 }
    	
  	else if (key > agac->data)
	  {
		  Ara(key, agac->sag);
	  }
    	
  	else if (key < agac->data)
	  {
		  Ara(key, agac->sol);
	  }
    	
}
void BST::pDeleteBST(Dugum *agac) //heapten tahsis edilen yerleri iade ediyoruz
{
	  if (!agac)
                return;

        Dugum *temp = agac;
        Dugum *solAgacDugum = agac->sol;
        Dugum *sagAgacDugum = agac->sag;
        delete(temp);
        pDeleteBST(solAgacDugum);
        pDeleteBST(sagAgacDugum);	
}
void BST::DeleteBST()
{
	pDeleteBST(root);
}

BST::~BST()  //yikici metod
{
	DeleteBST();
}

