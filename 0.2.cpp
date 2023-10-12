#include "Stu.h"
#include "Faprasai.h"
#include <chrono>


void Antrai(vector<Studentas>& studentai) {

    char SkaiciavimoBudas, Rikiavimas, Mazeja;
    int StudKiekis, nd_skaicius;

    cout << "Pasirinkite skaiciavimo metoda (V- Vidurkis, M - Mediana): ";
    cin >> SkaiciavimoBudas;
    cout<< endl;

    cout << "Pasirinkite kaip noresite, kad rezultatai butu pateikti: 1- Isrusiuoti pagal vardus, 2- Isrusiuoti pagal pavardes, 3 - Isrusiuoti pagal pazymius: ";
    cin >> Rikiavimas;
   // if (Rikiavimas != '1' && Rikiavimas != '2' && Rikiavimas != '3') {
   // cerr << "Blogas pasirinkimas. Prasau ivesti 1, 2 arba 3." << endl;



    cout << "Didejimo ar mazejimo tvarka: 1- Didejimo, 2- Mazejimo: ";
    cin >> Mazeja;
    //if (Mazeja != 1 && Mazeja != 2 ) {
   // cerr << "Blogas pasirinkimas. Prasau ivesti 1 arba 2" << endl;}

    cout << "Iveskite studentu kieki: ";
    cin >> StudKiekis;

    cout << "Iveskite ND pazymiu skaiciu: ";
    cin >> nd_skaicius;

    vector<Studentas> BiskiBumBum; // Studentai < 5
    vector<Studentas> BiskiProtingi; // Studentai >= 5

    auto start = high_resolution_clock::now();  // pradeda matuoti kiek truks duomenu generavimas ir palyginimas

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

    int tableWidth = 100;

    Rusiavimaass(studentai, BiskiBumBum, BiskiProtingi, Rikiavimas, Mazeja);

    string FailoPav = "rezultatai_" + to_string(StudKiekis) + ".txt";

    IsvestiDuomenisIpagrFaila(studentai, SkaiciavimoBudas, nd_skaicius, tableWidth, FailoPav);

    start = high_resolution_clock::now();

    AntrosIsvedimasIAtskirusFailus(BiskiBumBum, SkaiciavimoBudas, nd_skaicius, tableWidth, "BiskiBumBum_" + to_string(BiskiBumBum.size()) +"_" + to_string(StudKiekis) + ".txt");
    AntrosIsvedimasIAtskirusFailus(BiskiProtingi, SkaiciavimoBudas ,nd_skaicius, tableWidth, "BiskiProtingi_" + to_string(BiskiProtingi.size()) + "_" + to_string(StudKiekis) + ".txt");


    stop = high_resolution_clock::now(); // baigia matuoti failu isvedima
    duration = duration_cast<seconds>(stop - start);
    cout << "duomenu iskirtymas uztruko: " << duration.count() << " s" <<  endl;
    cout << endl;

    PasirinktiVeiksma(studentai);
}
void IsvestiDuomenisIpagrFaila(const vector<Studentas>& studentai, char SkaiciavimoBudas, int nd_skaicius, int tableWidth, const string& FailoPav) {

    auto start = high_resolution_clock::now(); // Pradeda matuoti duomenų išvedimą
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
        cout << "Duomenys isvestii i faila " << FailoPav << endl;
    } else {
        cout << "Nepavyko atidaryti failo " << FailoPav << endl;
    }

    auto stop = high_resolution_clock::now(); // Baigia matuoti failų išvedimą
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Duomenu isvedimas uztruko: " << duration.count() << " s" << endl;
    cout << endl;
}

void AntrosIsvedimasIAtskirusFailus(const vector<Studentas>& studentai, char SkaiciavimoBudas, int nd_skaicius, int tableWidth, const string& failoPavadinimas){

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

void Rusiavimaass(vector<Studentas>& studentai, vector<Studentas>& BiskiBumBum, vector<Studentas>& BiskiProtingi, char Rikiavimas, char Mazeja) {
    if (Rikiavimas == '1' && Mazeja == '1') {
        sort(studentai.begin(), studentai.end(), CompareByVardas);
        sort(BiskiBumBum.begin(), BiskiBumBum.end(), CompareByVardas);
        sort(BiskiProtingi.begin(), BiskiProtingi.end(), CompareByVardas);
    }
    else if (Rikiavimas == '1' && Mazeja == '2') {
        sort(studentai.begin(), studentai.end(), CompareByVardas1);
        sort(BiskiBumBum.begin(), BiskiBumBum.end(), CompareByVardas1);
        sort(BiskiProtingi.begin(), BiskiProtingi.end(), CompareByVardas1);
    }
    else if (Rikiavimas == '2' && Mazeja == '1') {
        sort(studentai.begin(), studentai.end(), CompareByPavarde);
        sort(BiskiBumBum.begin(), BiskiBumBum.end(), CompareByPavarde);
        sort(BiskiProtingi.begin(), BiskiProtingi.end(), CompareByPavarde);
    }
    else if (Rikiavimas == '2' && Mazeja == '2') {
        sort(studentai.begin(), studentai.end(), CompareByPavarde1);
        sort(BiskiBumBum.begin(), BiskiBumBum.end(), CompareByPavarde1);
        sort(BiskiProtingi.begin(), BiskiProtingi.end(), CompareByPavarde1);
    }
    else if (Rikiavimas == '3' && Mazeja == '1') {
        sort(studentai.begin(), studentai.end(), CompareByBalas);
        sort(BiskiBumBum.begin(), BiskiBumBum.end(), CompareByBalas);
        sort(BiskiProtingi.begin(), BiskiProtingi.end(), CompareByBalas);
    }
    else if (Rikiavimas == '3' && Mazeja == '2') {
        sort(studentai.begin(), studentai.end(), CompareByBalas1);
        sort(BiskiBumBum.begin(), BiskiBumBum.end(), CompareByBalas1);
        sort(BiskiProtingi.begin(), BiskiProtingi.end(), CompareByBalas1);
    }
}




