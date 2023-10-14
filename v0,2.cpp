#include "Stu.h"
#include "Faprasai.h"



// Function to write student data to a file
void IsvestiDuomenisIpagrFaila(const std::vector<Studentas>& studentai, const std::string& FailoPav) {
    auto start = std::chrono::high_resolution_clock::now(); // Start measuring data output time
    std::ofstream outFile(FailoPav);

    if (outFile.is_open()) {
        // Specify fixed widths for columns
        const int vardasWidth = 12; // Adjust to your desired width
        const int pavardeWidth = 12; // Adjust to your desired width
        const int galutinisWidth = 20;

        outFile << std::left << std::setw(vardasWidth) << "Vardas" << " | " << std::setw(pavardeWidth) << "Pavarde" << " | ";
        outFile << std::setw(galutinisWidth) << "Galutinis (Vid)" << " |" << std::endl;

        for (const Studentas& studentas : studentai) {
            outFile << std::left << std::setw(vardasWidth) << studentas.Vardas << " | " << std::setw(pavardeWidth) << studentas.Pavarde << " | ";
            outFile << std::setw(galutinisWidth) << std::fixed << std::setprecision(2) << studentas.GalutinisB << " |" << std::endl;
        }

        outFile.close(); // Close the file
        std::cout << "Data written to the file: " << FailoPav << std::endl;
    } else {
        std::cout << "Failed to open the file: " << FailoPav << std::endl;
    }

    auto stop = std::chrono::high_resolution_clock::now(); // Stop measuring data output time
    MatuotiLaika(start, stop, "Data output");
}



void MatuotiLaika(high_resolution_clock::time_point start, high_resolution_clock::time_point stop, const std::string& veiksmas) {
    auto duration = duration_cast<milliseconds>(stop - start);
    double seconds = duration.count() / 10000.0; // Convert milliseconds to seconds

    cout << veiksmas << " uztruko: " << std::fixed << setprecision(3) << seconds << " s" << std::endl;
    cout << std::endl;
}

void Generavimas(std::vector<Studentas>& studentai) {
    Studentas studentas;
    const std::vector<int> studentCounts = {1000, 10000, 100000, 1000000/*, 10000000*/};

    for (int StudKiekis : studentCounts) {
        auto start = std::chrono::high_resolution_clock::now(); // Start measuring data generation time

        for (int i = 1; i <= StudKiekis; ++i) {
            Studentas studentas;
            studentas.Vardas = "Vardas" + std::to_string(i);
            studentas.Pavarde = "Pavarde" + std::to_string(i);

    for (int j = 1; j <= 5; ++j) {
            int nd_pazymys = rand() % 10 + 1;
            studentas.ND.push_back(nd_pazymys);
        }
        studentas.Egzas = rand() % 11;
        studentas.GalutinisB = GalutinisBalas(studentas);
        studentai.push_back(studentas);  // kiekvienas sugeneruotas studentas perduodamas vektoriui studentai, kur sis vektorius yra oerduodamas kaip funkcijos parametras
        }

        // Do the sorting for this student count, if needed
        // Sort studentai vector here using your sorting function (SortStudentData)

        auto stop = std::chrono::high_resolution_clock::now(); // Stop measuring data generation time

        std::string FailoPav = std::to_string(StudKiekis) + ".txt";

        // Output data to a file using IsvestiDuomenisIpagrFaila
        IsvestiDuomenisIpagrFaila(studentai, FailoPav);

        // Clear the vector for the next iteration
        studentai.clear();
    }
}
