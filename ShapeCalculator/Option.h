#pragma once

#include <sstream>

class Option {

public:
	Option() {}

	Option(const std::string& optionName, const std::string& argumentDescription, const std::string& shapeName, unsigned int argumentCount)
		: optionName(optionName), argumentDescription(argumentDescription), shapeName(shapeName), argumentCount(argumentCount)
	{

	}
	
	unsigned int getArgumentCount() const {
		return argumentCount;
	}

	std::string getMessage() const {
		std::stringstream ss;
		ss << "Compute geometric parameters of " << shapeName << ". ";
		return ss.str();
	}

	std::string getArgumentErrorMessage() const {
		std::stringstream ss;
		ss << "Wrong argument type or number of arguments for " << shapeName << ".";
		return ss.str();
	}

	std::string getArgumentMessage() const {
		std::stringstream ss;
		ss << argumentDescription;
		return ss.str();
	}

private:
	std::string optionName;
	std::string argumentDescription;
	std::string shapeName;
	unsigned int argumentCount;
};
