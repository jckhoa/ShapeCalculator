#pragma once

#include "OptionBase.h"
#include <functional>

template <class T>
class Option : public OptionBase {

public:
	// Construct the option
	// optionName: set it to "r" if the command line option is to be "-r" for rectangle
	// argmentDescription: set it to "width height" if the command line option is to be "-r width height"
	// shapeName: set it to "Rectangle" if the command line option "-r" is for computing Rectangle
	// argumentCount: set it to 2 for a Rectangle because two values are needed (width and height)
	// setSizeFunction: function for setting the size of a shape. Set it to std::bind(&Rectangle::setSize, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) for a rectangle, for example
	Option(const std::string& optionName, const std::string& argumentDescription
			, const std::string& shapeName, unsigned int argumentCount
			, const std::function<void(T&, double, double, double)>& setSizeFunction)
		: OptionBase(optionName, argumentDescription, shapeName, argumentCount), setSizeFunc(setSizeFunction)
	{

	}

	std::string getShapeResult(const std::vector<double>& params) const {
		T* shape = new T();

		shape->setSize(params);
		
		std::stringstream ss;
		ss << shape->toString();
		if (shape->isValid()) {
			ss << " has " << shape->getPropertyString() << ".";
		}
		else {
			ss << " is invalid.";
		}
		
		delete shape;

		return ss.str();
	}

	// Return the number of required arguments for shape computation
	size_t getArgumentCount() {
		return T().getSerializationSize();
	}

private:
	std::function<void(T&, double, double, double)> setSizeFunc;
};
