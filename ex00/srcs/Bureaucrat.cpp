/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/20 13:54:15 by raveriss         ###   ########.fr       */
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
 *  Constructeur avec paramètres de la classe Bureaucrat
 */
Bureaucrat::Bureaucrat(const std::string& name, int grade)
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
 *  Constructeur de copie de la classe Bureaucrat
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
 *  Accesseur du nom du bureaucrate
 */
const std::string & Bureaucrat::getName() const
{
	return _name;
}

/**
 *  Accesseur du grade du bureaucrate
 */
int Bureaucrat::getGrade() const
{
	return _grade;
}

/**
 *  Incrémente le grade du bureaucrate, lance une exception si le grade devient trop élevé
 */
void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

/**
 *  Décrémente le grade du bureaucrate, lance une exception si le grade devient trop bas
 */
void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
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

/*
 * Exception pour un nom invalide
 */
const char * Bureaucrat::InvalidNameException::what() const throw()
{
	return "Invalid name: Name must not be empty and must not contain digits.";
}

/**
*  Surcharge de l'opérateur d'insertion pour la classe Bureaucrat
*/
std::ostream & operator << (std::ostream & os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return os;
}

/* BUREAUCRAT.CPP */
