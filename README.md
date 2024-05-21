# **Project CPP05 - École 42 | Paris**

## Introduction
CPP05 continues the exploration of advanced C++ concepts by diving into exception handling, the use of abstract classes, and interface design. The exercises are structured to enhance your understanding and application of these concepts in compliance with the C++98 standard.

## Project Structure
This module consists of a series of exercises, each focusing on different aspects of exception handling and polymorphism:

### Exercise 00: Bureaucracy
- **Directory:** `ex00/`
- **Files to submit:**
  - `Makefile`
  - `main.cpp`
  - Various class implementations (`*.cpp`, `*.h`, `*.hpp`)

#### Functionality
Introduces basic exception handling by implementing the `Bureaucrat` class, where methods throw exceptions for invalid operations (e.g., grades out of range).

### Exercise 01: Form Validation
- **Directory:** `ex01/`
- **Files to submit:**
- All files from Exercise 00 plus
- Additional class implementations (`*.cpp`, `*.h`, `*.hpp`)

#### Functionality
Expands upon the `Bureaucrat` class by introducing a `Form` class, which must be signed by bureaucrats. Demonstrates exception handling and validation within class interactions.

### Exercise 02: Advanced Forms
- **Directory:** 'ex02/'
- **Files to submit:**
  - All files from Exercise 01 plus
  - Modifications to use abstract classes (*.cpp, *.h, *.hpp)

#### Functionality
Transforms the `Form` class into an abstract base class and introduces several derived classes representing specific types of forms (e.g., ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm).

### Exercise 03: Interns
- **Directory**: `ex03/`
- **Files to submit:**
  - `Makefile`
  - `main.cpp`
  - Comprehensive implementations (`*.cpp`, `*.h`, `*.hpp`)

#### Functionality
Implements an `Intern` class responsible for creating form objects dynamically. This exercise showcases the factory design pattern and reinforces the use of interfaces and polymorphism.

## Compilation and Execution
Navigate to the specific exercise directory and use the make command to compile the projects. Each executable can be run directly to demonstrate the functionalities implemented.

## Ressources Utilisées
- [Apprenez à programmer en C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/1894236-apprenez-a-programmer-en-c)
- [Programmez en orienté objet avec C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c)
