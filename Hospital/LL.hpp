// Data structure used in "Patient Details Managment" is "Simple Linked List"
// This Header file Contains implementation of "Linked List"

#ifndef LL_HPP
#define LL_HPP

#include <iostream>
#include <string>

struct LinkNode {
    int p_ID;                               // patient ID
    std::string p_Name;                     // patient name
    std::string description;                // description - A short description of health issue
    int age;                                // age of patient
    char sex;                               // m - Male / f - Female
    char blood_group;                       // blood group: A+, B+, AB+, O+, O-, A-, B-, AB-

    // node constructor to assign data members
    LinkNode(int a, std::string b, std::string c, int d, char e, char f) {
        p_ID = a;
        p_Name = b;
        description = c;
        age = d;
        sex = e;
        blood_group = f;
    }
};

#endif // LINKED_LIST_HPP


