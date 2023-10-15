#include "Stu.h"
#include "Faprasai.h"

void Antraa(vector<Studentas>& studentai) {
    double visoLaikoTrukme = 0.0;  // Kintamasis laiko sumai
    const vector<int> studentCounts = {1000/*, 10000, 100000, 1000000, 10000000*/};
    string FailoPav;
    int Pasirinkimas, Tvarka;


    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    Generavimas(studentai);

    cout << "pasirinkite kaip duomenys bus isrusiuoti \n";
    cout << "1 - Pagal varda \n";
    cout << "2 - Pagal pavarde \n";
    cout << "3 - Pagal pazymius \n";
    cin >> Pasirinkimas;
   if (Pasirinkimas != 1 && Pasirinkimas != 2 && Pasirinkimas != 3)
{
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
    }

    if (ArMatuotiLaika()) {

        for (int StudKiekis : studentCounts) {
            cout << "Studentu kiekis: " << StudKiekis << " duomenu" << endl;
            double matavimoLaikaiNuskaitymas[3] = {0};
            double matavimoLaikaiRikiavimas[3] = {0};
            double matavimoLaikaiIsvestisVargsiukai[3] = {0};
            double matavimoLaikaiIsvestisKietiakiai[3] = {0};
            double matavimoLaikaiIsrusiavimui[3] = {0};
            for (int i = 0; i < 3; ++i) {

//----------------------------------------------------------------------------------------------------------------------------------------------------
                auto startNuskaitymas = high_resolution_clock::now();

                FailoPav = to_string(StudKiekis) + ".txt";
                NuskaitytiDuomenis(FailoPav, studentai);

                auto stopNuskaitymas = high_resolution_clock::now();
                auto nuskaitymoLaikas = duration_cast<milliseconds>(stopNuskaitymas - startNuskaitymas).count() / 1000.0;
                matavimoLaikaiNuskaitymas[i] = nuskaitymoLaikas;

 //----------------------------------------------------------------------------------------------------------------------------------------------------
                auto startIsrusiavimas = high_resolution_clock::now();

                RikiavimoMeniu(studentai,vargsiukai, kietiakiai, Pasirinkimas, Tvarka);

                auto stopIsrusiavimas = high_resolution_clock::now();
                auto IsrusiavimoLaikas = duration_cast<milliseconds>(stopIsrusiavimas - startIsrusiavimas).count() / 1000.0;
                matavimoLaikaiIsrusiavimui[i] = IsrusiavimoLaikas;

//----------------------------------------------------------------------------------------------------------------------------------------------------
                auto startRikiavimas = high_resolution_clock::now();

                RikiuotiStudentus(studentai, vargsiukai, kietiakiai);

                auto stopRikiavimas = high_resolution_clock::now();
                auto rikiavimoLaikas = duration_cast<milliseconds>(stopRikiavimas - startRikiavimas).count() / 1000.0;
                matavimoLaikaiRikiavimas[i] = rikiavimoLaikas;

//----------------------------------------------------------------------------------------------------------------------------------------------------

                auto startIsvestisVargsiukai = high_resolution_clock::now();

                IsvestiDuomenis(vargsiukai, "vargsiukai_" + to_string(vargsiukai.size()) + "_" + to_string(StudKiekis));
                vargsiukai.clear();

                auto stopIsvestisVargsiukai = high_resolution_clock::now();
                auto isvestiesLaikasVargsiukai = duration_cast<milliseconds>(stopIsvestisVargsiukai - startIsvestisVargsiukai).count() / 1000.0;
                matavimoLaikaiIsvestisVargsiukai[i] = isvestiesLaikasVargsiukai;

//----------------------------------------------------------------------------------------------------------------------------------------------------
                auto startIsvestisKietiakiai = high_resolution_clock::now();

                IsvestiDuomenis(kietiakiai, "kietiakiai_" + to_string(kietiakiai.size()) + "_" +to_string(StudKiekis));
                kietiakiai.clear();

                auto stopIsvestisKietiakiai = high_resolution_clock::now();
                auto isvestiesLaikasKietiakiai = duration_cast<milliseconds>(stopIsvestisKietiakiai - startIsvestisKietiakiai).count( ) / 1000.0;
                matavimoLaikaiIsvestisKietiakiai[i] = isvestiesLaikasKietiakiai;

//----------------------------------------------------------------------------------------------------------------------------------------------------
            }


            //apsakaiciuoja vidutinius laikus
            double vidutinisNuskaitymas = (matavimoLaikaiNuskaitymas[0] + matavimoLaikaiNuskaitymas[1] + matavimoLaikaiNuskaitymas[2]) / 3;
            double vidutinisRikiavimas = (matavimoLaikaiRikiavimas[0] + matavimoLaikaiRikiavimas[1] + matavimoLaikaiRikiavimas[2]) / 3;
            double vidutinisIsvestisVargsiukai = (matavimoLaikaiIsvestisVargsiukai[0] + matavimoLaikaiIsvestisVargsiukai[1] + matavimoLaikaiIsvestisVargsiukai[2]) / 3;
            double vidutinisIsvestisKietiakiai = (matavimoLaikaiIsvestisKietiakiai[0] + matavimoLaikaiIsvestisKietiakiai[1] + matavimoLaikaiIsvestisKietiakiai[2]) / 3;
            double vidutinisIsrusiavimas = (matavimoLaikaiIsrusiavimui[0] + matavimoLaikaiIsrusiavimui[1] + matavimoLaikaiIsrusiavimui[2]) / 3;

            cout << "Vidutinis nuskaitymo laikas (" << StudKiekis << " duomenu): " << vidutinisNuskaitymas << " s" << endl;
            cout << "Vidutinis isrusiavimo laikas ("  << StudKiekis << " duomenu): " <<  vidutinisIsrusiavimas << " s" << endl;
            cout << "Vidutinis iskaidymo laikas (" << StudKiekis << " duomenu): " << vidutinisRikiavimas << " s" << endl;
            cout << "Vidutinis isvedimo laikas vargsiukams (" << StudKiekis << " duomenu): " << vidutinisIsvestisVargsiukai << " s" << endl;
            cout << "Vidutinis isvedimo laikas kietiakiams (" << StudKiekis << " duomenu): " << vidutinisIsvestisKietiakiai << " s" << endl;
            cout<< endl;
            studentai.clear(); //isvalom vektoriu
        }


    }
    PasirinktiVeiksma(studentai);
}

void RikiuotiStudentus(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai) {
    //skirtymas i dvi grupes
    for (const Studentas& studentas : studentai) {

        if (studentas.GalutinisB < 5.0 && studentas.GalutinisB > 0.0) {
            vargsiukai.push_back(studentas);
        } else if (studentas.GalutinisB >= 5 && studentas.GalutinisB <= 10) {
            kietiakiai.push_back(studentas);
        }
    }

    studentai.clear();
}

void NuskaitytiVisusFailus(vector<Studentas>& studentai) {
    const vector<int> studentCounts = {1000, 10000, 100000, 1000000};

    for (int StudKiekis : studentCounts) {
        string FailoPav = to_string(StudKiekis) + ".txt";
        NuskaitytiDuomenis(FailoPav, studentai);
    }
}

void NuskaitytiDuomenis(const string& FailoPav, vector<Studentas>& studentai) {

    ifstream inFile(FailoPav);

    if (inFile.is_open()) {
        string line;
        bool praleisti = true; // Pradeti praleisti eilutes

        while (getline(inFile, line)) {
            if (praleisti) {
                praleisti = false; // daugiau nepraleidzia eiluciu
                continue; // Praleisti sia eilute ir eiti toliau
            }
            istringstream iss(line); // Tai yra "input string stream" klasė, kuri leidžia jums skaityti duomenis iš teksto eilutės kaip iš tekstinio srauto. Ši klasė yra naudinga, kai turite tekstinę eilutę, kurią norite išskaidyti į atskirus duomenis, pvz., skaičius arba žodžius.
            Studentas studentas;
            iss >> studentas.Vardas >> studentas.Pavarde >> studentas.GalutinisB; //nuskaito viska ir prideda studentai vektoriu
            studentai.push_back(studentas);
           // cout << line << endl;
        }

        inFile.close(); //baigus skaityti uzdaro faila
    } else {
        cout << "Nepavyko atidaryti failo." << endl;
    }
   /* cout << "Contents of studentai vector after reading the file:" << endl;
    for (const Studentas& studentas : studentai) {
        cout << "Vardas: " << studentas.Vardas << ", Pavarde: " << studentas.Pavarde << ", GalutinisB: " << studentas.GalutinisB << endl;
    }*/

}

void IsvestiDuomenisIpagrFaila(const vector<Studentas>& studentai, const string& FailoPav) {
    auto startIsvedimas = high_resolution_clock::now();

    ofstream outFile(FailoPav);

    if (outFile.is_open()) {
        const int vardasWidth = 30;
        const int pavardeWidth = 30;
        const int galutinisWidth = 25;

        outFile << left << setw(vardasWidth) << "Vardas" <<  setw(pavardeWidth) << "Pavarde" ;
        outFile << setw(galutinisWidth) << "Galutinis (Vid)" <<endl;

        for (const Studentas& studentas : studentai) {
            outFile << left << setw(vardasWidth) << studentas.Vardas <<  setw(pavardeWidth) << studentas.Pavarde ;
            outFile << setw(galutinisWidth) << std::fixed << setprecision(2) << studentas.GalutinisB << endl;
        }

        outFile.close(); // Close the file
        cout << "Duomenys isvesti i faila: " << FailoPav << endl;


    } else {
        cout << "Neisejo atidaryti failo: " << FailoPav << endl;
    }
    auto stopIsvedimas = high_resolution_clock::now();
    auto ISvedimoLaikas =duration_cast<std::chrono::milliseconds>(stopIsvedimas - startIsvedimas).count() / 1000.0;
    cout << "Isvedimas uztruko"  << ISvedimoLaikas << " s" << endl;
    cout << endl;
}

void IsvestiDuomenis(const vector<Studentas>& studentai, const string& FailoPav) {
    ofstream outFile(FailoPav);

    if (outFile.is_open()) {
        const int vardasWidth = 30;
        const int pavardeWidth = 30;
        const int galutinisWidth = 20;

        outFile << left << setw(vardasWidth) << "Vardas" <<  setw(pavardeWidth) << "Pavarde" ;
        outFile << setw(galutinisWidth) << "Galutinis (Vid)" <<endl;

        for (const Studentas& studentas : studentai) {
            outFile << left << setw(vardasWidth) << studentas.Vardas <<  setw(pavardeWidth) << studentas.Pavarde ;
            outFile << setw(galutinisWidth) << fixed << setprecision(2) << studentas.GalutinisB << endl;
        }

        outFile.close();
    } else {
        cout << "Nepavyko atidaryti failo:  " << FailoPav << endl;
    }
}

void MatuotiLaika(high_resolution_clock::time_point start, high_resolution_clock::time_point stop, const char* veiksmas) {

    auto duration = duration_cast<milliseconds>(stop - start);
    double seconds = duration.count() / 10000.0;

    cout << veiksmas << " uztruko: " << fixed << setprecision(3) << seconds << " s" << endl;
}

void Generavimas(vector<Studentas>& studentai) {

    Studentas studentas;
    const vector<int> studentCounts = {1000,/* 10000, 100000, 1000000, 10000000*/};

    for (int StudKiekis : studentCounts) {
        auto start = high_resolution_clock::now();

        for (int i = 1; i <= StudKiekis; ++i) {
            Studentas studentas;
            studentas.Vardas = "Vardas" + to_string(i);
            studentas.Pavarde = "Pavarde" + to_string(i);

    for (int j = 1; j <= 5; ++j) {
            int nd_pazymys = rand() % 10 + 1;
            studentas.ND.push_back(nd_pazymys);
        }
        studentas.Egzas = rand() % 11;
        studentas.GalutinisB = GalutinisBalas(studentas);
        studentai.push_back(studentas);  // kiekvienas sugeneruotas studentas perduodamas vektoriui studentai, kur sis vektorius yra oerduodamas kaip funkcijos parametras
        }

        string FailoPav = to_string(StudKiekis) + ".txt";
        auto stop = high_resolution_clock::now();
        cout << StudKiekis << " studentu" << endl;
        MatuotiLaika(start, stop, "Duomenu generavimas");
        IsvestiDuomenisIpagrFaila(studentai, FailoPav);

        studentai.clear();
    }
}

bool ArMatuotiLaika() {

    char atsakymas;
    cout << "Ar norite matuoti laika (t/n)? ";
    cin >> atsakymas;
    return (atsakymas == 't' || atsakymas == 'T');
}

void RikiavimoMeniu(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai, int Pasirinkimas, int Tvarka) {

   if (Pasirinkimas == 1 && Tvarka == 1) {
        sort(studentai.begin(), studentai.end(), CompareByVardas);
        sort(vargsiukai.begin(), vargsiukai.end(), CompareByVardas);
        sort(kietiakiai.begin(), kietiakiai.end(), CompareByVardas);
    }
    else if (Pasirinkimas == 1 && Tvarka == 2) {
        sort(studentai.begin(), studentai.end(), CompareByVardas1);
        sort(vargsiukai.begin(), vargsiukai.end(), CompareByVardas1);
        sort(kietiakiai.begin(), kietiakiai.end(), CompareByVardas1);
    }
    else if (Pasirinkimas == 2 && Tvarka == 1) {
        sort(studentai.begin(), studentai.end(), CompareByPavarde);
        sort(vargsiukai.begin(), vargsiukai.end(), CompareByPavarde);
        sort(kietiakiai.begin(), kietiakiai.end(), CompareByPavarde);
    }
    else if (Pasirinkimas == 2 && Tvarka == 2) {
        sort(studentai.begin(), studentai.end(), CompareByPavarde1);
        sort(vargsiukai.begin(), vargsiukai.end(), CompareByPavarde1);
        sort(kietiakiai.begin(), kietiakiai.end(), CompareByPavarde1);
    }
    else if (Pasirinkimas == 3 && Tvarka == 1) {
        sort(studentai.begin(), studentai.end(), CompareByBalas);
        sort(vargsiukai.begin(), vargsiukai.end(), CompareByBalas);
        sort(kietiakiai.begin(), kietiakiai.end(), CompareByBalas);
    }
    else if (Pasirinkimas == 3 && Tvarka == 2) {
        sort(studentai.begin(), studentai.end(), CompareByBalas1);
        sort(vargsiukai.begin(), vargsiukai.end(), CompareByBalas1);
        sort(kietiakiai.begin(), kietiakiai.end(), CompareByBalas1);
    }
}
