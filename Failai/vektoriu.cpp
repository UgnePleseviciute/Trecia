#include <algorithm>
#include "Stu.h"
#include "funkcijuAprasai.h"
#include "zmogus.h"


void Antraa(vector<Studentas>& studentai) {
    const vector<int> studentCounts = {1000, 10000, 100000, 1000000/*, 10000000*/};
    string FailoPav;
    int Pasirinkimas, Tvarka;

    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    char Generavimaas;
    cout << "ar norite generuoti failus [t/n]: " << endl;
    cin >> Generavimaas;

    if (Generavimaas == 't' || Generavimaas == 'T') {
        Generavimas(studentai);
    }

    cout << "pasirinkite kaip duomenys bus isrusiuoti \n";
    cout << "1 - Pagal varda \n";
    cout << "2 - Pagal pavarde \n";
    cout << "3 - Pagal pazymius \n";
    cin >> Pasirinkimas;

    if (Pasirinkimas != 1 && Pasirinkimas != 2 && Pasirinkimas != 3) {
        cout << "Netinkamas pasirinkimas, rūšiuosime pagal vardą ";
        Pasirinkimas = 1;
    }

    cout << "Pasirinkite kokia tvarka matuosime \n";
    cout << "1 - Didejimo \n";
    cout << "2 - Mazejimo \n";
    cin >> Tvarka;

    if (Tvarka != 1 && Tvarka != 2) {
        cout << "Netinkamas pasirinkimas, rūšiuosime didejimo tvarka ";
        Tvarka = 1;
    }

    for (int StudKiekis : studentCounts) {
        cout << "Studentu kiekis: " << StudKiekis << " duomenu" << endl;
        double matavimoLaikaiNuskaitymas[3] = {0};
        double matavimoLaikaiRikiavimas[3] = {0};
        double matavimoLaikaiIsvestisVargsiukai[3] = {0};
        double matavimoLaikaiIsvestisKietiakiai[3] = {0};
        double matavimoLaikaiIsrusiavimui[3] = {0};

        for (int i = 0; i < 3; ++i) {
            auto startNuskaitymas = high_resolution_clock::now();
            FailoPav = to_string(StudKiekis) + ".txt";
            Studentas::NuskaitytiDuomenis(FailoPav, studentai);
            auto stopNuskaitymas = high_resolution_clock::now();
            auto nuskaitymoLaikas = duration_cast<milliseconds>(stopNuskaitymas - startNuskaitymas).count() / 1000.0;
            matavimoLaikaiNuskaitymas[i] = nuskaitymoLaikas;

            // GalutinisB apskaičiavimas
            for (Studentas& studentas : studentai) {
                double galutinisB = studentas.CalculateGalutinisB();
                studentas.setGalutinisB(galutinisB);
            }

            auto startIsrusiavimas = high_resolution_clock::now();
            RikiavimoMeniu(studentai, vargsiukai, kietiakiai, Pasirinkimas, Tvarka);
            auto stopIsrusiavimas = high_resolution_clock::now();
            auto IsrusiavimoLaikas = duration_cast<milliseconds>(stopIsrusiavimas - startIsrusiavimas).count() / 1000.0;
            matavimoLaikaiIsrusiavimui[i] = IsrusiavimoLaikas;

            auto startRikiavimas = high_resolution_clock::now();
            Studentas::RikiuotiStudentus(studentai, vargsiukai);
            auto stopRikiavimas = high_resolution_clock::now();
            auto rikiavimoLaikas = duration_cast<milliseconds>(stopRikiavimas - startRikiavimas).count() / 1000.0;
            matavimoLaikaiRikiavimas[i] = rikiavimoLaikas;

            auto startIsvestisVargsiukai = high_resolution_clock::now();
            IsvestiDuomenis(vargsiukai, "vargsiukai_" + to_string(vargsiukai.size()) + "_" + to_string(StudKiekis));
            vargsiukai.clear();
            auto stopIsvestisVargsiukai = high_resolution_clock::now();
            auto isvestiesLaikasVargsiukai = duration_cast<milliseconds>(stopIsvestisVargsiukai - startIsvestisVargsiukai).count() / 1000.0;
            matavimoLaikaiIsvestisVargsiukai[i] = isvestiesLaikasVargsiukai;

            auto startIsvestisKietiakiai = high_resolution_clock::now();
            IsvestiDuomenis(studentai, "mazinti_" + to_string(studentai.size()) + "_" +to_string(StudKiekis));
            studentai.clear();
            auto stopIsvestisKietiakiai = high_resolution_clock::now();
            auto isvestiesLaikasKietiakiai = duration_cast<milliseconds>(stopIsvestisKietiakiai - startIsvestisKietiakiai).count( ) / 1000.0;
            matavimoLaikaiIsvestisKietiakiai[i] = isvestiesLaikasKietiakiai;
        }

        double vidutinisNuskaitymas = (matavimoLaikaiNuskaitymas[0] + matavimoLaikaiNuskaitymas[1] + matavimoLaikaiNuskaitymas[2]) / 3;
        double vidutinisRikiavimas = (matavimoLaikaiRikiavimas[0] + matavimoLaikaiRikiavimas[1] + matavimoLaikaiRikiavimas[2]) / 3;
        double vidutinisIsvestisVargsiukai = (matavimoLaikaiIsvestisVargsiukai[0] + matavimoLaikaiIsvestisVargsiukai[1] + matavimoLaikaiIsvestisVargsiukai[2]) / 3;
        double vidutinisIsvestisKietiakiai = (matavimoLaikaiIsvestisKietiakiai[0] + matavimoLaikaiIsvestisKietiakiai[1] + matavimoLaikaiIsvestisKietiakiai[2]) / 3;
        double vidutinisIsrusiavimas = (matavimoLaikaiIsrusiavimui[0] + matavimoLaikaiIsrusiavimui[1] + matavimoLaikaiIsrusiavimui[2]) / 3;

        cout << "Vidutinis nuskaitymo laikas (" << StudKiekis << " duomenu): " << vidutinisNuskaitymas << " s" << endl;
        cout << "Vidutinis isrusiavimo laikas ("  << StudKiekis << " duomenu): " <<  vidutinisIsrusiavimas << " s" << endl;
        cout << "Vidutinis iskaidymo laikas (" << StudKiekis << " duomenu): " << vidutinisRikiavimas << " s" << endl;
        cout << "Vidutinis isvedimo laikas vargsiukams (" << StudKiekis << " duomenu): " << vidutinisIsvestisVargsiukai << " s" << endl;
        cout << "Vidutinis isvedimo laikas mazintam (" << StudKiekis << " duomenu): " << vidutinisIsvestisKietiakiai << " s" << endl;
        cout << endl;
        studentai.clear(); //isvalom vektoriu
    }
    Studentas studentas;
    studentas.PasirinktiVeiksma(studentai);
}

void Studentas::RikiuotiStudentus(vector<Studentas>& studentai, vector<Studentas>& vargsiukai) {
    auto partitionIt = std::partition(studentai.begin(), studentai.end(),
        [](const Studentas& student) {
            return student.CalculateGalutinisB() > 5.0;
        });

    vargsiukai.insert(vargsiukai.end(), partitionIt, studentai.end());
    studentai.erase(partitionIt, studentai.end());
}

void NuskaitytiVisusFailus(vector<Studentas>& studentai) {
    const vector<int> studentCounts = {1000, 10000, 100000, 1000000, 10000000};

    for (int StudKiekis : studentCounts) {
        string FailoPav = to_string(StudKiekis) + ".txt";
        Studentas::NuskaitytiDuomenis(FailoPav, studentai);
    }
}

void Studentas::NuskaitytiDuomenis(const string& FailoPav, vector<Studentas>& studentai) {
    int temp;
    ifstream fileRead;
    string buff;
    try {
        fileRead.open(FailoPav);

        if (!fileRead.is_open()) {
            throw invalid_argument("Failas '" + FailoPav + "' neegzistuoja arba negali būti atidarytas!");
        }

        if (fileRead.is_open()) {
            getline(fileRead >> ws, buff);

            int pazymiu_sk = countWordsInString(buff) - 2;

            while (true) {
                Studentas student;
                if (!(fileRead >> buff)) {
                    break;
                }
                student.setVardas(buff);
                fileRead >> buff;
                student.setPavarde(buff);
                for (int i = 0; i < pazymiu_sk; i++) {
                    if (!(fileRead >> temp)) {
                        cout << "Klaida nuskaitant pažymį " << i + 1 << " studento " << student.getVardas() << " " << student.getPavarde() << endl;
                        break;
                    }
                    student.addND(temp);
                }

                fileRead >> temp;
                student.setEgzas(temp);
                studentai.push_back(student);
            }
        } else {
            cout << "Klaida atidarant failą!" << endl;
        }
        fileRead.close();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void IsvestiDuomenisIpagrFaila(const vector<Studentas>& studentai, const string& FailoPav) {
    auto startIsvedimas = high_resolution_clock::now();

    ofstream outFile(FailoPav);

    if (outFile.is_open()) {
        const int vardasWidth = 30;
        const int pavardeWidth = 30;
        const int nd_pazymysWidth = 8;
        const int egzasWidth = 8; // Width for the "Egz." column

        outFile << left << setw(vardasWidth) << "Vardas" << setw(pavardeWidth) << "Pavarde";
        for (int i = 1; i <= 5; ++i) {
            outFile << "ND" << i << setw(nd_pazymysWidth);
        }
        outFile << "Egz." << endl;

        for (const Studentas& studentas : studentai) {
            outFile << left << setw(vardasWidth) << studentas.getVardas() << setw(pavardeWidth) << studentas.getPavarde();

            // Print up to 5 ND grades
            for (int i = 0; i < 5; i++) {
                if (i < studentas.getND().size()) {
                    outFile << setw(nd_pazymysWidth) << fixed << setprecision(2) << studentas.getND()[i];
                } else {
                    outFile << setw(nd_pazymysWidth) << " ";
                }
            }

            outFile << setw(egzasWidth) << fixed << setprecision(2) << studentas.getEgzas() << endl;
        }

        outFile << endl;

        outFile.close();
    } else {
        cout << "Nepavyko atidaryti failo: " << FailoPav << endl;
    }
    auto stopIsvedimas = high_resolution_clock::now();
    auto ISvedimoLaikas = duration_cast<std::chrono::milliseconds>(stopIsvedimas - startIsvedimas).count() / 1000.0;
    cout << "Isvedimas uztruko " << ISvedimoLaikas << " s" << endl;
    cout << endl;
}

void IsvestiDuomenis(const vector<Studentas>& studentai, const string& failoPavadinimas) {
    ofstream outFile(failoPavadinimas);

    if (outFile.is_open()) {
        const int vardasWidth = 30;
        const int pavardeWidth = 30;
        const int galutinisWidth = 20;

        outFile << left << setw(vardasWidth) << "Vardas" << setw(pavardeWidth) << "Pavarde";
        outFile << setw(galutinisWidth) << "Galutinis (Vid)" << endl;

        for (const Studentas& studentas : studentai) {
            outFile << left << setw(vardasWidth) << studentas.getVardas() << setw(pavardeWidth) << studentas.getPavarde();
            outFile << setw(galutinisWidth) << fixed << setprecision(2) << studentas.getGalutinisB() << endl;
        }

        outFile.close();
    } else {
        cout << "Nepavyko atidaryti failo:  " << failoPavadinimas << endl;
    }
}

void MatuotiLaika(high_resolution_clock::time_point start, high_resolution_clock::time_point stop, const char* veiksmas) {
    auto duration = duration_cast<milliseconds>(stop - start);
    double seconds = duration.count() / 1000.0;

    cout << veiksmas << " užtruko: " << fixed << setprecision(3) << seconds << " s" << endl;
}

void Generavimas(vector<Studentas>& studentai) {
    const vector<int> studentCounts = {1000, 10000, 100000, 1000000 /*, 10000000*/};

    for (int StudKiekis : studentCounts) {
        auto start = high_resolution_clock::now();

        for (int i = 1; i <= StudKiekis; ++i) {
            Studentas studentas;
            studentas.setVardas("Vardas" + to_string(i));
            studentas.setPavarde("Pavarde" + to_string(i));

            for (int j = 1; j <= 5; ++j) {
                int nd_pazymys = rand() % 10 + 1;
                studentas.addND(nd_pazymys);
            }

            int egzas = rand() % 11;
            studentas.setEgzas(egzas);

            studentai.push_back(studentas);
        }

        string FailoPav = to_string(StudKiekis) + ".txt";
        auto stop = high_resolution_clock::now();
        cout << StudKiekis << " studentu" << endl;
        MatuotiLaika(start, stop, "Duomenu generavimas");
        IsvestiDuomenisIpagrFaila(studentai, FailoPav);

        studentai.clear();
    }
}

void RikiavimoMeniu(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai, int Pasirinkimas, int Tvarka) {
    if (Pasirinkimas == 1) {
        if (Tvarka == 1) {
            sort(studentai.begin(), studentai.end(), CompareByVardas);
            sort(vargsiukai.begin(), vargsiukai.end(), CompareByVardas);
        } else if (Tvarka == 2) {
            sort(studentai.begin(), studentai.end(), CompareByVardas1);
            sort(vargsiukai.begin(), vargsiukai.end(), CompareByVardas1);
        }
    } else if (Pasirinkimas == 2) {
        if (Tvarka == 1) {
            sort(studentai.begin(), studentai.end(), CompareByPavarde);
            sort(vargsiukai.begin(), vargsiukai.end(), CompareByPavarde);
        } else if (Tvarka == 2) {
            sort(studentai.begin(), studentai.end(), CompareByPavarde1);
            sort(vargsiukai.begin(), vargsiukai.end(), CompareByPavarde1);
        }
    } else if (Pasirinkimas == 3) {
        if (Tvarka == 1) {
            sort(studentai.begin(), studentai.end(), CompareByBalas);
            sort(vargsiukai.begin(), vargsiukai.end(), CompareByBalas);
        } else if (Tvarka == 2) {
            sort(studentai.begin(), studentai.end(), CompareByBalas1);
            sort(vargsiukai.begin(), vargsiukai.end(), CompareByBalas1);
        }
    }
}

void Pasirinkti() {
    vector<Studentas> studentai;

    char Listu;
    cout << "paspaudus n - bus generuojami duomenis naudojant vektorius kaip konteinerius" << endl;
    cin >> Listu;

        if (Listu == 'N' || Listu == 'n')
   {
        Antraa(studentai);
    }
    else {
            Studentas studentas;
        studentas.PasirinktiVeiksma(studentai);
    }
}
