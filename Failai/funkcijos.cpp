#include "Stu.h"
#include "funkcijuAprasai.h"
#include "zmogus.h"


void Studentas::PasirinktiVeiksma(vector<Studentas>& studentai) {
    char pasirinkimas;
    cout << "Pasirinkite kaip vesime duomenis ( 2 - duomenis reiks ivesti ranka,3 - Studentu sarasas bus sugeneruotas automatiskai ir parodyti laikai kiek uztruko, 4 - Demonstravimas Rule of three,  5 - Neveikia zmogus zmogus, 6 - baigti programa: ";
    cin >> pasirinkimas;
    cout << endl;

    if (pasirinkimas == '1') {
//----------------------------------------------

    } else if (pasirinkimas == '2') {
            Studentas studentas;

        char PridetiDarViena;
        do {
            studentas.inputFromStream(std::cin);
            std::cin >> studentas;  // Čia iškviestas operatorius
            studentai.push_back(studentas);

            cout << "Ar norite prideti dar viena studenta? (T - Taip, N - Ne) ";
            cin >> PridetiDarViena;
        } while (PridetiDarViena == 'T' || PridetiDarViena == 't');

        std::sort(studentai.begin(), studentai.end(), CompareByVardas);
        cout << "Studentu duomenys ir galutiniai balai:" << endl;
        bool isHeader = true;
        for (const Studentas& student : studentai) {
            std::cout << studentas;
            isHeader = false;
        }
    } else if (pasirinkimas == '3') {
        Pasirinkti();
   } else if (pasirinkimas == '4') {

    vector<Studentas> studentuSarasas;

    string failo_pav;
    cout << "Iveskite failo pavadinima: ";
    cin >> failo_pav;
    Studentas::read_from_file(studentuSarasas, failo_pav);

    vector<Studentas> nukopijuotas1(studentuSarasas);
    vector<Studentas> nukopijuotas2;
    nukopijuotas2 = studentuSarasas;

    cout << "Originalus:\n";
    for (const auto& studentas : studentuSarasas) {
        cout << studentas.getVardas() << " " << studentas.getPavarde() << endl;
    }

    cout << "\nNukopijuotas 1:\n";
    for (const auto& studentas : nukopijuotas1) {
        cout << studentas.getVardas() << " " << studentas.getPavarde() << endl;
    }

    cout << "\nNukopijuotas 2:\n";
    for (const auto& studentas : nukopijuotas2) {
        cout << studentas.getVardas() << " " << studentas.getPavarde() << endl;
    }


    } else if (pasirinkimas == '5') {


        //Zmogus zmogus;


        Studentas studentas;
        cin >> studentas;
        Studentas studentas2(studentas);
        Studentas studentas3=studentas;
        cout << studentas << endl;
        cout << studentas2 << endl;
        cout << studentas3 << endl;

    }else if (pasirinkimas == '6')
    {
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


unsigned int countWordsInString(const std::string& str) {
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

bool CompareByVardas(const Studentas& a, const Studentas& b) {
    return a.getVardas() < b.getVardas();
}

bool CompareByVardas1(const Studentas& a, const Studentas& b) {
    return a.getVardas() > b.getVardas();
}

bool CompareByPavarde(const Studentas& a, const Studentas& b) {
    return a.getPavarde() < b.getPavarde();
}

bool CompareByPavarde1(const Studentas& a, const Studentas& b) {
    return a.getPavarde() > b.getPavarde();
}

bool CompareByBalas(const Studentas& a, const Studentas& b) {
    return a.getGalutinisB() < b.getGalutinisB();
}

bool CompareByBalas1(const Studentas& a, const Studentas& b) {
    return a.getGalutinisB() > b.getGalutinisB();
}
