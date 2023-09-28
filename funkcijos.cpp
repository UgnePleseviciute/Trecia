#include "studentas.h"
#include <iostream>
#include <iomanip>
void StudentoDuomenys(Studentas& studentas) {
    cout << "Iveskite studento varda: ";
    cin >> studentas.Vardas;
    cout << "Iveskite studento pavarde: ";
    cin >> studentas.Pavarde;
    int NDrez;
    cout << "Iveskite ND rezultatus (veskite -1, kad baigti): ";
    while (true) {
        cin >> NDrez;
        if (NDrez == -1) {
            break;
        }
        studentas.ND.push_back(NDrez);
    }
    cout << "Iveskite egzamino rezultata: ";
    cin >> studentas.Egzas;
}
void PasirinktiVidurkiArMediana() {
    char pasirinkimas;
    cout << "Naudoti vidurki ar mediana (V/M): ";
    cin >> pasirinkimas;
}


double GalutinisBalas(const Studentas& studentas) {
    int totalHomework = 0;
    for (int nd : studentas.ND) {
        totalHomework += nd;
    if (studentas.ND.empty()) {
        return 0.6 * studentas.Egzas;
    }

    double GalutinisVidurkis = 0.4 * static_cast<double>(totalHomework) / studentas.ND.size() + 0.6 * studentas.Egzas;
    return GalutinisVidurkis;
    if (studentas.naudotiVidurki) {
        int totalHomework = 0;
        for (int nd : studentas.ND) {
            totalHomework += nd;
        }
        double GalutinisVidurkis = 0.4 * static_cast<double>(totalHomework) / studentas.ND.size() + 0.6 * studentas.Egzas;
        return GalutinisVidurkis;
    } else {

        vector<int> sortedND = studentas.ND;
        sort(sortedND.begin(), sortedND.end());

        int n = sortedND.size();
        if (n % 2 == 0) {

            int middle1 = sortedND[n / 2 - 1];
            int middle2 = sortedND[n / 2];
            return 0.4 * (static_cast<double>(middle1 + middle2) / 2.0) + 0.6 * studentas.Egzas;
        } else {

            int middle = sortedND[n / 2];
            return 0.4 * static_cast<double>(middle) + 0.6 * studentas.Egzas;
        }
    }
}
}
void Isvedimas(const Studentas& studentas, bool isHeader) {
    if (isHeader) {
        int tableWidth = 72;
        cout << string(tableWidth, '-') << endl;
        cout << "| " << left << setw(20) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << setw(20) << "Galutinis (Vid)" << " |" << endl;
        cout << "| " << left << setw(20) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << setw(20);
        if (studentas.naudotiVidurki) {
            cout << "Galutinis (Vid)";
        } else {
            cout << "Galutinis (Med)";
        }
        cout << " |" << endl;
        cout << string(tableWidth, '-') << endl;
    }

    cout << "| " << left << setw(20) << studentas.Vardas << " | " << setw(20) << studentas.Pavarde << " | " << setw(20) << fixed << setprecision(2) << studentas.GalutinisB << " |" << endl;
}
