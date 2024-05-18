/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:01:38 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 01:27:45 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>

/**
 * @brief Classe représentant un formulaire de demande de robotomie, dérivée de AForm
 */
class RobotomyRequestForm : public AForm {
    private:
        std::string target;

    protected:
        void executeAction() const;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string & target);
        RobotomyRequestForm(const RobotomyRequestForm & other);
        RobotomyRequestForm & operator = (const RobotomyRequestForm & other);
        virtual ~RobotomyRequestForm();
};

/* ROBOTOMYREQUESTFORM.HPP */
