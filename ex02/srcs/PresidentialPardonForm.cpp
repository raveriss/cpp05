/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:58:30 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 16:22:40 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe PresidentialPardonForm */
#include "PresidentialPardonForm.hpp"

/**
 *  Constructeur par défaut de la classe PresidentialPardonForm
 */
PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), target("")
{}

/**
 *  Constructeur avec paramètre de la classe PresidentialPardonForm
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{}

/**
 *  Constructeur de copie de la classe PresidentialPardonForm
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), target(other.target)
{}

/**
 *  Opérateur d'affectation de la classe PresidentialPardonForm
 */
PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm & other)
{
    if (this != & other)
    {
        AForm::operator=(other);
        target = other.target;
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
    std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}

/* PRESIDENTIALPARDONFORM.CPP */