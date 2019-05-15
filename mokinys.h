#ifndef MOKINYS_H
#define MOKINYS_H

#include "main.h"
#include "zmogus.h"

class mokinys : public zmogus {
private:
	Vector<int> pazym_;
	double egz_;
	double vid_;
	double med_;
public:
	mokinys() : zmogus{}, egz_{0} { }
	mokinys(string vardas, string pavarde) : zmogus{vardas, pavarde}, egz_{0} { }
	mokinys(std::ifstream &input, int& maxVardIlgis, int& maxPavardIlgis, bool& power);
	mokinys(mokinys&& a);
	mokinys(const mokinys& a);

	//setters
	void setEgzPopNd();
	void pushPazym(int pazym) { pazym_.push_back(pazym); }

	//getters
	double galBalasVid() { return vid_; }
	double galBalasMed() { return med_; }
	void skaiciuotiGalVid();
	void skaiciuotiGalMed();

	//v1.5
	void a() {/*yes*/}

	//overloaded operators v1.2
	bool operator==(const mokinys&);
	bool operator!=(const mokinys&);
	mokinys& operator=(mokinys&& m);
	mokinys& operator=(const mokinys& m);

	friend std::ostream& operator<<(std::ostream& out, const mokinys& m);
	friend std::istream& operator>>(std::istream& in, mokinys& m);

	void isvestiInfo(std::ofstream& out, int maxVardIlgis, int maxPavardIlgis, int vardPavKrit);
};

#endif