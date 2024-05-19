/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:46:56 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 11:33:11 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion du fichier d'en-tête de la classe Intern */
#include "AForm.hpp"

/* Inclusion de la bibliothèque standard pour la gestion des chaînes de caractères */
#include <string>

/**
 * @brief Classe représentant un stagiaire capable de créer différents formulaires
 */
class Intern
{
    public:
        /* Constructeur par défaut */
        Intern();

        /* Constructeur de copie */
        Intern(const Intern & other);

        /* Opérateur d'affectation */
        Intern & operator = (const Intern & other);

        /* Destructeur */
        ~Intern();

        /* Crée un formulaire en fonction du nom et de la cible */
        AForm * makeForm(const std::string & formName, const std::string & target) const;

    private:
        /* Crée un formulaire de création d'arbustes */
        AForm * createShrubberyCreation(const std::string & target) const;

        /* Crée un formulaire de demande de robotomie */
        AForm * createRobotomyRequest(const std::string & target) const;

        /* Crée un formulaire de grâce présidentielle */
        AForm * createPresidentialPardon(const std::string & target) const;
};

/* INTERN.HPP */
