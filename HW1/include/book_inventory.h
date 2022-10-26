#ifndef BOOK_INVENTORY_H
#define BOOK_INVENTORY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

struct Book
{
  Book(std::string _title, std::string _author, float _cost, std::string _isbn, std::string _language_code, int _num_pages,
  std::string _publisher, int _count);  //main constructor
  Book() = default;                     // default constructor
  std::string title;                    // title of the book
  std::string author;                   // author of the book
  float cost;                           // cost of the book
  std::string isbn;                     // a unique string assigned to each book
  std::string language_code;            // language of the book
  int num_pages;                        // number of pages
  std::string publisher;                // publisher of the book
  int count;                            // how many books left in the inventory
};


using Books = std::vector<Book>;

namespace book {

  Books read_database(const std::string filepath);
  std::string search(Books& inventory, const std::string title);
  bool order(Books& inventory, Books& shopinglist, const std::string isbn);
  double get_receipt(Books& shopinglist);

}




#endif