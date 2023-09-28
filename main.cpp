#include "studentas.h"


int main() {
    vector<Studentas> studentai;

    while (true) {
        Studentas studentas;
        StudentoDuomenys(studentas);
        studentas.GalutinisB = GalutinisBalas(studentas);
        studentai.push_back(studentas);

        cout << "Ar norite ivesti dar viena studenta? (taip/ne): ";
        string pasirinkimas;
        cin >> pasirinkimas;
        if (pasirinkimas != "taip") {
            break;
        }
    }

    cout << "Studentu duomenys ir galutiniai balai:" << endl;
    bool isHeader = true;
    for (const Studentas& student : studentai) {
        Isvedimas(student, isHeader);
        isHeader = false; // Nenustatome antra karta virsutines eilutes
    }

    return 0;
}
