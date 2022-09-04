//product cart item
#include<string>
#include<unordered_map>
using namespace std;
//forward declaration
class Item;
class cart;
class Product{
	int id;
	string name;
	int price;
public:
	Product(){

	}
	Product(int u_id, string name, int price){
		id=u_id;
		this->name=name;
		this->price=price;
	}
	string getdisplayname(){
		return name + ": Rs " + to_string(price) + "\n";
	}
	string getshortname()
	{
		return name.substr(0,1);

	}
	friend class Item;
	friend class Cart;

};
class Item{
	 Product product;
	int quantity;
public:
	Item(){

	}
	Item(Product p, int q): product(p), quantity(q){};
	int getitemprice(){
		return quantity * product.price;
	}
	string getiteminfo(){
		return to_string(quantity) + " x " + product.name + " Rs "+ to_string(quantity * product.price)+"\n";
	}
	friend class Cart;


};

class Cart{
	unordered_map<int,Item>items;
public:
	void addProduct(Product product){
		if(items.count(product.id)==0){
			Item newItem(product,1);
			items[product.id]=newItem;
		}
		else{
			items[product.id].quantity+=1;
		}
	}
	int gettotal(){
		int total=0;
		for(auto itempair:items){
			auto item=itempair.second;
			total+=item.getitemprice();
		}
		return total;
	}
	string viewcart(){
		if(items.empty()){
			return "Cart is empty";
		}
		string itemizedList;
		int cart_total=gettotal();
		for(auto itemptr:items){
			auto item=itemptr.second;
			itemizedList.append(item.getiteminfo());
		}
		return itemizedList + "Total Amount : Rs "+ to_string(cart_total)+"\n";
	}
	bool isempty()
	{
		return items.empty();
	}
};