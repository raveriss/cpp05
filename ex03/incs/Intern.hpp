/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:46:56 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 02:55:59 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

/**
 * @brief Classe représentant un stagiaire capable de créer différents formulaires
 */
class Intern
{
    public:
        Intern();
        Intern(const Intern & other);
        Intern & operator = (const Intern & other);
        ~Intern();

        AForm * makeForm(const std::string & formName, const std::string & target) const;

    private:
        AForm * createShrubberyCreation(const std::string & target) const;
        AForm * createRobotomyRequest(const std::string & target) const;
        AForm * createPresidentialPardon(const std::string & target) const;
};

/* INTERN.HPP */
