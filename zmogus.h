//v1.5
#ifndef ZMOGUS_H
#define ZMOGUS_H

#include "main.h"

class zmogus {
protected:
	string vardas_;
	string pavarde_;

public:
	zmogus() : vardas_{""}, pavarde_{""} {};
	zmogus(string vardas, string pavarde) : vardas_{vardas}, pavarde_(pavarde) {};

	virtual void a() = 0;

	void setVardas(string vardas) { vardas_ = vardas; }
	void setPavarde(string pavarde) { pavarde_ = pavarde; }

	string vardas() const { return vardas_; }
	string pavarde() const { return pavarde_; }
};

#endif