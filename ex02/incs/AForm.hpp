/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:01:43 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 02:44:08 by raveriss         ###   ########.fr       */
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
        void execute(const Bureaucrat & executor) const;

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