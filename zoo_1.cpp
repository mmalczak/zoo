#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


class Zwierze{
    public:
    virtual void daj_glos()=0;
    virtual void wyswietl_masa()=0;
    int masa;

    Zwierze(){
    masa=0;
    }

    virtual ~Zwierze(){

    }

};


class Kon : public Zwierze
{
    public:
    virtual void daj_glos(){cout << "ihaaa" << endl;}
    virtual void wyswietl_masa(){cout << "masa " << masa << endl;}
    Kon(){
    masa=128;
    }


};




class Osiol : public Zwierze{
    public:
    virtual void daj_glos(){cout << "duuuuurny" << endl;}
    virtual void wyswietl_masa(){cout << "masa" << endl;}
    Osiol(){
    masa=168;
    }

};


class Rzeznia{

    public:

    void usmierc(Zwierze* z){
        delete z;
        cout << "Usmiercony w rzezni"<<endl;
    }

};
class Fabryka_zwierzakow{

    public:
    Zwierze* wytworz_zwierze(){


		if(rand()%100 > 50)
			return new Osiol();
		else
			return new Kon();

    }

};


class Zoo{

    protected:
    vector <Zwierze*> v;

    public:

    int ile(){
        return v.size();
    }

    int masa(){
        int m=0;
        for(int i=0; i<ile(); i++){
            m=m+v.at(i)->masa;
        }
        return m;
    }

    bool dodaj_zwierze(Zwierze* z){

        if(masa()+z->masa<1000){
            v.push_back(z);
            z -> daj_glos();
            cout << masa() << endl;
            return true;
        }else{
            return false;
        }



    }
    Zwierze* odczytaj(int i){
        return v.at(i);;
    }



};


int main()
{

  /*  srand(time(NULL));

    vector<Zwierze*> v;

    v.push_back(new Osiol());
    v.push_back(new Kon());

   v.at(0)->daj_glos();
   v.at(1)->daj_glos();
*/

/*
Zoo zoo;
zoo.dodaj(new koza());
///////////

Zoo *zoo;

zoo = new Zoo();
zoo -> dodaj();
(*zoo).dodaj();

*/

    srand(time(NULL));


    Zoo* z = new Zoo();
    Rzeznia rz;
    Fabryka_zwierzakow f;
    Zwierze *zw;

    zw = f.wytworz_zwierze();
    if(z -> dodaj_zwierze(zw)==false){
        rz.usmierc(zw);
    }  zw = f.wytworz_zwierze();
    if(z -> dodaj_zwierze(zw)==false){
        rz.usmierc(zw);
    }  zw = f.wytworz_zwierze();
    if(z -> dodaj_zwierze(zw)==false){
        rz.usmierc(zw);
    }  zw = f.wytworz_zwierze();
    if(z -> dodaj_zwierze(zw)==false){
        rz.usmierc(zw);
    }  zw = f.wytworz_zwierze();
    if(z -> dodaj_zwierze(zw)==false){
        rz.usmierc(zw);
    }  zw = f.wytworz_zwierze();
    if(z -> dodaj_zwierze(zw)==false){
        rz.usmierc(zw);
    }  zw = f.wytworz_zwierze();
    if(z -> dodaj_zwierze(zw)==false){
        rz.usmierc(zw);
    }  zw = f.wytworz_zwierze();
    if(z -> dodaj_zwierze(zw)==false){
        rz.usmierc(zw);
    }  zw = f.wytworz_zwierze();
    if(z -> dodaj_zwierze(zw)==false){
        rz.usmierc(zw);
    }  zw = f.wytworz_zwierze();
    if(z -> dodaj_zwierze(zw)==false){
        rz.usmierc(zw);
    }




   /* cout<<z->odczytaj(0)->masa<<endl;

    cout << z -> masa()<<endl;
*/
    return 0;
}
