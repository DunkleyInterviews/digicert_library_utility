#include <iostream>
#include <fstream>
#include <algorithm>
#include "OptionSelector.h"
#include "Book.h"
#include <cstdio>
#include <boost/unordered_map.hpp>
#include <filesystem>

using std::string;

const string OptionSelector::LIST = "list";
const string OptionSelector::GET = "get";
const string OptionSelector::CREATE = "create";
const string OptionSelector::UPDATE = "update";
const string OptionSelector::DELETE = "delete";
const string OptionSelector::EXIT = "exit";

void OptionSelector::optionSelector(boost::unordered_map<string, Book> library, const char *fileName) {
    printLineBreak();

    std::cout << "Please choose from the following options:" << std::endl;
    std::cout << "To list all available books, input 'list'..." << std::endl;
    std::cout << "To get details on a specific book, input 'get'..." << std::endl;
    std::cout << "To create a new book entry, input 'create'..." << std::endl;
    std::cout << "To update a book entry, input 'update'..." << std::endl;
    std::cout << "To delete a book entry, input 'delete'..." << std::endl;
    std::cout << "To exit the library system, input 'exit'..." << std::endl;

    string selection;
    std::getline(std::cin, selection);

    if (selection == LIST) {
        getList(library, fileName);
    } else if (selection == GET) {
        handleGet(library, fileName);
    } else if (selection == CREATE) {
        handleCreate(library, fileName);
    } else if (selection == UPDATE) {
        handleUpdate(library, fileName);
    } else if (selection == DELETE) {
        handleDelete(library, fileName);
    } else if (selection == EXIT) {
        handleFileUpdate(library, fileName);
        std::cout << "Thank you, come again!" << std::endl;
        return;
    } else {
        std::cout << "INVALID ENTRY: '" + selection + "'" << std::endl;
        optionSelector(library, fileName);
    }
}

void OptionSelector::getList(boost::unordered_map<string, Book> library, const char *fileName) {
    printLineBreak();

    if (library.empty()) {
        std::cout << "There are currently no books in the library! Use the 'create' option to add some!" << std::endl;
    } else {
        std::cout << "Here are the books currently available! Copy an ID and use 'get' in the menu to retrieve additional details..." << std::endl;

        std::for_each(library.begin(), library.end(),
                      [](std::pair<std::string, Book> p) {
                          std::cout << p.first
                                    << " :: "
                                    << p.second.getName()
                                    << std::endl;
                      });
    }

    optionSelector(library, fileName);
}

void OptionSelector::handleGet(boost::unordered_map<string, Book> library, const char *fileName) {
    printLineBreak();

    std::cout << "Please input the ID for the book you would like to see..." << std::endl;

    string id;
    std::getline(std::cin, id);

    Book book;
    try {
        book = library.at(id);

        std::cout << "ID: " << book.getId() << std::endl;
        std::cout << "Name: " << book.getName() << std::endl;
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "ISBN: " << book.getIsbn() << std::endl;
        std::cout << "Year Published: " << book.getYearPublished() << std::endl;

        optionSelector(library, fileName);
    } catch(const std::out_of_range &e) {
        std::cout << "ID not found! Input 'exit' to return to menu or input any key to try again." << std::endl;
        string input;
        std::getline(std::cin, input);

        if (input == EXIT) {
            optionSelector(library, fileName);
        } else {
            handleGet(library, fileName);
        }
    }
}

void OptionSelector::handleCreate(boost::unordered_map<string, Book> library, const char *fileName) {
    printLineBreak();

    Book bookToCreate;
    bookToCreate.setId(Book::generate_uuid());

    std::cout << "Let's add your book!" << std::endl;

    std::cout << "What is the name of the book?" << std::endl;
    string name;
    std::getline(std::cin, name);
    bookToCreate.setName(name);

    std::cout << "Who is the author of the book?" << std::endl;
    string author;
    std::getline(std::cin, author);
    bookToCreate.setAuthor(author);

    std::cout << "What is the ISBN for the book?" << std::endl;
    string isbn;
    std::getline(std::cin, isbn);
    bookToCreate.setIsbn(isbn);

    std::cout << "What year was the book published?" << std::endl;
    string year;
    std::getline(std::cin, year);
    bookToCreate.setYearPublished(year);

    library.emplace(bookToCreate.getId(), bookToCreate);

    std::cout << "Thank you for adding to the library!" << std::endl;
    optionSelector(library, fileName);
}

void OptionSelector::handleUpdate(boost::unordered_map<string, Book> library, const char *fileName) {
    printLineBreak();

    std::cout << "Please input the ID for the book you would like to update..." << std::endl;

    string id;
    std::getline(std::cin, id);

    Book bookToUpdate;
    try {
        const string name = "name";
        const string author = "author";
        const string isbn = "isbn";
        const string year = "year";

        bookToUpdate = library.at(id);
        std::cout << "What field would you like to update?" << std::endl;
        std::cout << "Input options are 'name', 'author', 'isbn', and 'year'..." << std::endl;

        string field;
        std::getline(std::cin, field);

        string fieldUpdate;
        if (field == name) {
            std::cout << "What would you like the new name to be?" << std::endl;
            std::getline(std::cin, fieldUpdate);
            bookToUpdate.setName(fieldUpdate);
        } else if (field == author) {
            std::cout << "What would you like the new author to be?" << std::endl;
            std::getline(std::cin, fieldUpdate);
            bookToUpdate.setAuthor(fieldUpdate);
        } else if (field == isbn) {
            std::cout << "What would you like the new ISBN to be?" << std::endl;
            std::getline(std::cin, fieldUpdate);
            bookToUpdate.setIsbn(fieldUpdate);
        } else if (field == year) {
            std::cout << "What would you like the new year to be?" << std::endl;
            std::getline(std::cin, fieldUpdate);
            bookToUpdate.setYearPublished(fieldUpdate);
        } else {
            std::cout << "Invalid field '" + field + "'! Input 'exit' to return to menu or input any key to try again." << std::endl;
            string input;
            std::getline(std::cin, input);

            if (input == EXIT) {
                optionSelector(library, fileName);
            } else {
                handleUpdate(library, fileName);
            }
        }

        library.erase(bookToUpdate.getId());
        library.emplace(bookToUpdate.getId(), bookToUpdate);

        std::cout << "Book has been updated successfully!" << std::endl;

        optionSelector(library, fileName);

    } catch(const std::out_of_range &e) {
        std::cout << "ID not found! Input 'exit' to return to menu or hit enter to try again." << std::endl;
        string input;
        std::getline(std::cin, input);

        if (input == EXIT) {
            optionSelector(library, fileName);
        } else {
            handleUpdate(library, fileName);
        }

    }
}

void OptionSelector::handleDelete(boost::unordered_map<string, Book> library, const char *fileName) {
    printLineBreak();

    std::cout << "Please input the ID for the book you would like to remove..." << std::endl;

    string id;
    std::getline(std::cin, id);

    try {
        library.at(id);
        library.erase(id);
        std::cout << "ID '" + id + "' successfully removed!" << std::endl;

        optionSelector(library, fileName);
    } catch(const std::out_of_range &e) {
        std::cout << "ID not found! Input 'exit' to return to menu or hit enter to try again." << std::endl;
        string input;
        std::getline(std::cin, input);

        if (input == EXIT) {
            optionSelector(library, fileName);
        } else {
            handleDelete(library, fileName);
        }
    }
}

void OptionSelector::handleFileUpdate(boost::unordered_map<string, Book> library, const char *fileName) {
    std::ifstream currentFile(fileName);
    if (currentFile.is_open()) {
        currentFile.close();

        std::cout << "Backing up library data..." << std::endl;
        string fileNameString = fileName;
        string backupFileNameString = "backup_" + fileNameString;
        if (std::filesystem::remove(backupFileNameString))
            std::cout << "file " << backupFileNameString << " deleted.\n";
        else
            std::cout << "file " << backupFileNameString << " not found.\n";
        const char *backupFileName = backupFileNameString.c_str();
        rename(fileName, backupFileName);
    }

    std::cout << "Updating library data..." << std::endl;
    std::ofstream newFile(fileName);
    for (auto & it : library) {
        newFile << it.second.toString() << std::endl;
    }

    newFile.close();
}

void OptionSelector::printLineBreak() {
    std::cout << "----------------------------------------" << std::endl;
}
