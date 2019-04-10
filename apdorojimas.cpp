#include "apdorojimas.h"
#include "mokinys.h"
#include "funkcijos.h"
#include "main.h"

using namespace std::chrono;


//Funkcija atlieka v0.4 užduotį ir sudaro du mokinių sąrašus atskiruose failuose "./rezultatai" aplanke
void isvestiMokinius(vector<mokinys> &varg, vector<mokinys> &kiet, int maxVardIlgis, int maxPavardIlgis, int vardPavKrit) {
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
		kietOut << std::left << setw(maxVardIlgis + 2) << "Vardas" << setw(maxPavardIlgis + 2) << "Pavarde";
		vargOut << std::left << setw(maxVardIlgis + 2) << "Vardas" << setw(maxPavardIlgis + 2) << "Pavarde";
	} else if (vardPavKrit == 2) {
		kietOut << std::left << setw(maxPavardIlgis + 2) << "Pavarde" << setw(maxVardIlgis + 2) << "Vardas";
		vargOut << std::left << setw(maxPavardIlgis + 2) << "Pavarde" << setw(maxVardIlgis + 2) << "Vardas";
	} else {
		//Nenumatyta klaida
		cout << "Nenumatyta klaida.\n";
		return;
	}
	kietOut << "Galutinis (Vid.)  Galutinis (Med.)\n";
	vargOut << "Galutinis (Vid.)  Galutinis (Med.)\n";
	string linija(maxVardIlgis + maxPavardIlgis + 4, '-');
	kietOut << linija << "----------------------------------\n";
	vargOut << linija << "----------------------------------\n";
	auto it = varg.begin();
	while (it != varg.end()) {
		it->isvestiInfo(vargOut, maxVardIlgis, maxPavardIlgis, vardPavKrit);
		it++;
	}
	it = kiet.begin();
	while (it != kiet.end()) {
		it->isvestiInfo(kietOut, maxVardIlgis, maxPavardIlgis, vardPavKrit);
		it++;
	}
	kietOut.close();
	vargOut.close();
	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "\nRezultatai isvesti per: " << diff.count() << "s.\n\n";
}

//Duomenų skaitymo iš failo funkcija
void skaitytiMokinius(vector<mokinys> &mokiniai, int &maxVardIlgis, int &maxPavardIlgis) {
	string pavadinimas;
	cout << "Iveskite failo pavadinima (PVZ failas.txt): ";
	cin >> pavadinimas;
	try {
		auto start = high_resolution_clock::now();
		if (!ar_failas_egzistuoja("./duomenys/" + pavadinimas)) throw std::runtime_error("Nurodytas failas neegzistuoja!");
		std::ifstream input("./duomenys/" + pavadinimas);
		if (input.fail()) throw std::runtime_error("Nurodytas failas neatsidare!");

		bool power = true;
		while (power) {
			mokiniai.emplace_back(input, maxVardIlgis, maxPavardIlgis, power);
		}
		mokiniai.pop_back();
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

vector<mokinys> atskirtiVarg(vector<mokinys> &mokiniai, int kriterijus) {
	auto start = high_resolution_clock::now();
	vector<mokinys>::iterator it;

	if (kriterijus == 1 ) {
		it = std::stable_partition(mokiniai.begin(), mokiniai.end(), arIslaikeVid);
	} else if (kriterijus == 2) {
		it = std::stable_partition(mokiniai.begin(), mokiniai.end(), arIslaikMed);
	}

	vector<mokinys> varg(it, mokiniai.end());
	mokiniai.erase(it, mokiniai.end());
	mokiniai.shrink_to_fit();

	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "\nVargsai atskirti nuo kietu per: " << diff.count() << "s.\n\n";
	return varg;
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
void rikiuotiMokinius(vector<mokinys> &mokiniai, int pasirinkimas) {
	auto start = high_resolution_clock::now();
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

	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "\nKonteineris surikiuotas per: " << diff.count() << "s.\n\n";
}

//Pagrindinė apdorojimo funkcija
void skaiciuotiRezultatus() {
	try {
		vector<mokinys> mokiniai;
		int maxVardIlgis = 6, maxPavardIlgis = 7; //"vardas" - 6 simboliai//"pavarde" - 7 simboliai

		cout << "REZULTATU SKAICIAVIMAS\n";

		skaitytiMokinius(mokiniai, maxVardIlgis, maxPavardIlgis);

		cout << "Pagal ka norite rikiuoti mokinius?\n1. Varda\n2. Pavarde\n";
		int vardPavKrit = int_ivestis();//Vardo/Pavardės kriterijus. Galimi variantai : 1-2
		while (vardPavKrit != 1 && vardPavKrit != 2) {
			cout << "\nNetinkamas pasirinkimas. Galimi pasirinkimai:\n1. Varda\n2. Pavarde\nJusu pasirinkimas: ";
			vardPavKrit = int_ivestis();
		}
		rikiuotiMokinius(mokiniai, vardPavKrit);

		cout << "Pagal kokius rezultatus norite rusiuoti mokinius?\n1. Vidurki\n2. Mediana\n: ";
		int rezKrit = int_ivestis();
		while (rezKrit != 1 && rezKrit != 2) {
			cout << "Negalima reiksme. Iveskite reiksme is naujo: ";
			rezKrit = int_ivestis();
		}
		vector<mokinys> vargs = atskirtiVarg(mokiniai, rezKrit);
		isvestiMokinius(vargs, mokiniai, maxVardIlgis, maxPavardIlgis, vardPavKrit);
		
	} catch (std::exception& e) {
		//Kodėl šitas catch blokas tuščias, galbūt paaiškės paskaičius komentarus "skaitytiMokinius" funkcijoje
	}
}
