#include "Stu.h"
#include "Faprasai.h"



int main() {

    vector<Studentas> studentai; // Studentų sąrašas

    PasirinktiVeiksma(studentai); // Kviečiama funkcija, kurioje vyksta pasirinkimas

    return 0;
}
  /*  int pazymiu_sk;
    vector<Studentas> mok;
    vector<Studentas> studentai;
    char SkaiciavimoBudas;
    char PridetiDarViena;
    char temp;
    int pasirinkimas;

    cout << "Pasirinkite ka daryti (1 - nuskaityti is failo, 2 - vesti ranka): ";
    cin >> pasirinkimas;

    if (pasirinkimas == 1) { // bus nuskaityta is failiuko

        int pazymiu_sk;
        vector<Studentas> mok;
        read_from_file(mok, &pazymiu_sk);
        IsvedimasLenteles(mok);
        sort(mok.begin(), mok.end(), CompareByVardas);
    } else if (pasirinkimas == 2) { //tada vesime viska ranka

        cout << "Pasirinkite skaiciavimo metoda (V- Vidurkis, M - Mediana): ";
        cin >> SkaiciavimoBudas;

       if (SkaiciavimoBudas != 'V' && SkaiciavimoBudas != 'v' && SkaiciavimoBudas != 'M' && SkaiciavimoBudas != 'm') {
        cout << "Nesuprantama ivesti, naudosime Vidurki pagal Defaulta." << endl;
        SkaiciavimoBudas = 'V';
    }

        do {
            Studentas studentas;
            studentas.SkaiciavimoBudas = SkaiciavimoBudas;

            StudentoDuomenys(studentas); // va cia funkcija isviesta kad suvesti ranka

            studentai.push_back(studentas);

            cout << "Ar nortite prideti dar viena studenta? (T - Taip, N - Ne) ";
            cin >> PridetiDarViena;
        } while (PridetiDarViena == 'T' || PridetiDarViena == 't');
        std::sort(studentai.begin(), studentai.end(), CompareByVardas);
        cout << "Studentu duomenys ir galutiniai balai:" << endl;
        bool isHeader = true;
        for (const Studentas& student : studentai) {
            Isvedimas(student, isHeader);
            isHeader = false;
        }
    }

    return 0;*/






