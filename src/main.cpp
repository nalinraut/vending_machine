#include "vending_machine_implementation.h"
#include "exception.h"


int main (){
    VendingMachine* vm = new VendingMachineImplementation();
    while (1) {
        int mode;
       
        int item;
        double cash;
        int number_of_bills;
        Item item_in_bucket;
        ItemList item_list;

        
        std::cout << " ###################################" <<std::endl;
        std::cout << "        Welcome to Quench            " <<std::endl;
        std::cout << " ###################################" <<std::endl;
        //------------------------------------------------------------------
        std::cout << " 0. USER \n 1. ADMIN " <<std::endl;
        std::cout << "\n";
        std::cout << "ENTER MODE: ";
        std::cin >> mode;
        std::cout << "\n";
        //--------------------------------------------------s----------------

        switch (mode){
        case 0:
            
            std::cout <<"LIST OF ITEMS: "<<std::endl;
            try{
                item_list = vm->getItemList();
            }
            catch( const NoProductException& ex ){
                std::cerr<< ex.getMessage() <<std::endl;
            }
            for (auto i : item_list){
                std::cout << i.first <<". "<<i.second.first<< std::endl;
            }
            
            std::cout << "ENTER ITEM: ";
            std::cin >> item;
            std::cout <<"\n";
            try {
                double price = vm->selectItemAndGetPrice(item_list[item].second);
                std::cout<<"Product price: "<<price <<std::endl;
            }
            catch( const SoldOutException& ex ) {
                std::cerr << ex.getMessage() << std::endl;
                continue;
            }  
            //------------------------------------------------------------------
            std::cout << "[TESTING]: Click 0 for Dollar 1 bill."<<std::endl;
            std::cout << "INSERT CASH. ACCEPTS ONLY 1 DOLLAR BILLS. CASH: ";
            std::cin >> cash; 
            std::cout << "NUMBER OF BILLS: ";
            std::cin >> number_of_bills;

            try {
                vm->insertCash(Cash(cash), number_of_bills);
            }
            catch( const NotFullPaidException& ex ) {
                std::cerr << ex.getMessage() << std::endl;
            }
            //------------------------------------------------------------------
            try {
                item_in_bucket = vm->collectItemFromBucket();
                std::cout << "COLLECT ITEM. " <<std::endl;
                std::cout << "ITEM: " << item_in_bucket.getName() << std::endl;
                
            }
            catch(const NotFullPaidException& ex){
                std::cerr<<ex.getMessage()<<std::endl;
            }
            continue;
            
            
            
        case 1:
            while(1) {
                int admin_option;
                std::cout <<"\n* Admin mode *"<<std::endl;
                std::cout <<"Select from the following: "<<std::endl;
                std::cout << "0 Exit Admin Mode \n1 Add Product \n2 Add Item to Inventory \n"
                            "3 Get Balance \n4 Get Total Sales" << std::endl;
                std::cout <<"Admin option: ";
                std::cin >> admin_option;
                if (admin_option == 1) {
                    std::string product_enumeration;
                    std::string product_description;
                    std::string product_name;
                    double product_calories;
                    double product_price;

                    std::cout<<"Enter product enumeration in uppercase: ";
                    std::cin>>product_enumeration;
                    std::cout<<"Enter product price in USD (Denominations of 1 Dollar Bill): ";
                    std::cin>> product_price;
                    std::cout<<"\n";
                    std::cout<<"Enter product calories in Kcal: ";
                    std::cin>> product_calories;
                    std::cout<<"\n";

                    Item itemize;
                    itemize.setCalories(product_calories);
                    itemize.setPrice(product_price);
                    itemize.setName(product_enumeration);
                    vm->addProduct(product_enumeration, itemize);
                }
                else if (admin_option == 2) {
                    std::string item_enum;
                    int qty;
                    std::cout<<"Enter item enumeration in uppercase: ";
                    std::cin>> item_enum;
                    std::cout<<"\n";
                    std::cout<<"Enter item quantity: ";
                    std::cin>> qty;
                    std::cout<<"\n";
                    Item item_to_be_added;
                    item_to_be_added.setName(item_enum);
                    try {
                        vm->addItem(item_to_be_added, qty);
                    }
                    catch(const NoProductException& ex) {
                        std::cerr<<ex.getMessage()<<std::endl;
                        continue;
                    }
                }
                else if (admin_option == 3) {
                    double balance = vm->getBalance();
                    std::cout<<"Current Balance in USD: "<<balance<<std::endl;

                }
                else if (admin_option == 4) {
                    double total_sales = vm->getTotalSales();
                    std::cout<<"Total sales in USD: "<<total_sales<<std::endl;

                }
                else if (admin_option == 0) {
                    std::cout<<"Exiting Admin mode"<<std::endl;
                    break;

                }
                else {
                    std::cout<<"Invalid Admin option. Start Over."<<std::endl;
                    continue;
                }
                continue;
            }
        }
    }    
}



    
