// Let's Calculate Lesco Electricity Bill
#include <iostream>

int main() { 
  int units;
  // Taking Units Input
  std::cout<<"Calculate your Electricity Bill Now ! " << std::endl <<std::endl;
  std::cout<<"Enter your Units Consumed : " ;
  std::cin>>units;
  std::cout<<std::endl;
  // Declaring Slabs For Electricity Bill Tariff 
  float slab1 = 12.13; // For 0 - 100 Units
  float slab2 = 14.53; // For 101 - 200 Units
  float slab3 = 31.51; // For 201 - 300 Units
  float slab4 = 38.41; // For 301 - 400 Units
  float slab5 = 41.62; // For 401 - 500 Units
  float slab6 = 43.04; // For 501 - 600 Units
  float slab7 = 44.18; // For 601 - 700 Units
  float slab8 = 49.10; // For 700 Above Units
  
  // Calculating Electricity Bill
  if (units <= 100) {
    std::cout<<"Your Electricity Bill is Rs. " << (slab1*units) + 75 << std::endl; // 75 is fixed charges 
  }
  else if (units >100 && units<=200){
  std::cout<<"Your Electricity Bill is Rs. " << (slab1*100) +(slab2*(units-100)) + 75 << std::endl; // 75 is fixed charges 
    }
  else if (units >200 && units<=300){
  std::cout<<"Your Electricity Bill is Rs. " << (slab1*100) +(slab2*100) + (slab3*(units-200)) + 75 << std::endl; // 75 is fixed charges 
  }
  else if (units >300 && units<=400){
  std::cout<<"Your Electricity Bill is Rs. " << (slab1*100) + (slab2*100) + (slab3*100) +(slab4*(units-300)) + 200 + 75 << std::endl; // 75 and 200 are fixed charges 
  }
  else if (units >400 && units<=500){
  std::cout<<"Your Electricity Bill is Rs. " << (slab1*100) + (slab2*100) + (slab3*100) +(slab4*100) +(slab5*(units-400)) + 400 + 75 << std::endl; // 75 and 400 are fixed charges 
  }
  else if (units >500 && units<=600){
    std::cout<<"Your Electricity Bill is Rs. " << (slab1*100) + (slab2*100) + (slab3*100) + (slab4*100) + (slab5*100) + (slab6*(units-500)) + 600 + 75 << std::endl; // 75 and 600 is fixed charges 
      }
  else if (units >600 && units<=700){
  std::cout<<"Your Electricity Bill is Rs. " << (slab1*100) + (slab2*100) + (slab3*100) +(slab4*100) + (slab5*100) +(slab6*100) + (slab7*(units-600)) + 75 << std::endl; // 75 is fixed charges 
  }
  else {
  std::cout<<"Your Electricity Bill is Rs. " << (slab1*100) + (slab2*100) + (slab3*100) +(slab4*100) + (slab5*100) +(slab6*100) + (slab7*100) + (slab8*(units-600)) + 75 << std::endl;
   // 75 is fixed charges 
    return 0;
}
}

