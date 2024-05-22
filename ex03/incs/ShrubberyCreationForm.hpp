/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:02:46 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/20 17:31:31 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion du fichier d'en-tête de la classe AForm */
#include "AForm.hpp"

/* Inclusion de la bibliothèque standard pour la gestion des fichiers */
#include <fstream>

/* Inclusion de la bibliothèque standard pour les flux d'entrée/sortie */
#include <iostream>

/* Inclusion de la bibliothèque standard pour la gestion des flux de chaînes */
#include <sstream>

/* Inclusion de la bibliothèque standard pour la gestion des informations de fichier */
#include <sys/stat.h>

/**
 *  Classe représentant un formulaire de création d'arbustes, dérivée de AForm
 */
class ShrubberyCreationForm : public AForm
{
    private:
        /* Cible de la création d'arbustes */
        std::string _target;

    protected:
        /* Exécute l'action de création d'arbustes */
        void executeAction() const;

    public:
        /* Constructeur par défaut */
        ShrubberyCreationForm();

        /* Constructeur avec cible */
        ShrubberyCreationForm(const std::string & target);

        /* Constructeur de copie */
        ShrubberyCreationForm(const ShrubberyCreationForm & other);

        /* Opérateur d'affectation */
        ShrubberyCreationForm & operator = (const ShrubberyCreationForm & other);

        /* Destructeur */
        virtual ~ShrubberyCreationForm();

        /* Accesseur pour la cible */
        std::string getTarget() const;
};

/* SHRUBBERYCREATIONFORM.HPP */