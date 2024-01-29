#include <iostream>
#include <fstream>
//#include <unordered_map>
#include "OptionSelector.h"
#include "Book.h"
#include <boost/algorithm/string.hpp> // best example so far: https://www.geeksforgeeks.org/boostsplit-c-library/
#include <boost/unordered_map.hpp>
using namespace std;

boost::unordered_map<string, Book> handleFile(const char *fileName);

int main() {
    cout << "Hello, bookworm!  Welcome to the Digicert Library!" << endl;

    const char *fileName = "library.txt";
    boost::unordered_map<string, Book> library = handleFile(fileName);
    OptionSelector selector;
    selector.optionSelector(library, fileName);
    return 0;
}

boost::unordered_map<string, Book> handleFile(const char *fileName) {
    ifstream libraryFile(fileName);
    boost::unordered_map<string, Book> library;
    string line;

    if (libraryFile.is_open()) {
        while (getline (libraryFile, line)) {
            // build lines into Book objects
            vector<string> lineSplit;
            boost::split(lineSplit, line, boost::is_any_of("|"));

            Book book;
            book.setId(lineSplit[0]);
            book.setName(lineSplit[1]);
            book.setAuthor(lineSplit[2]);
            book.setIsbn(lineSplit[3]);
            book.setYearPublished(lineSplit[4]);

            library.emplace(book.getId(), book);
            }
        }

        libraryFile.close();

        return library;
    }