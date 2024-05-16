/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:46:56 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/16 22:40:46 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class Intern {
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
