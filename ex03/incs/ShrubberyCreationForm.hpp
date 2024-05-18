/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:02:46 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 00:32:22 by raveriss         ###   ########.fr       */
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
 * @brief Inclusion de la bibliothèque standard pour la gestion des fichiers
 */
#include <fstream>

/**
 * @brief Inclusion de la bibliothèque standard pour les flux d'entrée/sortie
 */
#include <iostream>

/**
 * @brief Inclusion de la bibliothèque standard pour la gestion des flux de chaînes
 */
#include <sstream>

/**
 * @brief Inclusion de la bibliothèque standard pour la gestion des informations de fichier
 */
#include <sys/stat.h>

/**
 * @brief Classe représentant un formulaire de création d'arbustes, dérivée de AForm
 */
class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    protected:
        void executeAction() const;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm(const ShrubberyCreationForm & other);
        ShrubberyCreationForm & operator = (const ShrubberyCreationForm & other);
        virtual ~ShrubberyCreationForm();
};

/* SHRUBBERYCREATIONFORM.HPP */