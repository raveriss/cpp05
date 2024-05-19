/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 23:55:04 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe Bureaucrat */
#include "../incs/Bureaucrat.hpp"

/* Inclusion du fichier d'en-tête pour l'utilisation de isdigit() */
#include <cctype> 

/**
 *  Constructeur par défaut de la classe Bureaucrat
 */
Bureaucrat::Bureaucrat()
: _name("Default"), _grade(150)
{}

/**
 *  Vérifie si un nom est valide
 */
bool isValidName(const std::string& name)
{
	if (name.empty())
		return false;
	for (size_t i = 0; i < name.length(); ++i)
	{
		if (std::isdigit(name[i]))
			return false;
	}
	return true;
}

/**
 *  Constructeur avec paramètres de la classe Bureaucrat, vérifie les exceptions de grade
 */
Bureaucrat::Bureaucrat(const std::string & name, int grade)
: _name(name), _grade(grade)
{
	if (!isValidName(name))
	{
		std::cout << "Invalid name: Name must not be empty and must not contain digits\n";
		throw InvalidNameException();
	}
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

/**
 *  Constructeur par copie de la classe Bureaucrat
 */
Bureaucrat::Bureaucrat(const Bureaucrat & rootBureaucrat)
: _name(rootBureaucrat._name), _grade(rootBureaucrat._grade)
{
	if (!isValidName(rootBureaucrat._name))
	{
		std::cout << "Invalid name: Name must not be empty and must not contain digits\n";
		throw InvalidNameException();
	}
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

/**
 *  Opérateur d'affectation de la classe Bureaucrat
 */
Bureaucrat & Bureaucrat :: operator = (const Bureaucrat & rootBureaucrat)
{
	if (this != &rootBureaucrat)
	{
		if (!isValidName(rootBureaucrat._name))
		{
			std::cout << "Invalid name: Name must not be empty and must not contain digits\n";
			throw InvalidNameException();
		}
		if (rootBureaucrat._grade < 1)
			throw GradeTooHighException();
		if (rootBureaucrat._grade > 150)
			throw GradeTooLowException();
		_grade = rootBureaucrat._grade;
	}
	return *this;
}

/**
 *  Destructeur de la classe Bureaucrat
 */
Bureaucrat::~Bureaucrat()
{}

/**
 *  Renvoie le nom du Bureaucrat
 */
const std::string & Bureaucrat::getName() const
{
	return _name;
}

/**
 *  Renvoie le grade du Bureaucrat
 */
int Bureaucrat::getGrade() const
{
	return _grade;
}

/**
 *  Incrémente le grade du Bureaucrat en vérifiant les exceptions
 */
void Bureaucrat::incrementGrade()
{
	if (_grade <= 1) throw GradeTooHighException();
	--_grade;
}

/**
 *  Décrémente le grade du Bureaucrat en vérifiant les exceptions
 */
void Bureaucrat::decrementGrade()
{
	if (_grade >= 150) throw GradeTooLowException();
	++_grade;
}

/**
 *  Signe un formulaire en attrapant les exceptions possibles
 */
void Bureaucrat::signForm(Form & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::logic_error& e)
	{
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

/**
 *  Exception pour un grade trop élevé dans la classe Bureaucrat
 */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

/**
 *  Exception pour un grade trop bas dans la classe Bureaucrat
 */
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

/**
 *  Surcharge de l'opérateur de flux pour la classe Bureaucrat
 */
std::ostream & operator << (std::ostream & os, const Bureaucrat & b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return os;
}

/* BUREAUCRAT.CPP */
