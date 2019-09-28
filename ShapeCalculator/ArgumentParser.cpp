#include "ArgumentParser.h"

#include <string>
#include <iostream>

ArgumentParser::ArgumentParser() {
}

ArgumentParser::~ArgumentParser() {
	// deallocate memory for OptionBase
	for (auto& item : options) {
		delete item.second;
	}
}

const std::map<std::string, ShapeOptionBase*>& ArgumentParser::getOptions() const {
	return options;
}

bool ArgumentParser::parseOptionArgument(const ShapeOptionBase& option, int &index, int argc, char* argv[], std::vector<double>& params) {
	for (unsigned int i = 0; i < option.getArgumentCount(); ++i) {
		++index;
		if (index >= argc) return false;
		double value = 0.;
		std::stringstream ss(argv[index]);
		ss >> value;
		if (ss.fail()) return false;
		params.push_back(value);
	}
	return true;
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
			if (option == "h") {
				return false;
			}

			auto iter = options.find(option);
			
			if (iter == options.end()) {
				std::stringstream ss;
				ss << "The option '" << option << "' is not found. ";
				errMessage = ss.str();
				return false;
			} 

			std::vector<double> params;
			if (!parseOptionArgument(*iter->second, index, argc, argv, params)) {
				errMessage = iter->second->getArgumentErrorMessage();
				return false;
			}

			results.push_back(iter->second->getShapeResult(params));
			
			++index;
		}
	}
	return true;
}

std::string ArgumentParser::getHelpMessage() const {
	// construct help message
	std::stringstream ss;
	ss << "ShapeCalculator calculate geometric measures (perimeters, areas, etc.) of shapes such as circle, square, rectangle, etc." << std::endl;
	ss << "Syntax: ShapeCalculator.exe [options]" << std::endl;
	ss << "Current available options: " << std::endl;
	ss << "-h : show this help message." << std::endl;
	for (const auto& item : options) {
		const ShapeOptionBase& option = *item.second;
		if (option.getOptionName() == "h") continue;
		ss << "-" << option.getOptionName() 
			<< " (" << option.getFullCommand() << ") : " << option.getOptionDescription() << ". " 
			<< option.getArgumentDescription() << std::endl;
	}
	return ss.str();
}

std::string ArgumentParser::getResults() const {
	std::stringstream ss;
	for (const auto& result : results) {
		ss << result << std::endl;
	}
	return ss.str();
}