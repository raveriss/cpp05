/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 01:55:34 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

/**
 * @brief Constructeur par défaut de la classe Bureaucrat
 */
Bureaucrat::Bureaucrat() : _name("Default"), _grade(75) {}

/**
 * @brief Constructeur avec paramètres de la classe Bureaucrat
 */
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (_grade < 1) throw GradeTooHighException();
    if (_grade > 150) throw GradeTooLowException();
}

/**
 * @brief Constructeur de copie de la classe Bureaucrat
 */
Bureaucrat::Bureaucrat(const Bureaucrat & rootBureaucrat) : _name(rootBureaucrat._name), _grade(rootBureaucrat._grade) {}

/**
 * @brief Opérateur d'affectation de la classe Bureaucrat
 */
Bureaucrat & Bureaucrat :: operator = (const Bureaucrat & rootBureaucrat)
{
    if (this != & rootBureaucrat)
    {
        _grade = rootBureaucrat._grade;
    }
    return *this;
}

/**
 * @brief Destructeur de la classe Bureaucrat
 */
Bureaucrat::~Bureaucrat() {}

/**
 * @brief Accesseur du nom du bureaucrate
 */
const std::string & Bureaucrat::getName() const {
    return _name;
}

/**
 * @brief Accesseur du grade du bureaucrate
 */
int Bureaucrat::getGrade() const {
    return _grade;
}

/**
 * @brief Incrémente le grade du bureaucrate, lance une exception si le grade devient trop élevé
 */
void Bureaucrat::incrementGrade() {
    if (_grade <= 1) throw GradeTooHighException();
    --_grade;
}

/**
 * @brief Décrémente le grade du bureaucrate, lance une exception si le grade devient trop bas
 */
void Bureaucrat::decrementGrade() {
    if (_grade >= 150) throw GradeTooLowException();
    ++_grade;
}

/**
* @brief Surcharge de l'opérateur d'insertion pour la classe Bureaucrat
*/
std::ostream & operator << (std::ostream & os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}

/* BUREAUCRAT.CPP */
