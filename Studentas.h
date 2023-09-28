#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::left;
using std::right;
using std::setw;
using std::fixed;
using std::setprecision;
using std::vector;
using std::sort;




struct Studentas {
    string Vardas;
    string Pavarde;
    vector<int> ND;
    int Egzas;
    double GalutinisB;
    bool naudotiVidurki;
};


void StudentoDuomenys(Studentas& studentas);
void PasirinktiVidurkiArMediana();
double GalutinisBalas(const Studentas& studentas);
void Isvedimas(const Studentas& studentas, bool isHeader);

#endif // STUDENTAS_H_INCLUDED
