#include "stu.h"
#include "Faprasai.h"


unsigned int countWordsInString(const string& str) {
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

void read_from_file(vector<Studentas>& mok, int* pazymiu_sk) {
    int student_counter = 0; // Counter for the students in the file
    int temp;
    ifstream fileRead;
    string buff;
    string failoPavadinimas;
    cout << "Iveskite failo pavadinima: ";
    cin >> failoPavadinimas;

    try {
        fileRead.open(failoPavadinimas);

        if (!fileRead.is_open()) {
            throw invalid_argument("Failas '" + failoPavadinimas + "' neegzistuoja arba negali buti atidarytas!");
        }

        if (fileRead.is_open()) {
            getline(fileRead >> ws, buff);
            *pazymiu_sk = countWordsInString(buff) - 3;
            while (true) {
                mok.resize(mok.size() + 1);
                fileRead >> mok.at(student_counter).Vardas;
                if (fileRead.eof()) { break; }
                fileRead >> mok.at(student_counter).Pavarde;
                for (int i = 0; i < *pazymiu_sk; i++) {
                    if (!(fileRead >> temp)) {
                        cout << "Klaida nuskaitant pazymi " << i + 1 << " studento " << mok.at(student_counter).Vardas << " " << mok.at(student_counter).Pavarde << endl;
                        mok.pop_back();
                        break;
                    }
                    mok.at(student_counter).ND.push_back(temp);
                }
                fileRead >> mok.at(student_counter).Egzas;
                student_counter++;
            }
        } else {
            cout << "Klaida atidarant failą!" << endl;
        }
        fileRead.close();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

float count_vidurkis(const vector<int>& pazymiai) {
    int suma = 0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return static_cast<float>(suma) / pazymiai.size();
}

float count_median(const vector<int>& pazymiai) {
    vector<int> sorted_pazymiai = pazymiai;
    sort(sorted_pazymiai.begin(), sorted_pazymiai.end());

    int n = sorted_pazymiai.size();
    if (n % 2 == 0) {
        int middle1 = sorted_pazymiai[n / 2 - 1];
        int middle2 = sorted_pazymiai[n / 2];
        return static_cast<float>(middle1 + middle2) / 2.0;
    } else {
        return static_cast<float>(sorted_pazymiai[n / 2]);
    }
}

void IsvedimasLenteles(const vector<Studentas>& studentai) {
    cout << left << setw(12) << "Vardas" << " | " << setw(12) << "Pavarde" << " | " << setw(18) << "Galutinis (vid)" << " | " << setw(18) << "Galutinis (med)" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (const Studentas& student : studentai) {
        float galutinis_vid = 0.4 * count_vidurkis(student.ND) + 0.6 * student.Egzas;
        float galutinis_med = 0.4 * count_median(student.ND) + 0.6 * student.Egzas;

        cout << setw(12) << left << student.Vardas << " | " << setw(12) << student.Pavarde << " | " << setw(18) << fixed << setprecision(2) << galutinis_vid << " | " << setw(18) << fixed << setprecision(2) << galutinis_med << endl;
    }
}

bool CompareByVardas(const Studentas& a, const Studentas& b) {
    return a.Vardas < b.Vardas;
}
