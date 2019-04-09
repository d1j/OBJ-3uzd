#ifndef MOKINYS_H
#define MOKINYS_H

#include "main.h"

class mokinys {
private:
	string vardas_;
	string pavarde_;
	vector<int> pazym_;
	double egz_;
	double vid_;
	double med_;
public:
	mokinys() : vardas_(""), pavarde_(""), egz_(0) { }
	mokinys(string vardas, string pavarde) : vardas_(vardas), pavarde_(pavarde), egz_(0) { }
	mokinys(std::ifstream &input, int& maxVardIlgis, int& maxPavardIlgis, bool& power);

	//setters
	void setVardas(string vardas) { vardas_ = vardas; }
	void setPavarde(string pavarde) { pavarde_ = pavarde; }
	void setEgzPopNd();
	void pushPazym(int pazym) { pazym_.push_back(pazym); }

	//getters
	string vardas() const { return vardas_; }
	string pavarde() const { return pavarde_; }
	double galBalasVid() { return vid_; }
	double galBalasMed() { return med_; }
	void skaiciuotiGalVid();
	void skaiciuotiGalMed();

	void isvestiInfo(std::ofstream& out, int maxVardIlgis, int maxPavardIlgis, int vardPavKrit);
};

#endif