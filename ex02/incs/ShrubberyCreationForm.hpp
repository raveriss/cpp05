/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:02:46 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/18 01:29:58 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/**
 * @brief Classe représentant un formulaire de création d'arbustes, dérivée de AForm
 */
class ShrubberyCreationForm : public AForm {
    private:
        std::string target;

    protected:
        void executeAction() const;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm(const ShrubberyCreationForm & other);
        ShrubberyCreationForm & operator = (const ShrubberyCreationForm & other);
        virtual ~ShrubberyCreationForm();
};

/* SHRUBBERYCREATIONFORM.HPP */