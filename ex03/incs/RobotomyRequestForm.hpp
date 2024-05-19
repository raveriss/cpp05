/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:01:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 11:56:09 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion du fichier d'en-tête de la classe AForm */
#include "AForm.hpp"

/* Inclusion de la bibliothèque standard pour les fonctions utilitaires générales */
#include <cstdlib>

/* Inclusion de la bibliothèque standard pour les flux d'entrée/sortie */
#include <iostream>

/**
 * @brief Classe représentant un formulaire de demande de robotomie, dérivée de AForm
 */
class RobotomyRequestForm : public AForm
{
    private:
        /* Cible de la demande de robotomie */
        std::string target;

    protected:
        /* Exécute l'action de robotomie */
        void executeAction() const;

    public:
        /* Constructeur par défaut */
        RobotomyRequestForm();

        /* Constructeur avec cible */
        RobotomyRequestForm(const std::string & target);

        /* Constructeur de copie */
        RobotomyRequestForm(const RobotomyRequestForm & other);

        /* Opérateur d'affectation */
        RobotomyRequestForm & operator = (const RobotomyRequestForm & other);

        /* Destructeur */
        virtual ~RobotomyRequestForm();
};

/* ROBOTOMYREQUESTFORM.HPP */