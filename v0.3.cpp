#include "Stu.h"
#include "Faprasai.h"

void Laikai(list<Studentas>& studentu){


int Pasirinkimass, Tvarkaa;
std::list<Studentas> vargsiuku;
std::list<Studentas> kietiaku;

    cout << "pasirinkite kaip duomenys bus isrusiuoti \n";
    cout << "1 - Pagal varda \n";
    cout << "2 - Pagal pavarde \n";
    cout << "3 - Pagal pazymius \n";
    cin >> Pasirinkimass;
    if (Pasirinkimass != 1 && Pasirinkimass != 2 && Pasirinkimass != 3)
{
        cout << "Netinkamas pasirinkimas, rūšiuosime pagal vardą ";
        Pasirinkimass = 1;
}

    cout << "Pasirinkite kokia tvarka matuosime \n";
    cout << "1 - Didejimo \n";
    cout << "2 - Mazejimo \n";
    cin >> Tvarkaa;
    if (Tvarkaa != 1 && Tvarkaa != 2) {

        cout << "Netinkamas pasirinkimas, rūšiuosime didejimo tvarka ";
        Tvarkaa = 1;
}

    const std::list<int> studentCounts = {1000, 10000/*, 100000/*, 1000000, 10000000*/};

    GeneravimasListu(studentu);

    for (int StudKiekis : studentCounts) {
            cout << "Studentu kiekis: " << StudKiekis << " duomenu" << endl;
            double matavimoLaikaiNuskaitymass[3] = {0};
            double matavimoLaikaiRikiavimass[3] = {0};
            double matavimoLaikaiIsvestisVargsiukaii[3] = {0};
            double matavimoLaikaiIsvestisKietiakiaii[3] = {0};
            double matavimoLaikaiIsrusiavimui[3] = {0};
            for (int i = 0; i < 3; ++i) {

//----------------------------------------------------------------------------------------------------------------------------------------------------
                auto startNuskaitymass = high_resolution_clock::now();

                string FailoPava = to_string(StudKiekis) +"L_"+  ".txt";
                NuskaitytiDuomenisListo(FailoPava, studentu);

                auto stopNuskaitymass = high_resolution_clock::now();
                auto nuskaitymoLaikass = duration_cast<milliseconds>(stopNuskaitymass - startNuskaitymass).count() / 1000.0;
                matavimoLaikaiNuskaitymass[i] = nuskaitymoLaikass;
//----------------------------------------------------------------------------------------------------------------------------------------------------
                auto startIsrusiavimas = high_resolution_clock::now();

                RikiavimoMeniuListo(studentu,vargsiuku, kietiaku, Pasirinkimass, Tvarkaa);

                auto stopIsrusiavimas = high_resolution_clock::now();
                auto IsrusiavimoLaikas = duration_cast<milliseconds>(stopIsrusiavimas - startIsrusiavimas).count() / 1000.0;
                matavimoLaikaiIsrusiavimui[i] = IsrusiavimoLaikas;



}
    }
}



void GeneravimasListu(std::list<Studentas>& studentu) {
        double totalExecutionTime = 0.0;

        const std::list<int> studentCounts = {1000, 10000/*, 100000/*, 1000000, 10000000*/};

        for (int StudKiekis : studentCounts) {

        auto start =  high_resolution_clock::now();

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
                studentu.push_back(studentas);
            }

        string FailoPava = to_string(StudKiekis) +"L_"+  ".txt";
        auto stopGeneravimas = high_resolution_clock::now();
        auto GeneravimoLaikas = duration_cast<std::chrono::milliseconds>(stopGeneravimas - start).count() / 1000.0;
        totalExecutionTime = AddTimeToTotalExecutionTime(totalExecutionTime, start, stopGeneravimas);

        auto startIsvedimas = high_resolution_clock::now();

    std::ofstream outFile(FailoPava);

    if (outFile.is_open()) {
        const int vardasWidth = 30;
        const int pavardeWidth = 30;
        const int galutinisWidth = 25;

        outFile << left << setw(vardasWidth) << "Vardas" <<  setw(pavardeWidth) << "Pavarde" ;
        outFile << setw(galutinisWidth) << "Galutinis (Vid)" << endl;

        for (const Studentas& studentas : studentu) { // Pakeistas sąrašo pavadinimas
            outFile << left << setw(vardasWidth) << studentas.Vardas <<  setw(pavardeWidth) << studentas.Pavarde ;
            outFile << setw(galutinisWidth) << std::fixed << setprecision(2) << studentas.GalutinisB << endl;
        }

        outFile.close(); // Uždaryti failą
        cout << "Duomenys isvesti i faila: " << FailoPava << endl;

    } else {
        cout << "Nepavyko atidaryti failo: " << FailoPava << endl;
    }

    auto stopIsvedimas = high_resolution_clock::now();
    auto ISvedimoLaikas = duration_cast<std::chrono::milliseconds>(stopIsvedimas - startIsvedimas).count() / 1000.0;
    cout << StudKiekis << "L : Generavimas uztruko " << GeneravimoLaikas << " s" << endl;
    cout << "L : Isvedimas uztruko " << ISvedimoLaikas << " s" << endl;
    cout << endl;
    studentu.clear();  // Išvalyti sąrašą
    }
}


void NuskaitytiDuomenisListo(const string& FailoPava, std::list<Studentas>& studentu) { // Pataisytas parametrų tipas


    ifstream inFile(FailoPava);
    const std::list<int> studentCounts = {1000, 10000/*, 100000/*, 1000000, 10000000*/};

    for (int StudKiekis : studentCounts) {
        string FailoPav = to_string(StudKiekis) + "L_" + ".txt"; // Pataisytas failo pavadinimas
    }

    if (inFile.is_open()) {
        string line;
        bool praleisti = true;

        while (getline(inFile, line)) {
            if (praleisti) {
                praleisti = false;
                continue;
            }
            istringstream iss(line);
            Studentas studentas;
            iss >> studentas.Vardas >> studentas.Pavarde >> studentas.GalutinisB;
            studentu.push_back(studentas); // Pataisytas šios eilutės tipas
        }

        inFile.close();
    } else {
        cout << "Nepavyko atidaryti failo." << endl;
    }

}

void RikiavimoMeniuListo(std::list<Studentas>& studentu, std::list<Studentas>& vargsiuku, std::list<Studentas>& kietiaku, int Pasirinkimas, int Tvarka) {
    if (Pasirinkimas == 1 && Tvarka == 1) {
        studentu.sort(CompareByVardas);
        vargsiuku.sort(CompareByVardas);
        kietiaku.sort(CompareByVardas);
    }
    else if (Pasirinkimas == 1 && Tvarka == 2) {
        studentu.sort(CompareByVardas1);
        vargsiuku.sort(CompareByVardas1);
        kietiaku.sort(CompareByVardas1);
    }
    else if (Pasirinkimas == 2 && Tvarka == 1) {
        studentu.sort(CompareByPavarde);
        vargsiuku.sort(CompareByPavarde);
        kietiaku.sort(CompareByPavarde);
    }
    else if (Pasirinkimas == 2 && Tvarka == 2) {
        studentu.sort(CompareByPavarde1);
        vargsiuku.sort(CompareByPavarde1);
        kietiaku.sort(CompareByPavarde1);
    }
    else if (Pasirinkimas == 3 && Tvarka == 1) {
        studentu.sort(CompareByBalas);
        vargsiuku.sort(CompareByBalas);
        kietiaku.sort(CompareByBalas);
    }
    else if (Pasirinkimas == 3 && Tvarka == 2) {
        studentu.sort(CompareByBalas1);
        vargsiuku.sort(CompareByBalas1);
        kietiaku.sort(CompareByBalas1);
    }
}






