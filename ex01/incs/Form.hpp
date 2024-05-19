/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:01:43 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 01:43:57 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @brief Directive pour éviter les inclusions multiples d'un fichier d'en-tête **/
#pragma once

/** @brief Inclusion bibliothèque standard pour gestion chaînes de caractères **/
#include <string>

/** @brief Inclusion de la bibliothèque standard pour les flux d'entrée/sortie **/
#include <iostream>

/** @brief Inclusion du fichier d'en-tête de la classe Bureaucrat **/
#include "Bureaucrat.hpp"

/** @brief Déclaration anticipée de la classe Bureaucrat **/
class Bureaucrat;

/**
 * @brief Déclaration de la classe Form avec gestion des signatures et exceptions de grade
 */
class Form
{
    private:
		/** @brief Nom du bureaucrate **/
        const std::string _name;

        /** @brief Indicateur de signature du formulaire **/
        bool _isSigned;

        /** @brief Grade requis pour signer le formulaire **/
        const int _gradeRequiredToSign;

        /** @brief Grade requis pour exécuter le formulaire **/
        const int _gradeRequiredToExecute;

    public:
		/** @brief Constructeur par défaut de la classe Form **/
        Form();

        /** @brief Constructeur avec paramètres de la classe Form **/
        Form(const std::string & name, int gradeToSign, int gradeToExecute);

        /** @brief Constructeur par copie de la classe AForm **/
        Form(const Form & src);

		/** @brief Opérateur d'affectation de la classe Form **/
        Form & operator = (const Form & rhs);

		/** @brief Destructeur de la classe Form **/
        ~Form();

		/** @brief Obtient le nom du bureaucrate **/
        const std::string & getName() const;

        /** @brief Vérifie si le formulaire est signé **/
        bool getIsSigned() const;

        /** @brief Obtient le grade requis pour signer le formulaire **/
        int getGradeRequiredToSign() const;

        /** @brief Obtient le grade requis pour exécuter le formulaire **/
        int getGradeRequiredToExecute() const;

        /** @brief Permet de signer le formulaire **/
        void beSigned(const Bureaucrat & bureaucrat);

		/** @brief Exception pour les grades trop élevés **/
        class GradeTooHighException : public std::exception
        {
			/** @brief Message d'erreur pour les grades trop élevés **/
            public:
                const char * what() const throw()
                {
                    return "Grade too high";
                }
        };
        
		/** @brief Exception pour les grades trop bas **/
        class GradeTooLowException : public std::exception
        {
            public:
				/** @brief Message d'erreur pour les grades trop bas **/
                const char * what() const throw()
                {
                    return "Grade too low";
                }
        };

};

/**
 * @brief Surcharge de l'opérateur de flux pour la classe Form
 */
std::ostream & operator << (std::ostream & os, const Form & form);

/* FORM.HPP */