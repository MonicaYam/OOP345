#pragma once

#include <string>
#include <iostream>
#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H
namespace sdds
{
    class Book
    {
        std::string bookAuthor="";
        std::string bookTitle="";
        std::string countryOfPublication="";
        size_t yearOfPublication=0;
        double priceOfBook=0.0;
        std::string descOfBook="";

    public:
        Book() :bookAuthor(""), bookTitle(""), countryOfPublication(""), yearOfPublication(0), priceOfBook(0.0), descOfBook("") {};
        Book(const std::string& strBook);
        const std::string& author() const;
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        const std::string& descrtiption() const;

        template <typename T>
        void fixSpelling(T spellChecker) {
            spellChecker(descOfBook);
        }

        friend std::ostream& operator<<(std::ostream&, const Book&);
    };

}

#endif
