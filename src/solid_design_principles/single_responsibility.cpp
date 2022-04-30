#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "single_responsibility.h"

//  Adds an entry in the journal object
void Journal::addEntry(string text) {
    jourVec.push_back(text);
}

//  Gets the entry at a particular index
string Journal::getEntry(uint32_t idx) const {
    string str = "";
    if (idx <= getNumEntries()) {
        str = jourVec[idx];
    }
    return str;
}

// Display the journal entries
void Journal::displayEntries() const {
    cout << "---\n";
    cout << "Journal content:\n";
    for (auto i = 0; i< getNumEntries(); ++i) {
        cout << (i+1) << ": " << jourVec[i] << "\n";
    }
    cout << "---\n";
}

//  Fetches the number of entries stored so far
uint32_t Journal::getNumEntries() const {
    return jourVec.size();
}

//  Get the name of the journal
string Journal::getJournalName() const {
    return jourName;
}

//  Constructor Journal
Journal::Journal(string name) {
    jourName = name;
}

//  Destructor
Journal::~Journal() {
    jourVec.clear();
    jourName = "INVALID";
}

//  Persistent storage part: constructor override for Journal class
template<>
Persistent<Journal>::Persistent(const Journal& journal, const string& filepath, const e_mode& mode) {
    fstream file;
    uint32_t numEntries;
    //  Open the file for whatever
    file.open(filepath, mapMode[mode]);
    file << journal.getJournalName() << "\n";
    //  Get the num of entries
    numEntries = journal.getNumEntries();
    //  Push the entries to the file
    for (auto i = 0; i < numEntries; ++i) {
        file << journal.getEntry(i) << "\n";
    }
    //  Close the file
    file.close();
}