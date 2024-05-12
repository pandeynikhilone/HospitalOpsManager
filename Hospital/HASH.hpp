// Data structure used in "doctor's prescription" is "Hash Map"
// This Header file Contains implementation of "Hash Map"

#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include <unordered_map>
#include <string>

class DoctorDatabase {
private:
    std::unordered_map<std::string, std::string> doctorSpecialties;

public:
    DoctorDatabase() {}

    // Add doctor along with their expertise
    void addDoctor(const std::string& doctorName, const std::string& expertise) {
        doctorSpecialties[doctorName] = expertise;
    }

    // Get expertise of a doctor
    std::string getExpertise(const std::string& doctorName) {
        if (doctorSpecialties.find(doctorName) != doctorSpecialties.end()) {
            return doctorSpecialties[doctorName];
        } else {
            return "Doctor not found";
        }
    }

    // List all doctors along with their expertise
    void listDoctors() {
        for (const auto& doctor : doctorSpecialties) {
            std::cout << "Doctor: " << doctor.first << ", Expertise: " << doctor.second << std::endl;
        }
    }
};

#endif // DOCTOR_DATABASE_H
