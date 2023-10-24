#include "Stu.h"
#include "Faprasai.h"


void PasirinktiVeiksma(vector<Studentas>& studentai) { // priima studentu objektu vektoriu kaip argumenta
    int Pasirinkimas, Tvarka;
    char pasirinkimas;
    cout << "Pasirinkite kaip vesime duomenis (1 - nuskaityta bus is failo, 2 - duomenis reiks ivesti ranka),3 - Studentu sarasas bus sugeneruotas automatiskai ir parodyti laikai kiek uztruko, 4 - Baigti programa: ";
    cin >> pasirinkimas;
    cout<< endl;
    if (pasirinkimas == '1') { //nusakito is failiuko

        int pazymiu_sk;
        vector<Studentas> mok; // sukuriamas naujas objektu vectoriuus mok kuris naudojamas saugoti studentu duomenis kurie bus nuskaityti is failo
        read_from_file(mok, &pazymiu_sk); // kvieciama funkcija kuri nuskaito studentu duomenis is failo ir juos saugo vektoriujyje
        IsvedimasLenteles(mok);  // kviecia funkcija kuri isveda studentu duomenis i lentele
        sort(mok.begin(), mok.end(), CompareByVardas); // surusiuojami studentu duomenys pagal varda
} else if (pasirinkimas == '2') {  // vesime ranka
        char SkaiciavimoBudas;
        cout << "Pasirinkite skaiciavimo metoda (V- Vidurkis, M - Mediana): ";
        cin >> SkaiciavimoBudas;

        if (SkaiciavimoBudas != 'V' && SkaiciavimoBudas != 'v' && SkaiciavimoBudas != 'M' && SkaiciavimoBudas != 'm') {
            cout << "Nesuprantama ivesti, naudosime Vidurki pagal Defaulta." << endl;
            SkaiciavimoBudas = 'V';
        }

        char PridetiDarViena;
        do {
            Studentas studentas;
            studentas.SkaiciavimoBudas = SkaiciavimoBudas;
            StudentoDuomenys(studentas); // Kviečiama funkcija, kurioje vyksta studento duomenų įvedimas
            studentai.push_back(studentas);

            cout << "Ar nortite prideti dar viena studenta? (T - Taip, N - Ne) ";
            cin >> PridetiDarViena;
        } while (PridetiDarViena == 'T' || PridetiDarViena == 't');

        std::sort(studentai.begin(), studentai.end(), CompareByVardas);
        cout << "Studentu duomenys ir galutiniai balai:" << endl;
        bool isHeader = true;
        for (const Studentas& student : studentai) {
            Isvedimas(student, isHeader); // Kviečiama funkcija, kuri spausdina duomenis
            isHeader = false;
        }
    }

    else if (pasirinkimas == '3') { // jei pasirinkimas 3 kviecia antrai funkcija
         Pasirinkti();

    }
    else if (pasirinkimas == '4') { // jei 4 baigia programos veikima
        exit(0);
    }
}
void StudentoDuomenys(Studentas& studentas) { // nuoroda funkcijos  i studentas objekta, kuris bus uzpildytas per sios funkcijos veikima duomenimis
    cout << "Iveskite studento varda: ";
    cin >> studentas.Vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> studentas.Pavarde;

    cout << "Studento objekto adresas atmintyje: " << &studentas << endl; //pridetas atminties adresas
    string Random;
    cout << "Generuoti atsitiktinius pazymius (Taip/Ne)? ";
    cin >> Random;

    if (Random == "Taip" || Random == "taip" || Random == "t") {

        srand(static_cast<unsigned>(time(0)));

        const int NDkiekis = rand() % 10 + 1;

        studentas.ND.clear(); //nes leidzia pasrinikti ar ranka vesim ar ne , jei anksciau buvo ivesta ir jie nebuvo issaugoti tai juos reik isvalyti

        cout << "Atsitiktinai sugeneruoti ND pazymiai: ";
        for (int i = 0; i < NDkiekis; ++i) {
            int RandomPaz = rand() % 11;
            studentas.ND.push_back(RandomPaz);
            cout << RandomPaz << " ";
        }

        studentas.Egzas = rand() % 11;
        cout << "\nAtsitiktinai sugeneruotas egzamino rezultatas: " << studentas.Egzas << "\n";
    } else if (Random == "Ne" || Random == "ne" || Random == "n") {
            int NDrez;
            double totalHomework = 0.0;

            studentas.ND.clear();

        cout << "Iveskite ND rezultatus (ivedus -1 baigsis ivedimas): ";
    while (true) {
        cin >> NDrez;

        if (NDrez == -1) {
        char baigimoPasirinkimas;
        cout << "Ar tikrai norite baigti ivedima? (T - Taip, N - Ne): ";
        cin >> baigimoPasirinkimas;
        if (baigimoPasirinkimas == 'T' || baigimoPasirinkimas == 't') {
            break; // Baigti ivedima jei ivesta -1 ir patvirtinta
        }
    } else {
        try {
            if (NDrez < 0 || NDrez > 10) {
                throw invalid_argument("Netinkamas pazymio formatas. Pazymiai turi buti nuo 0 iki 10.");
            }
            // Tikrinu ar tikrai tik skaicius ivede
            if (cin.fail()) { // tikrina ar pavyko nuskaityti reiksmes kurias ivede naudotojas
                cin.clear(); // klaida salina
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // padaro kad is naujo vesti skaicius
                throw invalid_argument("Ivesti netinkami duomenys (raide/simbolis). Prasau vesti tik skaicius.");
            }

            studentas.ND.push_back(NDrez);
            totalHomework += NDrez;
        } catch (const invalid_argument& e) {
            cout << e.what() << endl; //metodas kazkoks, naudojamas gauti klaidos pranesima , kuri programuotojas nurodo
            continue;
        }
    }
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

        double GalutinisVidurkis = 0.4 * static_cast<double>(totalHomework) / studentas.ND.size() + 0.6 * studentas.Egzas; //statistic  konvertuoja kitanmi i double
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
