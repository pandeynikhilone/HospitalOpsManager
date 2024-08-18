// Data structure used in "medicine" is "Matrix - Implemented using vector"
// This Header file Contains implementation of "Matrix"

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// Define a structure to hold medicine information
struct Medicine {
    std::string name;
    float price;
};

// Function to generate random number of medicines to be selected
int generateRandomNumberOfMedicines() {
    return rand() % 5 + 1; // Randomly select between 1 to 5 medicines
}

// Function to generate random index within the range of medicines
int generateRandomMedicineIndex(int maxIndex) {
    return rand() % maxIndex;
}

// Function to calculate total amount for selected medicines
float calculateTotalAmount(std::vector<Medicine>& medicines, std::vector<int>& selectedIndices) {
    float sum = 0;
    for (int index : selectedIndices) {
        sum += medicines[index].price;
    }
    return sum;
}

float performMedicineSelection() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Vector to store medicine information
       std::vector<Medicine> medicines = {
        {"Celestiprin", 25.99},
        {"Luminozole", 19.95},
        {"Tranquilax", 30.49},
        {"Cardioguard", 35.75},
        {"Revitalize Plus", 28.88},
        {"Dermacare Cream", 15.50},
        {"Osteoflex", 24.99},
        {"SleepEase Capsules", 18.75},
        {"DigestiClear", 22.45},
        {"ImmunoGuard", 29.99},
        {"Painaway", 12.25},
        {"ColdBlock", 21.75},
        {"AnxietyLess", 17.80},
        {"HeartEase", 23.60},
        {"EnergyMax", 31.20},
        {"SkinHeal", 16.85},
        {"JointEase", 27.30},
        {"SleepWell", 19.45},
        {"DigestiRelief", 14.99},
        {"ImmuneBoost", 26.50},
        {"Albuterol", 32.75}, 
        {"Antihistamine", 18.60}, 
        {"paracetamol", 24.25}, 
        {"Atorvastatin", 20.30}, 
        {"Ibuprofen", 33.60}, 
        {"Omeprazole", 15.85}, 
        {"Amlodipine", 28.30},
        {"Levothyroxine", 22.45}, 
        {"Lisinopril", 16.99}, 
        {"Levothyroxine", 27.50} 
    };
    // Generate random number of medicines to be selected
    int numMedicinesToSelect = generateRandomNumberOfMedicines();

    // Generate random indices to select medicines
    std::vector<int> selectedIndices;
    for (int i = 0; i < numMedicinesToSelect; ++i) {
        selectedIndices.push_back(generateRandomMedicineIndex(medicines.size()));
    }

    // Calculate total amount for selected medicines
    float totalAmount = calculateTotalAmount(medicines, selectedIndices);

    // Display selected medicines and total amount
    std::cout << "Selected Medicines:\n";
    for (int index : selectedIndices) {
        std::cout << "- " << medicines[index].name << " (Rs: " << medicines[index].price << "/-)\n";
    }

    return totalAmount;
}

#endif
