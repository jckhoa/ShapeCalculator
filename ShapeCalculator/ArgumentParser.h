#pragma once

#include "Option.h"
#include "Shape.h"

#include <map>
#include <vector>
// The class ArgumentParser is used for parsing argument from command line for the Shape Calculator program

class ArgumentParser {
public:
	// Constructor
	ArgumentParser();

	//Return the options
	const std::map<std::string, Option>& getOptions() const;

	// parse command line arguments.
	// Return true if there is no error, false otherwise.
	// Error messages is written to errorMessage if any.
	bool process(int argc, char* argv[], std::string& errorMessage);

	// Return help message
	const std::string& getHelpMessage() const;

	// Return results
	std::string getResults() const;

private:
	
	// Parse parameters for shape calculation, this function is used inside the process(...) function
	bool parseOptionArgument(const Option& option, int &index, int argc, char* argv[], std::vector<double>& arguments);
	
	// Store the result from shape computation for each shape, this function is used inside process(...) function
	void storeResult(const Shape* shape);
	
private:
	// Store available options
	std::map<std::string, Option> options;
	
	// Store the results
	std::vector<std::string> results;
	
	// Store the help message
	std::string helpMessage;

};