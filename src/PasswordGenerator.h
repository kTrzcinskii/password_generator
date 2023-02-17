#pragma once

#include <vector>
#include <string>
#include <tuple>

namespace password_generator {
	class PasswordGenerator {
		using arguments_t = std::vector<std::string>;
		using key_value_t = std::pair<std::string, std::string>;

	public:
		PasswordGenerator() {};
		PasswordGenerator(int argc, char* argv[]);
		void generate();
	private:
		//we want to have something like
		// --length=5
		// --lower=true
		//etc
		//when value is bool when user pass --lower we asume value is true
		const arguments_t POSSIBLE_ARGUMENTS = {
			"--length", //when no value we assume it's 8
			"--lower",
			"--numbers",
			"--special_char",
			"--number", //when no value we assume it's 1
		};
		//default options, can be changed by passing arguments into comandline
		size_t length = 8;
		bool only_lower = false;
		bool include_numbers = true;
		bool include_special_char = false;
		unsigned int number_of_passwords = 1;
		//helepr methods
		void parse_arguments(int argc, char* argv[]);
		key_value_t check_arg(std::string arg);
		bool is_positive_number(const std::string &s);
	};
}