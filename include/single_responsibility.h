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

typedef enum {RD = 0, WR, APP, RD_WR} e_mode;

//  Class to save the content to storage
template<typename T>
class Persistent {
    unordered_map<e_mode, ios_base::openmode> mapMode = {
            {RD, ios::in}, {WR, ios::out},
            {APP, ios::app}, {RD_WR, ios::in | ios::out}};

    public:
        Persistent(const T& obj, const string& filePath, const e_mode& mode = WR);
};

#endif