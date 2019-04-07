#include "mokinys.h"
#include "main.h"

void mokinys::isvestiInfo(std::ofstream& out, int maxVardIlgis, int maxPavardIlgis, int vardPavKrit) {
	if (vardPavKrit == 1) {
		//Rikiavimas pagal vardą, pirmas rodomas vardas
		out << setw(maxVardIlgis + 2) << std::left << vardas_ << setw(maxPavardIlgis + 2) << pavarde_;
	} else if (vardPavKrit == 2) {
		//RIkiavimas pagal pavardę, pirma rodoma pavardė
		out << setw(maxPavardIlgis + 2)  << std::left << pavarde_ << setw(maxVardIlgis + 2) << vardas_;
	} else {
		//Nenumatyta klaida.
		out << "Nenumatyta klaida.\n";
	}

	out << std::setprecision(2) << std::fixed << setw(18) << vid_
	    << std::setprecision(2) << std::fixed << setw(18) << med_ << endl;
}

void mokinys::setEgzPopNd() {
	egz_ = pazym_.back();
	pazym_.pop_back();
}

void mokinys::skaiciuotiGalVid() {
	int sk = pazym_.size();
	if (sk == 0) throw std::logic_error("Nera namu darbu pazymiu, apskaiciuoti vidurkio negalima. Mokinys: " + vardas_ + " " + pavarde_);
	double suma = 0;
	auto it = pazym_.begin();
	while (it != pazym_.end()) {
		suma += *it;
		it++;
	}
	double vidurkis = 1.0 * suma / (double)sk;
	vid_ = (0.4 * vidurkis) + (0.6 * egz_);
}

void mokinys::skaiciuotiGalMed() {
	int sk = pazym_.size();
	if (sk == 0) throw std::logic_error("Nera namu darbu pazymiu, apskaiciuoti medianos negalima. Mokinys: " + vardas_ + " " + pavarde_);
	//Prieš skaičiavimą išrikiuojame masyvo elementus didėjimo tvarka.
	std::sort(pazym_.begin(), pazym_.end());
	double mediana;
	//Nustatome mediana
	if (sk % 2 == 1) {
		//Nelyginis skaičius pažymiu
		mediana = pazym_[sk / 2];
	}
	else {
		//Lyginis skaičius pažymiu
		mediana = 1.0 * (pazym_[sk / 2 - 1] + pazym_[sk / 2]) / 2;
	}
	med_ = (0.4 * mediana) + (0.6 * egz_);
}
