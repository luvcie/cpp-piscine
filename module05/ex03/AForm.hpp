#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat; // forward declaration is enough just to say it exists somewhere

class AForm {
  private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
  protected:
    virtual void action() const = 0; // abstract !
  public:
    AForm();
    AForm (const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& brct);
    void execute(Bureaucrat const& executor) const;

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

  std::ostream& operator<<(std::ostream& os, const AForm& f);
#endif
