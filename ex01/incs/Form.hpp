/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:01:43 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 12:13:06 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion bibliothèque standard pour gestion chaînes de caractères */
#include <string>

/* Inclusion de la bibliothèque standard pour les flux d'entrée/sortie */
#include <iostream>

/* Inclusion du fichier d'en-tête de la classe Bureaucrat */
#include "Bureaucrat.hpp"

/* Déclaration anticipée de la classe Bureaucrat */
class Bureaucrat;

/**
 * @brief Déclaration de la classe Form avec gestion des signatures et exceptions de grade
 */
class Form
{
    private:
		/* Nom du bureaucrate */
        const std::string _name;

        /* Indicateur de signature du formulaire */
        bool _isSigned;

        /* Grade requis pour signer le formulaire */
        const int _gradeRequiredToSign;

        /* Grade requis pour exécuter le formulaire */
        const int _gradeRequiredToExecute;

    public:
		/* Constructeur par défaut de la classe Form */
        Form();

        /* Constructeur avec paramètres de la classe Form */
        Form(const std::string & name, int gradeToSign, int gradeToExecute);

        /* Constructeur par copie de la classe AForm */
        Form(const Form & src);

		/* Opérateur d'affectation de la classe Form */
        Form & operator = (const Form & rhs);

		/* Destructeur de la classe Form */
        ~Form();

		/* Obtient le nom du bureaucrate */
        const std::string & getName() const;

        /* Vérifie si le formulaire est signé */
        bool getIsSigned() const;

        /* Obtient le grade requis pour signer le formulaire */
        int getGradeRequiredToSign() const;

        /* Obtient le grade requis pour exécuter le formulaire */
        int getGradeRequiredToExecute() const;

        /* Permet de signer le formulaire */
        void beSigned(const Bureaucrat & bureaucrat);

		/* Exception pour les grades trop élevés */
        class GradeTooHighException : public std::exception
        {
			/* Message d'erreur pour les grades trop élevés */
            public:
                const char * what() const throw();
        };
        
		/* Exception pour les grades trop bas */
        class GradeTooLowException : public std::exception
        {
            public:
				/* Message d'erreur pour les grades trop bas */
                const char * what() const throw();
        };

};

/**
 * @brief Surcharge de l'opérateur de flux pour la classe Form
 */
std::ostream & operator << (std::ostream & os, const Form & form);

/* FORM.HPP */