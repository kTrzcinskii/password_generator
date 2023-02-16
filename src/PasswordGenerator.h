#pragma once

#include <vector>
#include <string>

namespace password_generator {
	class PasswordGenerator {
		using arguments_t = std::vector<std::string>;

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
			"--length",
			"--lower",
			"--numbers",
			"--special_char",
			"--number",
		};
		//default options, can be changed by passing arguments into comandline
		size_t length = 8;
		bool only_lower = false;
		bool include_numbers = true;
		bool include_special_char = false;
		unsigned int number_of_passwords = 1;
		//optional arguments
		arguments_t args {};
		//helepr methods
		arguments_t get_arguments(int argn, char* argv[]); //argn to remember it's without first arg (because it's a name of the file
		bool is_valid_arg(std::string arg);
	};
}