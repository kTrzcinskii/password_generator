#include "PasswordGenerator.h"
#include <stdexcept>
#include <iostream>
#include <cctype>

namespace password_generator {
	PasswordGenerator::PasswordGenerator(int argc, char* argv[])
	{
		//it means there are no arguments
		if (argc == 1) return;
		try
		{
			parse_arguments(argc, argv);
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what();
			throw e;
		}
	}

	void PasswordGenerator::parse_arguments(int argc, char* argv[])
	{
		//we start at 1 because argv[0] is program name
		for (int i = 1; i < argc; i++)
		{
			key_value_t key_val = check_arg(argv[i]);
			std::cout << "key: " << key_val.first << ", val: " + key_val.second + "\n";
			//TODO: parse args to class members values
		}
	}

	PasswordGenerator::key_value_t PasswordGenerator::check_arg(std::string arg)
	{
		key_value_t res{};
		for (auto const& possible_arg : POSSIBLE_ARGUMENTS)
		{
			if (arg.find(possible_arg) == 0)
			{
				res.first = possible_arg;
				//it means it has no value
				if (arg == possible_arg)
				{
					res.second = "DEFAULT";
					return res;
				}
				//now we have to check if the very next character is "="
				if (arg[possible_arg.length()] != '=') break;
				//we now it's "=", now we have to check if whats after "=" makes sense
				std::string value = arg.substr(possible_arg.length() + 1);
				//only --number has numeric value
				if (possible_arg == "--number")
				{
					if (!is_positive_number(value)) throw std::invalid_argument("The value of " + possible_arg + " must be greater than 0");
				}
				//else we check if it's true or false
				else if (value != "true" && value != "false")
				{
					throw std::invalid_argument("The value of " + possible_arg + " must be boolean(true/false)");
				}
				res.second = value;
				return res;
			}
		}

		throw std::invalid_argument("Invalid argument: " + arg);
	}
	
	bool PasswordGenerator::is_positive_number(const std::string& s)
	{
		if (s[0] == '0' || s[0] == '-') return false;
		for (auto const& c : s)
		{
			if (!isdigit(c)) return false;
		}
		return !s.empty();
	}

	void PasswordGenerator::generate()
	{
		//TODO
	}
}