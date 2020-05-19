#include "vending_machine.h"
#include "vending_machine_implementation.h"

VendingMachineImplementation::VendingMachineImplementation()
: _cash_inventory(std::make_shared<Inventory<Cash, CashHasher>>())
, _item_inventory(std::make_shared<Inventory<Item, ItemHasher>>())
{
    initialize();
}
VendingMachineImplementation::~VendingMachineImplementation()
{}

void VendingMachineImplementation::initialize() {
    _denominations = {{"1_DOLLAR",Cash(1)}};
    _products = {
        {"SODA", std::make_pair(0, Item("Plain aerated drink",
            "SODA",
            1.0,
            0))},
        {"COKE", std::make_pair(1, Item("Thirst quenching beverage by Coca Cola",
            "COKE",
            2.0,
            140))},
        {"PEPSI", std::make_pair(2, Item("Thirst quenching beverage by Pespsico",
            "PEPSI",
            2.0,
            140))},
        {"WATER", std::make_pair(3, Item("Smart water with added nutrients",
            "WATER",
            3.0,
            0))},
    };

    
    for (auto d : _denominations)
        _cash_inventory->put(d.second, 5);
    for (auto p : _products)
        _item_inventory->put(p.second.second, 5);
    updateItemList();

    
}

ItemList VendingMachineImplementation::getItemList() const{
    return _item_list;
}

void VendingMachineImplementation::updateItemList() {
    for (auto p : _products) {
        _item_list.insert(std::make_pair(p.second.first, std::make_pair(p.first,p.second.second)));
    
    }
}

double VendingMachineImplementation::selectItemAndGetPrice(const Item& item) {    
      
    if (_item_inventory->hasItem(item)) {
        _curr_item = item;
        return _curr_item.getPrice();
    }

    throw SoldOutException("Sold Out, Please buy another item.");   
}

void VendingMachineImplementation::insertCash(const Cash& cash, const int& bills) {

    _curr_balance = cash.getDenomination()*bills;
    _cash_inventory->add(cash,bills);
}

Item VendingMachineImplementation::collectItemFromBucket() {
    Item item = collectItem();
    _total_sales += _curr_item.getPrice();
    std::vector<Cash> change;// = collectChange();

    return item;
}

Item VendingMachineImplementation::collectItem() {
    if (isFullPaid()) {
        _item_inventory->deduct(_curr_item,1);
        return _curr_item;
    }
    double remaining_balance = _curr_item.getPrice() - _curr_balance;
    throw NotFullPaidException("Price not fully paid. Remaining:" + std::to_string(remaining_balance));
}

bool VendingMachineImplementation::isFullPaid() {
    if (_curr_balance >= _curr_item.getPrice()) {
        return true;
    }
    return false;
}

void VendingMachineImplementation::reset() {
    _cash_inventory->clear();
    _item_inventory->clear();
    _total_sales = 0.0;
    _curr_balance = 0;
}

void VendingMachineImplementation::addProduct(const std::string& product_enum, const Item& itemize_product) {
    _products[product_enum]=std::make_pair(_products.size(), itemize_product);
    _item_inventory->put(itemize_product, 0);
    updateItemList();

}

void VendingMachineImplementation::removeProduct(const std::string& product_enum) {
    auto it = _products.find(product_enum);
    if (it != _products.end()) {
        _item_inventory->deprecate(_products[it->first].second);
        _products.erase(product_enum);
        updateItemList();
    }
    else {
        throw NoProductException("No product of enumeration"+product_enum+" found.");
    }
}

void VendingMachineImplementation::addItem(const Item& item, const int& qty) {
    if (_item_inventory->hasItem(item)) {
        _item_inventory->add(item, qty);
    }
    else {
        throw NoProductException("No product named "+item.getName());
    }
}

void VendingMachineImplementation::removeItem(const Item& item, const int& qty) {
    if (_item_inventory->hasQuantity(item)) {
        _item_inventory->deduct(item, qty);
    }
    else {
        throw NotEnoughItemsToRemoveException("Not enough items to remove.");
    }
}

void VendingMachineImplementation::removeCash(const Cash& cash, const int& qty) {
    if (_cash_inventory->hasItem(cash)) {
        _cash_inventory->deduct(cash, qty);
    }
    else {
        throw NotEnoughBillsToRemoveException("Not enough bills to remove.");
    }
}

double VendingMachineImplementation::getTotalSales() const{
    return _total_sales;
}

double VendingMachineImplementation::getBalance() const{
    return _curr_balance;
}

