/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:47:28 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 16:22:40 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe Intern */
#include "../incs/Intern.hpp"

/* Inclusion du fichier d'en-tête de la classe ShrubberyCreationForm */
#include "../incs/ShrubberyCreationForm.hpp"

/* Inclusion du fichier d'en-tête de la classe RobotomyRequestForm */
#include "../incs/RobotomyRequestForm.hpp"

/* Inclusion du fichier d'en-tête de la classe PresidentialPardonForm */
#include "../incs/PresidentialPardonForm.hpp"

/* Inclusion de la bibliothèque standard pour les flux d'entrée/sortie */
#include <iostream>

/**
 *  Constructeur par défaut de la classe Intern
 */
Intern::Intern()
{}

/**
 *  Constructeur de copie de la classe Intern
 */
Intern::Intern(const Intern & other)
{
    *this = other;
}

/**
 *  Constructeur par copie et opérateur d'affectation de la classe Intern
 */
Intern & Intern::operator = (const Intern & other)
{
    if (this != & other)
    {}
    return *this;
}

/**
 *  Destructeur de la classe Intern
 */
Intern::~Intern()
{}

/**
 *  Crée un formulaire en fonction du nom et de la cible spécifiés
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
 *  Crée un formulaire ShrubberyCreation avec la cible spécifiée
 */
AForm * Intern::createShrubberyCreation(const std::string & target) const
{
    return new ShrubberyCreationForm(target);
}

/**
 *  Crée un formulaire RobotomyRequest avec la cible spécifiée
 */
AForm * Intern::createRobotomyRequest(const std::string & target) const
{
    return new RobotomyRequestForm(target);
}

/**
 *  Crée un formulaire PresidentialPardon avec la cible spécifiée
 */

AForm * Intern::createPresidentialPardon(const std::string & target) const
{
    return new PresidentialPardonForm(target);
}

/* INTERN.CPP */