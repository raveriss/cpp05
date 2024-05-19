/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:01:43 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/19 02:00:21 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @brief Directive évitant les inclusions multiples d'un fichier d'en-tête **/
#pragma once

/** @brief Inclusion bibliothèque standard chaînes de caractères **/
#include <string>

/** @brief Inclusion bibliothèque standard flux d'entrée/sortie **/
#include <iostream>

/** @brief Inclusion fichier d'en-tête classe Bureaucrat **/
#include "Bureaucrat.hpp"

/** @brief Déclaration anticipée classe Bureaucrat **/
class Bureaucrat;

/**
 * @brief Classe abstraite représentant un formulaire avec des informations de signature et d'exécution
 */
class AForm
{
    private:
		/** @brief Nom du bureaucrate **/
        const std::string _name;

        /** @brief Indicateur de signature du formulaire **/
        bool _isSigned;

        /** @brief Grade requis pour signer le formulaire **/
        const int _gradeRequiredToSign;

        /** @brief Grade requis pour exécuter le formulaire **/
        const int _gradeRequiredToExecute;

    protected:
        /** @brief Méthode virtuelle pure pour exécuter l'action du formulaire **/
        virtual void executeAction() const = 0;

    public:
		/** @brief Constructeur par défaut de la classe AForm **/
        AForm();

        /** @brief Constructeur avec paramètres de la classe AForm **/
        AForm(const std::string & name, int gradeToSign, int gradeToExecute);

        /** @brief Constructeur par copie de la classe AForm **/
        AForm(const AForm & src);

        /** @brief Opérateur d'affectation de la classe AForm **/
        AForm & operator = (const AForm & rhs);

        /** @brief Destructeur de la classe AForm **/
        virtual ~AForm();

        /** @brief Obtient le nom du formulaire **/
        std::string getName() const;

        /** @brief Vérifie si le formulaire est signé **/
        bool getIsSigned() const;

        /** @brief Obtient le grade requis pour signer le formulaire **/
        int getGradeRequiredToSign() const;

        /** @brief Obtient le grade requis pour exécuter le formulaire **/
        int getGradeRequiredToExecute() const;

        /** @brief Permet de signer le formulaire **/
        void beSigned(const Bureaucrat & bureaucrat);

        /** @brief Exécute le formulaire **/
        void execute(const Bureaucrat & executor) const;

        /** @brief Exception pour les grades trop élevés **/
        class GradeTooHighException : public std::exception
        {
            /** @brief Message d'erreur pour les grades trop élevés **/
            public:
                const char * what() const throw();
        };

        /** @brief Exception pour les grades trop bas **/
        class GradeTooLowException : public std::exception
        {
            /** @brief Message d'erreur pour les grades trop bas **/
            public:
                const char * what() const throw();
        };

        /** @brief Exception pour les formulaires non signés **/
        class FormNotSignedException : public std::exception
        {
            /** @brief Message d'erreur pour les formulaires non signés **/
            public:
                const char * what() const throw();
        };
};

/* AFORM.HPP */