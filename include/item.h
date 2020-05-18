#ifndef ITEM_H_
#define  ITEM_H_

/**
 * @author Nalin Raut
 * The item class encapsulates item details
 */

#include <iostream>
#include <string>

class Item{
public:

    Item();
    Item(const std::string& desc, const std::string& name, const double& price, const double& calories);
    ~Item();

    bool operator==(const Item &other) const;

    void setDescription(const std::string&);
    std::string getDescription() const;

    void setName(const std::string&);
    std::string getName() const;

    void setPrice(const double&);
    double getPrice() const;

    void setCalories(const double&);
    double getCalories() const;

private:
    
    std::string _description;
    std::string _name;
    double _price;
    double _calories;
        
}; 

struct ItemHasher
{
    std::size_t operator()(const Item& item) const
    {
        using std::size_t;
        return ((std::hash<std::string>()(item.getName())));
    }
};
#endif // ITEM_H_