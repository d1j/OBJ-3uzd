#include "mokinys.h"
#include "main.h"

mokinys::mokinys(std::ifstream &input, int& maxVardIlgis, int& maxPavardIlgis, bool& power) {
	if (!input.eof()) {
		int paz;
		input >> vardas_ >> pavarde_;
		if (vardas_ != "" || pavarde_ != "") {
			if (vardas_.size() > maxVardIlgis) maxVardIlgis = vardas_.size();
			if (pavarde_.size() > maxPavardIlgis) maxPavardIlgis = pavarde_.size();
			while (input.peek() != '\n' && !input.eof()) {
				input >> paz;
				if (input.fail()) {
					throw std::runtime_error("Nepavyko nuskaityti duomenu, patikrinkite, ar gerai ivedete duomenis.");
				}
				if (paz < 1  || paz > 10) {
					throw std::runtime_error("Nepavyko nuskaityti duomenu, patikrinkite, ar gerai ivedete duomenis.");
				}
				pazym_.push_back(paz);
			}
			if (pazym_.size() < 2) {
				throw std::logic_error("Mokinys turi tik viena pazymi, negalima nustatyti ar tai namu darbo pazymys ar egzamino pazymys.");
			}
			setEgzPopNd();
			skaiciuotiGalVid();
			skaiciuotiGalMed();
		}
	} else {
		power = false;
	}
}

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
	try {
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
	} catch (std::exception& e) {
		cout << "Nepavyko apskaiciuoti mokinio vidurkio: " << e.what() << endl;
		throw;
	}
}

void mokinys::skaiciuotiGalMed() {
	try {
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
	} catch (std::exception& e) {
		cout << "Nepavyko apskaiciuoti mokinio vidurkio: " << e.what() << endl;
		throw;
	}
}

//v1.2
bool mokinys::operator==(const mokinys& a) {
	return vardas_ == a.vardas_ && pavarde_ == a.pavarde_;
}

//v1.2
bool mokinys::operator!=(const mokinys& a) {
	return !(vardas_ == a.vardas_ && pavarde_ == a.pavarde_);
}

//v1.2
std::ostream& operator<<(std::ostream& out, const mokinys& m) {
	out << m.vardas_ << "  " << m.pavarde_ << "  " << m.vid_ << "  " << m.med_ << endl;
	return out;
}

std::istream& operator>>(std::istream& in, mokinys& m) {
	if (!in.eof()) {
		int paz;
		char *vard, *pav;
		in >> vard >> pav;
		m.vardas_ = vard;
		m.pavarde_ = pav;
		if (m.vardas_ != "" || m.pavarde_ != "") {
			while (in.peek() != '\n' && !in.eof()) {
				in >> paz;
				if (in.fail()) {
					throw std::runtime_error("Nepavyko nuskaityti duomenu, patikrinkite, ar gerai ivedete duomenis.");
				}
				if (paz < 1  || paz > 10) {
					throw std::runtime_error("Nepavyko nuskaityti duomenu, patikrinkite, ar gerai ivedete duomenis.");
				}
				m.pazym_.push_back(paz);
			}
			if (m.pazym_.size() < 2) {
				throw std::logic_error("Mokinys turi tik viena pazymi, negalima nustatyti ar tai namu darbo pazymys ar egzamino pazymys.");
			}
			m.setEgzPopNd();
		}
	} 
	return in;
}
