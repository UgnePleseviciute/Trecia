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
void AntrosIsvedimasIFaila (const vector<Studentas>& studentai, char SkaiciavimoBudas, int nd_skaicius, int tableWidth);


#endif // FAPRASAI_H_INCLUDED
