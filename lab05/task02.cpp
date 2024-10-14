// Write a function that calculates the size of the population for a year. The formula is N = P + BP – DP

#include <iostream>
using namespace std;

// Declaring Function
float newpopulation(float population, float birthRate, float deathRate) {
    return population + (birthRate * population) - (deathRate * population);
}

int main() {
    float startpopulation, birthrate, deathrate;
    int years;

    // Input validation for population size
    cout << "Enter the Starting size of population : "; 
    cin  >> startpopulation;
    if (startpopulation < 2)
    {
        cout << "\t\t" << "Sorry! The intial population cannot be less than 2.";
    }

    // Input validation for population size
    cout << "Enter the Annual birth rate : "; 
    cin  >> birthrate;
    if (birthrate < 1)
    {
        cout << "\t\t" << "Birth rate cannot be less than 1.";
    }
    else { birthrate = birthrate / 100; }
   
    // Taking Other Inputs
    cout << "Enter the Annual death rate : "; 
    cin  >> deathrate;
    deathrate = deathrate / 100;
    cout << "Number of years  : "; cin >> years;

    //  Calling Function and Determining Population
    cout << "The Population For Year 0 is : " << startpopulation << endl;
    for (int i = 1; i <= years; i++) {
        startpopulation = newpopulation(startpopulation, birthrate , deathrate);
        cout << "Population for year " << i << " is : " << startpopulation << endl;

    }

    
    return 0;
}

