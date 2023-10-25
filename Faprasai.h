#ifndef FAPRASAI_H_INCLUDED
#define FAPRASAI_H_INCLUDED

#include "stu.h"

double GalutinisBalas(const Studentas& studentas);
void Isvedimas(const Studentas& studentas, bool isHeader);
void StudentoDuomenys(Studentas& studentas);
void read_from_file(vector<Studentas>& Eil, int* pazymiu_sk);
void IsvedimasLenteles(const vector<Studentas>& studentai);
bool CompareByVardas(const Studentas& a, const Studentas& b);
bool TikrintiFailoTurini(const string& failoPavadinimas);
void PasirinktiVeiksma(vector<Studentas>& studentai);

bool CompareByPavarde(const Studentas& a, const Studentas& b);
bool CompareByPavarde1(const Studentas& a, const Studentas& b);
bool CompareByBalas(const Studentas& a, const Studentas& b);
bool CompareByBalas1(const Studentas& a, const Studentas& b);
bool CompareByVardas1(const Studentas& a, const Studentas& b);
unsigned int countWordsInString(const string& str);

void MatuotiLaika(high_resolution_clock::time_point start, high_resolution_clock::time_point stop, const char* veiksmas);
void Generavimas(vector<Studentas>& studentai);
void GenerateStudentData(vector <Studentas>& studentai);
void Antraa(vector<Studentas>& studentai);
void NuskaitytiDuomenis(const string& FailoPav, vector<Studentas>& studentai);
void NuskaitytiVisusFailus(std::vector<Studentas>& studentai);
void RikiuotiStudentus(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai);
void IsvestiDuomenisIpagrFaila(const vector<Studentas>& studentai, const string& FailoPav);
void IsvestiDuomenis(const vector<Studentas>& studentai, const string& FailoPav);
void RikiavimoMeniu(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai, int Pasirinkimas, int Tvarka);


void Laikai(list<Studentas>& studentu);
void GeneravimasListu(std::list<Studentas>& studentu);
void IsvestiDuomenisIpagrFailaListu(const std::list<Studentas>& studentu, const std::string& FailoPav);
void NuskaitytiDuomenisListo(const string& FailoPav, std::list<Studentas>& studentai);
void NuskaitytiVisusFailusListo(std::list<Studentas>& studentai);
void RikiavimoMeniuListo(std::list<Studentas>& studentu, std::list<Studentas>& vargsiuku, std::list<Studentas>& kietiaku, int Pasirinkimas, int Tvarka);
void RikiuotiStudentuss(std::list<Studentas>& studentu, std::list<Studentas>& vargsiuku, std::list<Studentas>& kietiaku);
void IsvestiDuomenisListo(const std::list<Studentas>& studentu, const std::string& FailoPava);
bool Pasirinkti();













                      #endif // FAPRASAI_H_INCLUDED
