#pragma once


#include <map>
#include <array>

#include "Option.h"


// The class ArgumentParser is used for parsing argument from command line for the Shape Calculator program

class ArgumentParser {
public:
	// Constructor
	ArgumentParser();

	// Destructor
	~ArgumentParser();

	//Return the options
	const std::map<std::string, OptionBase*>& getOptions() const;

	//Add option functions, allow upto only 3 arguments
	template<class T>
	void addOption(const std::string& optionName, const std::string& argumentDescription
				, const std::string& shapeName, unsigned int argumentCount) {
		options[optionName] = new Option<T>(optionName, argumentDescription, shapeName, argumentCount);

	}

	// parse command line arguments.
	// Return true if there is no error, false otherwise.
	// Error messages is written to errorMessage if any.
	bool process(int argc, char* argv[], std::string& errorMessage);

	// Return help message
	std::string getHelpMessage() const;

	// Return results
	std::string getResults() const;

private:
	// forbid copy constructor
	ArgumentParser(const ArgumentParser& other) {}
	
	// forbid assignment operator
	ArgumentParser operator=(const ArgumentParser& other) {}

	// forbid move constructor
	ArgumentParser(ArgumentParser&& other) {}

	//forbid move assignment operator
	ArgumentParser operator=(ArgumentParser&& other) {}

	// Parse parameters for shape calculation, this function is used inside the process(...) function
	bool parseOptionArgument(const OptionBase& option, int &index, int argc, char* argv[]);

private:
	// Store available options
	std::map<std::string, OptionBase*> options;
	
	// Store the results
	std::vector<std::string> results;
};