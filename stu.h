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
#include <sstream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <cstdlib>
#include <list>


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
using std::invalid_argument;
using std::istringstream;
using std::to_string;
using std::cerr;
using std::ios;
using std::streamsize;
using std::numeric_limits;
//antrai
using std::srand;
using std::random_shuffle;
using std::ofstream;
using namespace std::chrono;
using std::list;
#include <string>
#include <vector>


#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>

#include <iostream>
#include <vector>

class Studentas {
private:
    std::string Vardas;
    std::string Pavarde;
    std::vector<int> ND;
    int Egzas;
    double GalutinisB;
    char SkaiciavimoBudas;

public:
    // Default constructor with default parameter values
    Studentas() : Egzas(0), GalutinisB(0), SkaiciavimoBudas(' ') {}

    // Getter functions
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

    // Setter functions
    void setVardas(const std::string& vardas)
        { Vardas = vardas; }
    void setPavarde(const std::string& pavarde)
        { Pavarde = pavarde; }
    void setND(const std::vector<int>& nd)
        { ND = nd; }
    void setEgzas(int egzas)
        { Egzas = egzas; }
    void setGalutinisB(double galutinisB)
        { GalutinisB = galutinisB; }
    void setSkaiciavimoBudas(char skaiciavimoBudas)
        { SkaiciavimoBudas = skaiciavimoBudas; }


    double CalculateGalutinisB() const { \
        int totalHomework = 0;
        for (int nd : ND) {
            totalHomework += nd;
        }

        return 0.4 * static_cast<double>(totalHomework) / ND.size() + 0.6 * Egzas;
    }

     void addND(int value) {
        ND.push_back(value);
    }

    void inputFromStream(std::istream& is) {}
    void outputToStream(std::ostream& os, bool isHeader = false) const {}

};



#endif // STUDENTAS_H_INCLUDED
