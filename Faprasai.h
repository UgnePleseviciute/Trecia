#ifndef FAPRASAI_H_INCLUDED
#define FAPRASAI_H_INCLUDED

double GalutinisBalas(const Studentas& studentas);
void Isvedimas(const Studentas& studentas, bool isHeader);
void StudentoDuomenys(Studentas& studentas);
void read_from_file(vector<Studentas>& Eil, int* pazymiu_sk);
void IsvedimasLenteles(const vector<Studentas>& studentai);
bool CompareByVardas(const Studentas& a, const Studentas& b);
bool TikrintiFailoTurini(const string& failoPavadinimas);
void PasirinktiVeiksma(vector<Studentas>& studentai);

void Antrai (vector<Studentas>& studentai);
void AntrosIsvedimasIAtskirusFailus(const vector<Studentas>& studentai, char SkaiciavimoBudas, int nd_skaicius, int tableWidth, const string& failoPavadinimas);
bool CompareByPavarde(const Studentas& a, const Studentas& b);
bool CompareByPavarde1(const Studentas& a, const Studentas& b);
bool CompareByBalas(const Studentas& a, const Studentas& b);
bool CompareByBalas1(const Studentas& a, const Studentas& b);
bool CompareByVardas1(const Studentas& a, const Studentas& b);
void Rusiavimaass(vector<Studentas>& studentai, vector<Studentas>& biskiBumBum, vector<Studentas>& biskiProtingi, char Rikiavimas, char Mazeja);
void IsvestiDuomenisIpagrFaila(const vector<Studentas>& studentai, char SkaiciavimoBudas, int nd_skaicius, int tableWidth, const string& FailoPav);


#endif // FAPRASAI_H_INCLUDED
