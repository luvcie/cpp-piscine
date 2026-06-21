#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
  private:
    const std::string name;
    int grade;
  public:
    // nested classes    
    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
      };
    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
      };
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

    // methods
    std::string getName() const; // const at the end promises not to modify the object
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form& form);
};

    std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
