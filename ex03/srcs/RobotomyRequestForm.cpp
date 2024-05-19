/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:01:09 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 11:47:55 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe RobotomyRequestForm */
#include "../incs/RobotomyRequestForm.hpp"

/**
 * @brief Constructeur par défaut de la classe RobotomyRequestForm
 */
RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), target("")
{}

/**
 * @brief Constructeur avec paramètre de la classe RobotomyRequestForm
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{}

/**
 * @brief Constructeur de copie de la classe RobotomyRequestForm
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
: AForm(other), target(other.target)
{}

/**
 * @brief Opérateur d'affectation de la classe RobotomyRequestForm
 */
RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm & other)
{
    if (this != & other)
    {
        AForm::operator = (other);
        target = other.target;
    }
    return *this;
}

/**
 * @brief Destructeur de la classe RobotomyRequestForm
 */
RobotomyRequestForm::~RobotomyRequestForm()
{}

/**
 * @brief Exécute l'action spécifique de RobotomyRequestForm
 */
void RobotomyRequestForm::executeAction() const
{
    std::cout << "Drilling noises...\n";
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully.\n";
    else
        std::cout << "Robotomy of " << target << " failed.\n";
}

/* ROBOTOMYREQUESTFORM.CPP */