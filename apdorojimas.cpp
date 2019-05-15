#include "apdorojimas.h"
#include "mokinys.h"
#include "funkcijos.h"
#include "main.h"

using namespace std::chrono;


//Funkcija atlieka v0.4 užduotį ir sudaro du mokinių sąrašus atskiruose failuose "./rezultatai" aplanke
void isvestiMokinius(Vector<mokinys> &varg, Vector<mokinys> &kiet, int maxVardIlgis, int maxPavardIlgis, int vardPavKrit) {
	bool pavPower = true;
	string pavad;
	while (pavPower) {
		cout << "Iveskite tinkama rezultatu failo pavadinima (failo formato vesti nereikia. Programa automatiskai sukuria .txt formato rezultatu failus): ";
		cin >> pavad;
		if (ar_failas_egzistuoja("./rezultatai/" + pavad + "_kiet.txt") ||
		        ar_failas_egzistuoja("./rezultatai/" + pavad + "_varg.txt")) {
			//Failas jau egzistuoja
			int perrPasKrit; //perrašymo pasirinkimo kriterijus. Galimos reikšmės: 1-2
			cout << "Failai nurodytu pavadinimu jau sukurti, ar norite perrasyti siuos failus?\n1.Taip\n2.Ne\n: ";
			perrPasKrit = int_ivestis();
			while (perrPasKrit != 1 && perrPasKrit != 2) {
				cout << "Ivesta negalima reiksme. Iveskite reiksme per naujo: ";
				perrPasKrit = int_ivestis();
			}
			if (perrPasKrit == 1) {
				cout << "Failai pavadinimu " << pavad + "_kiet.txt ir " + pavad + "_varg.txt bus perrasyti.\n";
				pavPower = false;
			} else {
				cout << "Failai pavadinimu " << pavad + "_kiet.txt ir " + pavad + "_varg.txt nebus perrasyti.\n";
			}
		} else {
			//Failas neegzistuoja, galima kurti nauja faila
			pavPower = false;
		}
	}

	auto start = high_resolution_clock::now();
	std::ofstream kietOut("./rezultatai/" + pavad + "_kiet.txt"),
	    vargOut("./rezultatai/" + pavad + "_varg.txt");
	if (vardPavKrit == 1) {
		kietOut << "Vardas         Pavarde               ";
		vargOut << "Vardas         Pavarde               ";
	} else if (vardPavKrit == 2) {
		kietOut << "Vardas         Pavarde               ";
		vargOut << "Vardas         Pavarde               ";
	} else {
		//Nenumatyta klaida
		cout << "Nenumatyta klaida.\n";
		return;
	}
	kietOut << "Galutinis (Vid.)  Galutinis (Med.)\n";
	vargOut << "Galutinis (Vid.)  Galutinis (Med.)\n";

	for (auto i = 0; i < varg.size(); i++) {
		vargOut << varg[i];
	}

	for (auto i = 0; i < kiet.size(); i++) {
		kietOut << kiet[i];
	}

	kietOut.close();
	vargOut.close();
	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "\nRezultatai isvesti per: " << diff.count() << "s.\n\n";
}

//Duomenų skaitymo iš failo funkcija
void skaitytiMokinius(Vector<mokinys> &mokiniai, int &maxVardIlgis, int &maxPavardIlgis) {
	string pavadinimas;
	cout << "Iveskite failo pavadinima (PVZ failas.txt): ";
	cin >> pavadinimas;
	try {
		auto start = high_resolution_clock::now();
		if (!ar_failas_egzistuoja("./duomenys/" + pavadinimas)) throw std::runtime_error("Nurodytas failas neegzistuoja!");
		std::ifstream input("./duomenys/" + pavadinimas);
		if (input.fail()) throw std::runtime_error("Nurodytas failas neatsidare!");

		bool power = true;
		while (!input.eof()) {
			mokinys esamas;
			input >> esamas;
			esamas.skaiciuotiGalVid();
			esamas.skaiciuotiGalMed();
			mokiniai.push_back(esamas);
		}
		mokiniai.shrink_to_fit();

		input.close();
		auto end = high_resolution_clock::now();
		duration<double> diff = end - start;
		cout << "\nFailas nuskaitytas per: " << diff.count() << "s.\n\n";
	} catch (std::exception& e) {
		cout << "Ivyko klaida. " << e.what() << endl;
		throw; //Erroras permetamas į funkciją kvietėją. Šiuo atvėju "skaiciuotiRezultatus()" funkciją.
		//Ten bus sugautas tas pats erroras ir nebus vykdoma sekanti dalis kodo, einanti po įvykusios klaidos.
	}
}

bool arIslaikeVid(mokinys &a) {
	if (a.galBalasVid() < 5.0 && !arDoubleLygus(a.galBalasVid(), 5.0)) {
		return false;
	} return true;
}

bool arIslaikMed(mokinys &a) {
	if (a.galBalasMed() < 5.0 && !arDoubleLygus(a.galBalasMed(), 5.0)) {
		return false;
	} return true;
}

Vector<mokinys> atskirtiKiet(Vector<mokinys> &mokiniai, int kriterijus) {
	auto start = high_resolution_clock::now();

	////////////////////////////cia gali neveikt
	Vector<mokinys> kiet;
	int iter = 0;
	if (kriterijus == 1 ) {
		quickSortVid(mokiniai, 0, mokiniai.size() - 1);

		for (auto i = 0; i < mokiniai.size(); ++i) {
			if (arDoubleLygus(mokiniai[i].galBalasVid(), 5.0) || mokiniai[i].galBalasVid() > 5.0) {
				iter = i;
				break;
			}
		}
	} else if (kriterijus == 2) {
		quickSortMed(mokiniai, 0, mokiniai.size() - 1);
		for (auto i = 0; i < mokiniai.size(); ++i) {
			if (arDoubleLygus(mokiniai[i].galBalasMed(), 5.0) || mokiniai[i].galBalasMed() > 5.0) {
				iter = i;
				break;
			}
		}
	}
	for (auto i = iter; i < mokiniai.size(); ++i) {
		kiet.push_back(mokiniai[i]);
	}
	mokiniai.resize(iter);
	mokiniai.shrink_to_fit();
	////////////////////////////

	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "\nVargsai atskirti nuo kietu per: " << diff.count() << "s.\n\n";
	return kiet;
}

//Pagalbinė funkcija, nustatanti mokinio pirmenybę sąraše tarp dviejų mokinių pagal Vardą
bool rikVard(mokinys& i, mokinys& j) {
	if (i.vardas() < j.vardas()) {
		return true;
	}
	else if (i.vardas() == j.vardas()) {
		if (i.pavarde() < j.pavarde())
			return true;
		else
			return false;
	} else {
		return false;
	}
}
//Pagalbinė funkcija, nustatanti mokinio pirmenybę sąraše tarp dviejų mokinių pagal pavardę
bool rikPavard(mokinys& i, mokinys& j) {
	if (i.pavarde() < j.pavarde()) {
		return true;
	}
	else if (i.pavarde() == j.pavarde()) {
		if (i.vardas() < j.vardas())
			return true;
		else
			return false;
	} else {
		return false;
	}
}
//Mokinių rikiavimo funkcija
void rikiuotiMokinius(Vector<mokinys> &mokiniai, int pasirinkimas) {
	if (pasirinkimas == 1) {
		//Rikiavimas pagal vardą
		std::sort(mokiniai.begin(), mokiniai.end(), rikVard);
	}
	else if (pasirinkimas == 2) {
		//Rikiavimas pagal pavardę
		std::sort(mokiniai.begin(), mokiniai.end(), rikPavard);
	}
	else {
		//Klaida
		cout << "Ivyko nenumatyta klaida...";
	}
}

//Pagrindinė apdorojimo funkcija
void skaiciuotiRezultatus() {
	try {
		Vector<mokinys> mokiniai;
		int maxVardIlgis = 6, maxPavardIlgis = 7; //"vardas" - 6 simboliai//"pavarde" - 7 simboliai

		cout << "REZULTATU SKAICIAVIMAS\n";

		skaitytiMokinius(mokiniai, maxVardIlgis, maxPavardIlgis);

		cout << "Pagal ka norite rikiuoti mokinius?\n1. Varda\n2. Pavarde\n";
		int vardPavKrit = int_ivestis();//Vardo/Pavardės kriterijus. Galimi variantai : 1-2
		while (vardPavKrit != 1 && vardPavKrit != 2) {
			cout << "\nNetinkamas pasirinkimas. Galimi pasirinkimai:\n1. Varda\n2. Pavarde\nJusu pasirinkimas: ";
			vardPavKrit = int_ivestis();
		}

		cout << "Pagal kokius rezultatus norite rusiuoti mokinius?\n1. Vidurki\n2. Mediana\n: ";
		int rezKrit = int_ivestis();
		while (rezKrit != 1 && rezKrit != 2) {
			cout << "Negalima reiksme. Iveskite reiksme is naujo: ";
			rezKrit = int_ivestis();
		}

		////////////////////////cia gali but blogai
		Vector<mokinys> kiet = atskirtiKiet(mokiniai, rezKrit);
		auto start = high_resolution_clock::now();
		rikiuotiMokinius(kiet, vardPavKrit);
		rikiuotiMokinius(mokiniai, vardPavKrit);
		auto end = high_resolution_clock::now();
		duration<double> diff = end - start;
		cout << "\nKonteineris surikiuotas per: " << diff.count() << "s.\n\n";
		isvestiMokinius(mokiniai, kiet, maxVardIlgis, maxPavardIlgis, vardPavKrit);
		//////////////////////////

	} catch (std::exception& e) {
		//Kodėl šitas catch blokas tuščias, galbūt paaiškės paskaičius komentarus "skaitytiMokinius" funkcijoje
	}
}
