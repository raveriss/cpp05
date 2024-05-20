/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:02:30 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/20 14:20:57 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe ShrubberyCreationForm */
#include "../incs/ShrubberyCreationForm.hpp"

/**
 *  Constructeur par défaut de la classe ShrubberyCreationForm
 */
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("")
{
    std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
    throw std::invalid_argument("Target must be specified");
}

/**
 *  Constructeur avec paramètre de la classe ShrubberyCreationForm
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    if (_target.empty())
    {
        std::cout << "Error: Target must be specified '" << _target << " is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
    }
    
}

/**
 *  Constructeur de copie de la classe ShrubberyCreationForm
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other)
: AForm(other), _target(other._target)
{
    if (_target.empty())
    {
        std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
    }
}

/**
 *  Opérateur d'affectation de la classe ShrubberyCreationForm
 */
ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm & other)
{
    if (this != & other)
    {
        AForm::operator = (other);
		if (other._target.empty())
		{
			std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
			throw std::invalid_argument("Target must be specified");
		}
        _target = other._target;
    }
    return *this;
}

/**
 *  Destructeur de la classe ShrubberyCreationForm
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{}

/**
 *  Exécute l'action spécifique de ShrubberyCreationForm
 */
void ShrubberyCreationForm::executeAction() const
{
    std::string baseFilename = _target + "_shrubbery";
    std::string filename = baseFilename;
    struct stat fileStat;

    /**
     * Check if base file exists and its permissions
    */
    if (stat(filename.c_str(), &fileStat) == 0 && (fileStat.st_mode & S_IWUSR) == 0)
    {
        /** 
        * Fichier existant et non accessible en écriture
        */
        std::cout << "File " << baseFilename << " already exists and is not writable. \n";
        int counter = 1;
        bool fileFound = false;

        while (!fileFound)
        {
            std::ostringstream oss;
            oss << baseFilename << "_" << counter++;
            filename = oss.str();
            
            /**
             * Check if new filename exists
            */
            if (stat(filename.c_str(), &fileStat) == 0)
            {
                /**
                 * File exists, check its permissions
                */
                if ((fileStat.st_mode & S_IWUSR) == 0)
                    std::cout << "File " << filename << " already exists and is not writable. \nTrying next suffix.\n";
                else
                {
                    /**
                     * File exists and is writable
                    */
                    fileFound = true;
                }
            }
            else
            {
                /**
                 * File does not exist, can be created
                */
                fileFound = true;
            }
        }
        std::cout << "Creating a new file with suffix _" << counter - 1 << std::endl;
    }

    std::ofstream file(filename.c_str());
    if (file.is_open())
    {
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
    }
    else
        std::cerr << "Failed to open file: " << filename << "\n";
}

/* SHRUBBERYCREATIONFORM.CPP */