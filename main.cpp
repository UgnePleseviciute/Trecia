#include "Studentas.h"
int main() {
    vector<Studentas> studentai;
    char SkaiciavimoBudas;
    char PridetiDarViena;

    cout << "Pasirinkite skaiciavimo metoda (V- Vidurkis, M - Mediana): ";
    cin >> SkaiciavimoBudas;

    if (SkaiciavimoBudas != 'V' && SkaiciavimoBudas != 'v' && SkaiciavimoBudas != 'M' && SkaiciavimoBudas != 'm') {
        cout << "Nesuprantama ivesti, naudosime Vidurki pagal Default." << endl;
        SkaiciavimoBudas = 'V';
    }

    do {
        Studentas studentas;
        studentas.SkaiciavimoBudas = SkaiciavimoBudas;

        StudentoDuomenys(studentas);
        studentai.push_back(studentas);

        cout << "Ar nortite prideti dar viena studenta? (T - Taip, N - Ne) ";
        cin >> PridetiDarViena;
    } while (PridetiDarViena == 'T' || PridetiDarViena == 't');

    cout << "Studentu duomenys ir galutiniai balai:" << endl;
    bool isHeader = true;
    for (const Studentas& student : studentai) {
        Isvedimas(student, isHeader);
        isHeader = false;
    }

    return 0;
}
