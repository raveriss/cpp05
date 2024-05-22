/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:02:19 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/20 00:28:22 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe Form */
#include "../incs/Form.hpp"

/**
 *  Constructeur par défaut de la classe Form
 */
Form::Form()
: _name(""), _isSigned(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150)
{}

/**
 *  Constructeur avec paramètres de la classe Form
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
 *  Constructeur par copie de la classe Form
 */
Form::Form(const Form & src)
: _name(src._name), _isSigned(src._isSigned), _gradeRequiredToSign(src._gradeRequiredToSign), _gradeRequiredToExecute(src._gradeRequiredToExecute)
{}

/**
 *  Opérateur d'affectation de la classe Form
 */
Form& Form::operator = (const Form & rhs)
{
    if (this != & rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

/**
 *  Destructeur de la classe Form
 */
Form::~Form()
{}

/**
 *  Renvoie le nom du formulaire
 */
const std::string & Form::getName() const
{
    return _name;
}

/**
 *  Renvoie l'état de signature du formulaire
 */
bool Form::getIsSigned() const
{
    return _isSigned;
}

/**
 *  Renvoie le grade requis pour signer le formulaire
 */
int Form::getGradeRequiredToSign() const
{
    return _gradeRequiredToSign;
}

/**
 *  Renvoie le grade requis pour exécuter le formulaire
 */
int Form::getGradeRequiredToExecute() const
{
    return _gradeRequiredToExecute;
}

/**
 *  Signe le formulaire après vérification du grade et des exceptions
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
 *  Exception pour grade trop élevé dans la classe Form
 */
const char * Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

/**
 *  Exception pour grade trop bas dans la classe Form
 */
const char * Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

/**
 *  Surcharge de l'opérateur de flux pour la classe Form
 */
std::ostream& operator<<(std::ostream & os, const Form & form)
{
    os << form.getName() << ", Form grade required to sign: " << form.getGradeRequiredToSign()
       << ", Form grade required to execute: " << form.getGradeRequiredToExecute()
       << ", Is signed: " << (form.getIsSigned() ? "Yes" : "No");
    return os;
}

/* FORM.CPP */
