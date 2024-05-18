/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:01:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 00:32:12 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Directive pour éviter les inclusions multiples d'un fichier d'en-tête
 */
#pragma once

/**
 * @brief Inclusion du fichier d'en-tête de la classe Intern
 */
#include "AForm.hpp"

/**
 * @brief Inclusion de la bibliothèque standard pour les flux d'entrée/sortie
 */
#include <iostream>

/**
 * @brief Inclusion de la bibliothèque standard pour les fonctions utilitaires générales
 */
#include <cstdlib>

/**
 * @brief Classe représentant un formulaire de demande de robotomie, dérivée de AForm
 */
class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    protected:
        void executeAction() const;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string & target);
        RobotomyRequestForm(const RobotomyRequestForm & other);
        RobotomyRequestForm & operator = (const RobotomyRequestForm & other);
        virtual ~RobotomyRequestForm();
};

/* ROBOTOMYREQUESTFORM.HPP */