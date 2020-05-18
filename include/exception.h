#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>
#include <string>

/**
 * Throws sold out exception
 * @param msg - Message to be displayed while implemeting 
 * try-catch  
*/
class SoldOutException {
public:
    SoldOutException(std::string msg);
    ~SoldOutException();

    std::string getMessage() const;

private:
    std::string _message;
};

/**
 * Throws not full paid
 * @param msg - Message to be displayed while implemeting 
 * try-catch  
*/
class NotFullPaidException {
public:
    NotFullPaidException(std::string msg);
    ~NotFullPaidException();

    std::string getMessage() const;

private:
    std::string _message;
};

/**
 * Throws no product exception
 * @param msg - Message to be displayed while implemeting 
 * try-catch  
*/
class NoProductException {
public:
    NoProductException(std::string msg);
    ~NoProductException();

    std::string getMessage() const;

private:
    std::string _message;
};

/**
 * Throws not enough items to remove
 * @param msg - Message to be displayed while implemeting 
 * try-catch  
*/
class NotEnoughItemsToRemoveException {
public:
    NotEnoughItemsToRemoveException(std::string msg);
    ~NotEnoughItemsToRemoveException();

    std::string getMessage() const;

private:
    std::string _message;
};

/**
 * Throws not enough bills to remove
 * @param msg - Message to be displayed while implemeting 
 * try-catch  
*/
class NotEnoughBillsToRemoveException {
public:
    NotEnoughBillsToRemoveException(std::string msg);
    ~NotEnoughBillsToRemoveException();

    std::string getMessage() const;

private:
    std::string _message;
};


#endif // EXCEPTION_H_