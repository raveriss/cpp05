/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:24:41 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/20 00:12:18 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe Bureaucrat */
#include "../incs/Bureaucrat.hpp"

/* Inclusion de la bibliothèque standard pour les flux d'entrée/sortie */
#include <iostream>

/**
 *  Macro pour vérifier une expression et afficher un message de test passé/échoué
 */
#define ASSERT_TEST(expression, message) \
	if (expression) { std::cout << "\033[32m[TEST PASSED]\033[0m " << message << std::endl; } \
	else { std::cout << "\033[31m[TEST FAILED]\033[0m " << message << std::endl; }

/* Définitions des codes de couleur ANSI pour la sortie console */
#define GREY		"\033[0;30m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"
#define BLUE		"\033[0;34m"
#define MAGENTA		"\033[0;35m"
#define CYAN		"\033[0;36m"
#define NC			"\033[0m"

/**
 *  Point d'entrée principal du programme
 */
int main()
{
	Bureaucrat *original = NULL;
	Bureaucrat *copy = NULL;

	/**
	* TEST CREATION OF BUREAUCRAT WITH VALID GRADE
	*/
	std::cout << CYAN << "TEST CREATION OF BUREAUCRAT WITH VALID GRADE:" << NC  << std::endl;
	try
	{
		original = new Bureaucrat("John Doe", 75);
		std::cout << *original;
		ASSERT_TEST(original->getGrade() == 75, "Grade 75.");
		delete original;
		original = NULL;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "Should not throw an exception here.");
	}

	/**
	* TEST CREATION OF BUREAUCRAT WITH TOO HIGH GRADE
	*/
	std::cout << CYAN << "\nTEST CREATION OF BUREAUCRAT WITH TOO HIGH GRADE:" << NC << std::endl;
	try
	{
		original = new Bureaucrat("Jane Doe", 0);
		std::cout << *original;
		delete original;
		original = NULL;
		ASSERT_TEST(false, "Should have thrown GradeTooHighException.");
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(true, "Correctly threw GradeTooHighException.");
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught.");
	}

	/**
	* TEST CREATION OF BUREAUCRAT WITH TOO LOW GRADE
	*/
	std::cout << CYAN << "\nTEST CREATION OF BUREAUCRAT WITH TOO LOW GRADE:" << NC << std::endl;
	try
	{
		original = new Bureaucrat("Jim Doe", 151);
		std::cout << *original;
		delete original;
		original = NULL;
		ASSERT_TEST(false, "Should have thrown GradeTooLowException.");
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(true, "Correctly threw GradeTooLowException.");
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught.");
	}

	/**
	* TEST INCREMENTING AND DECREMENTING BUREAUCRAT'S GRADE
	*/
	std::cout << CYAN << "\nTEST INCREMENTING AND DECREMENTING BUREAUCRAT'S GRADE:" << NC << std::endl;
	try
	{
		original = new Bureaucrat("Julia Doe", 10);
		std::cout << *original;
		original->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing bureaucrat :" << NC << std::endl;
		std::cout << *original;
		ASSERT_TEST(original->getGrade() == 9, "Grade incremented to 9.");

		original->decrementGrade();
		std::cout << BLUE << "\nAfter decrementing bureaucrat :" << NC << std::endl;

		std::cout << *original;
		ASSERT_TEST(original->getGrade() == 10, "Grade decremented to 10.");

		delete original;
		original = NULL;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

	/**
	* TEST COPY CONSTRUCTOR
	*/
	std::cout << CYAN << "\nTEST COPY CONSTRUCTOR:" << NC << std::endl;
	try
	{		
		original = new Bureaucrat("Bureaucrat", 50);
		std::cout << "Original " << *original;

		copy = new Bureaucrat(*original);
		std::cout << "Copy " << *copy;

		ASSERT_TEST(copy->getName() == original->getName(), "Copy have the same name.");
		ASSERT_TEST(copy->getGrade() == original->getGrade(), "Copy have the same grade.");

		copy->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing copy:\n" << NC;
		std::cout << "Original " << *original;
		std::cout << "Copy " << *copy;
		ASSERT_TEST(original->getGrade() == 50, "Grade of original unchanged.");
		ASSERT_TEST(copy->getGrade() == 49, "Grade of copy incremented.");

		delete original;
		delete copy;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

	/**
	* TEST ASSIGNMENT OPERATOR
	*/
	std::cout << CYAN << "\nTEST ASSIGNMENT OPERATOR:" << NC << std::endl;
	try
	{
		original = new Bureaucrat("First", 75);
		copy = new Bureaucrat("Second", 100);
		std::cout <<  BLUE << "Before assignment:" << NC << std::endl << *original << *copy << std::endl;

		/**
		 * Using assignment operator
		*/
		*copy = *original;
		std::cout << BLUE << "After assignment:" << NC << std::endl;
		std::cout << *original << *copy;
		ASSERT_TEST(copy->getName() == "Second", "Name of copy unchanged.");
		ASSERT_TEST(copy->getGrade() == 75, "Grade of copy updated to 75.");

		copy->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing Second Bureaucrat :" << NC << std::endl;
		std::cout << *original << *copy;
		ASSERT_TEST(original->getGrade() == 75, "Grade of original unchanged.");
		ASSERT_TEST(copy->getGrade() == 74, "Grade of copy incremented.");

		delete original;
		delete copy;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

	/**
	 * TEST CREATION OF BUREAUCRAT WITH EMPTY NAME
	 */
	std::cout << CYAN << "\nTEST CREATION OF BUREAUCRAT WITH EMPTY NAME:" << NC << std::endl;
	try
	{
		Bureaucrat invalidNameBureaucrat("", 50);
		ASSERT_TEST(false, "Should have thrown an exception for empty name.");
	}
	catch (const Bureaucrat::InvalidNameException& e)
	{
		ASSERT_TEST(true, "Correctly threw an exception for Invalid name");
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught for empty name.");
	}

	/**
	 * TEST CREATION OF BUREAUCRAT WITH INVALID NAME
	 */
	std::cout << CYAN << "\nTEST CREATION OF BUREAUCRAT WITH INVALID NAME:" << NC << std::endl;
	
	try
	{
		Bureaucrat invalidNameBureaucrat("John123", 50);
		ASSERT_TEST(false, "Should have thrown an exception for name containing digits.");
	}
	catch (const Bureaucrat::InvalidNameException& e)
	{
		ASSERT_TEST(true, "Correctly threw an exception for Invalid name");
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught for name containing digits.");
	}

	return 0;
}

/* MAIN.CPP */