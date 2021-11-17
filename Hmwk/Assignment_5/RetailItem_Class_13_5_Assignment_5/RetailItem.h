using namespace std;

class RetailItem {
private:
	string description;
	int unitsOnHand;
	double price;
public:	
	RetailItem(string, int, double);
	void setDescription(string);
	void setUnitOnHand(int);
	void setPrice(double);
	string getDescription() const;
	int getUnitOnHand() const;
	double getPrice() const;
};
