/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:06 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/16 22:31:07 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <Form.hpp>

class Form;  // Déclaration anticipée de la classe Form


class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string & name, int grade);
		Bureaucrat(const Bureaucrat & rootBureaucrat);
		Bureaucrat & operator = (const Bureaucrat & rootBureaucrat);
		~Bureaucrat();
		

		const std::string & getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

    	void signForm(Form & form) const;


		class GradeTooHighException : public std::exception {
		public:
			const char * what() const throw() {
				return "Grade too high";
			}
		};

		class GradeTooLowException : public std::exception {
		public:
			const char * what() const throw() {
				return "Grade too low";
			}
		};
};

std::ostream & operator << (std::ostream & os, const Bureaucrat & b);

