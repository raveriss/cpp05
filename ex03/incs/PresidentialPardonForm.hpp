/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:59:02 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 04:08:09 by raveriss         ###   ########.fr       */
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
 * @brief Classe représentant un formulaire de grâce présidentielle, dérivée de AForm
 */
class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    protected:
        void executeAction() const;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string & target);
        PresidentialPardonForm(const PresidentialPardonForm & other);
        PresidentialPardonForm & operator = (const PresidentialPardonForm & other);
        virtual ~PresidentialPardonForm();
};

/* PRESIDENTIALPARDONFORM.HPP */