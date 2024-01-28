#include <iostream>
#include "OptionSelector.h"
using std::string;

void OptionSelector::optionSelector() {
    std::cout << "Please choose from the following options:" << std::endl;
    std::cout << "To list all available books, input 'list'..." << std::endl;
    std::cout << "To get details on a specific book, input 'get'..." << std::endl;
    std::cout << "To create a new book entry, input 'create'..." << std::endl;
    std::cout << "To update a book entry, input 'update'..." << std::endl;
    std::cout << "To delete a book entry, input 'delete'..." << std::endl;
    std::cout << "To exit the library system, input 'exit'..." << std::endl;

    string selection;
    std::cin >> selection;

    if (selection == LIST) {
        // list method
    } else if (selection == GET) {
        // get method
    } else if (selection == CREATE) {
        // create method
    } else if (selection == UPDATE) {
        // update method
    } else if (selection == DELETE) {
        // delete method
    } else if (selection == EXIT) {
        std::cout << "Thank you, come again!" << std::endl;
        return;
    } else {
        std::cout << "INVALID ENTRY: '" + selection + "'" << std::endl;
        optionSelector();
    }
}

const std::string OptionSelector::LIST = "list";
const std::string OptionSelector::GET = "get";
const std::string OptionSelector::CREATE = "create";
const std::string OptionSelector::UPDATE = "update";
const std::string OptionSelector::DELETE = "delete";
const std::string OptionSelector::EXIT = "exit";