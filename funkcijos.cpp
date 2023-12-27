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
            Studentas studentas;
            studentas.inputFromStream(std::cin);
            studentai.push_back(studentas);

            cout << "Ar norite prideti dar viena studenta? (T - Taip, N - Ne) ";
            cin >> PridetiDarViena;
        } while (PridetiDarViena == 'T' || PridetiDarViena == 't');

        std::sort(studentai.begin(), studentai.end(), CompareByVardas);
        cout << "Studentu duomenys ir galutiniai balai:" << endl;
        bool isHeader = true;
        for (const Studentas& student : studentai) {
            student.outputToStream(std::cout, true);  // Use true for isHeader
            isHeader = false;
        }
    } else if (pasirinkimas == '3') {
        Pasirinkti();
    } else if (pasirinkimas == '4') {
        exit(0);
    }
}
