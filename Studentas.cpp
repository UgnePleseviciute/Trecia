#include "stu.h"


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

void Studentas::StudentoDuomenys(Studentas& studentas) { // nuoroda funkcijos  i studentas objekta, kuris bus uzpildytas per sios funkcijos veikima duomenimis
        cout << "Iveskite studento varda: ";
        string vardas;
        cin >> vardas;
        studentas.setVardas(vardas);


        cout << "Iveskite studento pavarde: ";
        string pavarde;
        cin >> pavarde;
        studentas.setPavarde(pavarde);

        cout << "Studento objekto adresas atmintyje: " << &studentas << endl; //pridetas atminties adresas
        string Random;
        cout << "Generuoti atsitiktinius pazymius (Taip/Ne)? ";
        cin >> Random;

        if (Random == "Taip" || Random == "taip" || Random == "t") {

            srand(static_cast<unsigned>(time(0)));

            const int NDkiekis = rand() % 10 + 1;

            studentas.setND(std::vector<int>{}); // Clear the existing vector //nes leidzia pasrinikti ar ranka vesim ar ne , jei anksciau buvo ivesta ir jie nebuvo issaugoti tai juos reik isvalyti

            cout << "Atsitiktinai sugeneruoti ND pazymiai: ";
            for (int i = 0; i < NDkiekis; ++i) {
                int RandomPaz = rand() % 11;
                studentas.addND(RandomPaz);
                cout << RandomPaz << " ";
            }

            studentas.setEgzas( rand() % 11);
            cout << "\nAtsitiktinai sugeneruotas egzamino rezultatas: " << studentas.getEgzas() << "\n";
        } else if (Random == "Ne" || Random == "ne" || Random == "n") {
                int NDrez;
                double totalHomework = 0.0;

                studentas.setND(std::vector<int>{});

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

                studentas.addND(NDrez);
                totalHomework += NDrez;
            } catch (const invalid_argument& e) {
                cout << e.what() << endl; //metodas kazkoks, naudojamas gauti klaidos pranesima , kuri programuotojas nurodo
                continue;
            }
        }
    }


            cout << "Iveskite egzamino rezultata: ";
            int egzas;
            cin >> egzas;
            studentas.setEgzas(egzas);
        }
    }
