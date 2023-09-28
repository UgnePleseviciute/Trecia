#include "Stu.h"

void StudentoDuomenys(Studentas& studentas) {
    cout << "Iveskite studento varda: ";
    cin >> studentas.Vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> studentas.Pavarde;

    string Random;
    cout << "Generuoti atsitiktinius pazymius (Taip/Ne)? ";
    cin >> Random;

    if (Random == "taip") {

        srand(static_cast<unsigned>(time(0)));

        const int NDkiekis = rand() % 10 + 1;

        studentas.ND.clear();

        cout << "Atsitiktinai sugeneruoti ND pazymiai: ";
        for (int i = 0; i < NDkiekis; ++i) {
            int RandomPaz = rand() % 11;
            studentas.ND.push_back(RandomPaz);
            cout << RandomPaz << " ";
        }

        studentas.Egzas = rand() % 11;
        cout << "\nAtsitiktinai sugeneruotas egzamino rezultatas: " << studentas.Egzas << "\n";
    } else {
    int NDrez;
    double totalHomework = 0.0;

    studentas.ND.clear();

cout << "Iveskite ND rezultatus (ivedus -1 baigsis ivedimas): ";
while (true) {
    cin >> NDrez;

    // Tikrinu ar tikrai tik skaicius ivede
    if (cin.fail()) {
        cin.clear(); // klaida salina
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // padaro kad is naujo vesti skaicius
        cout << "Ivesti netinkami duomenys (raide). Prasome ivesti tik skaicius." << endl;
        continue; // isnaujo vedame
    }

    if (NDrez == -1) {
        char baigimoPasirinkimas;
        cout << "Ar tikrai norite baigti ivedima? (T - Taip, N - Ne): ";
        cin >> baigimoPasirinkimas;
        if (baigimoPasirinkimas == 'T' || baigimoPasirinkimas == 't') {
            break; // Baigti ivedima jei ivesta -1 ir patvirtinta
        }
    }

    studentas.ND.push_back(NDrez);
    totalHomework += NDrez;
}

cout << "Iveskite egzamino rezultata: ";
cin >> studentas.Egzas;

    }
}

double GalutinisBalas(const Studentas& studentas) {

    if (studentas.ND.empty()) {
        return 0.6 * studentas.Egzas;
    }

    if (studentas.SkaiciavimoBudas == 'M' || studentas.SkaiciavimoBudas == 'm') {
        vector<int> sortedND = studentas.ND;
        sort(sortedND.begin(), sortedND.end());

        int totalHomework = 0;
        for (int nd : sortedND) {
            totalHomework += nd;
        }

        int n = sortedND.size();
        if (n % 2 == 0) {
            int middle1 = sortedND[n / 2 - 1];
            int middle2 = sortedND[n / 2];
            return 0.4 * (static_cast<double>(middle1 + middle2) / 2.0) + 0.6 * studentas.Egzas;
        } else {
            int middle = sortedND[n / 2];
            return 0.4 * static_cast<double>(middle) + 0.6 * studentas.Egzas;
        }
    } else {
        int totalHomework = 0;
        for (int nd : studentas.ND) {
            totalHomework += nd;
        }

        double GalutinisVidurkis = 0.4 * static_cast<double>(totalHomework) / studentas.ND.size() + 0.6 * studentas.Egzas;
        return GalutinisVidurkis;
    }
}



void Isvedimas(const Studentas& studentas, bool isHeader) {
    if (isHeader) {
        int tableWidth = 72;
        cout << string(tableWidth, '-') << endl;
        cout << "| " << left << setw(20) << "Vardas" << " | " << setw(20) << "Pavarde" << " | ";
        if (studentas.SkaiciavimoBudas == 'V' || studentas.SkaiciavimoBudas == 'v') {
            cout << setw(20) << "Galutinis (Vid)" << " |" << endl;
        } else {
            cout << setw(20) << "Galutinis (Med)" << " |" << endl;
        }
        cout << string(tableWidth, '-') << endl;
    }

    cout << "| " << left << setw(20) << studentas.Vardas << " | " << setw(20)
        << studentas.Pavarde << " | ";

    if (studentas.SkaiciavimoBudas == 'V' || studentas.SkaiciavimoBudas == 'v') {
        cout << setw(20) << fixed << setprecision(2) << GalutinisBalas(studentas) << " |" << endl;
    } else {
        cout << setw(20) << fixed << setprecision(2) << GalutinisBalas(studentas) << " |" << endl;
    }
}
