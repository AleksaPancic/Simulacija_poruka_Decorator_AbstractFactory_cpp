#include<iostream>
#include<cstring>

using namespace std;

class Poruka{
protected:
    string sadrzaj;
    string posiljaoc;
    string primalac;
    string vreme;
public:
    virtual string otvoriPoruku(string sadrzaj) = 0;
    virtual string kojeposiljaoc(string posiljaoc) = 0;
    virtual string kojeprimalac(string primalac) = 0;
    virtual string vidivreme(string vreme) = 0;
    virtual string posaljiporuku() = 0;
};

class Vider : public Poruka{
public:
    string otvoriPoruku(string sadrzaj){
        return "Vider.poruka: " + sadrzaj;
    }
    string kojeposiljaoc(string posiljaoc){
        return "Vider.posiljaoc: " + posiljaoc;
    }
    string kojeprimalac(string primalac){
        return "Vider.primalac: " + primalac;
    }
    string vidivreme(string vreme){
        return "Vider.vreme: " + vreme;
    }
    string posaljiporuku(){
        return "Saljem poruku preko Vider-a";
    }
};
class Skarp : public Poruka{
public:
    string otvoriPoruku(string sadrzaj){
        return "Skarp.poruka: " + sadrzaj;
    }
    string kojeposiljaoc(string posiljaoc){
        return "Skarp.posiljaoc: " + posiljaoc;
    }
    string kojeprimalac(string primalac){
        return "Skarp.primalac: " + primalac;
    }
    string vidivreme(string vreme){
        return "Skarp.vreme: " + vreme;
    }
    string posaljiporuku(){
        return "Saljem poruku preko Skarp-a";
    }
};
//apstraktna fabrika
class Fabrika{
public:
    virtual Poruka* skarp() = 0;
    virtual Poruka* vider() = 0;
};
//konkretna fabrika
class FabrikaKreiranjaPoruka{
    public:
    Poruka* skarp(){
        return new Skarp();
    }
    Poruka* vider(){
        return new Vider();
    }
};
//Dopuna/decorator
//apstraktna dopuna
class PorukaDopuna{
protected:
    Poruka* poruke;
public:
    PorukaDopuna(Poruka* dopuna){
        if(poruke!=NULL){
            poruke = dopuna;
        }
    }
    virtual string otvoriporuku(string sadrzaj){
        poruke->otvoriPoruku(sadrzaj);
    }
    virtual string posaljiporuku(){
        poruke->posaljiporuku();
    }
    virtual ~PorukaDopuna(){
        delete poruke;
    }
};
//konkretna dopuna sa slikom
class PorukaDopunaSaSlikom : public PorukaDopuna{
public:
    //PorukaDopunaSaSlikom(Poruka* dopuna) : PorukaDopuna(dopuna){}
     virtual string otvoriporuku(string sadrzaj){
        poruke->otvoriPoruku(sadrzaj) + "sa slikom";
    }
    virtual string posaljiporuku(){
        poruke->posaljiporuku() + "sa slikom";
    }
    /*virtual ~PorukaDopunaSaSlikom(){
        delete poruke;
    }*/
};

class PorukaDopunaSaFajlom : public PorukaDopuna{
public:
    string pitajkorisnika();
    // PorukaDopunaSaFajlom(Poruka* dopuna) : PorukaDopuna(dopuna){}
    virtual string otvoriporuku(string sadrzaj){
        poruke->otvoriPoruku(sadrzaj) + "sa fajlom" + pitajkorisnika();
    }
    virtual string posaljiporuku(){
        poruke->posaljiporuku() + "sa fajlom";
    }
   /* virtual ~PorukaDopunaSaFajlom(){
        delete poruke;
    }*/
};

class PorukaDopunaSaVideom : public PorukaDopuna{
public:
    // PorukaDopunaSaFajlom(Poruka* dopuna) : PorukaDopuna(dopuna){}
    virtual string otvoriporuku(string sadrzaj){
        poruke->otvoriPoruku(sadrzaj) + "sa videom";
    }
    virtual string posaljiporuku(){
        poruke->posaljiporuku() + "sa videom";
    }
   /* virtual ~PorukaDopunaSaVideom(){
        delete poruke;
    }*/
};

string pitajkorisnika(){
    cout << "Da li zelite da otvorite fajl?" << endl;
    string odgovor;
    cin >> odgovor;
    if(odgovor == "Da"){
        return "Otvaram fajl..";
    }else{
        return " ";
    }
}
int main(){
    FabrikaKreiranjaPoruka* fabrika = new FabrikaKreiranjaPoruka();
    Poruka* poruka;
    poruka = fabrika->skarp();
    cout << poruka->otvoriPoruku("Test otvaranja skarp poruke") << endl;
    cout << poruka->kojeposiljaoc("Aleksa") << endl;
    cout << poruka->kojeprimalac("Aleksa") << endl;
    cout << poruka->vidivreme("10:01AM") << endl;
    cout << poruka->posaljiporuku() << endl;
    poruka = fabrika->vider();
    cout << poruka->otvoriPoruku("Test otvaranja vider poruke") << endl;
    cout << poruka->kojeposiljaoc("Aleksa") << endl;
    cout << poruka->kojeprimalac("Aleksa") << endl;
    cout << poruka->vidivreme("10:02AM") << endl;
    cout << poruka->posaljiporuku() << endl;
    cout << "Dopuna: " << endl;
    /*PorukaDopunaSaVideom* porukadopuna = new PorukaDopunaSaVideom();
    cout<< porukadopuna->posaljiporuku() << endl;*/
}
