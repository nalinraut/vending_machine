#include "inventory.h"

template<class T, class S>
Inventory<T, S>::Inventory()
{}

template<class T, class S>
Inventory<T, S>::~Inventory()
{}

template<class T, class S>
void Inventory<T, S>::put(const T& item, const int& qty) {
    _inventory.insert (std::pair<T,int>(item,qty));
}

template<class T, class S>
void Inventory<T, S>::deprecate(const T& item) {
    if (_inventory.find(item) != _inventory.end())
        _inventory.erase(item);
}

template<class T, class S>
void Inventory<T, S>::add(const T& item) {
    
    if (_inventory.find(item) != _inventory.end())
        _inventory.find(item)->second += 1;

    else
        _inventory.insert(std::make_pair(item, 1));
}

template<class T, class S>
void Inventory<T, S>::add(const T& item, const int& count) {
    if (_inventory.find(item) != _inventory.end())
        _inventory.find(item)->second += count;

    else
        _inventory.insert(std::make_pair(item, count));
}

template<class T, class S>
void Inventory<T, S>::deduct(T item) {

    if (_inventory.find(item) != _inventory.end())
        _inventory.find(item)->second -= 1;
}

template<class T, class S>
void Inventory<T, S>::deduct(const T& item, const int& count) {

    if (_inventory.find(item) != _inventory.end() && _inventory[item] > 0)
        _inventory.find(item)->second -= count;
}

template<class T, class S>
bool Inventory<T, S>::hasItem(const T& item) const {
    if (_inventory.find(item) != _inventory.end())
        return true;
    return false;
}

template<class T, class S>
bool Inventory<T,S>::hasQuantity(const T& item) const {
    if (_inventory.find(item) != _inventory.end())
        if (_inventory.find(item)->second != 0)
            return true;
    return false;
}

template<class T, class S>
void Inventory<T, S>::clear() {
    _inventory.clear();
}

template<class T, class S>
int Inventory<T, S>::getQuantity(const T& item) const {
    if (hasItem(item))
        return _inventory.find(item)->second;
    else 
        return -1;
}





