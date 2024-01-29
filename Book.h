#ifndef DIGICERT_LIBRARY_UTILITY_BOOK_H
#define DIGICERT_LIBRARY_UTILITY_BOOK_H
#include <string>
using std::string;

class Book {
public:
    string id;
    string name;
    string author;
    string isbn;
    string yearPublished;

    static string generate_uuid();
    string toString();

    const string &getId() const;

    void setId(const string &id);

    const string &getName() const;

    void setName(const string &name);

    const string &getAuthor() const;

    void setAuthor(const string &author);

    const string &getIsbn() const;

    void setIsbn(const string &isbn);

    string getYearPublished() const;

    void setYearPublished(string yearPublished);
};


#endif //DIGICERT_LIBRARY_UTILITY_BOOK_H
