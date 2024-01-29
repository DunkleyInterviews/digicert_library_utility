#include "Book.h"
#include <iostream>
#include <random>

const string &Book::getId() const {
    return id;
}

void Book::setId(const string &id) {
    Book::id = id;
}

const string &Book::getName() const {
    return name;
}

void Book::setName(const string &name) {
    Book::name = name;
}

const string &Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const string &author) {
    Book::author = author;
}

const string &Book::getIsbn() const {
    return isbn;
}

void Book::setIsbn(const string &isbn) {
    Book::isbn = isbn;
}

string Book::getYearPublished() const {
    return yearPublished;
}

void Book::setYearPublished(string yearPublished) {
    Book::yearPublished = yearPublished;
}

string Book::generate_uuid() {
    // TODO: fix issues to use Boost UUID library to get true UUIDs
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);

    const char* hex_chars = "0123456789abcdef";

    std::string uuid = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx";

    for (char& c : uuid) {
        if (c == 'x') {
            c = hex_chars[dis(gen)];
        } else if (c == 'y') {
            c = hex_chars[(dis(gen) & 0x3) | 0x8];
        }
    }

    return uuid;
}

string Book::toString() {
    string output;

    output.append(this->getId());
    output.append("|");
    output.append(this->getName());
    output.append("|");
    output.append(this->getAuthor());
    output.append("|");
    output.append(this->getIsbn());
    output.append("|");
    output.append(this->getYearPublished());

    return output;
}