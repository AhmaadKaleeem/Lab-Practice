/*  Implement a C++ program using functions for an online store's billing system. The system needs to calculate the total bill based on the price of individual items and their quantity.
The system should also apply discounts for purchases over $100. The discount percentage depends on the total bill amount:
If the total bill is between $100 and $200, a 5% discount is applied.
If the total bill is above $200, a 10% discount is applied.
For bills under $100, no discount is given.
Include a feature that allows customers to add more items to their cart until they decide to proceed to checkout.

Implement a C++ program that includes functions to:
Calculate the total price of items.
Apply the discount based on the total amount.
Display the final bill after applying any discount.
Design the program to handle multiple items in the cart and ensure that the discount is applied only if the total amount exceeds the specified thresholds. */

#include <iostream>
#include <string>
using namespace std;

// Function To Calculate Total Price 
int totalpricee(int price1, int price2, int price3 , int quan1,int quan2, int quan3)
{
   int allprice =(price1*quan1)+ (price2*quan2)+ (price3*quan3);
   return (allprice) ;
}

// Function To Calculate Discount Depending On Condtions Given
int discountt (int price)
{
    int discountprice=0;
    if (price>200)
   {  discountprice = price*0.1 ;
     
   }
   else if (price>=100 && price<=200)
   {  
     discountprice = price*0.05 ;
     
   }
    return (discountprice); 

}

// Calculating Total Bill After Applying Discount
void payablebill (int& price)
{
    int remaining = discountt (price);
    int totalbill = price - remaining;
     cout << "Thanks for Shopping, You Have Total Bill of " <<  totalbill << " $."; 

}

// Function to Validate Quantitiy
void quantityCheck(int& quan) {
    while (quan < 0) {
        cout << "Quantity Cannot be Less Than Zero.\n";
        cout << "Please, Enter Again the Quantity : ";
        cin >> quan;
    }
}

int main(){

    int price1=29,price2=36,price3=40,quan1,quan2,quan3,cart=0,total,i=0,discount;
    char option;

    // Validiating Inputs Until User Checkout
    do{
        cout << "Please Select Shirts Quantity : ";
        cin >> quan1;
        quantityCheck(quan1);
        
        cout << "Please Select Hoodies Quantity : "; 
        cin >> quan2;
        quantityCheck(quan2);
      
        cout << "Please Select Jeans Quantity : ";
        cin >> quan3;
        quantityCheck(quan3);

         total = totalpricee(price1, price2, price3 , quan1, quan2, quan3);
         cart += total;
        cout << "\n" <<  "Enter \"e\" to Checkout or Press Any Letter to Continue Shopping." << "\n";;
        cout << "Enter Your Choice : " ;
        cin >> option;
        cout << "\n";
        
    }
   while (option != 'e') ;

  // Calling Function To Show Bill
   payablebill (cart);
  


}