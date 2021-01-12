#pragma once
#include <string>
#include <iostream>

namespace sdds
{
    class Book
    {
        std::string bookAuthor;
        std::string bookTitle;
        std::string countryOfPublication;
        size_t yearOfPublication;
        double priceOfBook;
        std::string descOfBook;

    public:
        Book():bookAuthor(""), bookTitle(""), countryOfPublication(""), yearOfPublication(0), priceOfBook(0.0), descOfBook("") {};
        Book(const std::string& strBook);
        const std::string& author() const;
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        const std::string& descrtiption() const;

        friend std::ostream& operator<<(std::ostream&, const Book&);
    };



}
