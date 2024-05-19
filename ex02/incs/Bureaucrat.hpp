/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:06 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 02:12:40 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @brief Directive pour éviter les inclusions multiples d'un fichier d'en-tête **/
#pragma once

/** @brief Inclusion de la bibliothèque standard pour les flux d'entrée/sortie **/
#include <iostream>

/** @brief Inclusion de la bibliothèque standard pour la gestion des exceptions **/
#include <stdexcept>

/** @brief Inclusion du fichier d'en-tête de la classe AForm **/
#include <AForm.hpp>

/** @brief Inclusion du fichier d'en-tête de la classe Bureaucrat **/
#include <Bureaucrat.hpp>

/** @brief Déclaration anticipée de la classe AForm **/
class AForm;

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
		
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form) const;
		void executeForm(const AForm &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

/**
 * @brief Opérateur de sortie pour la classe Bureaucrat
 */
std::ostream & operator << (std::ostream & out, const Bureaucrat & bureaucrat);

/* BUREAUCRAT.HPP */

