/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:02:19 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 12:14:46 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe Form */
#include "../incs/Form.hpp"

/**
 * @brief Constructeur par défaut de la classe Form
 */
Form::Form()
: _name(""), _isSigned(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150)
{}

/**
 * @brief Constructeur avec paramètres de la classe Form
 */
Form::Form(const std::string & name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign), _gradeRequiredToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

/**
 * @brief Constructeur par copie de la classe Form
 */
Form::Form(const Form & src)
: _name(src._name), _isSigned(src._isSigned), _gradeRequiredToSign(src._gradeRequiredToSign), _gradeRequiredToExecute(src._gradeRequiredToExecute)
{}

/**
 * @brief Opérateur d'affectation de la classe Form
 */
Form& Form::operator=(const Form & rhs)
{
    if (this != & rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

/**
 * @brief Destructeur de la classe Form
 */
Form::~Form()
{}

/**
 * @brief Renvoie le nom du formulaire
 */
const std::string & Form::getName() const
{
    return _name;
}

/**
 * @brief Renvoie l'état de signature du formulaire
 */
bool Form::getIsSigned() const
{
    return _isSigned;
}

/**
 * @brief Renvoie le grade requis pour signer le formulaire
 */
int Form::getGradeRequiredToSign() const
{
    return _gradeRequiredToSign;
}

/**
 * @brief Renvoie le grade requis pour exécuter le formulaire
 */
int Form::getGradeRequiredToExecute() const
{
    return _gradeRequiredToExecute;
}

/**
 * @brief Signe le formulaire après vérification du grade et des exceptions
 */
void Form::beSigned(const Bureaucrat & bureaucrat)

{
    if (_isSigned)
        throw std::logic_error("Form already signed.");
    if (bureaucrat.getGrade() <= _gradeRequiredToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

/**
 * @brief Exception pour grade trop élevé dans la classe Form
 */
const char * Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

/**
 * @brief Exception pour grade trop bas dans la classe Form
 */
const char * Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

/**
 * @brief Surcharge de l'opérateur de flux pour la classe Form
 */
std::ostream& operator<<(std::ostream & os, const Form & form)
{
    os << form.getName() << ", Form grade required to sign: " << form.getGradeRequiredToSign()
       << ", Form grade required to execute: " << form.getGradeRequiredToExecute()
       << ", Is signed: " << (form.getIsSigned() ? "Yes" : "No");
    return os;
}

/* FORM.CPP */
