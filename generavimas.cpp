#include "generavimas.h"
#include "funkcijos.h"
#include "main.h"

using namespace std::chrono;

void generuoti(string pavad, int mokSk) {
	try {
		auto start = high_resolution_clock::now();
		int pazSk = 0;
		std::ofstream out("./duomenys/" + pavad);
		if (out.fail()) throw std::runtime_error("Nepavyko sukurti/atidaryti failo. Patikrinkite, ar gerai ivedete pavadinima");
		for (int i = 0; i < mokSk; ++i ) {
			pazSk = gen_reiksm(min_paz_sk, max_paz_sk);
			out << "Vardas" << gen_reiksm(min_mok_sk, max_mok_sk)
			    << " Pavarde" << gen_reiksm(min_mok_sk, max_mok_sk) << " ";
			for (int j = 0; j < pazSk; ++j) {
				out << gen_reiksm(1, 10) << " ";
			}
			out << gen_reiksm(1, 10);
			if (i != mokSk - 1) {
				out << endl;
			}
		}
		out.close();
		auto end = high_resolution_clock::now();
    	duration<double> diff = end-start;  
		cout << "\nFailas sugeneruotas per: "<< diff.count()<< "s.\n\n";
	} catch (std::exception& e) {
		cout << e.what() << endl;
	}
}

void generuotiDuomenis() {
	cout << "DUOMENU GENERAVIMAS\n";
	cout << "noredami nutraukti generavima, bet kada irasykite \"-1\"\n";
	cout << "Iveskite, kiek mokiniu norite sugeneruoti: ";
	int mokSk = int_ivestis();
	while (mokSk != -1 && mokSk < min_mok_sk && mokSk > max_mok_sk) {
		cout << "Ivesta netinkama reiksme. Galimos reiksmes: -1 arba 1-10 000 000\n:";
		mokSk = int_ivestis();
	}
	if (mokSk != -1) {
		bool pavPower = true;
		string pavad;
		while (pavPower) {
			cout << "Iveskite tinkama failo pavadinima (PVZ.: duomenys.txt arba input.in): ";
			cin >> pavad;
			if (pavad != "-1") {
				if (ar_failas_egzistuoja("./duomenys/" + pavad)) {
					//Failas jau egzistuoja
					int perPasirink;
					cout << "Failas nurodytu pavadinimu jau egzistuoja, ar norite perrasyti si faila?\n1.Taip\n2.Ne\n: ";
					perPasirink = int_ivestis();
					while (perPasirink != 1 && perPasirink != 2) {
						cout << "Ivesta negalima reiksme. Iveskite reiksme per naujo: ";
						perPasirink = int_ivestis();
					}
					if (perPasirink == 1) {
						cout << "Failas pavadinimu " << pavad << " bus perrasytas.\n";
						pavPower = false;
					} else {
						cout << "Failas pavadinimu " << pavad << " nebus perrasytas.\n";
					}
				} else {
					//Failas neegzistuoja, galima kurti nauja faila
					pavPower = false;
				}
			} else {
				pavPower = false;
			}
		}
		if (pavad != "-1")
			generuoti(pavad, mokSk);
	}
}