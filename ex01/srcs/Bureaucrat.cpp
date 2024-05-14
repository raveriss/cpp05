/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/14 17:06:50 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <limits>


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

Bureaucrat::Bureaucrat(const Bureaucrat & rootBureaucrat) : _name(rootBureaucrat._name), _grade(rootBureaucrat._grade) {}

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
const std::string& Bureaucrat::getName() const {
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

void Bureaucrat::incrementGrade() {
    if (_grade <= 1) throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150) throw GradeTooLowException();
    ++_grade;
}

void Bureaucrat::signForm(Form &form) const {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}
