#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstdlib>  
#include <ctime>   

class DoctorDatabase {
private:
    std::unordered_map<std::string, std::string> doctorDegrees;

public:
    // Constructor that automatically adds default doctors
    DoctorDatabase() {
        // Add default doctors and their degrees
        addDoctor("Dr. Smith", "MBBS, MD");
        addDoctor("Dr. Johnson", "MBBS, MS");
        addDoctor("Dr. Williams", "MBBS, PhD");
        addDoctor("Dr. Brown", "MBBS, MD");
        addDoctor("Dr. Taylor", "MBBS, MS");
    }

    // Add doctor along with their degree
    void addDoctor(const std::string& doctorName, const std::string& degree) {
        doctorDegrees[doctorName] = degree;
    }

    // Get degree of a doctor
    std::string getDegree(const std::string& doctorName) {
        if (doctorDegrees.find(doctorName) != doctorDegrees.end()) {
            return doctorDegrees[doctorName];
        } else {
            return "Doctor not found";
        }
    }

    // List all doctors along with their degrees
    void listDoctors() const {
        for (const auto& doctor : doctorDegrees) {
            std::cout << "Doctor: " << doctor.first << ", Degree: " << doctor.second << std::endl;
        }
    }

    // Function to randomly select a doctor
    std::pair<std::string, std::string> getRandomDoctor() {
        // Seed the random number generator
        std::srand(static_cast<unsigned>(std::time(0)));

        // Create a vector to store doctor names
        std::vector<std::string> doctorNames;
        for (const auto& doctor : doctorDegrees) {
            doctorNames.push_back(doctor.first);
        }

        // Get a random index
        int randomIndex = std::rand() % doctorNames.size();

        // Return the randomly selected doctor and their degree
        std::string selectedDoctorName = doctorNames[randomIndex];
        return {selectedDoctorName, doctorDegrees[selectedDoctorName]};
    }
};

// Create a global instance of DoctorDatabase with predefined doctors
DoctorDatabase doctors;

#endif // HASH_HPP
