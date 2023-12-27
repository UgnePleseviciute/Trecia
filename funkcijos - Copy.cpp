#include "Stu.h"
#include "FunkcijuAprasai.h"


    void PasirinktiVeiksma(vector<Studentas>& studentai) {
    int Pasirinkimas;
    char pasirinkimas;
    cout << "Pasirinkite kaip vesime duomenis (1 - nuskaityta bus is failo, 2 - duomenis reiks ivesti ranka),3 - Studentu sarasas bus sugeneruotas automatiskai ir parodyti laikai kiek uztruko, 4 - Baigti programa: ";
    cin >> pasirinkimas;
    cout << endl;

    if (pasirinkimas == '1') {
        int pazymiu_sk;
        vector<Studentas> mok;
        read_from_file(mok, &pazymiu_sk);
        IsvedimasLenteles(mok);
        sort(mok.begin(), mok.end(), CompareByVardas);
    } else if (pasirinkimas == '2') {
        char SkaiciavimoBudas;
        cout << "Pasirinkite skaiciavimo metoda (V- Vidurkis, M - Mediana): ";
        cin >> SkaiciavimoBudas;

        if (SkaiciavimoBudas != 'V' && SkaiciavimoBudas != 'v' && SkaiciavimoBudas != 'M' && SkaiciavimoBudas != 'm') {
            cout << "Nesuprantama ivesti, naudosime Vidurki pagal Defaulta." << endl;
            SkaiciavimoBudas = 'V';
        }

        char PridetiDarViena;
        do {
            // Create an instance of the Studentas class
            Studentas studentas;
            StudentoDuomenys(studentas); // Pass the Studentas object to the function for data input
            studentai.push_back(studentas);

            cout << "Ar norite prideti dar viena studenta? (T - Taip, N - Ne) ";
            cin >> PridetiDarViena;
        } while (PridetiDarViena == 'T' || PridetiDarViena == 't');

        std::sort(studentai.begin(), studentai.end(), CompareByVardas);
        cout << "Studentu duomenys ir galutiniai balai:" << endl;
        bool isHeader = true;
        for (const Studentas& student : studentai) {
            Isvedimas(student, isHeader);
            isHeader = false;
        }
    } else if (pasirinkimas == '3') {
        Pasirinkti();
    } else if (pasirinkimas == '4') {
        exit(0);
    }
}
  void StudentoDuomenys(Studentas& studentas) {
    cout << "Iveskite studento varda: ";
    string vardas;
    cin >> vardas;
    studentas.setVardas(vardas);

    cout << "Iveskite studento pavarde: ";
    string pavarde;
    cin >> pavarde;
    studentas.setPavarde(pavarde);

    cout << "Studento objekto adresas atmintyje: " << &studentas << endl;

    string Random;
    cout << "Generuoti atsitiktinius pazymius (Taip/Ne)? ";
    cin >> Random;

    if (Random == "Taip" || Random == "taip" || Random == "t") {
        srand(static_cast<unsigned>(time(0)));

        const int NDkiekis = rand() % 10 + 1;

        studentas.setND({}); // Assuming you have a method to set ND in your class

        cout << "Atsitiktinai sugeneruoti ND pazymiai: ";
        for (int i = 0; i < NDkiekis; ++i) {
            int RandomPaz = rand() % 11;
            studentas.addND(RandomPaz); // Assuming you have a method to add ND in your class
            cout << RandomPaz << " ";
        }

        int egzas = rand() % 11;
        studentas.setEgzas(egzas);
        cout << "\nAtsitiktinai sugeneruotas egzamino rezultatas: " << egzas << "\n";
    } else if (Random == "Ne" || Random == "ne" || Random == "n") {
        int NDrez;
        double totalHomework = 0.0;

        studentas.setND({}); // Assuming you have a method to set ND in your class

        cout << "Iveskite ND rezultatus (ivedus -1 baigsis ivedimas): ";
        while (true) {
            cin >> NDrez;

            if (NDrez == -1) {
                char baigimoPasirinkimas;
                cout << "Ar tikrai norite baigti ivedima? (T - Taip, N - Ne): ";
                cin >> baigimoPasirinkimas;
                if (baigimoPasirinkimas == 'T' || baigimoPasirinkimas == 't') {
                    break;
                }
            } else {
                try {
                    if (NDrez < 0 || NDrez > 10) {
                        throw invalid_argument("Netinkamas pazymio formatas. Pazymiai turi buti nuo 0 iki 10.");
                    }

                    // Assuming you have a method to add ND in your class
                    studentas.addND(NDrez);
                    totalHomework += NDrez;
                } catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                    continue;
                }
            }
        }

        int egzas;
        cout << "Iveskite egzamino rezultata: ";
        cin >> egzas;
        studentas.setEgzas(egzas);
    }
}


    double GalutinisBalas(const Studentas& studentas) {
    if (studentas.getND().empty()) {
        return 0.6 * studentas.getEgzas();
    }

    if (studentas.getSkaiciavimoBudas() == 'M' || studentas.getSkaiciavimoBudas() == 'm') {
        vector<int> sortedND = studentas.getND();
        sort(sortedND.begin(), sortedND.end());

        int totalHomework = 0;
        for (int nd : sortedND) {
            totalHomework += nd;
        }

        int n = sortedND.size();
        if (n % 2 == 0) {
            int middle1 = sortedND[n / 2 - 1];
            int middle2 = sortedND[n / 2];
            return 0.4 * (static_cast<double>(middle1 + middle2) / 2.0) + 0.6 * studentas.getEgzas();
        } else {
            int middle = sortedND[n / 2];
            return 0.4 * static_cast<double>(middle) + 0.6 * studentas.getEgzas();
        }
    } else {
        int totalHomework = 0;
        for (int nd : studentas.getND()) {
            totalHomework += nd;
        }

        double GalutinisVidurkis = 0.4 * static_cast<double>(totalHomework) / studentas.getND().size() + 0.6 * studentas.getEgzas();
        return GalutinisVidurkis;
    }
}


  void Isvedimas(const Studentas& studentas, bool isHeader) {
    if (isHeader) {
        int tableWidth = 72;
        cout << string(tableWidth, '-') << endl;
        cout << "| " << left << setw(20) << "Vardas" << " | " << setw(20) << "Pavarde" << " | ";
        if (studentas.getSkaiciavimoBudas() == 'V' || studentas.getSkaiciavimoBudas() == 'v') {
            cout << setw(20) << "Galutinis (Vid)" << " |" << endl;
        } else {
            cout << setw(20) << "Galutinis (Med)" << " |" << endl;
        }
        cout << string(tableWidth, '-') << endl;
    }

    cout << "| " << left << setw(20) << studentas.getVardas() << " | " << setw(20)
         << studentas.getPavarde() << " | ";

    if (studentas.getSkaiciavimoBudas() == 'V' || studentas.getSkaiciavimoBudas() == 'v') {
        cout << setw(20) << fixed << setprecision(2) << GalutinisBalas(studentas) << " |" << endl;
    } else {
        cout << setw(20) << fixed << setprecision(2) << GalutinisBalas(studentas) << " |" << endl;
    }
}
