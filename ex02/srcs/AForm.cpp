/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:02:19 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/15 15:55:35 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign), _gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& src)
    : _name(src._name), _isSigned(src._isSigned), _gradeRequiredToSign(src._gradeRequiredToSign), _gradeRequiredToExecute(src._gradeRequiredToExecute) {
}

AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

AForm::~AForm() {
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeRequiredToSign() const {
    return _gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
    return _gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (_isSigned) {
        throw std::logic_error("AForm already signed.");
    }
    if (bureaucrat.getGrade() <= _gradeRequiredToSign) {
        _isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
    os << AForm.getName() << ", AForm grade required to sign: " << AForm.getGradeRequiredToSign()
       << ", AForm grade required to execute: " << AForm.getGradeRequiredToExecute()
       << ", Is signed: " << (AForm.getIsSigned() ? "Yes" : "No");
    return os;
}
