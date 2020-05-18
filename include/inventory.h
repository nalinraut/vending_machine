#ifndef INVENTORY_H_
#define INVENTORY_H_

/**
 * @author Nalin Raut
 * The inventory class manages both cash and items
 */

#include <iostream>
#include <unordered_map>

template <class T, class S>
class Inventory {

public:
    Inventory();
    ~Inventory();

    std::size_t operator()(const T& k) const; 
    int getQuantity(const T&) const;
    bool hasItem(const T&) const;
    bool hasQuantity(const T&) const;
    void put(const T&, const int&);
    void deprecate(const T&);
    void add(const T&);
    void add(const T&, const int&);
    void deduct(T);
    void deduct(const T&, const int&);
    void clear();

private:
    std::unordered_map<T, int, S> _inventory;
};
#endif // INVENTORY_H_