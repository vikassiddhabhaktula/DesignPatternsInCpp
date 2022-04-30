#ifndef SINGLE_RESPONSIBILITY_H
#define SINGLE_RESPONSIBILITY_H

using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

//  Class to create & maintain a Journal
class Journal {
    vector<string> jourVec;
    string jourName;

    public:
        void addEntry(string text);
        string getEntry(uint32_t idx) const;
        void displayEntries() const;
        uint32_t getNumEntries() const;
        string getJournalName() const;
        Journal(string name);
        ~Journal();
};

enum class enumFileMode {RD, WR, APP, RD_WR};

//  Class to save the content to storage
template<typename T>
class Persistent {
    unordered_map<enumFileMode, ios_base::openmode> mapMode = {
            {enumFileMode::RD, ios::in}, {enumFileMode::WR, ios::out},
            {enumFileMode::APP, ios::app}, {enumFileMode::RD_WR, ios::in | ios::out}};

    public:
        Persistent(const T& obj, const string& filePath, const enumFileMode& mode = enumFileMode::WR);
};

void driverSingleResponsibility();

#endif