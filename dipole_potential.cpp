#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

//If u want uncomment the below line & remove std:
//using namespace std;

// Constants
const double K = 8.99e9; // Coulomb's constant
const double Q = 1e-6;   // Charge magnitude
const double D = 0.1;    // Distance between charges

// Calculate potential at (x, y)
double calculatePotential(double x, double y) {
    // Dipole aligned on x-axis, centered at origin
    double rPlus = std::sqrt(std::pow(x - D/2, 2) + std::pow(y, 2));
    double rMinus = std::sqrt(std::pow(x + D/2, 2) + std::pow(y, 2));
    
    if (rPlus < 1e-4 || rMinus < 1e-4) return 0; 
    
    return K * Q * (1.0 / rPlus - 1.0 / rMinus);
}

int main() {
    std::ofstream file("dipole_potential.csv");
    int grid_size = 200;
    double limit = 0.5;

    // Generate grid and write potential to CSV
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            double x = -limit + (2.0 * limit * i) / grid_size;
            double y = -limit + (2.0 * limit * j) / grid_size;
            double v = calculatePotential(x, y);
            file << x << "," << y << "," << v << "\n";
        }
    }
    file.close();
    return 0;
}
