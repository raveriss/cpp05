/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:01:43 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 12:06:11 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive évitant les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion bibliothèque standard chaînes de caractères */
#include <string>

/* Inclusion bibliothèque standard flux d'entrée/sortie */
#include <iostream>

/* Inclusion fichier d'en-tête classe Bureaucrat */
#include "Bureaucrat.hpp"

/* Déclaration anticipée classe Bureaucrat */
class Bureaucrat;

/**
 * @brief Classe abstraite représentant un formulaire avec des informations de signature et d'exécution
 */
class AForm
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

	protected:
        /* Méthode virtuelle pure pour exécuter l'action du formulaire */
		virtual void executeAction() const = 0;

	public:
		/* Constructeur par défaut de la classe AForm */
		AForm();

        /* Constructeur avec paramètres de la classe AForm */
		AForm(const std::string & name, int gradeToSign, int gradeToExecute);

        /* Constructeur par copie de la classe AForm */
		AForm(const AForm & src);

        /* Opérateur d'affectation de la classe AForm */
		AForm & operator = (const AForm & rhs);

        /* Destructeur de la classe AForm */
		virtual ~AForm();

        /* Obtient le nom du formulaire */
		std::string getName() const;

        /* Vérifie si le formulaire est signé */
		bool getIsSigned() const;

        /* Obtient le grade requis pour signer le formulaire */
		int getGradeRequiredToSign() const;

        /* Obtient le grade requis pour exécuter le formulaire */
		int getGradeRequiredToExecute() const;

        /* Permet de signer le formulaire */
		void beSigned(const Bureaucrat & bureaucrat);

        /* Exécute le formulaire */
		bool execute(const Bureaucrat & executor) const;

        /* Exception pour les grades trop élevés */
		class GradeTooHighException : public std::exception
		{
			public:
            	/* Message d'erreur pour les grades trop élevés */
				const char * what() const throw();
		};

        /* Exception pour les grades trop bas */
		class GradeTooLowException : public std::exception
		{
			public:
            	/* Message d'erreur pour les formulaires non signés */
				const char * what() const throw();
		};
		
		class FormNotSignedException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

/* AFORM.HPP */