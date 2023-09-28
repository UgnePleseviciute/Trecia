#include "stu.h"
unsigned int countWordsInString(const string& str) {
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

void read_from_file(vector<Studentas>& mok, int* pazymiu_sk) {
    int student_counter = 0;
    int temp;
    ifstream fileRead;
    string buff;
    fileRead.open("kursiokai.txt");
    if (fileRead.is_open()) {
        getline(fileRead >> ws, buff);
        *pazymiu_sk = countWordsInString(buff) - 3;
        while (true) {
            mok.resize(mok.size() + 1);
            fileRead >> mok.at(student_counter).Vardas;
            if (fileRead.eof()) { mok.pop_back(); break; }
            fileRead >> mok.at(student_counter).Pavarde;
            for (int i = 0; i < *pazymiu_sk; i++) {
                fileRead >> temp;
                mok.at(student_counter).ND.push_back(temp);
            }
            fileRead >> mok.at(student_counter).Egzas;
            student_counter++;
        }
    }
    else { cout << "Klaida atidarant failą!" << endl; }
    fileRead.close();
}





void IsvedimasLenteles(const vector<Studentas>& studentai) {
    cout << setw(15) << left << "Vardas" << setw(15) << "Pavarde";

    for (int i = 1; i <= studentai[0].ND.size(); i++) {
        cout << setw(6) << right << "ND" << i;
    }

    cout << setw(6) << right << "Egzaminas" << endl;

    for (const Studentas& student : studentai) {
        cout << setw(15) << left << student.Vardas << setw(15) << student.Pavarde;
        for (int pazymys : student.ND) {
            cout << setw(6) << right << pazymys;
        }
        cout << setw(6) << right << student.Egzas << endl;
    }
}
