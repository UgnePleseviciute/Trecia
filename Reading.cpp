#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "stu.h"

unsigned int countWordsInString(const std::string& str) {
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void read_from_file(std::vector<Studentas>& mok, int* pazymiu_sk) {
    int student_counter = 0;
    int temp;
    std::ifstream fileRead;
    std::string buff;
    std::string failoPavadinimas;
    std::cout << "Iveskite failo pavadinima: ";
    std::cin >> failoPavadinimas;

    try {
        fileRead.open(failoPavadinimas); // atidaromas failas

        if (!fileRead.is_open()) {
            throw std::invalid_argument("Failas '" + failoPavadinimas + "' neegzistuoja arba negali buti atidarytas!");
        }

        if (fileRead.is_open()) {
            fileRead >> buff;
            *pazymiu_sk = countWordsInString(buff) - 3;

            while (true) {
                mok.resize(mok.size() + 1);
                fileRead >> buff;
                mok.at(student_counter).setVardas(buff);

                if (fileRead.eof()) { break; }

                fileRead >> buff;
                mok.at(student_counter).setPavarde(buff);

                for (int i = 0; i < *pazymiu_sk; i++) {
                    if (!(fileRead >> temp)) {
                        std::cout << "Klaida nuskaitant pazymi " << i + 1 << " studento " << mok.at(student_counter).getVardas() << " " << mok.at(student_counter).getPavarde() << std::endl;
                        mok.pop_back();
                        break;
                    }
                    mok.at(student_counter).addND(temp);
                }

                fileRead >> temp;
                mok.at(student_counter).setEgzas(temp);
                student_counter++;
            }
        } else {
            std::cout << "Klaida atidarant faila!" << std::endl;
        }
        fileRead.close();
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

float count_vidurkis(const std::vector<int>& pazymiai) {
    int suma = 0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return static_cast<float>(suma) / pazymiai.size();
}

float count_median(const std::vector<int>& pazymiai) {
    std::vector<int> sorted_pazymiai = pazymiai;
    std::sort(sorted_pazymiai.begin(), sorted_pazymiai.end());

    int n = sorted_pazymiai.size();
    if (n % 2 == 0) {
        int middle1 = sorted_pazymiai[n / 2 - 1];
        int middle2 = sorted_pazymiai[n / 2];
        return static_cast<float>(middle1 + middle2) / 2.0;
    } else {
        return static_cast<float>(sorted_pazymiai[n / 2]);
    }
}

void IsvedimasLenteles(const std::vector<Studentas>& studentai) {
    std::cout << std::left << std::setw(12) << "Vardas" << " | " << std::setw(12) << "Pavarde" << " | " << std::setw(18) << "Galutinis (vid)" << " | " << std::setw(18) << "Galutinis (med)" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;

    for (const Studentas& student : studentai) {
        float galutinis_vid = 0.4 * count_vidurkis(student.getND()) + 0.6 * student.getEgzas();
        float galutinis_med = 0.4 * count_median(student.getND()) + 0.6 * student.getEgzas();

        std::cout << std::setw(12) << std::left << student.getVardas() << " | " << std::setw(12) << student.getPavarde() << " | " << std::setw(18) << std::fixed << std::setprecision(2) << galutinis_vid << " | " << std::setw(18) << std::fixed << std::setprecision(2) << galutinis_med << std::endl;
    }
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
