#ifndef TYPES_H_
#define TYPES_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "cash.h"
#include "item.h"


typedef std::map<std::string, Cash> Denomination;
typedef std::map<std::string, std::pair<int, Item>> Product;
typedef std::map<int, std::pair<std::string, Item>> ItemList;
enum Status {SUCCESS, FAILED, UNKNOWN};

typedef Item Bucket;

struct Transaction {
    unsigned long long id;
    unsigned long long card_number;
    double amount_deducted;
    double amount_returned;
    bool cash;
    bool card;
    std::string msg;
    Status status;
};


#endif // TYPES_H_