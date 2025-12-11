// Week_15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>   

using namespace std;

// -------------------------------------------------------------
// CLASS: Represents ONE row/entry in the WDI dataset
// -------------------------------------------------------------
class WDIEntry {
public:
    string country;
    string indicator;
    string sex;
    string ageGroup;
    float value2020;

    // Constructor
    WDIEntry(string c, string ind, string s, string age, float v2020) {
        country = c;
        indicator = ind;
        sex = s;
        ageGroup = age;
        value2020 = v2020;
    }

    // Display the entry in readable format
    void display() const {
        cout << "Country: " << country << endl;
        cout << "Indicator: " << indicator << endl;
        cout << "Sex: " << sex << endl;
        cout << "Age Group: " << ageGroup << endl;
        cout << "Value (2020): " << value2020 << endl;
        cout << "-------------------------------------\n";
    }
};

// -------------------------------------------------------------
// FUNCTION: Split CSV line into tokens safely
// -------------------------------------------------------------
vector<string> splitCSV(const string& line) {
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    return tokens;
}

// -------------------------------------------------------------
// MAIN PROGRAM
// -------------------------------------------------------------
int main() {
    ifstream file("world_development_indicators.csv");

    if (!file.is_open()) {
        cout << "Error: Could not open dataset file.\n";
        return 1;
    }

    vector<WDIEntry> entries;
    string line;

    // Skip the header row
    getline(file, line);

    int count = 0;

    // Load at least 10 rows from the dataset
    while (getline(file, line) && count < 10) {
        vector<string> cols = splitCSV(line);

        if (cols.size() < 70) continue;  // Ensure row has enough columns

        string country = cols[3];          // REF_AREA_LABEL
        string indicator = cols[5];        // INDICATOR_LABEL
        string sex = cols[7];              // SEX_LABEL
        string ageGroup = cols[9];         // AGE_LABEL

        float value2020 = 0.0f;
        try {
            value2020 = stof(cols[60]);    // Column for year 2020
        }
        catch (...) {
            value2020 = -1; // Missing or invalid data
        }

        entries.emplace_back(country, indicator, sex, ageGroup, value2020);
        count++;
    }

    file.close();

    // ---------------------------------------------------------
    // DISPLAY THE LOADED RESULTS
    // ---------------------------------------------------------
    cout << "Loaded " << entries.size() << " entries from dataset:\n";
    cout << "=====================================\n";

    for (const WDIEntry& e : entries) {
        e.display();
    }

    return 0;
}
