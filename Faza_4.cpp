#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::istream;
using std::ostream;
using std::string;
using std::endl;


class Magazin {
private:
	const int taxa;
	string numeMagazin;
	int numarAngajati;
	string adresa;
	int numarProduse;
	int* inventar;
	static int nrMagazine; //total magazine din lant

public:

	//Constructor fara parametrii
	Magazin() :taxa(1) {
		numeMagazin = "Necunoscut";
		numarAngajati = 0;
		adresa = "Necunoscut";
		numarProduse = 0;
		inventar = 0;
	}

	//Constructor cu toti parametrii
	Magazin(int taxaInitiala, string numeMagazin, int numarAngajati, string adresa, int numarProduse, int* inventar) :taxa(taxaInitiala) {
		this->numeMagazin = numeMagazin;
		this->numarAngajati = numarAngajati;
		this->adresa = adresa;
		this->numarProduse = numarProduse;
		this->inventar = new int[numarProduse];
		for (int i = 0;i < numarProduse;i++)
		{
			this->inventar[i] = inventar[i];
		}
	}

	Magazin(int taxaInitiala, int numarProduse, int* inventar) :taxa(taxaInitiala) {
		this->numarProduse = numarProduse;
		this->inventar = new int[numarProduse];
		for (int i = 0;i < numarProduse;i++)
		{
			this->inventar[i] = inventar[i];
		}
	}

	//Prima functie pt clasa Magazin
	int valoareaTotalaInventar() {
		int valoareTotala = 0;
		for (int i = 0; i < numarProduse; i++)
		{
			valoareTotala += inventar[i];
		}
		return valoareTotala;
	}

	//operator<<
	friend ostream& operator<<(ostream& afisare, const Magazin& m) {
		afisare << "Nume magazin: " << m.numeMagazin << endl;
		afisare << "Numar angajati: " << m.numarAngajati << endl;
		afisare << "Adresa: " << m.adresa << endl;
		afisare << "Numar produse: " << m.numarProduse << endl;
		afisare << "Inventar: ";
		for (int i = 0;i < m.numarProduse;i++)
		{
			afisare << m.inventar[i] << " ";
		}
		afisare << endl;
		return afisare;
	}

	//operator>>
	friend istream& operator>>(istream& citire, Magazin& m) {
		cout << "Nume magazin: ";
		citire >> m.numeMagazin;
		cout << endl;
		cout << "Numar angajati: ";
		citire >> m.numarAngajati;
		cout << endl;
		cout << "Adresa: ";
		citire >> m.adresa;
		cout << endl;
		cout << "Numar produse: ";
		citire >> m.numarProduse;
		cout << endl;
		cout << "Inventar: ";
		if (m.inventar != NULL)
			delete[]m.inventar;
		m.inventar = new int[m.numarProduse];
		for (int i = 0;i < m.numarProduse;i++)
		{
			cout << "Inventarul " << i + 1 << " este: ";
			citire>> m.inventar[i];
		}
		cout << endl;
		return citire;

	}

	//Destructor
	~Magazin() {
		if (inventar != NULL) {
			delete[]inventar;
		}
	}

	//Constructor de copiere
	Magazin(const Magazin& m) :taxa(m.taxa) {
		this->numeMagazin = m.numeMagazin;
		this->numarAngajati = m.numarAngajati;
		this->adresa = m.adresa;
		this->numarProduse = m.numarProduse;
		this->inventar = new int[m.numarProduse];
		for (int i = 0;i < m.numarProduse;i++)
		{
			this->inventar[i] = m.inventar[i];
		}
	}

	//getteri
	const int getTaxa() {
		return this->taxa;
	}

	string getNumeMagazin() {
		return this->numeMagazin;
	}

	int getNumarAngajati() {
		return this->numarAngajati;
	}

	string getAdresa() {
		return this->adresa;
	}

	int getNumarProduse() {
		return this->numarProduse;
	}

	int* getInventar() {
		return this->inventar;
	}

	//setteri
	void setNumeMagazin(string numeMagazin) {
		this->numeMagazin = numeMagazin;
	}

	void setNumarAngajati(int numarAngajati) {
		this->numarAngajati = numarAngajati;
	}

	void setAdresa(string adresa) {
		this->adresa = adresa;
	}

	void setProduse(int numarProduse, int* inventar) {
		this->numarProduse = numarProduse;
		this->inventar = new int[this->numarProduse];
		for (int i = 0;i < this->numarProduse;i++)
		{
			this->inventar[i] = inventar[i];
		}
	}

	//functiile statice de acces pentru atributele statice
	static int getNrMagazine() {
		return Magazin::nrMagazine;
	}

	static void setNrMagazine(int nrMagazine) {
		Magazin::nrMagazine = nrMagazine;
	}

	//functie prietena
	friend void schimbareNumeMagazin(Magazin& m, string& numeNou);

	//operator =
	Magazin& operator=(const Magazin& m) {
		if (this != &m)
		{
			if (inventar != NULL)
			{
				delete[]inventar;
			}
			this->numeMagazin = m.numeMagazin;
			this->numarAngajati = m.numarAngajati;
			this->adresa = m.adresa;
			this->numarProduse = m.numarProduse;
			this->inventar = new int[m.numarProduse];
			for (int i = 0;i < m.numarProduse;i++)
			{
				this->inventar[i] = m.inventar[i];
			}
			return *this;
		}
	}

	//operator ++ prefixat
	Magazin& operator++() {
		numarAngajati++;
		return *this;
	}

	//operator index
	int& operator[] (int index) {
		if (index >= 0 && index <= this->numarProduse)
			return this->inventar[index];
	}

	bool operator>=(const Magazin& m) {
		return(this->numarAngajati >= m.numarAngajati);
	}
};

//functie globala
void schimbareNumeMagazin(Magazin& m, string& numeNou) {
	cout << "Numele magazinului se schimba din " << m.numeMagazin << " in " << numeNou << endl;
	m.numeMagazin = numeNou;
}


class Client {
private:
	const int discount;
	string numeClient;
	string numarTelefon;
	int numarComanda;
	float* istoricCumparaturi;//banii inregistrati in fiecare sesiune 
	static int numarClienti; //numarul de clienti inregistrati in sistem

public:

	//Constructor fara parametrii
	Client() :discount(1) {
		numeClient = "Necunoscut";
		numarTelefon = "Necunoscut";
		numarComanda = 0;
		istoricCumparaturi = 0;
	}

	//Constructor cu toti parametrii
	Client(int discountInitial, string numeClient, string numarTelefon, float numarComanda, float* istoricCumparaturi) :discount(discountInitial) {
		this->numeClient = numeClient;
		this->numarTelefon = numarTelefon;
		this->numarComanda = numarComanda;
		this->istoricCumparaturi = new float[numarComanda];
		for (int i = 0;i < numarComanda;i++) {
			this->istoricCumparaturi[i] = istoricCumparaturi[i];
		}
	}

	Client(int discountInitial, float numarComanda, float* istoricCumparaturi) :discount(discountInitial) {
		this->numarComanda = numarComanda;
		this->istoricCumparaturi = new float[numarComanda];
		for (int i = 0;i < numarComanda;i++) {
			this->istoricCumparaturi[i] = istoricCumparaturi[i];
		}
	}

	//Prima functie pentru clasa Client
	void istoriculCumparaturilor() {
		cout << "Istoricul cumparaturilor al clientului " << numeClient << endl;
		for (int i = 0;i < numarComanda;i++) {
			cout << "Sesiunea de cumparaturi " << i + 1 << " este in valoare de " << istoricCumparaturi[i] << " lei." << endl;
		}
	}

	//operator<<
	friend ostream& operator<<(ostream& afisare, const Client& c) {
		afisare << "Nume client: " << c.numeClient << endl;
		afisare << "Numar telefon: " << c.numarTelefon << endl;
		afisare << "Numar comanda: " << c.numarComanda << endl;
		afisare << "Istoric cumparaturi: ";
		for (int i = 0;i < c.numarComanda;i++) {
			afisare << c.istoricCumparaturi[i] << " ";
		}
		afisare << endl;
		return afisare;
	}

	friend istream& operator>>(istream& citire, Client& c) {
		cout << "Nume client: ";
		citire >> c.numeClient;
		cout << endl;
		cout << "Numar telefon: ";
		citire >> c.numarTelefon;
		cout << endl;
		cout << "Numar comanda: ";
		citire >> c.numarComanda;
		cout << endl;
		cout << "Istoric cumparaturi: ";
		c.istoricCumparaturi = new float[c.numarComanda];
		for (int i = 0;i < c.numarComanda;i++) {
			cout << "Istoricul cumparaturilor comenzii " << i + 1 << " este: " << endl;
			citire >> c.istoricCumparaturi[i];
		}
		cout << endl;
		return citire;
	}

	//Desctructor
	~Client() {
		if (istoricCumparaturi != NULL) {
			delete[]istoricCumparaturi;
		}
	}

	//Constructor de copiere
	Client(const Client& c) : discount(c.discount) {
		this->numeClient = c.numeClient;
		this->numarTelefon = c.numarTelefon;
		this->numarComanda = c.numarComanda;
		this->istoricCumparaturi = new float[c.numarComanda];
		for (int i = 0;i < c.numarComanda;i++) {
			this->istoricCumparaturi[i] = c.istoricCumparaturi[i];
		}
	}

	//getteri
	const int getDiscount() {
		return this->discount;
	}

	string getNumeClient() {
		return this->numeClient;
	}

	string getNumarTelefon() {
		return this->numarTelefon;
	}

	float getNumarComanda() {
		return this->numarComanda;
	}

	float* getIstoricCumparaturi() {
		return this->istoricCumparaturi;
	}

	//setteri
	void setNumeClient(string numeClient) {
		this->numeClient = numeClient;
	}

	void setNumarTelefon(string numarTelefon) {
		this->numarTelefon = numarTelefon;
	}

	void setCumparaturi(float numarComanda, float* istoricCumparaturi) {
		this->numarComanda = numarComanda;
		this->istoricCumparaturi = new float[this->numarComanda];
		for (int i = 0;i < this->numarComanda;i++) {
			this->istoricCumparaturi[i] = istoricCumparaturi[i];
		}
	}

	//functiile statice de acces pentru atributele statice
	static int getNrClienti() {
		return Client::numarClienti;
	}

	static void setNrClienti(int numarClienti) {
		Client::numarClienti = numarClienti;
	}

	//functie prietena
	friend void afisareInformatiiClient(const Client& c);

	Client& operator=(const Client& c) {
		if (this != &c)
		{
			if (istoricCumparaturi != NULL)
			{
				delete[]istoricCumparaturi;
			}
			this->numeClient = c.numeClient;
			this->numarTelefon = c.numarTelefon;
			this->numarComanda = c.numarComanda;
			this->istoricCumparaturi = new float[c.numarComanda];
			for (int i = 0;i < c.numarComanda;i++) {
				this->istoricCumparaturi[i] = c.istoricCumparaturi[i];
			}
			return *this;
		}
	}

	//operator += 
	Client operator+=(const Client& c) {
		Client aux = *this;
		this->numarComanda += c.numarComanda;
		delete[]istoricCumparaturi;
		this->istoricCumparaturi = new float[this->numarComanda];
		for (int i = 0; i < this->numarComanda - 1;i++) {
			this->istoricCumparaturi[i] = c.istoricCumparaturi[i];
		}
		return *this;
	}

	//operator <
	bool operator<(const Client& c) {
		return(this->numarClienti < c.numarClienti);
	}

	//operatorul !=
	bool operator!=(const Client& c) {
		return !(this->numeClient == c.numeClient && this->numarTelefon == c.numarTelefon);
	}


};

//functie globala
void afisareInformatiiClient(const Client& c) {
	cout << "Nume client: " << c.numeClient << endl << "Numar telefon: " << c.numarTelefon << endl << "Numar comanda: " << c.numarComanda << endl;
}

class Tranzactie {
private:
	const int taxaTranzactie;
	string dataTranzactie;
	int numarTranzactii;
	string metodaPlata;
	float* tranzactii;
	static int numarMaximTranzactii; //numar maxim posibil de tranzactii

public:

	//Constructor fara parametrii
	Tranzactie() :taxaTranzactie(1) {
		dataTranzactie = "Necunoscut";
		numarTranzactii = 0;
		metodaPlata = "Necunoscut";
		tranzactii = 0;
	}

	//Constructor cu toti parametrii
	Tranzactie(int taxaTranzactieInitiala, string dataTranzactie, string metodaPlata, int numarTranzactii, float* tranzactii) :taxaTranzactie(taxaTranzactieInitiala) {
		this->dataTranzactie = dataTranzactie;
		this->metodaPlata = metodaPlata;
		this->numarTranzactii = numarTranzactii;
		this->tranzactii = new float[numarTranzactii];
		for (int i = 0; i < numarTranzactii;i++) {
			this->tranzactii[i] = tranzactii[i];
		}
	}

	Tranzactie(int taxaTranzactieInitiala, int numarTranzactii, float* tranzactii) :taxaTranzactie(taxaTranzactieInitiala) {
		this->numarTranzactii = numarTranzactii;
		this->tranzactii = new float[numarTranzactii];
		for (int i = 0; i < numarTranzactii;i++) {
			this->tranzactii[i] = tranzactii[i];
		}
	}

	//Prima functie pentru clasa Tranzactie
	float medieTranzactii() {
		float suma = 0;
		for (int i = 0;i < numarTranzactii;i++) {
			suma += tranzactii[i];
		}
		return suma / numarTranzactii;
	}

	friend ostream& operator<< (ostream& afisare, const Tranzactie& t) {
		afisare << "Data tranzactie: " << t.dataTranzactie << endl;
		afisare << "Numar tranzactie: " << t.numarTranzactii << endl;
		afisare << "Metoda plata: " << t.metodaPlata << endl;
		afisare << "Tranzactii: ";
		for (int i = 0;i < t.numarTranzactii;i++) {
			afisare << t.tranzactii[i] << " ";
		}
		afisare << endl;
		return afisare;
	}

	friend istream& operator>>(istream& citire, Tranzactie& t) {
		cout << "Data tranzactie: ";
		citire >> t.dataTranzactie;
		cout << endl;
		cout << "Numar tranzactie: ";
		citire >> t.numarTranzactii;
		cout << endl;
		cout << "Metoda plata: ";
		citire >> t.metodaPlata;
		cout << endl;
		cout << "Tranzactii: ";
		t.tranzactii = new float[t.numarTranzactii];
		for (int i = 0; i < t.numarTranzactii;i++) {
			cout << "Tranzactia: " << i + 1 << " este: " << endl;
			citire>>t.tranzactii[i];
		}
		cout << endl;
		return citire;

	}

	//Destructor
	~Tranzactie() {
		if (tranzactii != NULL) {
			delete[]tranzactii;
		}
	}

	//Constructor de copiere
	Tranzactie(const Tranzactie& t) :taxaTranzactie(t.taxaTranzactie) {
		this->dataTranzactie = t.dataTranzactie;
		this->metodaPlata = t.metodaPlata;
		this->numarTranzactii = t.numarTranzactii;
		this->tranzactii = new float[t.numarTranzactii];
		for (int i = 0; i < t.numarTranzactii;i++) {
			this->tranzactii[i] = t.tranzactii[i];
		}
	}

	//getteri
	const int getTaxaTranzactie() {
		return this->taxaTranzactie;
	}

	string getDataTranzactie() {
		return this->dataTranzactie;
	}

	int getNumarTranzactii() {
		return this->numarTranzactii;
	}

	string getMetodaPlata() {
		return this->metodaPlata;
	}

	float* getTranzactii() {
		return this->tranzactii;
	}

	//setteri
	void setDataTranzactie(string dataTranzactie) {
		this->dataTranzactie = dataTranzactie;
	}

	void setMetodaPlata(string metodaPlata) {
		this->metodaPlata = metodaPlata;
	}

	void setTranzactii(int numarTranzactii, float* tranzactii) {
		this->numarTranzactii = numarTranzactii;
		this->tranzactii = new float[numarTranzactii];
		for (int i = 0; i < numarTranzactii;i++) {
			this->tranzactii[i] = tranzactii[i];
		}
	}

	//functiile statice de acces pentru atributele statice
	static int getNrMaximTranzactii() {
		return Tranzactie::numarMaximTranzactii;
	}

	static void setNrMaximTranzactii(int numarMaximTranzactii) {
		Tranzactie::numarMaximTranzactii = numarMaximTranzactii;
	}

	Tranzactie& operator=(const Tranzactie& t) {
		if (this != &t)
		{
			if (tranzactii != NULL) {
				delete[]tranzactii;
			}
			this->dataTranzactie = t.dataTranzactie;
			this->metodaPlata = t.metodaPlata;
			this->numarTranzactii = t.numarTranzactii;
			this->tranzactii = new float[t.numarTranzactii];
			for (int i = 0; i < t.numarTranzactii;i++) {
				this->tranzactii[i] = t.tranzactii[i];
			}
			return *this;
		}
	}

	//operator cast()
	operator int()const {
		return this->numarTranzactii;
	}

	//operator ++ postfixat
	Tranzactie& operator++(int) {
		Tranzactie aux = *this;
		this->numarTranzactii++;
		return aux;
	}

	//operator ==
	bool operator ==(Tranzactie t) {
		return this->numarTranzactii == t.numarTranzactii;
	}


};

int Magazin::nrMagazine = 10;
int Client::numarClienti = 240;
int Tranzactie::numarMaximTranzactii = 1200;

int main() {
	int* inventar = new int[3]{ 20, 12, 3 };
	Magazin m1, m2(21, 3, inventar), m3(10, "Mega", 7, "Str. Lalelei", 3, inventar), m5(5, "Penny", 5, "str. Florii", 3, inventar);
	cout << "Constructor fara parametrii (Magazin): " << endl;
	cout << m1 << endl;
	cout << "Constructor cu 2 parametrii (Magazin): " << endl;
	cout << m2 << endl;
	cout << "Constructor cu toti parametrii (Magazin): " << endl;
	cout << m3 << endl;

	float* istoricCumparaturi = new float[7]{ 10.2,75,62.9,21.8,89.5,47,91 };
	Client c1, c2(15, 7, istoricCumparaturi), c3(10, "Andra Cordes", "0733243567", 7, istoricCumparaturi), c5(5, "Maria Lascu", "0788392434", 7, istoricCumparaturi);
	cout << "Constructor fara parametrii (Client): " << endl;
	cout << c1 << endl;
	cout << "Constructor cu 2 parametrii (Client): " << endl;
	cout << c2 << endl;
	cout << "Constructor cu toti parametrii (Client): " << endl;
	cout << c3 << endl;

	float* tranzactii = new float[4]{ 54,67,80,91 };
	float* tranzactii2 = new float[3]{ 5,1,23 };
	Tranzactie t1, t2(25, 4, tranzactii), t3(25, "20.02.2020", "card", 4, tranzactii), t4(20, "20.02.2020", "cash", 3, tranzactii2), t5(10, "15.01.2007", "card", 4, tranzactii);
	cout << "Constructor fara parametrii (Tranzactie): " << endl;
	cout << t1 << endl;
	cout << "Constructor cu 2 parametrii (Tranzactie): " << endl;
	cout << t2 << endl;
	cout << "Constructor cu toti parametrii (Tranzactie): " << endl;
	cout << t3 << endl;

	cout << "Prima functie pentru clasa Magazin: " << endl;
	cout << "Valoarea totala a inventarului magazinului " << m3.getNumeMagazin() << " este: " << m3.valoareaTotalaInventar() << " lei." << endl;

	cout << endl << "Prima functie pentru clasa Client: " << endl;
	c3.istoriculCumparaturilor();

	cout << endl << "Prima functie pentru clasa Tranzactie: " << endl;
	cout << "Media tranzactiilor t5 este: " << t5.medieTranzactii() << endl;

	cout << endl << "Constructor de copiere------------" << endl;
	Magazin m4 = m2;
	Client c4 = c3;
	Tranzactie t6 = t4;
	cout << "Magazin 4: " << endl << m4 << endl;
	cout << "Client 4: " << endl << c4 << endl << endl;
	cout << "Tranzactie 6: " << endl << t6 << endl;

	cout << endl << "Getteri---------------------" << endl << endl;
	cout << m3.getAdresa() << endl;
	cout << m3.getNrMagazine() << endl;
	cout << m3.getNumarAngajati() << endl;
	cout << m3.getNumarProduse() << endl;
	for (int i = 0; i < m3.getNumarProduse(); i++)
	{
		cout << m3.getInventar()[i] << " ";
	}
	cout << endl;

	cout << endl << "Setteri---------------------" << endl << endl;
	t3.setDataTranzactie("1.08.2021");
	cout << t3.getDataTranzactie() << endl;
	t3.setMetodaPlata("cash");
	cout << t3.getMetodaPlata() << endl;
	t3.setNrMaximTranzactii(2000);
	cout << t3.getNrMaximTranzactii() << endl;
	float* tranzactii3 = new float[4]{ 10,12,9.2,3.8 };
	t3.setTranzactii(4, tranzactii3);
	for (int i = 0; i < t3.getNumarTranzactii();i++) {
		cout << t3.getTranzactii()[i] << " ";
	}
	cout << endl;

	cout << endl << "Functiile statice de acces pentru atributele statice---------------------" << endl;
	Magazin::setNrMagazine(50);
	cout << Magazin::getNrMagazine() << endl;
	Client::setNrClienti(35);
	cout << Client::getNrClienti() << endl;
	Tranzactie::setNrMaximTranzactii(2500);
	cout << Tranzactie::getNrMaximTranzactii() << endl << endl;

	cout << "Functiile globale---------------------" << endl;
	string numeNou = "Penny";
	schimbareNumeMagazin(m3, numeNou);
	cout << endl;
	afisareInformatiiClient(c3);

	cout << endl << endl << "Operator = ---------------------" << endl;
	m1 = m3;
	cout << m1 << endl;
	c1 = c2;
	cout << c1 << endl;
	t1 = t4;
	cout << t4 << endl;

	cout << endl << "Operatori clasa Magazin------------" << endl << endl << "Operatorul ++ (prefixat): " << endl;
	++m3;
	cout << m3.getNumarAngajati() << endl << endl;
	cout << "Operatorul index: " << endl;
	int aux = m3[2];
	cout << aux << endl << endl;
	cout << "Operatorul >=: " << endl;
	bool b;
	b = m3 >= m5;
	cout << b << endl;

	cout << endl << "Operatori clasa Client--------------" << endl << endl << "Operatorul += : " << endl;
	c3 += c5;
	cout << c3.getNumarComanda() << endl << endl;
	cout << "Operatorul < : " << endl;

	bool b1;
	b1 = c3 < c4;
	cout << b1 << endl << endl;
	cout << "Operatorul != : " << endl;
	if (c2 != c3) {
		cout << "Client1 si Client2 sunt diferiti." << endl;
	}
	else {
		cout << "Client1 si Client2 sunt la fel." << endl;
	}

	cout << endl << "Operatori clasa Tranzactie--------------" << endl << endl << "Operatorul cast() : " << endl;
	int op = (int)t3;
	cout << op << endl << endl;
	cout << "Operatorul ++ (prefixat): " << endl;
	t3++;
	cout << "Numarul de tranzactii: " << t3.getNumarTranzactii() << endl << endl;
	cout << "Operatorul == : " << endl;
	if (t3 == t4) {
		cout << "Tranzactia 1 si Tranzactia 2 au acelasi numar de tranzactii." << endl;
	}
	else {
		cout << "Tranzactia 1 si Tranzactia 2 au numere diferite de tranzactii." << endl;
	}

	int nrMagazine;
	cout << "Introduceti numarul magazinelor: ";
	cin >> nrMagazine;
	Magazin* vectorMagazin = new Magazin[nrMagazine];
	for (int i = 0; i < nrMagazine; i++) {
		cout << "Magazinul " << i + 1 << ":" << endl;
		cin >> vectorMagazin[i];
	}

	for (int i = 0; i < nrMagazine; i++) {
		cout << vectorMagazin[i] << endl;
	}

	delete[]vectorMagazin;

	int nrClienti;
	cout << "Introduceti numarul clientilor: ";
	cin >> nrClienti;
	Client* vectorClient = new Client[nrClienti];
	for (int i = 0; i < nrClienti; i++) {
		cout << "Clientul " << i + 1 << ":" << endl;
		cin >> vectorClient[i];
	}
	for (int i = 0; i < nrClienti; i++) {
		cout << vectorClient[i] << endl;
	}

	delete[]vectorClient;

	int nrTranzactii;
	cout << "Introduceti numarul tranzactiilor: ";
	cin >> nrTranzactii;
	Tranzactie* vectorTranzactie = new Tranzactie[nrTranzactii];
	for (int i = 0; i < nrTranzactii; i++) {
		cout << "Tranzactia " << i + 1 << ":" << endl;
		cin >> vectorTranzactie[i];
	}
	for (int i = 0; i < nrTranzactii; i++) {
		cout << vectorTranzactie[i] << endl;
	}

	delete[]vectorTranzactie;

	int numarDeLinii, numarDeColoane;
	cout << "Introduceti numarul de linii pentru matricea clasei Magazin: ";
	cin >> numarDeLinii;
	cout << "Introduceti numarul de coloane pentru matricea clasei Magazin: ";
	cin >> numarDeColoane;
	Magazin** matriceMagazin = new Magazin * [numarDeLinii];
	for (int i = 0; i < numarDeLinii; i++) {
		matriceMagazin[i] = new Magazin[numarDeColoane];
	}

	for (int i = 0; i < numarDeLinii; i++) {
		for (int j = 0; j < numarDeColoane; j++) {
			cout << "Introduceti informatiile magazinului [" << i + 1 << "][" << j + 1 << "]:\n";
			cin >> matriceMagazin[i][j];

		}
	}

	for (int i = 0; i < numarDeLinii; i++) {
		for (int j = 0; j < numarDeColoane; j++) {
			cout << "Magazinul [" << i + 1 << "][" << j + 1 << "]:\n";
			cout << matriceMagazin[i][j];
		}
	}
}
