#include "Stu.h"
#include "FunkcijuAprasai.h"


void Studentas::PasirinktiVeiksma(vector<Studentas>& studentai) {
    int Pasirinkimas;
    char pasirinkimas;
    cout << "Pasirinkite kaip vesime duomenis (1 - nuskaityta bus is failo, 2 - duomenis reiks ivesti ranka),3 - Studentu sarasas bus sugeneruotas automatiskai ir parodyti laikai kiek uztruko, 4 - Baigti programa: ";
    cin >> pasirinkimas;
    cout << endl;

    if (pasirinkimas == '1') {
        /*int pazymiu_sk;
        vector<Studentas> mok;
        Studentas::read_from_file(mok, &pazymiu_sk);
        IsvedimasLenteles(mok);
        sort(mok.begin(), mok.end(), CompareByVardas);*/
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
            Studentas studentas;
            studentas.inputFromStream(std::cin);
            studentas.StudentoDuomenys(studentas);  // Call the member function on the instance
            studentai.push_back(studentas);

            cout << "Ar norite prideti dar viena studenta? (T - Taip, N - Ne) ";
            cin >> PridetiDarViena;
        } while (PridetiDarViena == 'T' || PridetiDarViena == 't');

        std::sort(studentai.begin(), studentai.end(), CompareByVardas);
        cout << "Studentu duomenys ir galutiniai balai:" << endl;
        bool isHeader = true;
        for (const Studentas& student : studentai) {
            Isvedimas(student, isHeader);  // Use true for isHeader
            isHeader = false;
        }
    } else if (pasirinkimas == '3') {
        Pasirinkti();
    } else if (pasirinkimas == '4') {
        exit(0);
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
