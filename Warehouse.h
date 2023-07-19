#ifndef WAREHOUSE_H_INCLUDED
#define WAREHOUSE_H_INCLUDED
class Warehouse {
private:
    int unitInvC{1500};
    int unitInvNC{1500};
public:
    void updateInv(double com,double units) {
        if(com == 1.0) {
            unitInvC -= units;
        } else {
            unitInvNC -= units;
        }
    }

    int invC() {
        return unitInvC;
    }

    int invNC() {
        return unitInvNC;
    }
};


#endif // WAREHOUSE_H_INCLUDED
