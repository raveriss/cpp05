/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:01:43 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/16 22:39:43 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;  // Déclaration anticipée de la classe AForm


class AForm {
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

		class GradeTooHighException : public std::exception {
		public:
			const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			const char * what() const throw();
		};
		
		class FormNotSignedException : public std::exception {
		public:
			const char * what() const throw();
		};

};