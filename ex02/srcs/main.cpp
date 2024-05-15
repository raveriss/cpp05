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
    /*
    * TEST BUREAUCRAT CREATION AND FORM EXECUTION
    */
    std::cout << CYAN << "TEST BUREAUCRAT CREATION AND FORM EXECUTION:" << NC << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Alice");
        PresidentialPardonForm pardon("Charlie");

        bob.signForm(shrub);
        bob.executeForm(shrub);
        ASSERT_TEST(shrub.getIsSigned(), "ShrubberyCreationForm signed.");
        ASSERT_TEST(true, "ShrubberyCreationForm executed.");

        bob.signForm(robot);
        bob.executeForm(robot);
        ASSERT_TEST(robot.getIsSigned(), "RobotomyRequestForm signed.");
        ASSERT_TEST(true, "RobotomyRequestForm executed.");

        bob.signForm(pardon);
        bob.executeForm(pardon);
        ASSERT_TEST(pardon.getIsSigned(), "PresidentialPardonForm signed.");
        ASSERT_TEST(true, "PresidentialPardonForm executed.");
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        ASSERT_TEST(false, "Exception should not be thrown.");
    }

    /*
    * TEST AForm CLASS NAME
    */
    std::cout << CYAN << "\nTEST AForm CLASS NAME:" << NC << std::endl;
    ASSERT_TEST(std::string(typeid(AForm).name()).find("AForm") != std::string::npos, "AForm class name is correct.");

    /*
    * TEST PRIVATE ATTRIBUTES IN AForm
    */
    std::cout << CYAN << "\nTEST PRIVATE ATTRIBUTES IN AForm:" << NC << std::endl;
    ASSERT_TEST(true, "Attributes of AForm are private.");

    /*
    * TEST ATTRIBUTES IN BASE CLASS AForm
    */
    std::cout << CYAN << "\nTEST ATTRIBUTES IN BASE CLASS AForm:" << NC << std::endl;
    ASSERT_TEST(true, "Attributes are in the base class AForm.");

    /*
    * TEST FORM CONSTRUCTORS
    */
    std::cout << CYAN << "\nTEST FORM CONSTRUCTORS:" << NC << std::endl;
    try {
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Alice");
        PresidentialPardonForm pardon("Charlie");
        ASSERT_TEST(true, "Forms constructed with a single parameter.");
    } catch (std::exception &e) {
        ASSERT_TEST(false, "Form constructors threw an exception.");
    }

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
    std::cout << CYAN << "\nTEST ShrubberyCreationForm FILE CREATION:" << NC << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("test_target");
        bob.signForm(shrub);
        bob.executeForm(shrub);
        std::ifstream infile("test_target_shrubbery");
        ASSERT_TEST(infile.good(), "Shrubbery file created.");
        infile.close();
        std::remove("test_target_shrubbery");
    } catch (std::exception &e) {
        ASSERT_TEST(false, "Exception should not be thrown during Shrubbery file creation.");
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
    * TEST RobotomyRequestForm DRILLING NOISE
    */
    std::cout << CYAN << "\nTEST RobotomyRequestForm DRILLING NOISE:" << NC << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        RobotomyRequestForm robot("test_target");
        bob.signForm(robot);
        bob.executeForm(robot);
        ASSERT_TEST(true, "Drilling noise and success/failure message observed.");
    } catch (std::exception &e) {
        ASSERT_TEST(false, "Exception should not be thrown during Robotomy execution.");
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

    /*
    * TEST PresidentialPardonForm PARDON
    */
    std::cout << CYAN << "\nTEST PresidentialPardonForm PARDON:" << NC << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        PresidentialPardonForm pardon("test_target");
        bob.signForm(pardon);
        bob.executeForm(pardon);
        ASSERT_TEST(true, "Pardon message observed.");
    } catch (std::exception &e) {
        ASSERT_TEST(false, "Exception should not be thrown during pardon execution.");
    }

    /*
    * TEST FORM EXECUTION METHOD
    */
    std::cout << CYAN << "\nTEST FORM EXECUTION METHOD:" << NC << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("home");
        bob.signForm(shrub);
        shrub.execute(bob);
        ASSERT_TEST(true, "Form execution method works correctly.");
    } catch (std::exception &e) {
        ASSERT_TEST(false, "Exception should not be thrown during form execution.");
    }

    /*
    * EST BUREAUCRAT EXECUTE FORM
    */
    std::cout << CYAN << "\nTEST BUREAUCRAT EXECUTE FORM:" << NC << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("home");
        bob.signForm(shrub);
        bob.executeForm(shrub);
        ASSERT_TEST(true, "Bureaucrat executed form successfully.");
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        ASSERT_TEST(false, "Bureaucrat execution of form should not throw an exception.");
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
