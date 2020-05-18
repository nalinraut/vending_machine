#include "item.h"

Item::Item()
: _description("None")
, _name("None")
, _price(0.0)
, _calories(0.0)
{}

Item::Item(const std::string& desc, const std::string& name, const double& price, const double& calories)
: _description(desc)
, _name (name)
, _price(price)
, _calories() 
{}

Item::~Item() {}

bool Item::operator==(const Item &other) const
{ 
    return (_name == other._name);
}

void Item::setDescription(const std::string& desc) {
    _description = desc;
}

std::string Item::getDescription() const {
    return _description;
}

void Item::setName(const std::string& name) {
    _name = name;
}

std::string Item::getName() const {
    return _name;
}

void Item::setPrice(const double& price) {
    _price = price;
}

double Item::getPrice() const {
    return _price;
}

void Item::setCalories(const double& calories) {
    _calories = calories;
}

double Item::getCalories() const {
    return _calories;
}

