/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:01:43 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 04:16:25 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Directive pour éviter les inclusions multiples d'un fichier d'en-tête
 */
#pragma once

/**
 * @brief Inclusion de la bibliothèque standard pour la gestion des chaînes de caractères
 */
#include <string>

/**
 * @brief Inclusion de la bibliothèque standard pour les flux d'entrée/sortie
 */
#include <iostream>

/**
 * @brief Inclusion du fichier d'en-tête de la classe Bureaucrat
 */
#include "Bureaucrat.hpp"

/**
 * @brief Déclaration anticipée de la classe Bureaucrat
 */
class Bureaucrat;

/**
 * @brief Classe abstraite représentant un formulaire avec des informations de signature et d'exécution
 */
class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;

	protected:
		virtual void executeAction() const = 0;

	public:
		AForm();
		AForm(const std::string & name, int gradeToSign, int gradeToExecute);
		AForm(const AForm & src);
		AForm & operator = (const AForm & rhs);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;

		void beSigned(const Bureaucrat & bureaucrat);
		bool execute(const Bureaucrat & executor) const;

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
		
		class FormNotSignedException : public std::exception
		{
			public:
				const char * what() const throw();
		};

};

/* AFORM.HPP */