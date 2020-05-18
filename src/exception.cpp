#include "exception.h"

SoldOutException::SoldOutException(std::string msg)
:_message(msg)
{}
SoldOutException::~SoldOutException()
{}

std::string SoldOutException::getMessage() const {
    return _message;
}

// -----------------------------------------------------------------

NotFullPaidException::NotFullPaidException(std::string msg)
:_message(msg)
{}
NotFullPaidException::~NotFullPaidException()
{}

std::string NotFullPaidException::getMessage() const {
    return _message;
}

// -----------------------------------------------------------------

NoProductException::NoProductException(std::string msg)
:_message(msg)
{}
NoProductException::~NoProductException()
{}

std::string NoProductException::getMessage() const {
    return _message;
}

// -----------------------------------------------------------------

NotEnoughItemsToRemoveException::NotEnoughItemsToRemoveException(std::string msg)
:_message(msg)
{}
NotEnoughItemsToRemoveException::~NotEnoughItemsToRemoveException()
{}

std::string NotEnoughItemsToRemoveException::getMessage() const {
    return _message;
}

// -----------------------------------------------------------------

NotEnoughBillsToRemoveException::NotEnoughBillsToRemoveException(std::string msg)
:_message(msg)
{}
NotEnoughBillsToRemoveException::~NotEnoughBillsToRemoveException()
{}

std::string NotEnoughBillsToRemoveException::getMessage() const {
    return _message;
}

// -----------------------------------------------------------------
