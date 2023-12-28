#include "stu.h"
#include "funkcijuAprasai.h"


void  Studentas::read_from_file(std::vector<Studentas>& studentai, string failopav) {
    ifstream failas(failopav);
    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo" << endl;
        return;
    }

    string eil;
    getline(failas, eil);

    stringstream x(eil);

    string el;

  int num = 5;


    while (getline(failas, eil)) {
    Studentas temp;
    stringstream stud(eil);
    stud >> temp.Vardas >> temp.Pavarde;

   // cout << "Vardas: " << temp.Vardas << " Pavarde: " << temp.Pavarde << " Pazymiai: ";

    for (int i = 1; i <= num; i++) {
        int pazymys;
        if (stud >> pazymys) {
            temp.getND().push_back(pazymys);
     //       cout << pazymys << " ";
        }
    }

    //cout << " Egzaminas: ";
    stud >> temp.Egzas;
    //cout << temp.Egzas << endl;

    double galutinisBalas = 0.4 * vidurkis(temp.getND())+ 0.6 * temp.getEgzas();
    temp.setGalutinisB(galutinisBalas);;
    studentai.push_back(temp);
}
}
