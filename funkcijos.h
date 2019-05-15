#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "main.h"
#include "mokinys.h"

int int_ivestis();

int gen_reiksm(int intPrad, int intPab);

bool ar_failas_egzistuoja(string pav);

bool arDoubleLygus(double dFirstVal, double dSecondVal);

void quickSortMed(Vector<mokinys> &mas, int kaire, int desine);

void quickSortVid(Vector<mokinys> &mas, int kaire, int desine);

#endif