#ifndef STU_H_INCLUDED
#define STU_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <ctime>
#include<sstream>




#include <stdlib.h>

#include <fstream>
#include <iterator>


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
using std::stringstream;
using std::istream_iterator;
using std::ifstream;
using std::ws;


struct Studentas {
    string Vardas;
    string Pavarde;
    vector<int> ND;
    int Egzas;
    double GalutinisB;
    char SkaiciavimoBudas;
};


double GalutinisBalas(const Studentas& studentas);
void Isvedimas(const Studentas& studentas, bool isHeader);
void StudentoDuomenys(Studentas& studentas);
void read_from_file(std::vector<Studentas>& Eil, int* pazymiu_sk);
void IsvedimasLenteles(const std::vector<Studentas>& studentai);
bool CompareByVardas(const Studentas& a, const Studentas& b);

#endif
