#include "Book.h"
#include <iomanip>
namespace sdds
{

    //: A constructor that receives the book as a string;
    //this constructor is responsible to extract the information about the book from the parameterand store it in the attributes of the instance.
    //    The parameter will always have the following format : AUTHOR, TITLE, COUNTRY, PRICE, YEAR, DESCRIPTION
    Book::Book(const std::string& strBook) {
        std::string temp = strBook;
        size_t place, c, i = 0;
        std::string tempStr[5];

        while (((place = temp.find(",")) != std::string::npos) && i < 5) {
            tempStr[i] = temp.substr(0, place);
           
	    c = tempStr[i].find_first_not_of(" "); 
            if (c != std::string::npos) {
                tempStr[i].erase(0, c);
            }

	    c = tempStr[i].find_last_not_of(" ");
	
            if (c != std::string::npos) {
                tempStr[i].erase(c+1);
            }

            temp.erase(0, place + 1);
	    i++;
        }

	c = temp.find_first_not_of(" ");
        if (c != std::string::npos) {
            temp.erase(0, c);
        }

            c = temp.find_last_not_of(" ");

            if (c != std::string::npos) {
                temp.erase(c+1);
            }



        bookAuthor = tempStr[0];
        bookTitle = tempStr[1];
        countryOfPublication = tempStr[2];
        priceOfBook = std::stod(tempStr[3]);
        yearOfPublication = std::stoi(tempStr[4]);
        descOfBook = temp;
    }


    std::ostream& operator<<(std::ostream& os, const Book& book) {
        //double price = book.price();
        os << std::setw(20) << book.author() << " | "
            << std::setw(22) << book.title() << " | "
            << std::setw(5) << book.country() << " | "
            << std::setw(4) << book.year() << " | "
            << std::setw(6) << std::fixed << std::setprecision(2)
            << book.priceOfBook << " | "
            << book.descrtiption() << std::endl;

        return os;
    }

    const std::string& Book::author() const {
        return bookAuthor;
    }
    const std::string& Book::title() const {
        return bookTitle;
    }
    //: a query that returns the publication country
    const std::string& Book::country() const {
        return countryOfPublication;
    }
    // : a query that returns the publication year
    const size_t& Book::year() const {
        return yearOfPublication;
    }
    // : a function that returns the price by reference, allowing you to update the price
    double& Book::price() {
        return priceOfBook;
    }
    // return desc
    const std::string& Book::descrtiption() const {
        return descOfBook;
    }

}
