#include <iostream>
#include <string>

class Sales{
private:
    double ttlsalesC{0}; //total commercial sales
    double ttlsalesNC{0}; //total non-commercial sales
    int ttlUntC{0}; //total units of commercial sold
    int ttlUntNC{0}; //total units of non-commercial sold
    double sp1Sales{0};
    double sp2Sales{0};
    //int ttlUntRC{0}; //total returned commercial units
    //int ttlUntRNC{0}; //total retuned non-commercial units


public:

    void addSales(int type, int units, int sp){
        //calculating $ sales & units for commercial
        double sales; //single sale
        if(type == 1){//calculating total sales
            sales = units * 350;
            if(sales >= 1000 ){
                ttlsalesC += sales - (sales * 0.1);
                if(sp == 1) {
                    sp1Sales += 0.9 * sales;
                } else {
                    sp2Sales += 0.9 * sales;
                }
            }
            else {
                ttlsalesC += sales;
                if(sp == 1) {
                    sp1Sales += sales;
                } else {
                    sp2Sales += sales;
                }
            }
        //calculating total units
        ttlUntC += units;
        }
        //calculating $ sales & units for commercial
        else{//calculating total sales
            sales = units * 75.55;
            if(sales >= 1000 ){
                ttlsalesNC += sales - (sales * 0.1);
                if(sp == 1) {
                    sp1Sales += 0.9 * sales;
                } else {
                    sp2Sales += 0.9 * sales;
                }
            }
            else{
                ttlsalesNC += sales;
                if(sp == 1) {
                    sp1Sales += sales;
                } else {
                    sp2Sales += sales;
                }
            }
        //calculating total units
        ttlUntNC += units;
        }
    }//end of function


    //amount of commercial sales $
    double salesC(){
        return ttlsalesC;
    }

    //amount of non-commercial sales $
    double salesNC(){
        return ttlsalesNC;
    }

    //unit of commercial sales #
    int salesUntC(){
        return  ttlUntC;
    }


    //unit of non-commercial sales #
    int salesUntNC(){
        return ttlUntNC;
    }

    double ttlSp1Sales() {
        return sp1Sales;
    }

    double ttlSp2Sales() {
        return sp2Sales;
    }

    //unit of retuned commercial sales #
    //int salesRC(){
    //return ttlUntRC;
    //}

    // unit of returned non-commercial sales #
    //int salesRNC(){
    //return ttlUntRNC;
    //}


}; // end of sales class
