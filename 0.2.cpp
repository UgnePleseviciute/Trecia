#include "Stu.h"
#include "Faprasai.h"
#include <chrono>

void Antrai(vector<Studentas>& studentai) {
    char SkaiciavimoBudas;
    cout << "Pasirinkite skaiciavimo metoda (V- Vidurkis, M - Mediana): ";
    cin >> SkaiciavimoBudas;
    cout<< endl;

    int StudKiekis;
    cout << "Iveskite studentu kieki: ";
    cin >> StudKiekis;

    int nd_skaicius;
    cout << "Iveskite ND pazymiu skaiciu: ";
    cin >> nd_skaicius;

    vector<Studentas> BiskiBumBum; // Studentai < 5
    vector<Studentas> BiskiProtingi; // Studentai >= 5

    auto start = high_resolution_clock::now();  // pradeda matuoti kiek truks duomenu generavimas

    for (int i = 1; i <= StudKiekis; ++i) {
        Studentas studentas;
        studentas.Vardas = "Vardas" + to_string(i);
        studentas.Pavarde = "Pavarde" + to_string(i);

        for (int j = 1; j <= nd_skaicius; ++j) {
            int nd_pazymys = rand() % 10 + 1;
            studentas.ND.push_back(nd_pazymys);
        }
        studentas.Egzas = rand() % 11;
        studentas.GalutinisB = GalutinisBalas(studentas);

        studentai.push_back(studentas);

        if (studentas.GalutinisB < 5.0) {    // Palygina galutni bala
            BiskiBumBum.push_back(studentas);
        } else {
            BiskiProtingi.push_back(studentas);
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Duomenu generavimas uztruko: " << duration.count() << " s" << endl;  // baigia matuoti duomenu generavima
    cout << endl;

    int tableWidth = 95;
    /*cout << string(tableWidth, '-') << endl;
    cout << "| " << left << setw(20) << "Vardas" << " | " << setw(20) << "Pavarde" << " | ";

    for (int i = 1; i <= nd_skaicius; ++i) {
        cout << "ND" << i << " | ";
    }
    cout << "Egzaminas | ";

    if (SkaiciavimoBudas == 'V' || SkaiciavimoBudas == 'v') {
        cout << setw(20) << "Galutinis (Vid)" << " |" << endl;
    } else {
        cout << setw(20) << "Galutinis (Med)" << " |" << endl;
    }
    //cout << string(tableWidth, '-') << endl;*/

    string FailoPav = "rezultatai_" + to_string(StudKiekis) + ".txt";

    start = high_resolution_clock::now(); // pradeda matuoti duomenu isvedima

    ofstream outFile(FailoPav);

    if (outFile.is_open()) {
        outFile << string(tableWidth, '-') << endl;
        outFile << "| " << left << setw(20) << "Vardas" << " | " << setw(20) << "Pavarde" << " | ";

        for (int i = 1; i <= nd_skaicius; ++i) {
            outFile << "ND" << i << " | ";
        }
        outFile << "Egzaminas | ";

        if (SkaiciavimoBudas == 'V' || SkaiciavimoBudas == 'v') {
            outFile << setw(20) << "Galutinis (Vid)" << " |" << endl;
        } else {
            outFile << setw(20) << "Galutinis (Med)" << " |" << endl;
        }
        outFile << string(tableWidth, '-') << endl;

        for (const Studentas& studentas : studentai) {
            outFile << "| " << left << setw(20) << studentas.Vardas << " | " << setw(20)
                << studentas.Pavarde << " | ";

            for (int nd : studentas.ND) {
                outFile << setw(4) << nd << " | ";
            }
            outFile << setw(8) << studentas.Egzas << " | ";

            if (SkaiciavimoBudas == 'V' || SkaiciavimoBudas == 'v') {
                outFile << setw(20) << fixed << setprecision(2) << studentas.GalutinisB << " |" << endl;
            } else {
                outFile << setw(20) << fixed << setprecision(2) << studentas.GalutinisB << " |" << endl;
            }
        }
        outFile.close();
        cout << "Duomenys isvesti i faila " << FailoPav << endl;
    } else {
        cout << "Nepavyko atidaryti failo " << FailoPav << endl;
    }
    stop = high_resolution_clock::now(); // baigia matuoti failu isvedima
    duration = duration_cast<seconds>(stop - start);
    cout << "Duomenu isvedimas uztruko: " << duration.count() << " s" << endl;
    cout << endl;

    start = high_resolution_clock::now();

    AntrosIsvedimasIAtskirusFailus(BiskiBumBum, SkaiciavimoBudas, nd_skaicius, tableWidth, "BiskiBumBum.txt");
    AntrosIsvedimasIAtskirusFailus(BiskiProtingi, SkaiciavimoBudas, nd_skaicius, tableWidth, "BiskiProtingi.txt");

    stop = high_resolution_clock::now(); // baigia matuoti failu isvedima
    duration = duration_cast<seconds>(stop - start);
    cout << "duomenu iskirtymas uztruko: " << duration.count() << " s" <<  endl;
    cout << endl;

    PasirinktiVeiksma(studentai);
}

void AntrosIsvedimasIAtskirusFailus(const vector<Studentas>& studentai, char SkaiciavimoBudas, int nd_skaicius, int tableWidth, const string& failoPavadinimas) {
    auto start = high_resolution_clock::now(); // pradeda matuoti kiek uztrunka sukurti atskirus failus

    ofstream outFile(failoPavadinimas);

    if (outFile.is_open()) {
        outFile << string(tableWidth, '-') << endl;
        outFile << "| " << left << setw(20) << "Vardas" << " | " << setw(20) << "Pavarde" << " | ";

        if (SkaiciavimoBudas == 'V' || SkaiciavimoBudas == 'v') {
            outFile << setw(20) << "Galutinis (Vid)" << " |" << endl;
        } else {
            outFile << setw(20) << "Galutinis (Med)" << " |" << endl;
        }
        outFile << string(tableWidth, '-') << endl;

        for (const Studentas& studentas : studentai) {
            outFile << "| " << left << setw(20) << studentas.Vardas << " | " << setw(20)
                << studentas.Pavarde << " | ";

            if (SkaiciavimoBudas == 'V' || SkaiciavimoBudas == 'v') {
                outFile << setw(20) << fixed << setprecision(2) << studentas.GalutinisB << " |" << endl;
            } else {
                outFile << setw(20) << fixed << setprecision(2) << studentas.GalutinisB << " |" << endl;
            }
        }
        outFile.close();
        cout << "Duomenys isvesti i faila " << failoPavadinimas << endl;
    } else {
        cout << "Nepavyko atidaryti failo " << failoPavadinimas << endl;
    }

    auto stop = high_resolution_clock::now(); // baigia
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Duomenu isvedimas uztruko: " << duration.count() << " s" << endl;
    cout << endl;
}
