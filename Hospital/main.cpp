#include <iostream>
#include <ctime>
#include "LL.hpp"
#include "BST.hpp"
#include "Hash.hpp"
#include "Matrix.hpp"
#include"console.hpp"

class CabinManager {
public:
    // Default constructor
    CabinManager() {
        // Manually insert data into the binary search tree
        patientCabin.insert(new TreeNode("CAB001", true));
        patientCabin.insert(new TreeNode("CAB002", true));
        patientCabin.insert(new TreeNode("CAB003", true));
        patientCabin.insert(new TreeNode("CAB004", true));
        patientCabin.insert(new TreeNode("CAB005", true));
        // Add more dummy data as needed
    }

    BinarySearchTree& getCabinTree() {
        return patientCabin;
    }

private:
    BinarySearchTree patientCabin;
};

int main() {
    CabinManager cabinManager;

    // 1. Patient Details
    LinkNode patient1(1, "John Doe", "Fever", 30, 'm', 'O+');

    // 2. Patient Details - search and allotment
    BinarySearchTree& patientCabin = cabinManager.getCabinTree();

    // Searching for a cabin
    std::string cabinCode = "CAB001";
    TreeNode* cabin = patientCabin.search(cabinCode);
    if (cabin != nullptr) {
        std::cout << "Patient is allotted to cabin: " << cabin->cabin_code << std::endl;
    } else {
        std::cout << "Cabin not found." << std::endl;
    }

    // 3. Doctors Prescription
    DoctorDatabase doctors;
    doctors.addDoctor("Dr. Smith", "Cardiology");
    doctors.addDoctor("Dr. Johnson", "Neurology");

    // 4. Medicine
    performMedicineSelection();

    // 5. Receipt
    // Get current date and time
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    // Display receipt
    std::cout << "\nReceipt:\n";
    std::cout << "Patient Name: " << patient1.p_Name << std::endl;
    std::cout << "Patient Age: " << patient1.age << std::endl;
    std::cout << "Date: " << (localTime->tm_year + 1900) << '-' << (localTime->tm_mon + 1) << '-' << localTime->tm_mday << std::endl;
    std::cout << "Time: " << localTime->tm_hour << ":" << localTime->tm_min << std::endl;

    // Assuming arbitrary charges
    float medicineCharges = 100.0; 
    float bedCharges = 200.0; 
    float hospitalCharges = 300.0; 
    float otherCharges = 50.0;

    // Calculate total amount
    float totalAmount = medicineCharges + bedCharges + hospitalCharges + otherCharges;

    // Display charges
    std::cout << "Medicine Charges: Rs " << medicineCharges << std::endl;
    std::cout << "Bed Charges: Rs " << bedCharges << std::endl; 
    std::cout << "Hospital Charges: Rs " << hospitalCharges << std::endl;
    std::cout << "Other Charges: Rs " << otherCharges << std::endl;
    std::cout << "Total Amount: Rs " << totalAmount << std::endl;

    return 0;
}
