/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:47:28 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 03:59:59 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Inclusion du fichier d'en-tête de la classe Intern
 */
#include "../incs/Intern.hpp"

/**
 * @brief Inclusion du fichier d'en-tête de la classe ShrubberyCreationForm
 */
#include "../incs/ShrubberyCreationForm.hpp"

/**
 * @brief Inclusion du fichier d'en-tête de la classe RobotomyRequestForm
 */
#include "../incs/RobotomyRequestForm.hpp"

/**
 * @brief Inclusion du fichier d'en-tête de la classe PresidentialPardonForm
 */
#include "../incs/PresidentialPardonForm.hpp"

/**
 * @brief Inclusion de la bibliothèque standard pour les flux d'entrée/sortie
 */
#include <iostream>

/**
 * @brief Constructeur par défaut de la classe Intern
 */
Intern::Intern()
{}

/**
 * @brief Constructeur de copie de la classe Intern
 */
Intern::Intern(const Intern & other)
{
    *this = other;
}

/**
 * @brief Constructeur par copie et opérateur d'affectation de la classe Intern
 */
Intern & Intern::operator = (const Intern & other)
{
    if (this != & other)
    {}
    return *this;
}

/**
 * @brief Destructeur de la classe Intern
 */
Intern::~Intern()
{}

/**
 * @brief Crée un formulaire en fonction du nom et de la cible spécifiés
 */
AForm * Intern::makeForm(const std::string & formName, const std::string & target) const
{
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*formCreators[3])(const std::string&) const = {
        &Intern::createShrubberyCreation,
        &Intern::createRobotomyRequest,
        &Intern::createPresidentialPardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i])
        {
            AForm* form = (this->*formCreators[i])(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    std::cout << "Error: Form name '" << formName << "' is not recognized." << std::endl;
    return NULL;
}

/**
 * @brief Crée un formulaire ShrubberyCreation avec la cible spécifiée
 */
AForm * Intern::createShrubberyCreation(const std::string & target) const
{
    return new ShrubberyCreationForm(target);
}

/**
 * @brief Crée un formulaire RobotomyRequest avec la cible spécifiée
 */
AForm * Intern::createRobotomyRequest(const std::string & target) const
{
    return new RobotomyRequestForm(target);
}

/**
 * @brief Crée un formulaire PresidentialPardon avec la cible spécifiée
 */

AForm * Intern::createPresidentialPardon(const std::string & target) const
{
    return new PresidentialPardonForm(target);
}

/* INTERN.CPP */