#ifndef LL_HPP
#define LL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  
#include <ctime>    

struct LinkNode {
    int p_ID;                               // patient ID
    std::string p_Name;                     // patient name
    std::string description;                // description - A short description of health issue
    int age;                                // age of patient
    char sex;                               // m - Male / f - Female
    char blood_group;                       // blood group: A+, B+, AB+, O+, O-, A-, B-, AB-

    // node constructor to assign data members
    LinkNode(int a, std::string b, std::string c, int d, char e, char f)
        : p_ID(a), p_Name(b), description(c), age(d), sex(e), blood_group(f) {}
};

// Create a vector of patient nodes
std::vector<LinkNode> patients = {
    LinkNode(1, "John Doe", "Fever", 30, 'm', 'O+'),
    LinkNode(2, "Jane Smith", "Cough", 25, 'f', 'A+'),
    LinkNode(3, "Mark Taylor", "Headache", 40, 'm', 'B-'),
    LinkNode(4, "Lucy Brown", "Cold", 28, 'f', 'AB+'),
    LinkNode(5, "Robert Wilson", "Stomach Pain", 35, 'm', 'O-')
};

// Function to randomly select a patient
LinkNode getRandomPatient() {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    // Get a random index
    int randomIndex = std::rand() % patients.size();

    // Return the randomly selected patient
    return patients[randomIndex];
}

#endif // LL_HPP
