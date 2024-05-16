/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/16 22:30:08 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 */
Bureaucrat::Bureaucrat() : _name("Default"), _grade(75) {}

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 * 
 * @param name 
 * @param grade 
 */
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (_grade < 1) throw GradeTooHighException();
    if (_grade > 150) throw GradeTooLowException();
}

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 * 
 * @param rootBureaucrat 
 */
Bureaucrat::Bureaucrat(const Bureaucrat & rootBureaucrat) : _name(rootBureaucrat._name), _grade(rootBureaucrat._grade) {}

/**
 * @brief 
 * 
 * @param rootBureaucrat 
 * @return Bureaucrat& 
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
 * @brief Destroy the Bureaucrat:: Bureaucrat object
 * 
 */
Bureaucrat::~Bureaucrat() {}

/**
 * @brief 
 * 
 * @return const std::string& 
 */
const std::string & Bureaucrat::getName() const {
    return _name;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Bureaucrat::getGrade() const {
    return _grade;
}

/**
 * @brief incrementGrade
 * 
 */
void Bureaucrat::incrementGrade() {
    if (_grade <= 1) throw GradeTooHighException();
    --_grade;
}

/**
 * @brief 
 * 
 */
void Bureaucrat::decrementGrade() {
    if (_grade >= 150) throw GradeTooLowException();
    ++_grade;
}

/**
 * @brief 
 * 
 * @param os 
 * @param b 
 * @return std::ostream& 
 */
std::ostream & operator << (std::ostream & os, const Bureaucra t& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}
