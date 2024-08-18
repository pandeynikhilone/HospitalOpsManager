#include <iostream>
#include <ctime>
#include "LL.hpp"
#include "BST.hpp"
#include "Hash.hpp"
#include "Matrix.hpp"
#include "console.hpp"

class CabinManager {
public:
    CabinManager() : patientCabin() {} // Cabins are automatically inserted in the BST constructor

    BinarySearchTree& getCabinTree() {
        return patientCabin;
    }

private:
    BinarySearchTree patientCabin;
};

int main() {
    CabinManager cabinManager;

    // 1. Patient Details
    LinkNode randomPatient = getRandomPatient();

    // 2. Cabin Allocation
    BinarySearchTree& cabinTree = cabinManager.getCabinTree();
    TreeNode* randomCabin = cabinTree.getRandomCabin();

    if (randomCabin != nullptr) {
        std::cout << "Patient is allotted to cabin: " << randomCabin->cabin_code << std::endl;
    } else {
        std::cout << "No cabins available." << std::endl;
    }

    // 3. Doctor's Prescription
    DoctorDatabase doctors;
    auto randomDoctor = doctors.getRandomDoctor();

    // 4. Medicine
    float medicineCharges = performMedicineSelection();

    // 5. Receipt
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    // Display receipt
    std::cout << "\nReceipt:\n";
    std::cout << "Patient ID: " << randomPatient.p_ID << std::endl;
    std::cout << "Patient Name: " << randomPatient.p_Name << std::endl;
    std::cout << "Description: " << randomPatient.description << std::endl;
    std::cout << "Age: " << randomPatient.age << std::endl;
    std::cout << "Sex: " << randomPatient.sex << std::endl;
    std::cout << "Blood Group: " << randomPatient.blood_group << std::endl;
    std::cout << "Assigned Doctor: " << randomDoctor.first << std::endl;
    std::cout << "Doctor's Degree: " << randomDoctor.second << std::endl;
    std::cout << "Assigned Cabin: " << randomCabin->cabin_code << std::endl;

    // Assuming arbitrary charges
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
