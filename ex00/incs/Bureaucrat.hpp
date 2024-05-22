/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:06 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 23:40:00 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive évitant les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion bibliothèque standard flux d'entrée/sortie */
#include <iostream>

/* Inclusion bibliothèque standard gestion des exceptions */
#include <stdexcept>

/**
 *  Classe représentant un bureaucrate
 */
class Bureaucrat
{
	private:
		/* Nom du bureaucrate */
		const std::string _name;

		/* grade du bureaucrate */
		int _grade;

	public:
		/* Constructeur par défaut de la classe Bureaucrat */
		Bureaucrat();

		/* Constructeur avec paramètres de la classe Bureaucrat */
		Bureaucrat(const std::string & name, int grade);
		
		/* Constructeur de copie de la classe Bureaucrat */
		Bureaucrat(const Bureaucrat & rootBureaucrat);

		/* Opérateur d'affectation de la classe Bureaucrat */
		Bureaucrat & operator = (const Bureaucrat & rootBureaucrat);

		/* Destructeur de la classe Bureaucrat */
		~Bureaucrat();

		/* Obtient le nom du bureaucrate */
		const std::string & getName() const;
		
		/* Obtient le grade du bureaucrate */
		int getGrade() const;

		/* Incrémente le grade du bureaucrate */
		void incrementGrade();

		/* Décrémente le grade du bureaucrate */
		void decrementGrade();

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

		/* Exception pour les noms invalides */
        class InvalidNameException : public std::exception
        {
            public:
                const char * what () const throw ();
        };
};

/**
 *  Opérateur de sortie pour la classe Bureaucrat
 */
std::ostream & operator << (std::ostream & os, const Bureaucrat & b);

/* BUREAUCRAT.HPP */