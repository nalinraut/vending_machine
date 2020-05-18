#ifndef VENDING_MACHINE_
#define VENDING_MACHINE_

/**
 * @author Nalin Raut
 * The abstract class include methods for the API
 * The methods can be used off the shelf for implementing 
 * an interface
 */

#include "types.h"

class VendingMachine {
    
public:

    /**
     * Default constructor
    */
    VendingMachine();

    /**
     * Default destructor
    */
    virtual ~VendingMachine();

    void interface();

    // User
    /**
     * Retrieves the list of items to be displayed to the user
    */
    virtual ItemList getItemList() const = 0;
    
    /**
     * Allows user to select an item and returns the price of the item
    */
    virtual double selectItemAndGetPrice(const Item&) = 0;

    /**
     * Allows the user to insert cash with certain denomination 
     * and quantity of bills 
    */
    virtual void insertCash(const Cash&, const int&) = 0;
    
    /**
     * Allows the user to insert card for transaction
     */
    //virtual void insertCard() = 0;
    
    /**
     * Returns the amount if transaction is not complete due 
     * to any exceptions 
     */
    //virtual Cash returnAmount() = 0;

    /**
     * Allows the user to collect item from bucket
    */
    virtual Item collectItemFromBucket() = 0;

    /**
     * Resets the vending machine to factory setting with 
     * no items and cash
    */
    virtual void reset() = 0;

    // Admin
    /**
     * Allows the admin to add certain denomination types to the 
     * vending machine NOT IMPLEMENTED 
    */
    //virtual void addDenomination(const std::string&, const Cash&) = 0;
    
    /**
     * Allows the admin to add a new product type to the 
     * vending machine
    */
    virtual void addProduct(const std::string&, const Item&) = 0 ;
    
    /**
     * Allows the admin to deprecate certain denomination from 
     * the vending machine NOT IMPLEMENTED 
    */
    //virtual void removeDenomination(const std::string&) = 0;
    
    /**
     * Allows the admin to remove new product from the 
     * vending machine
     */
    virtual void removeProduct(const std::string&) = 0;

    /**
     * Allows the user to add more items to the inventory 
     * of existing products
    */
    virtual void addItem(const Item&, const int&) = 0;
    
    /**
     * Allows the admin to add more bills to the 
     * existing denominations NOT IMPLEMENTED 
    */
    //virtual void addCash(const Cash&, int qty) = 0;

    /**
     * Allows the admin to remove item in quantities from the 
     * inventory of product
    */
    virtual void removeItem(const Item&, const int&) = 0;
    
    /**
     * Allows the admin to remove bills of denominations 
     * from the vending machine
    */
    virtual void removeCash(const Cash&, const int&) = 0;

    /**
     * Gets the total sales for admin
    */
    virtual double getTotalSales() const = 0;

    /**
     * Gets the balance
    */
    virtual double getBalance() const = 0;
};


#endif // VENDING_MACHINE_
