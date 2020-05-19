#ifndef VENDING_MACHINE_IMPLEMENTATION_
#define VENDING_MACHINE_IMPLEMENTATION_
/**
 * @author Nalin Raut
 * This class includes implemented methods for the API
 * The methods are abstracted out to more higher level 
 * methods in the abstract class
 */

#include <memory>

#include "cash.h"
#include "item.h"
#include "inventory.h"
#include "inventory.hpp"
#include "exception.h"
#include "vending_machine.h"

class VendingMachineImplementation : public VendingMachine
{

public:
    /**
     * Default constructor
    */
    VendingMachineImplementation();

    /**
     * Default Destructor
    */
    ~VendingMachineImplementation();

    /**
     * Initializes vending machine with cash and items
    */
    void initialize();

    // User
    ItemList getItemList() const; 
    
    /**
     * Allows user to select item and retrieves the price
    */
    double selectItemAndGetPrice(const Item&);

    /**
     * Allows user to insert cash and bill count
    */
    void insertCash(const Cash&, const int&);

    /**
     * Returns the amount if transaction is not complete due
     * to any exceptions
    */
    Cash returnAmount();

    /**
     * Allows the user to collect item from bucket
    */
    Item collectItemFromBucket();

    /**
     * Resets the vendingmachine to factory setting with no
     * items and cash
    */
    void reset();

    /**
     * Update Item List for display 
    */ 
    void updateItemList();

    /**
     * Checks if the cash inserted is equal or more than the 
     * price of the item
    */
    bool isFullPaid();
    


    // Admin
    /**
     * Allows the admin to add certain denomination types to the 
     * vending machine NOT IMPLEMENTED 
    */
    //void addDenomination(const std::string&, const Cash&);
    
    /**
     * Allows the admin to add a new product type to the 
     * vending machine
    */
    void addProduct(const std::string&, const Item&); 
    
    /**
     * Allows the admin to deprecate certain denomination from 
     * the vending machine NOT IMPLEMENTED 
    */
    //void removeDenomination(const std::string&);

    /**
     * Allows the admin to remove new product from the 
     * vending machine
     */
    void removeProduct(const std::string&);

    /**
     * Allows the user to add more items to the inventory 
     * of existing products
    */
    void addItem(const Item&, const int&);
    
    /**
     * Allows the admin to add more bills to the 
     * existing denominations  
    */
    //void addCash(const Cash&, int qty);

    /**
     * Allows the admin to remove item in quantities from the 
     * inventory of product
    */
    void removeItem(const Item&, const int&);

    /**
     * Allows the admin to remove bills of denominations 
     * from the vending machine
    */
    void removeCash(const Cash&, const int&);

    /**
     * Gets the total sales for admin
    */
    double getTotalSales() const;

    /**
     * Gets the balance in the machine
    */
    double getBalance() const;

private:
    Item collectItem();
   // std::vector<Cash> collectChange();

private:
    std::shared_ptr<Inventory<Cash, CashHasher>> _cash_inventory;
    std::shared_ptr<Inventory<Item, ItemHasher>> _item_inventory;
    Item _curr_item;
    Denomination _denominations;
    Product _products;
    double _curr_balance;
    double _total_sales;
    ItemList _item_list;

};

#endif // VENDING_MACHINE_IMPLEMENTATION_