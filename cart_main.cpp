#include<iostream>
#include<vector>
#include "datamodel.h"
using namespace std;
vector<Product> allProducts = {
		Product(1, "apple", 26),
		Product(2, "mango", 40),
		Product(3, "guava", 25),
		Product(4, "pine-apple", 45),
		Product(5, "litchi", 60),
		Product(6, "banana", 55),
		Product(7, "orange", 80),
		Product(8, "grapes", 52),
		Product(9, "watermelon", 90),
		Product(10, "strawberry", 120),

	};
	Product *chooseProduct(){
		string productList;
		cout<<"Available Products "<<endl;
		for(auto product: allProducts)
		{
			productList.append(product.getdisplayname());

		}
		cout<<productList<<endl;
		cout<<"****************************"<<endl;
		string choice;
		cin>>choice;
		for(int i=0;i<allProducts.size();i++){
			if(allProducts[i].getshortname()== choice)
			{
				return &allProducts[i];
			}
		}
		cout<<"Product not found"<<endl;
		return NULL;

	}
	bool checkout(Cart &cart){
		if(cart.isempty()){
			return false;
		}
		int total= cart.gettotal();
		cout<<"Pay in Cash";
		int paid;
		cin>>paid;
		if(paid>total)
		{
			cout<<"Change "<<paid-total<<endl;
			cout<<"Thankyou for Shopping";
			return true;
		}
		else{
			cout<<"Not enogh cash!";
			return false;
		}
	}
int main()
{
	char action;
	Cart cart;
	while(true)
	{
		cout<<"Select an action- (a)add item, (v)view cart, (c)checkout "<<endl;
		cin>>action;
		if(action=='a')
		{
			//add the item
			//view and choose the product
			Product *product=chooseProduct();
			if(product!=NULL){
				cout<<"Added to cart  "<<product->getdisplayname()<<endl;
				cart.addProduct(*product);
			}


		}
		else if(action=='v')
		{
			cout<<"*****************************"<<endl;
			cout<<cart.viewcart();
			cout<<"****************************"<<endl;

		}
		else{
			cart.viewcart();
			if(checkout(cart)){
				break;
			}

		}
	}
	
	return 0;
}
