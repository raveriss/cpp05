/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:06 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 02:13:17 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @brief Directive pour éviter les inclusions multiples d'un fichier d'en-tête **/
#pragma once

/** @brief Inclusion de la bibliothèque standard pour les flux d'entrée/sortie **/
#include <iostream>

/** @brief Inclusion de la bibliothèque standard pour la gestion des exceptions **/
#include <stdexcept>

/** @brief Inclusion du fichier d'en-tête de la classe Form **/
#include <Form.hpp>

/** @brief Déclaration anticipée de la classe Form **/
class Form;

/**
 * @brief Classe représentant un bureaucrate
 */
class Bureaucrat
{
	private:
		/** @brief Nom du bureaucrate **/
		const std::string _name;
		
		/** @brief grade du bureaucrate **/
		int _grade;

	public:
		/** @brief Constructeur par défaut de la classe Bureaucrat **/
		Bureaucrat();

		/** @brief Constructeur avec paramètres de la classe Bureaucrat **/
		Bureaucrat(const std::string & name, int grade);

		/** @brief Constructeur de copie de la classe Bureaucrat **/
		Bureaucrat(const Bureaucrat & rootBureaucrat);

		/** @brief Opérateur d'affectation de la classe Bureaucrat **/
		Bureaucrat & operator = (const Bureaucrat & rootBureaucrat);

		/** @brief Destructeur de la classe Bureaucrat **/
		~Bureaucrat();
		
		/** @brief Obtient le nom du bureaucrate **/
		const std::string & getName() const;

		/** @brief Obtient le grade du bureaucrate **/
		int getGrade() const;

		/** @brief Incrémente le grade du bureaucrate **/
		void incrementGrade();

		/** @brief Décrémente le grade du bureaucrate **/
		void decrementGrade();

		/** @brief Fait signer un formulaire par le bureaucrate **/
    	void signForm(Form & form) const;

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
 * @brief Opérateur de sortie pour la classe Bureaucrat
 */
std::ostream & operator << (std::ostream & os, const Bureaucrat & b);

/* BUREAUCRAT.HPP */

