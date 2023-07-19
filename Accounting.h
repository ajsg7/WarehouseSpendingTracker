    #ifndef ACCOUNTING_H_INCLUDED
#define ACCOUNTING_H_INCLUDED
#include <iostream>
//#include "Sales.h";



#endif // ACCOUNTING_H_INCLUDED

    class Accounting {
    public:
         //Constructor
         Accounting(double sales)
         {
             ttlSales = sales;
         }
        //Function that calculates the Total Expenditures of the company
        double getExp()
        {
        double Exp{0};
        Exp += getSalesDep() + getAccDep() + getWarehDep();
        return Exp;
        }

        //Function that calculates the Sales Department Expenditures
        double getSalesDep()
        {
            double SalesDep{0};
        SalesDep = 2*(2000 + 0.1*ttlSales); //totalsales
        return SalesDep;
        }

        //Function that calculates the Warehouse Department's Expenditures
        double getWarehDep()
        {
            double WarehDep{0};
            double wws = 23*40*4; //$23.00 times 40 hours a week, over a period of 4 weeks
        WarehDep = 6500+4500+wws; //
        return WarehDep;
        }

        //Function that calculates the Accounting Department
        double getAccDep()
        {
            double AccDep{0};
            AccDep = 6500+7500;
            return AccDep; //Accountant Salary + Monthly payment for January respectively
        }
/*
        void getbreakEP()
        {
            double CompProf= 0.25*(ttlSales);
            //double breakEP = CompProf - getExp();
            if(CompProf >= getExp())
                {
                std::cout<<"We broke even"<<std::endl;
                }
            else
                {
                std::cout<<"We did not break even"<<std::endl;
                }
        }*/

        double getCompProf()
        {
            double CompProf;
            CompProf = 0.25*(ttlSales);
            return CompProf;
        }

        bool getbreakEP()
        {
            //double CompProf= 0.25*(ttlSales);
            //double breakEP = CompProf - getExp();
            if(getCompProf() >= getExp())
                {
                return true;
                }
            else
                {
                return false;
                }
        }
    private:
        double ttlSales;

};
