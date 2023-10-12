#include "Stu.h"
#include "Faprasai.h"
#include <chrono>


void Antrai(vector<Studentas>& studentai) {

    char SkaiciavimoBudas = 'v', Rikiavimas, Mazeja;
    int StudKiekis, nd_skaicius;
    int tableWidth = 100;
    int FailuKiekis;
    string FailoPav;

    vector<Studentas> BiskiBumBum; // Studentai < 5
    vector<Studentas> BiskiProtingi; // Studentai >= 5

    cout<< endl;
    cout << "pasirinkite kiek failu kursime: ";
    cin>> FailuKiekis;


    cout << "Iveskite ND pazymiu skaiciu: ";
    cin >> nd_skaicius;
    cout << "--------------------------------------------------" << endl;

    for ( int i =1 ; i <= FailuKiekis ; i++)
    {
        failoGeneravimas(studentai, StudKiekis, nd_skaicius, SkaiciavimoBudas, tableWidth);
        cout << "laiko matavimai nuskaitant is failo: " <<endl;
        cout << endl;
        readIsfailo3(studentai);
        studentai.clear(); // isvalo studentu vektoriu pries generuojant kita nes kitaip pizdec biski
        cout<< "-------------------------------------------------- " << endl;
    }


}
void failoGeneravimas(vector<Studentas>& studentai, int StudKiekis, int nd_skaicius, char SkaiciavimoBudas, int tableWidth) {

    cout << "Iveskite studentu kieki: ";
    cin >> StudKiekis;

    auto start = high_resolution_clock::now();

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

    }

    string FailoPav = to_string(StudKiekis) + ".txt";

    auto stop = high_resolution_clock::now();
    MatuotiLaika(start, stop, "Duomenu generavimas");
    IsvestiDuomenisIpagrFaila(studentai, SkaiciavimoBudas, nd_skaicius, tableWidth, FailoPav);
}

void readIsfailo3(vector<Studentas>& studentai) {

    auto start = high_resolution_clock::now();

    char SkaiciavimoBudas;
    int nd_skaicius;
    int tableWidth, StudKiekis;
    string failoPavadinimas;
    cout << "Iveskite failo pavadinima: ";
    cin >> failoPavadinimas;

    ifstream inFile(failoPavadinimas);

    if (inFile.is_open()) {
        string line;
        bool praleisti = true; // Pradeti praleisti eilutes

        while (getline(inFile, line)) {
            if (praleisti) {
                praleisti = false; // daugiau nepraleidzia eiluciu
                continue; // Praleisti sia eilute ir eiti toliau
            }
            istringstream iss(line);
            Studentas studentas;
            iss >> studentas.Vardas >> studentas.Pavarde >> studentas.GalutinisB;
            studentai.push_back(studentas);
            //cout << line << endl;
        }

        inFile.close();
    } else {
        cout << "Nepavyko atidaryti failo." << endl;
    }
    auto stop = high_resolution_clock::now();
    MatuotiLaika(start, stop, "Duomenu nuskaitymas");
    cout << endl;
    // iskvieciu iskirstymas funkcija kad isskirtu i du vektorius ir joje iskviestu funkcija kur bus isskaidyti i failus
    Iskirstymas(studentai, failoPavadinimas, SkaiciavimoBudas, nd_skaicius, tableWidth, StudKiekis);
}
void Iskirstymas (vector<Studentas>& studentai, string failoPavadinimas, int SkaiciavimoBudas, int nd_skaicius, int tableWidth, int StudKiekis)
{
    auto start = high_resolution_clock::now();

    vector<Studentas> BiskiBumBum; // Studentai < 5
    vector<Studentas> BiskiProtingi; // Studentai >= 5

    // Ciklas, kuris skirsto studentus į dvi grupes
    for (const Studentas& studentas : studentai) {
        if (studentas.GalutinisB < 5.0 && studentas.GalutinisB > 0.0) {
            BiskiBumBum.push_back(studentas);
        } else if (studentas.GalutinisB >= 5 && studentas.GalutinisB <= 10) {
            BiskiProtingi.push_back(studentas);
        }
    }


    auto stop = high_resolution_clock::now();
    MatuotiLaika(start, stop, "Duomenu iskisrtymas");
    cout << endl;
//isveda duomenis i du atskirus failus
    AntrosIsvedimasIAtskirusFailus(BiskiBumBum, SkaiciavimoBudas, nd_skaicius, tableWidth, "BiskiBumBum_"+ to_string(BiskiBumBum.size()) + "_" + failoPavadinimas);
    AntrosIsvedimasIAtskirusFailus(BiskiProtingi, SkaiciavimoBudas, nd_skaicius, tableWidth, "BiskiProtingi_" + to_string(BiskiProtingi.size()) + "_" +failoPavadinimas);

}

void IsvestiDuomenisIpagrFaila(const vector<Studentas>& studentai, char SkaiciavimoBudas, int nd_skaicius, int tableWidth, const string& FailoPav) {

    auto start = high_resolution_clock::now(); // Pradeda matuoti duomenu isvedima
    ofstream outFile(FailoPav);

    if (outFile.is_open()) {
        outFile  << left << setw(20) << "Vardas" << " | " << setw(20) << "Pavarde" << " | ";

        if (SkaiciavimoBudas == 'V' || SkaiciavimoBudas == 'v') {
            outFile << setw(20) << "Galutinis (Vid)" << " |" << endl;
        } else {
            outFile << setw(20) << "Galutinis (Med)" << " |" << endl;
        }


        for (const Studentas& studentas : studentai) {
            outFile << left << setw(20) << studentas.Vardas  << setw(20)
                << studentas.Pavarde << " | ";

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

    auto stop = high_resolution_clock::now(); // Baigia matuoti duomenu isvedima
    MatuotiLaika(start, stop, "Duomenu isvedimas");
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
    MatuotiLaika(start, stop, "Duomenu isvedimas");

}

void MatuotiLaika(high_resolution_clock::time_point start, high_resolution_clock::time_point stop, const string& veiksmas) {
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << veiksmas << " uztruko: " << duration.count() << " ms" << endl;
    cout << endl;
}
