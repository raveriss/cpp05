/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:24:41 by raveriss          #+#    #+#             */
/*   Updated: 2024/05/15 12:22:45 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>

#define ASSERT_TEST(expression, message) \
	if (expression) { std::cout << "\033[32m[TEST PASSED]\033[0m " << message << std::endl; } \
	else { std::cout << "\033[31m[TEST FAILED]\033[0m " << message << std::endl; }

#define GREY		"\033[0;30m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"
#define BLUE		"\033[0;34m"
#define MAGENTA		"\033[0;35m"
#define CYAN		"\033[0;36m"
#define NC			"\033[0m"

int main() {
	Bureaucrat *bureaucrat = NULL;
	Bureaucrat *copyBureaucrat = NULL;

	std::cout << CYAN << "TEST CREATION OF BUREAUCRAT WITH VALID GRADE:" << NC  << std::endl;
	try {
		bureaucrat = new Bureaucrat("John Doe", 75);
		std::cout << *bureaucrat;
		ASSERT_TEST(bureaucrat->getGrade() == 75, "Grade 75.");
		delete bureaucrat;
		bureaucrat = NULL;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "Should not throw an exception here.");
	}

	std::cout << CYAN << "\nTEST CREATION OF BUREAUCRAT WITH TOO HIGH GRADE:" << NC << std::endl;
	try {
		bureaucrat = new Bureaucrat("Jane Doe", 0);
		std::cout << *bureaucrat;
		delete bureaucrat;
		bureaucrat = NULL;
		ASSERT_TEST(false, "Should have thrown GradeTooHighException.");
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(true, "Correctly threw GradeTooHighException.");
	} catch (...) {
		ASSERT_TEST(false, "Wrong exception type caught.");
	}

	std::cout << CYAN << "\nTEST CREATION OF BUREAUCRAT WITH TOO LOW GRADE:" << NC << std::endl;
	try {
		bureaucrat = new Bureaucrat("Jim Doe", 151);
		std::cout << *bureaucrat;
		delete bureaucrat;
		bureaucrat = NULL;
		ASSERT_TEST(false, "Should have thrown GradeTooLowException.");
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(true, "Correctly threw GradeTooLowException.");
	} catch (...) {
		ASSERT_TEST(false, "Wrong exception type caught.");
	}

    std::cout << CYAN << "\nTEST CHECK INITIAL isSigned STATE OF FORM:" << NC << std::endl;
    Form *initialStateForm = NULL;
    try {
        initialStateForm = new Form("Initial State Form", 50, 25);
		std::cout << "Value of isSigned : " << initialStateForm->getIsSigned() << std::endl;
        ASSERT_TEST(initialStateForm->getIsSigned() == false, "Form isSigned should be false upon creation."); // Check if isSigned is false
        delete initialStateForm;
        initialStateForm = NULL;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        ASSERT_TEST(false, "Should not throw an exception for creating a form.");
    }

	std::cout << CYAN << "\nTEST INCREMENTING AND DECREMENTING BUREAUCRAT'S GRADE:" << NC << std::endl;
	try {
		bureaucrat = new Bureaucrat("Julia Doe", 10);
		std::cout << *bureaucrat;
		bureaucrat->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing bureaucrat :" << NC << std::endl;
		std::cout << *bureaucrat;
		ASSERT_TEST(bureaucrat->getGrade() == 9, "Grade incremented to 9.");

		bureaucrat->decrementGrade();
		std::cout << BLUE << "\nAfter decrementing bureaucrat :" << NC << std::endl;

		std::cout << *bureaucrat;
		ASSERT_TEST(bureaucrat->getGrade() == 10, "Grade decremented to 10.");

		delete bureaucrat;
		bureaucrat = NULL;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

	// Test for Copy Constructor
	std::cout << CYAN << "\nTEST COPY CONSTRUCTOR:" << NC << std::endl;
	try {
		bureaucrat = new Bureaucrat("Original Bureaucrat", 50);
		std::cout << "Original Bureaucrat: " << *bureaucrat;

		copyBureaucrat = new Bureaucrat(*bureaucrat);
		std::cout << "    Copy Bureaucrat: " << *copyBureaucrat;

		ASSERT_TEST(copyBureaucrat->getName() == bureaucrat->getName(), "Copy have the same name.");
		ASSERT_TEST(copyBureaucrat->getGrade() == bureaucrat->getGrade(), "Copy have the same grade.");

		copyBureaucrat->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing copy:\n" << NC;
		std::cout << *copyBureaucrat;
		std::cout << *bureaucrat;
		ASSERT_TEST(copyBureaucrat->getGrade() == 49, "Grade of copy incremented.");
		ASSERT_TEST(bureaucrat->getGrade() == 50, "Grade of original unchanged.");

		delete bureaucrat;
		delete copyBureaucrat;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

	// Test for Assignment Operator
	std::cout << CYAN << "\nTEST ASSIGNMENT OPERATOR:" << NC << std::endl;
	try {
		bureaucrat = new Bureaucrat("First Bureaucrat", 75);
		copyBureaucrat = new Bureaucrat("Second Bureaucrat", 100);
		std::cout <<  BLUE << "Before assignment:" << NC << "\nOriginal: " << *bureaucrat << "   Copy: " << *copyBureaucrat << std::endl;

		*copyBureaucrat = *bureaucrat;  // Using assignment operator
		std::cout << BLUE << "After assignment:" << NC << std::endl;
		std::cout << " " << *bureaucrat;
		std::cout << *copyBureaucrat;

		ASSERT_TEST(copyBureaucrat->getName() == "Second Bureaucrat", "Name of copy unchanged.");
		ASSERT_TEST(copyBureaucrat->getGrade() == 75, "Grade of copy updated to 75.");

		copyBureaucrat->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing Second Bureaucrat :" << NC << std::endl;

		std::cout << *copyBureaucrat;
		std::cout << " " << *bureaucrat;

		ASSERT_TEST(copyBureaucrat->getGrade() == 74, "Grade of copy incremented.");
		ASSERT_TEST(bureaucrat->getGrade() == 75, "Grade of original unchanged.");

		delete bureaucrat;
		delete copyBureaucrat;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

    std::cout << CYAN << "\nTEST CREATION OF FORM:" << NC << std::endl;
    Form *form = NULL;
    try {
        form = new Form("Form 42", 50, 25);
        std::cout << *form << std::endl;
        ASSERT_TEST(form->getGradeRequiredToSign() == 50, "Grade required to sign is 50.");
        ASSERT_TEST(form->getGradeRequiredToExecute() == 25, "Grade required to execute is 25.");
        delete form;
        form = NULL;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        ASSERT_TEST(false, "Should not throw an exception here.");
    }

    std::cout << CYAN << "\nTEST SIGNING FORM WITH SUFFICIENT GRADE:" << NC << std::endl;
    try {
        bureaucrat = new Bureaucrat("John Doe", 30);
        form = new Form("Top Secret", 50, 25);
        bureaucrat->signForm(*form);
        ASSERT_TEST(form->getIsSigned() == true, "Form should be signed.");
        delete bureaucrat;
        delete form;
        bureaucrat = NULL;
        form = NULL;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        ASSERT_TEST(false, "No exception should be thrown here.");
    }

    std::cout << CYAN << "\nTEST SIGNING FORM WITH INSUFFICIENT GRADE:" << NC << std::endl;
    try {
        bureaucrat = new Bureaucrat("Jane Doe", 60);
        form = new Form("Top Secret", 50, 25);
        bureaucrat->signForm(*form);
        ASSERT_TEST(form->getIsSigned() == false, "Form should not be signed.");
        delete bureaucrat;
        delete form;
        bureaucrat = NULL;
        form = NULL;
    } catch (Form::GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        ASSERT_TEST(true, "Correctly threw GradeTooLowException because grade is too low to sign.");
    } catch (std::exception& e) {
        std::cerr << "Unhandled exception caught: " << e.what() << std::endl;
        ASSERT_TEST(false, "Unhandled exception type.");
    }

    std::cout << CYAN << "\nTEST SIGNING FORM WITH TWO BUREAUCRATS WITH SAME GRADE:" << NC << std::endl;
    Bureaucrat *firstBureaucrat = NULL;
    Bureaucrat *secondBureaucrat = NULL;
    try {
        firstBureaucrat = new Bureaucrat("Alice", 30);
        secondBureaucrat = new Bureaucrat("Bob", 30);
        form = new Form("Confidential Report", 30, 20);

        firstBureaucrat->signForm(*form);
        ASSERT_TEST(form->getIsSigned() == true, "Form should be signed by Alice.");

        // Try to sign the same form with Bob
        secondBureaucrat->signForm(*form);
        ASSERT_TEST(form->getIsSigned() == true, "Form should remain signed despite Bob's attempt.");

        delete firstBureaucrat;
        delete secondBureaucrat;
        delete form;
        firstBureaucrat = NULL;
        secondBureaucrat = NULL;
        form = NULL;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        ASSERT_TEST(false, "No exception should be thrown here.");
    }

    std::cout << CYAN << "\nTEST MULTIPLE SIGNING ATTEMPTS ON A FORM:" << NC << std::endl;
    try {
        bureaucrat = new Bureaucrat("Claire", 20);
        form = new Form("Top-Level Directive", 25, 15);

        bureaucrat->signForm(*form);
        bureaucrat->signForm(*form);

        ASSERT_TEST(form->getIsSigned() == true, "Form should be signed initially by Claire.");

        // Attempt to sign again
        bureaucrat->signForm(*form);
        ASSERT_TEST(form->getIsSigned() == true, "Form should remain signed; no change on second signing attempt.");

        delete bureaucrat;
        delete form;
        bureaucrat = NULL;
        form = NULL;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        ASSERT_TEST(false, "No exception should be thrown on multiple signing attempts.");
    }
	return 0;
}

