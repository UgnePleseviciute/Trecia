#include "stu.h"


Studentas::Studentas(std::istream& is) {
    readStudent(is);
}



void Studentas::skaiciuotiGalutiniB() {
    if (ND.empty()) {
        GalutinisB = 0.6 * Egzas;
    } else {
        if (SkaiciavimoBudas == 'M' || SkaiciavimoBudas == 'm') {
            // Calculate median for ND
            std::vector<int> sortedND = ND;
            std::sort(sortedND.begin(), sortedND.end());

            int n = sortedND.size();
            if (n % 2 == 0) {
                int middle1 = sortedND[n / 2 - 1];
                int middle2 = sortedND[n / 2];
                GalutinisB = 0.4 * (static_cast<double>(middle1 + middle2) / 2.0) + 0.6 * Egzas;
            } else {
                int middle = sortedND[n / 2];
                GalutinisB = 0.4 * static_cast<double>(middle) + 0.6 * Egzas;
            }
        } else {
            // Calculate average for ND
            int totalHomework = 0;
            for (int nd : ND) {
                totalHomework += nd;
            }

            GalutinisB = 0.4 * static_cast<double>(totalHomework) / ND.size() + 0.6 * Egzas;
        }
    }
}

void Studentas::inputFromStream(std::istream& is) {

    cout << "Iveskite studento varda: ";
    is >> Vardas;

    cout << "Iveskite studento pavarde: ";
    is >> Pavarde;

    cout << "Studento objekto adresas atmintyje: " << this << endl;

    string Random;
    cout << "Generuoti atsitiktinius pazymius (Taip/Ne)? ";
    is >> Random;

    if (Random == "Taip" || Random == "taip" || Random == "t") {
        srand(static_cast<unsigned>(time(0)));

        const int NDkiekis = rand() % 10 + 1;

        ND.clear();
        cout << "Atsitiktinai sugeneruoti ND pazymiai: ";
        for (int i = 0; i < NDkiekis; ++i) {
            int RandomPaz = rand() % 11;
            ND.push_back(RandomPaz);
            cout << RandomPaz << " ";
        }

        int egzas = rand() % 11;
        Egzas = egzas;
        cout << "\nAtsitiktinai sugeneruotas egzamino rezultatas: " << egzas << "\n";
    } else if (Random == "Ne" || Random == "ne" || Random == "n") {
        int NDrez;
        double totalHomework = 0.0;

        ND.clear();
        cout << "Iveskite ND rezultatus (ivedus -1 baigsis ivedimas): ";
        while (true) {
            is >> NDrez;

            if (NDrez == -1) {
                char baigimoPasirinkimas;
                cout << "Ar tikrai norite baigti ivedima? (T - Taip, N - Ne): ";
                is >> baigimoPasirinkimas;
                if (baigimoPasirinkimas == 'T' || baigimoPasirinkimas == 't') {
                    break;
                }
            } else {
                try {
                    if (NDrez < 0 || NDrez > 10) {
                        throw invalid_argument("Netinkamas pazymio formatas. Pazymiai turi buti nuo 0 iki 10.");
                    }

                    ND.push_back(NDrez);
                    totalHomework += NDrez;
                } catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                    continue;
                }
            }
        }

        int egzas;
        cout << "Iveskite egzamino rezultata: ";
        is >> egzas;
        Egzas = egzas;
    }

    CalculateGalutinisB();
}
// Output operator

void Studentas::outputToStream(std::ostream& os, bool isHeader) const {

    if (isHeader) {
        int tableWidth = 72;
        os << std::string(tableWidth, '-') << std::endl;
        os << "| " << std::left << std::setw(20) << "Vardas" << " | " << std::setw(20) << "Pavarde" << " | ";
        if (SkaiciavimoBudas == 'V' || SkaiciavimoBudas == 'v') {
            os << std::setw(20) << "Galutinis (Vid)" << " |" << std::endl;
        } else {
            os << std::setw(20) << "Galutinis (Med)" << " |" << std::endl;
        }
        os << std::string(tableWidth, '-') << std::endl;
        isHeader = false;  // Pirmoji eilutė su antraštėmis išvedama, tolimesni įrašai bus lygiagretūs
    }

    os << "| " << std::left << std::setw(20) << Vardas << " | " << std::setw(20)
       << Pavarde << " | ";

    if (SkaiciavimoBudas == 'V' || SkaiciavimoBudas == 'v') {
        os << std::setw(20) << std::fixed << std::setprecision(2) << CalculateGalutinisB() << " |" << std::endl;
        os << std::string(72, '-') << std::endl;  // Brūkšnys po kiekvieno studento
    } else {
        os << std::setw(20) << std::fixed << std::setprecision(2) << CalculateGalutinisB() << " |" << std::endl;
        isHeader = true;  // Naujas įrašas bus išvedamas naujoje eilutėje
    }
}

std::ostream& operator<<(std::ostream& os, const Studentas& student) {
    student.outputToStream(os, true);
    return os;
}

double Studentas::GalutinisBalas() const {
    if (ND.empty()) {
        return 0.6 * Egzas;
    }

    if (SkaiciavimoBudas == 'M' || SkaiciavimoBudas == 'm') {
        vector<int> sortedND = ND;
        sort(sortedND.begin(), sortedND.end());

        int totalHomework = 0;
        for (int nd : sortedND) {
            totalHomework += nd;
        }

        int n = sortedND.size();
        if (n % 2 == 0) {
            int middle1 = sortedND[n / 2 - 1];
            int middle2 = sortedND[n / 2];
            return 0.4 * (static_cast<double>(middle1 + middle2) / 2.0) + 0.6 * Egzas;
        } else {
            int middle = sortedND[n / 2];
            return 0.4 * static_cast<double>(middle) + 0.6 * Egzas;
        }
    } else {
        int totalHomework = 0;
        for (int nd : ND) {
            totalHomework += nd;
        }

        double GalutinisVidurkis = 0.4 * static_cast<double>(totalHomework) / ND.size() + 0.6 * Egzas;
        return GalutinisVidurkis;
    }
}
