/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:59:02 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 01:47:32 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>

/**
 * @brief Classe représentant un formulaire de grâce présidentielle, dérivée de AForm
 */
class PresidentialPardonForm : public AForm {
    private:
        std::string target;

    protected:
        void executeAction() const;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string & target);
        PresidentialPardonForm(const PresidentialPardonForm & other);
        PresidentialPardonForm & operator = (const PresidentialPardonForm & other);
        virtual ~PresidentialPardonForm();
};

/* PRESIDENTIALPARDONFORM.HPP */