/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:06 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 12:11:32 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Directive pour éviter les inclusions multiples d'un fichier d'en-tête */
#pragma once

/* Inclusion de la bibliothèque standard pour les flux d'entrée/sortie */
#include <iostream>

/* Inclusion de la bibliothèque standard pour la gestion des exceptions */
#include <stdexcept>

/* Inclusion du fichier d'en-tête de la classe Form */
#include <Form.hpp>

/* Déclaration anticipée de la classe Form */
class Form;

/**
 * @brief Classe représentant un bureaucrate
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

		/* Fait signer un formulaire par le bureaucrate */
    	void signForm(Form & form) const;

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
 * @brief Opérateur de sortie pour la classe Bureaucrat
 */
std::ostream & operator << (std::ostream & os, const Bureaucrat & b);

/* BUREAUCRAT.HPP */

