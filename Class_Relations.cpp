#include <iostream>
#include "Inheritence/inheritence.h"
#include "Implementation/Implementation.h"

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

int main()
{
	InheritenceExample();
	ImplementationExample();

	return 0;
}

