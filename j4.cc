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



int twelveHours() {
    int result = 0;
    for (int i = 1; i <= 12; i++) {
        for (int j = 0; j < 60; j++) {
            int first = i / 10;
            int second = i % 10;
            int third = j / 10;
            int fourth = j % 10;
            if (first == 0 && third - second == fourth - third) {
                    result++;
                }
            else if (first != 0 && second - first == third - second && third - second == fourth - third) {
                result++;
            }
        }
    }
    return result;
}

int givenTime(const int hour, const int min) {
    int result = 0;
    const int firstHour = 12;
    int firstMin = 59;
    if (hour == 0) {
        firstMin = min;
    }
    for (int j = 0; j <= firstMin; j++) {
        int first = firstHour / 10;
        int second = firstHour % 10;
        int third = j / 10;
        int fourth = j % 10;
        if (second - first == third - second && third - second == fourth - third) {
            result++;
        }
    }
    if (hour != 0) {
        for (int i = 1; i < hour; i++) {
            for (int j = 0; j < 60; j++) {
                int first = i / 10;
                int second = i % 10;
                int third = j / 10;
                int fourth = j % 10;
                if (first == 0 && third - second == fourth - third) {
                    result++;
                }
                else if (first != 0 && second - first == third - second && third - second == fourth - third) {
                    result++;
                }
            }
        }
        for (int j = 0; j <= min; j++) {
                int first = hour / 10;
                int second = hour % 10;
                int third = j / 10;
                int fourth = j % 10;
                if (first == 0 && third - second == fourth - third) {
                    result++;
                }
                else if (first != 0 && second - first == third - second && third - second == fourth - third) {
                    result++;
                }
            }
    }
    return result;
}

int main(int argc, char *argv[]){
    int a;
    string text;
    if (argc > 1) {
        std::string fileName = argv[1];
        std::fstream file;
        file.open(fileName, std::ios::in);
        if (!file) cout << "Can't open input file!";
        while(getline(file, text)) {
            a = stoi(text);
        }
    }
    else {
        cin >> a;
    }
    int hours = a / 60;
    int minutes = a % 60;
    int twelve = hours / 12;
    hours = hours % 12;
    cout << twelve * twelveHours() + givenTime(hours, minutes) << endl;
}
