#include <iostream>
#include "Inheritence/inheritence.h"
#include "Implementation/Implementation.h"
#include "Assosication/OneToOne.h"
#include "Assosication/OneToMany.h"
#include "Assosication/ManyToMany.h"
#include "Aggregation/Aggregation.h"
#include "Composition/Composition.h"
#include "Dependency/Dependency.h"

/**
 * C++ Inheritance Access Table
 *
 * Defines how the access level of a base class member changes
 * when inherited by a derived class.
 *
 * ----------------------------------------------------------------
 * | Base Member Access | Inheritance Type | Derived Member Access |
 * ----------------------------------------------------------------
 * | public             | public           | public                |
 * | protected          | public           | protected             |
 * | private            | public           | inaccessible          |
 * ----------------------------------------------------------------
 * | public             | protected        | protected             |
 * | protected          | protected        | protected             |
 * | private            | protected        | inaccessible          |
 * ----------------------------------------------------------------
 * | public             | private          | private               |
 * | protected          | private          | private               |
 * | private            | private          | inaccessible          |
 * ----------------------------------------------------------------
 *
 * NOTE: 'inaccessible' means the member is part of the derived
 * object but cannot be accessed by name or inherited further.
 */
void InheritenceExample()
{
	Dog dog;
	dog.Bark();
	dog.Eat();

	GoldenRetriever goldenRetriever;
	goldenRetriever.FirstBreatheThenEat();
	/**
	 * @note We cannot call "goldenRetriever.Eat();" because GoldenRetriever class
	 *		 uses "protected" inheritence. Which makes all public
	 *	     members and functions protected and therefore cannot
	 *	     be called publicly. But we can still call it in our class.
	 */

	GoodBoy goodBoy;
	goodBoy.FirstEatThenBreathe();
	goodBoy.TailWiggle();
	/**
	 * @note We still cannot call "goodBoy.Eat();" because GoodBoy class
	 *		 uses "private" inheritence. Which makes all public
	 *	     members and functions private and therefore cannot
	 *	     be called publicly. But we can still call it in our class.
	 */

	GoodestBoy goodestBoy;
	goodestBoy.JumpOnLap();
	goodestBoy.EatAndBreathe();
	/**
	 * @note We still cannot call "goodestBoy.Eat();" because GoodestBoy class
	 *		 uses "private" inheritence. Which makes all public
	 *	     members and functions private and therefore cannot
	 *	     be called publicly. And even more we cannot even call
	 *		 Eat() and Breathe() functions inside our class because
	 *		 they were private for GoodBoy class already.
	 */
}
void ImplementationExample() 
{
	/**
	 * @note You cannot directly instantiate an Abstract Base Class
	 *		 Shape s; (Error)
	 *		 You need a concrete, realized class to instantiate.
	 * 
	 *		 Rectangle class implemented the pure virtual "getArea()" function
	 *		 that is in the "Shape" Abstract Base Class so we can instantiate that.
	 */
	Rectangle rect(5.0, 4.0);
	rect.Greetings();
	std::cout << "Rectangle Area: " << rect.getArea() << std::endl;
}
void OneToOneExample() 
{
	/**
	 * @note In this example Person class and Passport class
	 *		 are in "Association" relation. Both can exist without other one.
	 *		 And a person "may" have a passport.
	 */
	Person myPerson("Jamie");
	Passport myPassport("12345");

	myPerson.PrintInfo();
	myPerson.SetPassport(&myPassport);
	myPerson.PrintInfo();
}
void OneToManyExample() 
{
	/**
	 * @note In this example Department class can have
	 *		 multiple employees or none. It is optional.
	 */
	Department myDepartment("Software Team");
	myDepartment.PrintInfo();
	Employee employee1("Ali");
	Employee employee2("Veli");
	Employee employee3("Mahmut");
	myDepartment.AddEmployee(&employee1);
	myDepartment.PrintInfo();
	myDepartment.AddEmployee(&employee2);
	myDepartment.PrintInfo();
	myDepartment.AddEmployee(&employee3);
	myDepartment.PrintInfo();
}
void ManyToManyExample() 
{
	/**
	 * @note In this example, a project might have multiple developer
	 *		 working on it or none. Also a developer might be working on multiple
	 *	     project or none.
	 */
	Project project1("Project 1");
	Project project2("Project 2");
	Project project3("Project 3");
	Developer developer1("Dev 1");
	Developer developer2("Dev 2");
	Developer developer3("Dev 3");
	developer1.PrintInfo();
	developer2.PrintInfo();
	developer3.PrintInfo();
	project1.PrintInfo();
	project2.PrintInfo();
	project3.PrintInfo();
	developer1.AssignToProject(&project1);
	developer1.AssignToProject(&project2);
	developer2.AssignToProject(&project3);
	developer3.AssignToProject(&project1);
	developer3.AssignToProject(&project3);
	developer1.PrintInfo();
	developer2.PrintInfo();
	developer3.PrintInfo();
	project1.PrintInfo();
	project2.PrintInfo();
	project3.PrintInfo();
}
void AssociationExample() 
{
	/* Association is a connection between classes. */
	OneToOneExample();
	OneToManyExample();
	ManyToManyExample();
}
void AggregationExample() 
{
	/** 
	 * @note In this example "Car" class needs an "Engine" 
	 *		 class to initialize. It cannot work without an engine.
	 *		 But even after we delete "myCar" object, "myEngine" is still
	 *	     usable. It's life does not depend on "Car";
	 */
	Engine myEngine("Benzin");
	Car* myCar = new Car("Clio", &myEngine);
	myCar->Start();
	delete myCar;
	Car* mySecondCar = new Car("Megane", &myEngine);
	mySecondCar->Start();
}
void CompositionExample() 
{
	/**
	 * @note In this example "Human" class has a "Heart" object
	 *		 inside it. We don't provide it from outside as pointer or refrence.
	 *		 It initializes Heart object with it's constructor and since Heart object
	 *	     in this example is in Stack memory it will also be destructed with Human object.
	 */
	Human myHuman("James");
	myHuman.Live();
}
void DependencyExample()
{
	/**
	 * @note In this example Printer class does not have neither pointer
	 *		 nor object of Document class. It just takes a refrence right before
	 *		 using it. So there are no long term relation between there classes.
	 */
	Document myDoc1("Doc1");
	Document myDoc2("Doc2");
	Printer myPrinter;
	myPrinter.PrintDocumentInfo(myDoc1);
	myPrinter.PrintDocumentInfo(myDoc2);

	/**
	 * @note In this example Printer class creates an object from "RawDataExtractor" class,
	 *		 uses it and let it destroy itself going out of scope. This is also an example of
	 *		 dependency.
	 */
	myPrinter.ExtractRawData();
}

int main()
{
	InheritenceExample();
	ImplementationExample();
	AssociationExample();
	AggregationExample();
	CompositionExample();
	DependencyExample();
	return 0;
}

