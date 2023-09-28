#include "studentas.h"


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

double GalutinisBalas(const Studentas& studentas) {
    int totalHomework = 0;
    for (int nd : studentas.ND) {
        totalHomework += nd;
    }

    double GalutinisVidurkis = 0.4 * static_cast<double>(totalHomework) / studentas.ND.size() + 0.6 * studentas.Egzas;
    return GalutinisVidurkis;
}

void Isvedimas(const Studentas& studentas, bool isHeader) {
    if (isHeader) {
        int tableWidth = 72;
        cout << string(tableWidth, '-') << endl;
        cout << "| " << left << setw(20) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << setw(20) << "Galutinis (Vid)" << " |" << endl;
        cout << string(tableWidth, '-') << endl;
    }

    cout << "| " << left << setw(20) << studentas.Vardas << " | " << setw(20) << studentas.Pavarde << " | " << setw(20) << fixed << setprecision(2) << studentas.GalutinisB << " |" << endl;
}
