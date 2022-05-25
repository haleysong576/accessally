#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::istringstream;
using std::getline;
using std::setw;
using std::right;
using std::left;
using std::getline;

int blood1[8];
int patient1[8];
int blood2[8];
int patient2[8];

int numberOfBlood(int type, int p, int *blood, int *patient) {
    int result = std::min(blood[type], patient[p]);
    blood[type] = blood[type] - result;
    patient[p] = patient[p] - result;
    return result;
}

int main(int argc, char *argv[]){
    string text;
    string line2;
    if (argc > 1) {
        std::string fileName = argv[1];
        std::fstream file;
        file.open(fileName, std::ios::in);
        if (!file) cout << "Can't open input file!";
        else {
            getline(file, text);
            getline(file, line2);
        }

    }
    else {
        std::getline(std::cin, text);
        std::getline(std::cin, line2);
    }
    std::stringstream l;
    l << text;
    for (int i = 0; i < 8; i++) {
        int t;
        l >> t;
        blood1[i] = t;
        blood2[i] = t;
    }
    std::stringstream p;
    p << line2;
    for (int i = 0; i < 8; i++) {
        int t;
        p >> t;
        patient1[i] = t;
        patient2[i] = t;
    }
    
    // There are two possible orders for blood distribution, I will calculate for both and determine ..
    // .. the biggest one.

    //Order number 1
    int total = 0;

    // O-
    total = total + numberOfBlood(0,0, blood1, patient1);
    // O+: O+ then O-
    total = total + numberOfBlood(1,1, blood1, patient1) + numberOfBlood(0,1, blood1, patient1);
    // A-: A- then O-
    total = total + numberOfBlood(2,2, blood1, patient1) + numberOfBlood(0,2, blood1, patient1);
    // B-: B- then O-
    total = total + numberOfBlood(4,4, blood1, patient1) + numberOfBlood(0,4, blood1, patient1);
    // A+: A+ then O+
    total = total + numberOfBlood(3,3, blood1, patient1) + numberOfBlood(1,3, blood1, patient1);
    // B+: B+ then O+
    total = total + numberOfBlood(5,5, blood1, patient1) + numberOfBlood(1,5, blood1, patient1);
    // A+: A- then O-
    total = total + numberOfBlood(2,3, blood1, patient1) + numberOfBlood(0,3, blood1, patient1);
    // B+: B+ then O-
    total = total + numberOfBlood(4,5, blood1, patient1) + numberOfBlood(0,5, blood1, patient1);
    // AB-: AB-, then B-, A-, then O-
    total = total + numberOfBlood(6,6, blood1, patient1) + numberOfBlood(4,6, blood1, patient1) + numberOfBlood(2,6, blood1, patient1) + numberOfBlood(0,6, blood1, patient1);
    // AB-: everything 
    total = total + numberOfBlood(7,7, blood1, patient1) + numberOfBlood(6,7, blood1, patient1) + numberOfBlood(5,7, blood1, patient1) + numberOfBlood(4,7, blood1, patient1) + numberOfBlood(3,7, blood1, patient1) + numberOfBlood(2,7, blood1, patient1) + numberOfBlood(1,7, blood1, patient1) + numberOfBlood(0,7, blood1, patient1);

    //Order number 2
    int total2 = 0;

    // O-
    total2 = total2 + numberOfBlood(0,0, blood2, patient2);
    // O+: O+ then O-
    total2 = total2 + numberOfBlood(1,1, blood2, patient2) + numberOfBlood(0,1, blood2, patient2);
    // A-: A- then O-
    total2 = total2 + numberOfBlood(2,2, blood2, patient2) + numberOfBlood(0,2, blood2, patient2);
    // B-: B- then O-
    total2 = total2 + numberOfBlood(4,4, blood2, patient2) + numberOfBlood(0,4, blood2, patient2);
     // A+: A+ then A-
    total2 = total2 + numberOfBlood(3,3, blood2, patient2) + numberOfBlood(2,3, blood2, patient2);
    // B+: B+ then B-
    total2 = total2 + numberOfBlood(5,5, blood2, patient2) + numberOfBlood(4,5, blood2, patient2);
    // A+: O+ then O-
    total2 = total2 + numberOfBlood(1,3, blood2, patient2) + numberOfBlood(0,3, blood2, patient2);
    // B+: O+ then O-
    total2 = total2 + numberOfBlood(1,5, blood2, patient2) + numberOfBlood(0,5, blood2, patient2);

    // AB-: AB-, then B-, A-, then O-
    total2 = total2 + numberOfBlood(6,6, blood2, patient2) + numberOfBlood(4,6, blood2, patient2) + numberOfBlood(2,6, blood2, patient2) + numberOfBlood(0,6, blood2, patient2);
    // AB-: everything 
    total2 = total2 + numberOfBlood(7,7, blood2, patient2) + numberOfBlood(6,7, blood2, patient2) + numberOfBlood(5,7, blood2, patient2) + numberOfBlood(4,7, blood2, patient2) + numberOfBlood(3,7, blood2, patient2) + numberOfBlood(2,7, blood2, patient2) + numberOfBlood(1,7, blood2, patient2) + numberOfBlood(0,7, blood2, patient2);
    cout << std::max(total, total2) << endl;
}
