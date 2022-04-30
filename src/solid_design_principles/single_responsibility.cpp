#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "single_responsibility.h"
#include "printer.h"

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
Persistent<Journal>::Persistent(const Journal& journal, const string& filepath, const enumFileMode& mode) {
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

//  Driver code to run the test examples
void driverSingleResponsibility() {
    Journal *myDiary = new Journal("myDiary");
    myDiary->addEntry("I have started studying design");
    myDiary->addEntry("I looked for textbooks, but they are all expensive");
    myDiary->addEntry("I found an Udemy course and I am trying to follow it for a while to save money");
    myDiary->addEntry("However, I find the C++ in the course as very advanced");
    myDiary->addEntry("I think I will need a lot of ramp up time to catch up to the instructor");
    myDiary->displayEntries();
    //  Get a particular entry
    dbgVec(myDiary->getEntry(10));
    dbgVec(myDiary->getEntry(2));
    Persistent<Journal> storeJournal(*myDiary, "myDiary.txt");
    delete myDiary;
    Persistent<Journal> storeJournal2(*myDiary, "myDiary2.txt"); 
}