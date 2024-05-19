/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:59:02 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 11:57:32 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion du fichier d'en-tête de la classe AForm */
#include "AForm.hpp"

/* Inclusion de la bibliothèque standard pour les flux d'entrée/sortie */
#include <iostream>

/**
 * @brief Classe représentant un formulaire de grâce présidentielle, dérivée de AForm
 */
class PresidentialPardonForm : public AForm
{
    private:
        /* Cible de la grâce présidentielle */
        std::string target;

    protected:
        /* Exécute l'action de grâce présidentielle */
        void executeAction() const;

    public:
        /* Constructeur par défaut */
        PresidentialPardonForm();

        /* Constructeur avec cible */
        PresidentialPardonForm(const std::string & target);

        /* Constructeur de copie */
        PresidentialPardonForm(const PresidentialPardonForm & other);

        /* Opérateur d'affectation */
        PresidentialPardonForm & operator = (const PresidentialPardonForm & other);

        /* Destructeur */
        virtual ~PresidentialPardonForm();
};

/* PRESIDENTIALPARDONFORM.HPP */