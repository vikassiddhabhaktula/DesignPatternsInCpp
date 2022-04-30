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

enum class FileMode {RD, WR, APP, RD_WR};
static unordered_map<FileMode, const ios_base::openmode> mapMode = {
        {FileMode::RD, ios::in}, {FileMode::WR, ios::out},
        {FileMode::APP, ios::app}, {FileMode::RD_WR, ios::in | ios::out}};

//  Class to save the content to storage
template<typename T>
class Persistent {
    public:
        Persistent(const T& obj, const string& filePath, const FileMode& mode = FileMode::WR);
};

void driverSingleResponsibility();

#endif