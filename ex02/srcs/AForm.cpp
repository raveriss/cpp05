/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:02:19 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 21:54:59 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe AForm */
#include "../incs/AForm.hpp"

/**
 *  Constructeur par défaut de la classe AForm
 */
AForm::AForm()
: _name("Default"), _isSigned(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150)
{}

/**
 *  Constructeur avec paramètres de la classe AForm, vérifie les exceptions de grade
 */
AForm::AForm(const std::string & name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign), _gradeRequiredToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

/**
 * Constructeur par copie de la classe AForm
 */
AForm::AForm(const AForm & src)
: _name(src._name), _isSigned(src._isSigned), _gradeRequiredToSign(src._gradeRequiredToSign), _gradeRequiredToExecute(src._gradeRequiredToExecute)
{}

/**
 *  Opérateur d'affectation de la classe AForm
 */
AForm& AForm::operator = (const AForm & rhs)
{
    if (this != & rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

/**
 *  Destructeur de la classe AForm
 */
AForm::~AForm()
{}

/**
 *  Acceseur du nom du formulaire
 */
std::string AForm::getName() const
{
    return _name;
}

/**
 *  Renvoie l'état de signature du formulaire
 */
bool AForm::getIsSigned() const
{
    return _isSigned;
}

/**
 *  Renvoie le grade requis pour signer le formulaire
 */
int AForm::getGradeRequiredToSign() const
{
    return _gradeRequiredToSign;
}

/**
 *  Renvoie le grade requis pour exécuter le formulaire
 */
int AForm::getGradeRequiredToExecute() const
{
    return _gradeRequiredToExecute;
}

/**
 *  Signe le formulaire après vérification du grade et des exceptions
 */
void AForm::beSigned(const Bureaucrat & bureaucrat)
{
    if (_isSigned)
        throw std::logic_error("AForm already signed.");
    if (bureaucrat.getGrade() <= _gradeRequiredToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

/**
 *  Exécute le formulaire après vérification des conditions et des exceptions
 */
void AForm::execute(const Bureaucrat & executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeRequiredToExecute)
        throw GradeTooLowException();
    executeAction();
}

/**
 *  Surcharge de l'opérateur de flux pour la classe AForm
 */
std::ostream & operator<<(std::ostream & os, const AForm & AForm)
{
    os << AForm.getName() << ", AForm grade required to sign: " << AForm.getGradeRequiredToSign()
       << ", AForm grade required to execute: " << AForm.getGradeRequiredToExecute()
       << ", Is signed: " << (AForm.getIsSigned() ? "Yes" : "No");
    return os;
}

/**
 *  Exception pour grade trop élevé dans la classe AForm
 */
const char * AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

/**
 *  Exception pour grade trop bas dans la classe AForm
 */
const char * AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

/**
 *  Exception pour formulaire non signé dans la classe AForm
 */
const char * AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

/* AFORM.CPP */