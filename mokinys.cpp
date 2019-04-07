#include "mokinys.h"
#include "main.h"

void mokinys::isvestiInfo(std::ofstream& out, int maxVardIlgis, int maxPavardIlgis, int vardPavKrit) {
	if (vardPavKrit == 1) {
		//Rikiavimas pagal vardą, pirmas rodomas vardas
		out << setw(maxVardIlgis + 2) << std::left << vardas << setw(maxPavardIlgis + 2) << pavarde;
	} else if (vardPavKrit == 2) {
		//RIkiavimas pagal pavardę, pirma rodoma pavardė
		out << setw(maxPavardIlgis + 2)  << std::left << pavarde << setw(maxVardIlgis + 2) << vardas;
	} else {
		//Nenumatyta klaida.
		out << "Nenumatyta klaida.\n";
	}

	out << std::setprecision(2) << std::fixed << setw(18) << (0.4 * vidurkis) + (0.6 * egz)
	    << std::setprecision(2) << std::fixed << setw(18) << (0.4 * mediana) + (0.6 * egz) << endl;
}

void mokinys::spausdintiInfo(int maxVardIlgis, int maxPavardIlgis, int pasirink) {
	if (pasirink == 1) {
		//Rikiavimas pagal vardą, pirmas rodomas vardas
		cout << setw(maxVardIlgis + 2) << std::left << vardas << setw(maxPavardIlgis + 2) << pavarde;
	} else if (pasirink == 2) {
		//RIkiavimas pagal pavardę, pirma rodoma pavardė
		cout << setw(maxPavardIlgis + 2)  << std::left << pavarde << setw(maxVardIlgis + 2) << vardas;
	} else {
		//Nenumatyta klaida.
		cout << "Nenumatyta klaida.\n";
	}

	cout << std::setprecision(2) << std::fixed << setw(18) << (0.4 * vidurkis) + (0.6 * egz)
	     << std::setprecision(2) << std::fixed << setw(18) << (0.4 * mediana) + (0.6 * egz) << endl;
}

void mokinys::skaiciuotiVidurki() {
	int sk = pazym.size();
	if (sk == 0) throw std::logic_error("Nera namu darbu pazymiu, apskaiciuoti vidurkio negalima. Mokinys: " + vardas + " " + pavarde);
	double suma = 0;
	auto it = pazym.begin();
	while (it != pazym.end()) {
		suma += *it;
		it++;
	}
	vidurkis = 1.0 * suma / (double)sk;

}

void mokinys::skaiciuotiMediana() {
	int sk = pazym.size();
	if (sk == 0) throw std::logic_error("Nera namu darbu pazymiu, apskaiciuoti medianos negalima. Mokinys: " + vardas + " " + pavarde);
	//Prieš skaičiavimą išrikiuojame masyvo elementus didėjimo tvarka.
	std::sort(pazym.begin(), pazym.end());
	//Nustatome mediana
	if (sk % 2 == 1) {
		//Nelyginis skaičius pažymiu
		mediana = pazym[sk / 2];
	}
	else {
		//Lyginis skaičius pažymiu
		mediana = 1.0 * (pazym[sk / 2 - 1] + pazym[sk / 2]) / 2;
	}

}