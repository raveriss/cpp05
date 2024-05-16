#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <typeinfo>

#define ASSERT_TEST(expression, message) \
    if (expression) { std::cout << "\033[32m[TEST PASSED]\033[0m " << message << std::endl; } \
    else { std::cout << "\033[31m[TEST FAILED]\033[0m " << message << std::endl; }

#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

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
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(true, "Correctly threw GradeTooLowException.");
	} catch (...) {
		ASSERT_TEST(false, "Wrong exception type caught.");
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

    /*
    * TEST BUREAUCRAT CREATION AND FORM EXECUTION
    */
    std::cout << std::endl << CYAN << "TEST BUREAUCRAT CREATION AND FORM EXECUTION:" << NC << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Alice");
        PresidentialPardonForm pardon("Charlie");

        bob.signForm(shrub);
        bob.executeForm(shrub);
        ASSERT_TEST(shrub.getIsSigned(), "ShrubberyCreationForm signed.");
        ASSERT_TEST(shrub.getIsSigned() && shrub.getGradeRequiredToExecute() >= bob.getGrade(), "ShrubberyCreationForm executed.");

        bob.signForm(robot);
        bob.executeForm(robot);
        ASSERT_TEST(robot.getIsSigned(), "RobotomyRequestForm signed.");
        ASSERT_TEST(robot.getIsSigned() && robot.getGradeRequiredToExecute() >= bob.getGrade(), "RobotomyRequestForm executed.");

        bob.signForm(pardon);
        bob.executeForm(pardon);
        ASSERT_TEST(pardon.getIsSigned(), "PresidentialPardonForm signed.");
        ASSERT_TEST(pardon.getIsSigned() && pardon.getGradeRequiredToExecute() >= bob.getGrade(), "PresidentialPardonForm executed.");
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        ASSERT_TEST(false, "Exception should not be thrown.");
    }

    /*
    * TEST GETTERS IN AForm
    */
    std::cout << CYAN << "\nTEST GETTERS IN AForm:" << NC << std::endl;
    try {
        ShrubberyCreationForm shrub("test");
        ASSERT_TEST(shrub.getName() == "ShrubberyCreationForm", "getName() works correctly.");
        ASSERT_TEST(!shrub.getIsSigned(), "getIsSigned() works correctly.");
        ASSERT_TEST(shrub.getGradeRequiredToSign() == 145, "getGradeRequiredToSign() works correctly.");
        ASSERT_TEST(shrub.getGradeRequiredToExecute() == 137, "getGradeRequiredToExecute() works correctly.");
    } catch (std::exception &e) {
        ASSERT_TEST(false, "Exception should not be thrown during getters tests.");
    }

    /*
    * TEST AForm CLASS NAME
    */
    std::cout << CYAN << "\nTEST AForm CLASS NAME:" << NC << std::endl;
    ASSERT_TEST(std::string(typeid(AForm).name()).find("AForm") != std::string::npos, "AForm class name is correct.");

    /*
    * TEST ShrubberyCreationForm REQUIREMENTS
    */
    std::cout << CYAN << "\nTEST ShrubberyCreationForm REQUIREMENTS:" << NC << std::endl;
    try {
        ShrubberyCreationForm shrub("home");
        ASSERT_TEST(shrub.getGradeRequiredToSign() == 145, "ShrubberyCreationForm sign grade is 145.");
        ASSERT_TEST(shrub.getGradeRequiredToExecute() == 137, "ShrubberyCreationForm execute grade is 137.");
    } catch (std::exception &e) {
        ASSERT_TEST(false, "ShrubberyCreationForm constructor threw an exception.");
    }

    /*
    * TEST ShrubberyCreationForm FILE CREATION
    */
    std::cout << CYAN << "\nTEST ShrubberyCreationForm:" << NC << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("test_target");
        bob.signForm(shrub);

        // Exécuter le formulaire avec executeForm
        bob.executeForm(shrub);
        std::ifstream infile("test_target_shrubbery");
        ASSERT_TEST(infile.good(), "Shrubbery file created using executeForm.");
        infile.close();
        std::remove("test_target_shrubbery");

        // Exécuter le formulaire avec execute
        shrub.execute(bob);
        infile.open("test_target_shrubbery");
        ASSERT_TEST(infile.good(), "Shrubbery file created using execute.");
        infile.close();
        std::remove("test_target_shrubbery");
    } catch (std::exception &e) {
        ASSERT_TEST(false, "Exception should not be thrown during Shrubbery creation/execution.");
    }

    /*
    * TEST RobotomyRequestForm REQUIREMENTS
    */
    std::cout << CYAN << "\nTEST RobotomyRequestForm REQUIREMENTS:" << NC << std::endl;
    try {
        RobotomyRequestForm robot("Alice");
        ASSERT_TEST(robot.getGradeRequiredToSign() == 72, "RobotomyRequestForm sign grade is 72.");
        ASSERT_TEST(robot.getGradeRequiredToExecute() == 45, "RobotomyRequestForm execute grade is 45.");
    } catch (std::exception &e) {
        ASSERT_TEST(false, "RobotomyRequestForm constructor threw an exception.");
    }

    /*
    * TEST PresidentialPardonForm REQUIREMENTS
    */
    std::cout << CYAN << "\nTEST PresidentialPardonForm REQUIREMENTS:" << NC << std::endl;
    try {
        PresidentialPardonForm pardon("Charlie");
        ASSERT_TEST(pardon.getGradeRequiredToSign() == 25, "PresidentialPardonForm sign grade is 25.");
        ASSERT_TEST(pardon.getGradeRequiredToExecute() == 5, "PresidentialPardonForm execute grade is 5.");
    } catch (std::exception &e) {
        ASSERT_TEST(false, "PresidentialPardonForm constructor threw an exception.");
    }

    // Note: Le test suivant est là pour illustrer qu'AForm est abstraite.
    // Cette partie du code ne peut pas être exécutée car AForm ne peut pas être instanciée directement.
    // /*
    // std::cout << CYAN << "\nTEST AForm CANNOT BE INSTANTIATED:" << NC << std::endl;
    // try {
    //     // Cette ligne devrait échouer car AForm est une classe abstraite.
    //     AForm *form = new AForm("TestForm", 50, 25);
    //     ASSERT_TEST(false, "AForm should not be instantiable directly.");
    // } catch (std::exception& e) {
    //     ASSERT_TEST(true, "Correctly caught exception for AForm instantiation.");
    // }
    // */
    return 0;
}
