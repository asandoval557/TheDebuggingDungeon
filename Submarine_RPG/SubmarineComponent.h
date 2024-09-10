#pragma once
#ifndef SUBMARINECOMPONENT_H
#define SUBMARINECOMPONENT_H

#include <string>

class SubmarineComponent {
protected:
    std::string name_;

public:
    SubmarineComponent(std::string name);   // constructor to initialize the component with a name
    virtual ~SubmarineComponent();

    // Declare the performOperation method as pure virtual to make this an abstract base class
   virtual void performOperation()=0 ;

    // Declare the getDescription method as virtual to allow derived classes to override it
   virtual std::string getDescription()=0 ;

    // Declare the getName method as virtual to allow derived classes to override it
    virtual std::string getName() = 0;
};

#endif // SUBMARINECOMPONENT_H