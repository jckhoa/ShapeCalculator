#include "ArgumentParser.h"

#include <string>
#include <iostream>

#include "Circle.h"
#include "Donut.h"
#include "Triangle.h"
#include "IsoscelesTriangle.h"
#include "RectangularTriangle.h"
#include "Square.h"
#include "Rectangle.h"

ArgumentParser::ArgumentParser() {
	options["h"] = Option("h", "", "", 0);
	options["c"] = Option("c", "radius", "Circle", 1);
	options["d"] = Option("d", "internalRadius externalRadius", "Donut", 2);
	options["r"] = Option("r", "width, height", "Rectangle", 2);
	options["s"] = Option("s", "side", "Square", 1);
	options["t"] = Option("t", "side1, side2, side3", "Triangle", 3);
	options["it"] = Option("it", "side, base", "IsoscelesTriangle", 2);
	options["rt"] = Option("rt", "side1, side2", "RectanglarTriangle", 2);

	// construct help message
	std::stringstream ss;
	ss << "ShapeCalculator calculate geometric measures (perimeters, areas, etc.) of shapes such as circle, square, rectangle, etc." << std::endl;
	ss << "Syntax: ShapeCalculator.exe [options]" << std::endl;
	ss << "Current available options: " << std::endl;
	ss << "-h : show this help message." << std::endl;
	for (const auto& item : options) {
		if (item.first.compare("h") == 0) continue;
		ss << "-" << item.first << " " << item.second.getArgumentMessage() << " : " << item.second.getMessage() << std::endl;
	}
	helpMessage = ss.str();
}

const std::map<std::string, Option>& ArgumentParser::getOptions() const {
	return options;
}

bool ArgumentParser::parseOptionArgument(const Option& option, int &index, int argc, char* argv[], std::vector<double>& argument) {
	for (unsigned int i = 0; i < option.getArgumentCount(); ++i) {
		++index;
		if (index >= argc) return false;
		double value = 0.;
		std::stringstream ss(argv[index]);
		ss >> value;
		if (ss.fail()) return false;
		argument.push_back(value);
	}
	return true;
}

void ArgumentParser::storeResult(const Shape* shape) {
	std::stringstream resultStr;
	resultStr << shape->toString();
	if (shape->isValid()) {
		resultStr << " has " << shape->getPropertyString() << ".";
	}
	else {
		resultStr << " is invalid.";
	}
	results.push_back(resultStr.str());
}

bool ArgumentParser::process(int argc, char* argv[], std::string& errMessage) {
	
	// initialize error message and results
	errMessage = "";
	results.clear();

	if (argc <= 1) { 
		errMessage = "Please provide more options";
		return false; 
	}
	else {
		std::string option("");
		int index = 1;
		while (index < argc) {
			if (argv[index][0] == '-') {
				option = std::string(argv[index]).substr(1);
			}
			else {
				std::stringstream ss;
				ss << "Error. Expecting the " << index << "th parameter to be an option, not argument.";
				errMessage = ss.str();
				return false;
			}
			auto iter = options.find(option);
			
			if (iter == options.end()) {
				std::stringstream ss;
				ss << "The option '" << option << "' is not found. ";
				errMessage = ss.str();
				return false;
			} 

			if (iter->first.compare("h") == 0) {
				return false;
			}
			
			std::vector<double> arguments;
			if (!parseOptionArgument(iter->second, index, argc, argv, arguments)) {
				errMessage = iter->second.getArgumentErrorMessage();
				return false;
			}

			std::string optionName = iter->first;

			if (optionName.compare("c") == 0) { // Circle
				Circle c(arguments[0]);
				storeResult(&c);
			}
			else if (optionName.compare("d") == 0) { // Donut
				Donut d(arguments[0], arguments[1]);
				storeResult(&d);
			}
			else if (optionName.compare("it") == 0) { // IsoscelesTriangle
				IsoscelesTriangle it(arguments[0], arguments[1]);
				storeResult(&it);
			}
			else if (optionName.compare("r") == 0) { // Rectangle
				Rectangle r(arguments[0], arguments[1]);
				storeResult(&r);
			}
			else if (optionName.compare("rt") == 0) { //RectangularTriangle
				RectangularTriangle rt(arguments[0], arguments[1]);
				storeResult(&rt);
			}
			else if (optionName.compare("s") == 0) { // Square
				Square s(arguments[0]);
				storeResult(&s);
			}
			else if (optionName.compare("t") == 0) { // Triangle
				Triangle t(arguments[0], arguments[1], arguments[2]);
				storeResult(&t);
			}
			else {				
				return false;
			}
			++index;
		}
	}
	return true;
}

const std::string& ArgumentParser::getHelpMessage() const {
	return helpMessage;
}

std::string ArgumentParser::getResults() const {
	std::stringstream ss;
	for (const auto& result : results) {
		ss << result << std::endl;
	}
	return ss.str();
}