/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:01:43 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 02:07:02 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

/**
 * @brief Déclaration anticipée de la classe Bureaucrat
 */
class Bureaucrat;

/**
 * @brief Déclaration de la classe Form avec gestion des signatures et exceptions de grade
 */

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeRequiredToSign;
        const int _gradeRequiredToExecute;

    public:
        Form();
        Form(const std::string & name, int gradeToSign, int gradeToExecute);
        Form(const Form & src);
        Form & operator = (const Form & rhs);
        ~Form();

        const std::string & getName() const;
        bool getIsSigned() const;
        int getGradeRequiredToSign() const;
        int getGradeRequiredToExecute() const;

        void beSigned(const Bureaucrat & bureaucrat);

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

/**
 * @brief Surcharge de l'opérateur de flux pour la classe Form
 */
std::ostream & operator << (std::ostream & os, const Form & form);

/* FORM.HPP */