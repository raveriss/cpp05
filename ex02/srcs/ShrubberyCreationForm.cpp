/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:02:30 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/17 15:52:26 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <sys/stat.h>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : AForm(other), target(other.target) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm & other) {
    if (this != & other) {
        AForm::operator = (other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

#include <fstream>
#include <sstream>
#include <iostream>
#include <sys/stat.h> // Pour la fonction stat

void ShrubberyCreationForm::executeAction() const {
    std::string baseFilename = target + "_shrubbery";
    std::string filename = baseFilename;
    struct stat fileStat;

    // Check if base file exists and its permissions
    if (stat(filename.c_str(), &fileStat) == 0 && (fileStat.st_mode & S_IWUSR) == 0) { // Fichier existant et non accessible en écriture
        std::cout << "File " << baseFilename << " already exists and is not writable. \n";
        int counter = 1;
        bool fileFound = false;

        while (!fileFound) {
            std::ostringstream oss;
            oss << baseFilename << "_" << counter++;
            filename = oss.str();
            
            // Check if new filename exists
            if (stat(filename.c_str(), &fileStat) == 0) {
                // File exists, check its permissions
                if ((fileStat.st_mode & S_IWUSR) == 0) {
                    std::cout << "File " << filename << " already exists and is not writable. \nTrying next suffix.\n";
                } else {
                    fileFound = true; // File exists and is writable
                }
            } else {
                fileFound = true; // File does not exist, can be created
            }
        }
        std::cout << "Creating a new file with suffix _" << counter - 1 << std::endl;
    }

    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        file << "      /\\\n";
        file << "     /\\*\\\n";
        file << "    /\\O\\*\\\n";
        file << "   /*/\\/\\/\\\n";
        file << "  /\\O\\/\\*\\/\\\n";
        file << " /\\*\\/\\*\\/\\/\\\n";
        file << "/\\O\\/\\/*/\\/O/\\\n";
        file << "      ||\n";
        file << "      ||\n";
        file.close();
        std::cout << "File " << filename << " created successfully." << std::endl;
    } else {
        std::cerr << "Failed to open file: " << filename << "\n";
    }
}







// void ShrubberyCreationForm::executeAction() const {
//     std::ofstream file((target + "_shrubbery").c_str());
//     if (file.is_open()) {
//         file << "      /\\\n";
//         file << "     /\\*\\\n";
//         file << "    /\\O\\*\\\n";
//         file << "   /*/\\/\\/\\\n";
//         file << "  /\\O\\/\\*\\/\\\n";
//         file << " /\\*\\/\\*\\/\\/\\\n";
//         file << "/\\O\\/\\/*/\\/O/\\\n";
//         file << "      ||\n";
//         file << "      ||\n";
//         file.close();
//     }
// }
