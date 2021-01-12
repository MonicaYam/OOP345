// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0u; i < desc.size(); i++)
		{
			for (size_t k = 0u; k < price.size(); k++)
			{
				if (desc[i].code == price[k].code)
				{
					Product* product = new Product(desc[i].desc, price[k].price);
					product->validate();
					priceList += product;
					
					delete product;
				}
			}
		}

		return priceList;
	}


	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for(size_t i = 0u; i < desc.size(); i++){
			for(size_t k = 0u; k < price.size(); k++){
				if(desc[i].code == price[k].code){
					unique_ptr<Product> product(new Product(desc[i].desc, price[k].price));
					product->validate();
					priceList += move(product);
				}
			}
		}

		return priceList;
	}
}
