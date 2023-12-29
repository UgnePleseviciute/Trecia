#include "Stu.h"
#include "funkcijuAprasai.h"

#include "zmogus.h"

int main() {

    /*Studentas studentas;
    cin >> studentas;
    Studentas studentas2(studentas);
    Studentas studentas3=studentas;
    cout << studentas << endl;
    cout << studentas2 << endl;
    cout << studentas3 << endl;*/

    vector  <Studentas> studentai;
    Studentas studentas;
    studentas.PasirinktiVeiksma(studentai);

    return 0;
}
