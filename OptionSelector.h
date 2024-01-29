#ifndef DIGICERTLIBRARY_OPTIONSELECTOR_H
#define DIGICERTLIBRARY_OPTIONSELECTOR_H
#include <string>
#include <boost/unordered_map.hpp>
#include "Book.h"

using std::string;

class OptionSelector {
public:
    static const std::string LIST;
    static const std::string GET;
    static const std::string CREATE;
    static const std::string UPDATE;
    static const std::string DELETE;
    static const std::string EXIT;

    void optionSelector(boost::unordered_map <string, Book> library, const char *fileName);

    void getList(boost::unordered_map<string, Book> library, const char *fileName);
    void handleGet(boost::unordered_map<string, Book> library, const char *fileName);
    void handleCreate(boost::unordered_map<string, Book> library, const char *fileName);
    void handleUpdate(boost::unordered_map<string, Book> library, const char *fileName);
    void handleDelete(boost::unordered_map<string, Book> library, const char *fileName);
    void handleFileUpdate(boost::unordered_map<string, Book> library, const char *fileName);

    static void printLineBreak();
};

#endif //DIGICERTLIBRARY_OPTIONSELECTOR_H
