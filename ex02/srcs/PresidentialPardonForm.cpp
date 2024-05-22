/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:58:30 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/20 21:19:02 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe PresidentialPardonForm */
#include "PresidentialPardonForm.hpp"

/**
 *  Constructeur par défaut de la classe PresidentialPardonForm
 */
PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("")
{
    std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
    throw std::invalid_argument("Target must be specified");
}

/**
 *  Constructeur avec paramètre de la classe PresidentialPardonForm
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    if (_target.empty())
    {
        std::cout << "Error: Target must be specified '" << _target << " is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
    }
}

/**
 *  Constructeur de copie de la classe PresidentialPardonForm
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), _target(other._target)
{
    if (_target.empty())
    {
        std::cout << "Error: Target must be specified '" << _target << " is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");

    }
}

/**
 *  Opérateur d'affectation de la classe PresidentialPardonForm
 */
PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm & other)
{
    if (this != & other)
    {
        AForm::operator = (other);
        if (other._target.empty())
        {
			std::cout << "Error: Target must be specified '" << _target << " is not recognized." << std::endl;
            throw std::invalid_argument("Target must be specified");
        }
        _target = other._target;
    }
    return *this;
}

/**
 *  Destructeur de la classe PresidentialPardonForm
 */
PresidentialPardonForm::~PresidentialPardonForm()
{}

/**
 *  Exécute l'action spécifique de PresidentialPardonForm
 */
void PresidentialPardonForm::executeAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}

/**
 *  Accesseur pour la cible
 */
std::string PresidentialPardonForm::getTarget() const
{
    return _target;
}

/* PRESIDENTIALPARDONFORM.CPP */