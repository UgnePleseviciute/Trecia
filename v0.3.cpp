 /*   #include "Stu.h"
    #include "Faprasai.h"

    void Laikai(list<Studentas>& studentu){

    vector<Studentas> studentai;

    double sumaa;

    list<Studentas> vargsiuku;
    list<Studentas> kietiaku;
    int Pasirinkimass, Tvarkaa;

        cout << "Listu" << endl;
        cout<<endl;

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

        list<int> studentCounts = {1000, 10000, 100000, 1000000/*, 10000000};


/*      char generavimaas;
        cout << "ar norite generuoti failus [t/n]: " << endl;
        cin >> generavimaas;

    if (generavimaas == 't' || generavimaas == 'T') {
        GeneravimasListu(studentu);
    }

        for (int StudKiekis : studentCounts) {
                cout << "Studentu kiekis: " << StudKiekis << " duomenu" << endl;

                double matavimoLaikaiNuskaitymass[3] = {0};
                double matavimoLaikaiRikiavimass[3] = {0};
                double matavimoLaikaiIsvestisVargsiukaii[3] = {0};
                double matavimoLaikaiIsvestisKietiakiaii[3] = {0};
                double matavimoLaikaiIsrusiavimuii[3] = {0};
                for (int i = 0; i < 3; ++i) {

    //----------------------------------------------------------------------------------------------------------------------------------------------------
                    auto startNuskaitymass = high_resolution_clock::now();

                    string FailoPava = to_string(StudKiekis) +"L_"+  ".txt";
                    NuskaitytiDuomenisListo(FailoPava, studentu);

                    auto stopNuskaitymass = high_resolution_clock::now();
                    auto nuskaitymoLaikass = duration_cast<milliseconds>(stopNuskaitymass - startNuskaitymass).count() / 1000.0;
                    matavimoLaikaiNuskaitymass[i] = nuskaitymoLaikass;

                    for (Studentas& studentas : studentu) {
                        double galutinisB = CalculateGalutinisBlISTO(studentas);
                        studentas.GalutinisB = galutinisB;
                      //  cout<< galutinisB << endl;
                    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------
                    auto startIsrusiavimass = high_resolution_clock::now();

                    RikiavimoMeniuListo(studentu,vargsiuku, kietiaku, Pasirinkimass, Tvarkaa);

                    auto stopIsrusiavimass = high_resolution_clock::now();
                    auto IsrusiavimoLaikas = duration_cast<milliseconds>(stopIsrusiavimass - startIsrusiavimass).count() / 1000.0;
                    matavimoLaikaiIsrusiavimuii[i] = IsrusiavimoLaikas;

    //----------------------------------------------------------------------------------------------------------------------------------------------------
                    auto startRikiavimass = high_resolution_clock::now();

                    RikiuotiStudentuss(studentu, vargsiuku, kietiaku);

                    auto stopRikiavimass = high_resolution_clock::now();
                    auto rikiavimoLaikas = duration_cast<milliseconds>(stopRikiavimass - startRikiavimass).count() / 1000.0;
                    matavimoLaikaiRikiavimass[i] = rikiavimoLaikas;

    //----------------------------------------------------------------------------------------------------------------------------------------------------

        auto startIsvestisVargsiukaii = high_resolution_clock::now();
        IsvestiDuomenisListo(vargsiuku, "vargsiukai_" + to_string(vargsiuku.size()) + "_L_" + to_string(StudKiekis));
        vargsiuku.clear();
        auto stopIsvestisVargsiukaii = high_resolution_clock::now();
                    auto isvestiesLaikasVargsiukaii = duration_cast<milliseconds>(stopIsvestisVargsiukaii - startIsvestisVargsiukaii).count() / 1000.0;
                    matavimoLaikaiIsvestisVargsiukaii[i] = isvestiesLaikasVargsiukaii;

    //----------------------------------------------------------------------------------------------------------------------------------------------------

                    auto startIsvestisKietiakiaii = high_resolution_clock::now();

                    IsvestiDuomenisListo(kietiaku, "kietiakiai_" + to_string(kietiaku.size()) + "_L_" +to_string(StudKiekis));
                    kietiaku.clear();

                    auto stopIsvestisKietiakiaii = high_resolution_clock::now();
                    auto isvestiesLaikasKietiakiaii = duration_cast<milliseconds>(stopIsvestisKietiakiaii - startIsvestisKietiakiaii).count( ) / 1000.0;
                    matavimoLaikaiIsvestisKietiakiaii[i] = isvestiesLaikasKietiakiaii;

    //----------------------------------------------------------------------------------------------------------------------------------------------------
                }

                double vidutinisNuskaitymass = (matavimoLaikaiNuskaitymass[0] + matavimoLaikaiNuskaitymass[1] + matavimoLaikaiNuskaitymass[2]) / 3;
                double vidutinisRikiavimass = (matavimoLaikaiRikiavimass[0] + matavimoLaikaiRikiavimass[1] + matavimoLaikaiRikiavimass[2]) / 3;
                double vidutinisIsvestisVargsiukaii = (matavimoLaikaiIsvestisVargsiukaii[0] + matavimoLaikaiIsvestisVargsiukaii[1] + matavimoLaikaiIsvestisVargsiukaii[2]) / 3;
                double vidutinisIsvestisKietiakiaii = (matavimoLaikaiIsvestisKietiakiaii[0] + matavimoLaikaiIsvestisKietiakiaii[1] + matavimoLaikaiIsvestisKietiakiaii[2]) / 3;
                double vidutinisIsrusiavimass = (matavimoLaikaiIsrusiavimuii[0] + matavimoLaikaiIsrusiavimuii[1] + matavimoLaikaiIsrusiavimuii[2]) / 3;

              //  sumaa = vidutinisIsrusiavimass + vidutinisIsvestisKietiakiaii + vidutinisIsvestisVargsiukaii + vidutinisNuskaitymass + vidutinisRikiavimass;


                cout << "Vidutinis nuskaitymo laikas (" << StudKiekis << " duomenu): " << vidutinisNuskaitymass << " s" << endl;
                cout << "Vidutinis isrusiavimo laikas ("  << StudKiekis << " duomenu): " <<  vidutinisIsrusiavimass << " s" << endl;
                cout << "Vidutinis iskaidymo laikas (" << StudKiekis << " duomenu): " << vidutinisRikiavimass << " s" << endl;
                cout << "Vidutinis isvedimo laikas vargsiukams (" << StudKiekis << " duomenu): " << vidutinisIsvestisVargsiukaii << " s" << endl;
                cout << "Vidutinis isvedimo laikas kietiakiams (" << StudKiekis << " duomenu): " << vidutinisIsvestisKietiakiaii << " s" << endl;
               // cout<< "bendra suma: " << sumaa << endl;;
                cout<< endl;
                studentu.clear(); //isvalom lista
            }
            PasirinktiVeiksma(studentai);

    }

    double CalculateGalutinisBlISTO(const Studentas& studentas) {
        int totalHomework = 0;
        for (int nd : studentas.ND) {
            totalHomework += nd;
        }

        return 0.4 * static_cast<double>(totalHomework) / studentas.ND.size() + 0.6 * studentas.Egzas;
    }

    void NuskaitytiVisusFailusListo(list<Studentas>& studentu) {
        const list<int> studentCounts = {1000, 10000, 100000, 1000000, 10000000};

        for (int StudKiekis : studentCounts) {
            string FailoPava = to_string(StudKiekis) + ".txt";
            NuskaitytiDuomenisListo(FailoPava, studentu); // Call the modified function with a list parameter
        }
    }


    void GeneravimasListu(list<Studentas>& studentu) {
            double totalExecutionTime = 0.0;

            const list<int> studentCounts = {1000, 10000, 100000, 1000000/*, 10000000*};

 /*           for (int StudKiekis : studentCounts) {

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

    auto startIsvedimas = high_resolution_clock::now();

    ofstream outFile(FailoPava);

    if (outFile.is_open()) {
        const int vardasWidth = 30;
        const int pavardeWidth = 30;
        const int nd_pazymysWidth = 8; // Adjust the width as needed
        const int egzasWidth = 8; // Width for the "Egz." column

        outFile << left << setw(vardasWidth) << "Vardas" << setw(pavardeWidth) << "Pavarde";
        for (int i = 1; i <= 5; ++i) {
            outFile << "ND" << i << setw(nd_pazymysWidth);
        }
        outFile << "Egz." << endl;

        for (const Studentas& studentas : studentu) { // Loop through the list studentu
            outFile << left << setw(vardasWidth) << studentas.Vardas << setw(pavardeWidth) << studentas.Pavarde;

            // Print up to 5 ND grades
            for (int i = 0; i < 5; i++) {
                if (i < studentas.ND.size()) {
                    outFile << setw(nd_pazymysWidth) << fixed << setprecision(2) << studentas.ND[i];
                } else {
                    outFile << setw(nd_pazymysWidth) << " ";
                }
            }

            outFile << setw(egzasWidth) << fixed << setprecision(2) << studentas.Egzas << endl;
        }

        outFile << endl;

        outFile.close();
    } else {
        cout << "Nepavyko atidaryti failo: " << FailoPava << endl;
    }

    auto stopIsvedimas = high_resolution_clock::now();
    auto ISvedimoLaikas = duration_cast<std::chrono::milliseconds>(stopIsvedimas - startIsvedimas).count() / 1000.0;
    cout << "Išvedimas užtruko " << ISvedimoLaikas << " s" << endl;
    cout << endl;

        studentu.clear();  // Isvalo saras
        }
    }


    void NuskaitytiDuomenisListo(const string& FailoPava, std::list<Studentas>& studentu) {
        int temp;
        ifstream fileRead;
        string buff;
        try {
            fileRead.open(FailoPava); // Use the provided file name

            if (!fileRead.is_open()) {
                throw invalid_argument("Failas '" + FailoPava + "' neegzistuoja arba negali būti atidarytas!");
            }

            if (fileRead.is_open()) {
                getline(fileRead >> ws, buff);

                // Calculate the number of "ND" columns
                int pazymiu_sk = countWordsInString(buff) - 2; // Assuming "Vardas" and "Pavarde"

                while (true) {
                    Studentas student; // Create a new Studentas object
                    if (!(fileRead >> student.Vardas)) {
                        break;
                    }
                    int i;
                    fileRead >> student.Pavarde;
                    for ( i = 0; i < pazymiu_sk; i++) {
                        if (!(fileRead >> temp)) {
                            cout << "Klaida nuskaitant pažymį " << i + 1 << " studento " << student.Vardas << " " << student.Pavarde << endl;
                            break;
                        }
                        student.ND.push_back(temp);
                    }

                    fileRead >> student.Egzas;
                    studentu.push_back(student); // Add the student to the list
       // cout << "Read Vardas: " << student.Vardas << " Pavarde: " << student.Pavarde << i +1  << temp << endl;

                }
            } else {
                cout << "Klaida atidarant failą!" << endl;
            }
            fileRead.close();
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    void RikiavimoMeniuListo(list<Studentas>& studentu, list<Studentas>& vargsiuku, list<Studentas>& kietiaku, int Pasirinkimas, int Tvarka) {
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


    void RikiuotiStudentuss(list<Studentas>& studentu, list<Studentas>& vargsiuku, list<Studentas>& kietiaku) {
        for (list<Studentas>::iterator it = studentu.begin(); it != studentu.end();) { //An Iterator is an object that can be used to loop through collections, like ArrayList and HashSet.
            list<Studentas>::iterator current = it++;//In essence, this line of code is creating a new iterator current that initially points to the same element as it, and then it increments it. This is commonly used to keep track of the previous element while iterating through a container so that you can compare or perform operations on consecutive elements. For example, you might use current to access the current element and it to access the next element, or vice versa.
            if (current->GalutinisB < 5.0 && current->GalutinisB > 0.0) {
                vargsiuku.push_back(*current);
                studentu.erase(current);
            } else if (current->GalutinisB >= 5 && current->GalutinisB <= 10) {
                kietiaku.push_back(*current);
                studentu.erase(current);
            }
        }
    }


void IsvestiDuomenisListo(const list<Studentas>& studentu, const string& FailoPava) {
    ofstream outFile(FailoPava);

    if (outFile.is_open()) {
        const int vardasWidth = 30;
        const int pavardeWidth = 30;
        const int galutinisWidth = 20;

        outFile << left << setw(10) << "Adresas" << setw(vardasWidth) << "Vardas" <<  setw(pavardeWidth) << "Pavarde" ;
        outFile << setw(galutinisWidth) << "Galutinis (Vid)" << endl;

        for (const Studentas& studentas : studentu) {
            outFile << left << setw(vardasWidth) << studentas.Vardas <<  setw(pavardeWidth) << studentas.Pavarde ;
            outFile << setw(galutinisWidth) << fixed << setprecision(2) << studentas.GalutinisB << endl;
        }

        outFile.close();
    } else {
        cout << "Nepavyko atidaryti failo:  " << FailoPava << endl;
    }
}



*/


