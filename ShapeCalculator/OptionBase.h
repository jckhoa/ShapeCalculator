#pragma once

#include "Shape.h"
#include <vector>
#include <sstream>

class OptionBase {
public:
	// Construct the option base
	// optionName: set it to "r" if the command line option is to be "-r" for rectangle
	// argmentDescription: set it to "width height" if the command line option is to be "-r width height"
	// shapeName: set it to "Rectangle" if the command line option "-r" is for computing Rectangle
	// argumentCount: set it to 2 for a Rectangle because two values are needed (width and height)
	OptionBase(const std::string& optionName, const std::string& argumentDescription, const std::string& shapeName, unsigned int argumentCount)
		: optionName(optionName), argumentDescription(argumentDescription), shapeName(shapeName), argumentCount(argumentCount)
	{

	}

	// Destructor
	virtual ~OptionBase() {}

	// Return the option name
	const std::string& getOptionName() {
		return optionName;
	}

	// Return the number of required arguments for shape computation
	virtual size_t getArgumentCount() const = 0;

	// Return message for the shape
	std::string getMessage() const {
		std::stringstream ss;
		ss << "Compute geometric parameters of " << shapeName << ". ";
		return ss.str();
	}

	// Return error message on arguments
	std::string getArgumentErrorMessage() const {
		std::stringstream ss;
		ss << "Wrong argument type or number of arguments for " << shapeName << ".";
		return ss.str();
	}

	// Return the argument description string
	std::string getArgumentMessage() const {
		std::stringstream ss;
		ss << argumentDescription;
		return ss.str();
	}

	// Return the string containing the results after shape computation
	// Allow the maximum number of parameters to 7
	virtual std::string getShapeResult(const std::vector<double>& params) const = 0;

protected:
	

protected:
	std::string optionName;
	std::string argumentDescription;
	std::string shapeName;
};