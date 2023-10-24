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

struct Studentas {
    string Vardas;
    string Pavarde;
    vector<int> ND;
    int Egzas;
    double GalutinisB;
    char SkaiciavimoBudas;
};


#endif // STU_H_INCLUDED
