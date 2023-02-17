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
			if (key_val.first == "--length")
			{
				parse_numeric(key_val, DEFAULT_LENGTH_VALUE, length);
			}
			else if (key_val.first == "--only_lower")
			{
				parse_boolean(key_val, only_lower);
			}
			else if (key_val.first == "--include_numbers")
			{
				parse_boolean(key_val, include_numbers);
			}
			else if (key_val.first == "--include_special_char")
			{
				parse_boolean(key_val, include_special_char);
			}
			else if (key_val.first == "--number")
			{
				parse_numeric(key_val, DEFAUlT_NUM_OF_PASSWORDS, number_of_passwords);
			}
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
				//we know it's "=", now we have to check if whats after "=" makes sense
				std::string value = arg.substr(possible_arg.length() + 1);
				//only --number and --length has numeric value
				if (possible_arg == "--number" || possible_arg == "--length")
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

	void PasswordGenerator::parse_boolean(const key_value_t &key_val, bool& member)
	{
		if (key_val.second == "false") member = false;
		else member = true;
	}

	void PasswordGenerator::parse_numeric(const key_value_t &key_val, unsigned int default_val, unsigned int& member)
	{
		if (key_val.second == "DEFAULT") member = default_val;
		else member = static_cast<unsigned int>(std::stoi(key_val.second));
	}
	void PasswordGenerator::parse_numeric(const key_value_t &key_val, size_t default_val, size_t& member)
	{
		if (key_val.second == "DEFAULT") member = default_val;
		else member = static_cast<size_t>(std::stoi(key_val.second));
	}

	void PasswordGenerator::generate()
	{
		//TODO
	}
}