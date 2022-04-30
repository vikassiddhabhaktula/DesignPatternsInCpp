// std includes
#include <iostream>
#include <vector>
using namespace std;
// header includes
#include "printer.h"
#include "single_responsibility.h"

int main() {
    cout << "=======================\n";
    cout << "Let's design some code\n";
    cout << "=======================\n";
    /*  Solid design principles
     *  1. Single resposibility:
     *      -   Make sure that the class we design is subject to a single
     *          responsibility. Example, if we are forming a journal of
     *          daily activities, make sure the class just does the journal
     *          management and not the saving to file/ db etc., Keep that
     *          saving as another single responsibility class, that way the
     *          design can scale naturally.
     *  2.  Open but closed:
     *      -   Make sure that the class we create is open for scaling but
     *          closed for any changes in the base class. Instead derive
     *          something out of what is already there and scale it.
     */
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
    return 0;
}