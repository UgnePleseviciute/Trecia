#ifndef FUNKCIJUAPRASAI_H_INCLUDED
#define FUNKCIJUAPRASAI_H_INCLUDED
#include "stu.h"


void Isvedimas(const Studentas& studentas, bool isHeader);
bool CompareByVardas(const Studentas& a, const Studentas& b);
bool CompareByPavarde(const Studentas& a, const Studentas& b);
bool CompareByPavarde1(const Studentas& a, const Studentas& b);
bool CompareByBalas(const Studentas& a, const Studentas& b);
bool CompareByBalas1(const Studentas& a, const Studentas& b);
bool CompareByVardas1(const Studentas& a, const Studentas& b);
unsigned int countWordsInString(const string& str);
void MatuotiLaika(high_resolution_clock::time_point start, high_resolution_clock::time_point stop, const char* veiksmas);
void Generavimas(vector<Studentas>& studentai);
void Antraa(vector<Studentas>& studentai);
void NuskaitytiVisusFailus(std::vector<Studentas>& studentai);
void IsvestiDuomenisIpagrFaila(const vector<Studentas>& studentai, const string& FailoPav);
void IsvestiDuomenis(const vector<Studentas>& studentai, const string& FailoPav);
void RikiavimoMeniu(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai, int Pasirinkimas, int Tvarka);
void Pasirinkti();
double CalculateGalutinisB(const Studentas& studentas);




#endif // FUNKCIJUAPRASAI_H_INCLUDED
