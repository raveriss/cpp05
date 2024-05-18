/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:06 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 02:44:35 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <AForm.hpp>
#include <Bureaucrat.hpp>

/**
 * @brief Déclaration anticipée de la classe Form
 */
class AForm;

/*
 * @brief Classe représentant un bureaucrate
 */
class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string & name, int grade);
		Bureaucrat(const Bureaucrat & rootBureaucrat);
		Bureaucrat & operator = (const Bureaucrat & rootBureaucrat);
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

