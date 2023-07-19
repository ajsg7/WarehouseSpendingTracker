#include <iostream>
#include <array>
#include <iomanip>
#include <string>
#include "Accounting.h";
#include "Sales.h";
#include "Warehouse.h";
using namespace std;

const size_t column = 5;
const size_t row = 11;

void printArray(array<array<double, column>, row>& excel);
void printArrayS(array<string, column>& names);

int main() {

    double ttlSales;
    int com, units, person;
    double sp1Sales{0};
    double sp2Sales{0};

    array<string, column> names {
        "MONTH" , "TYPE", "UNITS SOLD", "PRICE PER UNIT", "SALES PERSON"
    };

    array<array<double, column>, row> excel {
        1 , 0, 293, 75.55, 1,
        1 , 1, 285,   350, 1,
        1, 1, 256,   350, 2,
        1, 0, 192, 75.55, 2,
        1, 0, 178, 75.55, 2,
        1, 0, 202, 75.55, 1,
        1, 1, 258,   350, 2,
        1, 0, 511, 75.55, 2,
        1, 0, 251, 75.55, 1,
        1, 0, 358, 75.55, 1,
        1, 1, 392,   350, 1
    };

    Sales s1;
    Warehouse w1;

    for(int i{0}; i < 11; i++) {
        com = excel[i][1];
        units = excel[i][2];
        person = excel[i][4];
        s1.addSales(com, units, person);
        w1.updateInv(com, units);
    }
    ttlSales = s1.salesC() + s1.salesNC();

    Accounting a1(ttlSales);

  /*  if(w1.invC() < 0) {
        cout << "**Commercial Inventory Depleted**" << endl;
    }
    if(w1.invNC() < 0) {
        cout << "**Non-Commercial Inventory Depleted**" << endl;
    }*/
    cout << "                               Cameras R Us - Sales Report\n" << endl;

    cout << "TYPE:" << "            " << "SALES PERSON:" << endl;
    cout << "   1:Comercial" << "    " << "          1:JANE" <<endl;
    cout << "   0:Non-Comercial" <<"          2:JOHN\n" << endl;
    printArrayS(names);
    printArray(excel);

    cout << "STATISTICS:"<<endl;

    cout << "\tSales Person 1 Sales: $"<< s1.ttlSp1Sales() << endl;
    cout << "\tSales Person 2 Sales: $"<< s1.ttlSp2Sales() << endl;
    cout << "\tTotal Expenditures: $"<<a1.getExp() << endl;
    cout<< "\tTotal Profit in January: $"<<a1.getCompProf() <<endl;
    if(a1.getbreakEP()) {
        cout << "\tWe broke even!" << endl;
    } else {
        cout << "\tWe did not break even!" << endl;
    }
    cout << endl;
    if(w1.invC() < 0) {
        cout << "**Commercial Inventory Depleted**" << endl;
    }
    if(w1.invNC() < 0) {
        cout << "**Non-Commercial Inventory Depleted**" << endl;
    }
    return 0;
}

void printArrayS(array<string, column>& names) {
    for(int k{0}; k < column; k++) {
            cout << setw(16) << names[k] << " ";
        }
    cout << endl;
}

void printArray(array<array<double, column>, row>& excel) {
    for(int i{0}; i < row; i++) {
        for(int j{0}; j < column; j++) {
            cout << setw(16) << excel[i][j] << " ";
        }
        cout << endl;
    }
}
