using namespace std;

class InventoryClass{
private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;
public:
    void setItemNumber(int itemn){
        itemNumber = itemn;
    }
    void setQuantity(int qt){
        quantity = qt;
        setTotalCost();
    }
    void setCost(double ct){
        cost = ct;
        setTotalCost();
    }
    int getItemNumber()const{
        return itemNumber;
    }
    int getQuantity()const{
        return quantity;
    }
    double getCost()const{
        return cost;
    }
    double getTotalCost()const{
        return totalCost;
    }
    void setTotalCost(){
        totalCost = quantity * cost;
    }
    InventoryClass(){
        itemNumber = 0;
        quantity = 0;
        cost = 0.00;
        totalCost = 0.00;
    }
    InventoryClass(int itemn, int qt, double cost1){
        itemNumber = itemn;
        quantity = qt;
        cost = cost1;
        setTotalCost();
    }
};