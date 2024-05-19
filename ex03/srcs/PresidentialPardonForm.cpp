/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:58:30 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 11:48:06 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe PresidentialPardonForm */
#include "../incs/PresidentialPardonForm.hpp"

/**
 * @brief Constructeur par défaut de la classe PresidentialPardonForm
 */
PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), target("")
{}

/**
 * @brief Constructeur avec paramètre de la classe PresidentialPardonForm
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{}

/**
 * @brief Constructeur de copie de la classe PresidentialPardonForm
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other)
: AForm(other), target(other.target)
{}

/**
 * @brief Opérateur d'affectation de la classe PresidentialPardonForm
 */
PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm & other)
{
    if (this != & other)
    {
        AForm::operator = (other);
        target = other.target;
    }
    return *this;
}

/**
 * @brief Destructeur de la classe PresidentialPardonForm
 */
PresidentialPardonForm::~PresidentialPardonForm()
{}

/**
 * @brief Exécute l'action spécifique de PresidentialPardonForm
 */
void PresidentialPardonForm::executeAction() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}

/* PRESIDENTIALPARDONFORM.CPP */