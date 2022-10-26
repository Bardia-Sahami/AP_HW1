#include "book_inventory.h"


Book::Book(std::string _title, std::string _author, float _cost, std::string _isbn, std::string _language_code, int _num_pages,
  std::string _publisher, int _count) {
    title = _title;
    author = _author;
    cost = _cost;
    isbn = _isbn;
    language_code = _language_code;
    num_pages = _num_pages;
    publisher = _publisher;
    count = _count;
  }

Books book::read_database(const std::string filepath) {
    if (filepath != "inventory.txt")
      throw std::runtime_error("Invalid syntax.");
    Books b {};
    std::string inputstr;
    std::ifstream inventory;
    inventory.open (filepath); 
    
    for (size_t j{}; j < 59; j++) {
        std::string _title {};
        std::string _author {};
        float _cost {}; 
        std::string _isbn {};
        std::string _language_code {}; 
        int _num_pages {};
        std::string _publisher {}; 
        int _count {};

        std::string _str_cost {};
        std::string _str_num_pages {};
        std::string _str_count {};       
        int k {-1};
        getline(inventory, inputstr, '\n');

        for (size_t i {0}; i < inputstr.length(); i++) {
            if(isdigit(inputstr.at(i)) && k == -1) {
              continue;
            } else if (inputstr.at(i) != ',' && k == 0) {
                _title.push_back(inputstr.at(i));
            } else if (inputstr.at(i) != ',' && k == 1) {
                _author.push_back(inputstr.at(i));
            } else if (inputstr.at(i) != ',' && k == 2) {
                _str_cost.push_back(inputstr.at(i));
            } else if (inputstr.at(i) != ',' && k == 3) {
                _isbn.push_back(inputstr.at(i));
            } else if (inputstr.at(i) != ',' && k == 4) {
                _language_code.push_back(inputstr.at(i));
            } else if (inputstr.at(i) != ',' && k == 5) {
                _str_num_pages.push_back(inputstr.at(i));
            } else if (inputstr.at(i) != ',' && k == 6) {
                _publisher.push_back(inputstr.at(i));
            } else if (inputstr.at(i) != ',' && k == 7) {
                _str_count.push_back(inputstr.at(i));
            } else {
                k++;
            }
        }
       _cost = stof (_str_cost);
      _num_pages = stoi (_str_num_pages);
      _count = stoi (_str_count);
      b.push_back({_title, _author, _cost, _isbn, _language_code, _num_pages, _publisher, _count});
    }
    
    inventory.close();
    return b;
}

std::string book::search(Books& inventory, const std::string title) {
  for (size_t i {}; i < 59; i++) {
    if (inventory[i].title == title) {
      return inventory[i].isbn;
    }
  }
  return "none";

}

bool book::order(Books& inventory, Books& shopinglist, const std::string isbn) {
  bool order{false};
  for (size_t i {}; i < 59; i++) {
    if (inventory[i].isbn == isbn) {
      if (inventory[i].count > 0) {
        inventory[i].count--;
        order = true;
        shopinglist.push_back(inventory[i]);
      }
    }
  }
  return order;
}

double book::get_receipt(Books& shopinglist) {
  double sum {};
  for (size_t i {}; i < shopinglist.size(); i++) {
    sum += static_cast<double>(shopinglist[i].cost);
  }
  std::cout << "╔═════════════════════════════════════════════════════════╗" << std::endl;
  std::cout << "║                        │RECEIPT│                        ║" << std::endl;
  std::cout << "║If you dont like to read, you havent found the right book║" << std::endl;
  std::cout << "║TITLE\t\t\t \tISBN\t \tPRICE\t  ║" << std::endl;
  for (size_t i {}; i < shopinglist.size(); i++ ) {
    std::cout << "║"     << shopinglist[i].title.substr(0,13); 
    if (shopinglist[i].title.length() < 7) {
      std::cout << "\t\t";
    }
    std::cout << ". . .  " 
              << "\t    " << shopinglist[i].isbn << "     "
              << "USD\t"   << shopinglist[i].cost << "  \t  ║" << std::endl;
  }
  std::cout << "║           \tTOTAL:     \t\t  USD " << sum << "\t  ║" << std::endl
            << "╚═════════════════════════════════════════════════════════╝" << std::endl;
  return sum;
  
}