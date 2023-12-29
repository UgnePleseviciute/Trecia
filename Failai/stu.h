// Studentas.h
#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED
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
#include <stdexcept>
#include <chrono>
#include <cstdlib>
#include <list>
#include <numeric>


#include "Zmogus.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
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
using std::invalid_argument;
using std::istringstream;
using std::to_string;
using std::cerr;
using std::ios;
using std::streamsize;
using std::numeric_limits;
using std::srand;
using std::random_shuffle;
using std::ofstream;
using namespace std::chrono;
using std::list;


class Studentas : public Zmogus{
private:

    std::vector<int> ND;
    int Egzas;
    double GalutinisB;
    char SkaiciavimoBudas;

public:
    Studentas() : Zmogus(), Egzas(0), GalutinisB(0), SkaiciavimoBudas(' ') {}

    // Getter
    std::string getVardas() const
     { return Vardas; }
    std::string getPavarde() const
     { return Pavarde; }
    std::vector<int> getND() const
     { return ND; }
    int getEgzas() const
     { return Egzas; }
    double getGalutinisB() const
    { return GalutinisB; }
    char getSkaiciavimoBudas() const
     { return SkaiciavimoBudas; }

    // Setter
    void setVardas(const std::string& newVardas);

    void setPavarde(const std::string& newPavarde);

    void setND(const std::vector<int>& newND);

    void setEgzas(int newegzas);

    void setGalutinisB(double newGalutinisB);

   void setSkaiciavimoBudas(char newSkaiciavimoBudas);


     void addND(int value) {
        ND.push_back(value);
    }

    void inputFromStream(std::istream& is) {}
    void outputToStream(std::ostream& os, bool isHeader = false) const {}

    //Kopijavimo konstruktorius
    Studentas(const Studentas& other)
        : Zmogus(other),
          ND(other.ND),
          Egzas(other.Egzas),
          GalutinisB(other.GalutinisB),
          SkaiciavimoBudas(other.SkaiciavimoBudas) {}


    Studentas& operator=(const Studentas& other) { //priskyrimo
        if (this != &other) {
            Zmogus::operator=(other);
            ND = other.ND;
            Egzas = other.Egzas;
            GalutinisB = other.GalutinisB;
            SkaiciavimoBudas = other.SkaiciavimoBudas;
        }
        return *this;
    }

    ~Studentas()  //destruktorius
    { ND.clear(); }


static double vidurkis(const vector<int>& pazymiai) {
        double paz_suma = accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
        return pazymiai.size() > 0 ? paz_suma / pazymiai.size() : 0;
    }

    void dosmth() const override
    { cout<< Vardas << " " << Pavarde << " daro " <<endl;}

    double CalculateGalutinisB() const;
    static void read_from_file(std::vector<Studentas>& studentai, string failopav);
    static void NuskaitytiDuomenis(const string& FailoPav, vector<Studentas>& studentai);
    static void RikiuotiStudentus(vector<Studentas>& studentai, vector<Studentas>& vargsiukai);
    void PasirinktiVeiksma(vector<Studentas>& studentai);
    static void StudentoDuomenys(Studentas& studentas);

    friend std::istream& operator>>(std::istream& is, Studentas& studentas);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas);
    friend double GalutinisBalas(const Studentas& studentas);

 };



#endif // STUDENTAS_H_INCLUDED
