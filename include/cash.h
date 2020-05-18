#ifndef CASH_H_
#define CASH_H_
/**
 * @author Nalin Raut
 * The item class encapsulates cash details
 */

#include <iostream>


class Cash{

public:
    Cash();
    Cash(const double&);
    ~Cash();
    bool operator==(const Cash &other) const;
 
    void setDenomination(const double&);
    double getDenomination() const;

private:
    double _denomination;
}; 

struct CashHasher
{
    std::size_t operator()(const Cash& cash) const
    {
        using std::size_t;
        return ((std::hash<double>()(cash.getDenomination())));
    }
};
#endif // CASH_H_