#include "stu.h"
#include "funkcijuAprasai.h"
#include "zmogus.h"


void Studentas::setVardas(const std::string& newVardas) {
    Vardas = newVardas;
}
void Studentas::setPavarde(const std::string& newPavarde) {
    Pavarde = newPavarde;
}
void Studentas::setND(const std::vector<int>& newND) {
    ND = newND;
}

void Studentas::setEgzas(int newEgzas) {
    Egzas = newEgzas;
}
void Studentas::setGalutinisB(double newGalutinisB) {
    GalutinisB = newGalutinisB;
}

  double Studentas::CalculateGalutinisB() const {
    if (ND.size() == 0) {
        cerr << "Klaida: Nenustatytas pazymiu skaicius." << endl;
        return 0.0;
    }

    int totalHomework = 0;
    for (int nd : ND) {
        totalHomework += nd;
    }

    return 0.4 * static_cast<double>(totalHomework) / ND.size() + 0.6 * Egzas;
}

std::istream& operator>>(std::istream& is, Studentas& studentas) {
    cout << "Iveskite studento varda: ";
    is >> studentas.Vardas;

    cout << "Iveskite studento pavarde: ";
    is >> studentas.Pavarde;

    cout << "Studento objekto adresas atmintyje: " << &studentas << endl;

    string Random;
    cout << "Generuoti atsitiktinius pazymius (Taip/Ne)? ";
    is >> Random;

    if (Random == "Taip" || Random == "taip" || Random == "t") {
        srand(static_cast<unsigned>(time(0)));

        const int NDkiekis = rand() % 10 + 1;

        studentas.ND.clear();
        cout << "Atsitiktinai sugeneruoti ND pazymiai: ";
        for (int i = 0; i < NDkiekis; ++i) {
            int RandomPaz = rand() % 11;
            studentas.ND.push_back(RandomPaz);
            cout << RandomPaz << " ";
        }

        int egzas = rand() % 11;
        studentas.Egzas = egzas;
        cout << "\nAtsitiktinai sugeneruotas egzamino rezultatas: " << egzas << "\n";
    } else if (Random == "Ne" || Random == "ne" || Random == "n") {
        int NDrez;
        double totalHomework = 0.0;

        studentas.ND.clear();
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

                    studentas.ND.push_back(NDrez);
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
        studentas.Egzas = egzas;
    }

    studentas.CalculateGalutinisB();
    return is;
}

// Išvesties operatorius
std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
    bool isHeader =true;
    if (isHeader) {
        int tableWidth = 72;
        os << std::string(tableWidth, '-') << std::endl;
        os << "| " << std::left << std::setw(20) << "Vardas" << " | " << std::setw(20) << "Pavarde" << " | ";
        os << std::setw(20) << "Galutinis (Vid)" << " |" << std::endl;
        os << std::string(tableWidth, '-') << std::endl;
    }

    os << "| " << std::left << std::setw(20) << studentas.getVardas() << " | " << std::setw(20)
       << studentas.getPavarde() << " | ";
    os << std::setw(20) << std::fixed << std::setprecision(2) << studentas.CalculateGalutinisB() << " |" << std::endl;

    return os;
}







