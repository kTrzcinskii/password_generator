#pragma once

#include <vector>
#include <string>
#include <tuple>
#include <random>

namespace password_generator {
	class PasswordGenerator {
		using arguments_t = std::vector<std::string>;
		using key_value_t = std::pair<std::string, std::string>;

		enum Char_to_generate {
			LOWER,
			UPPER,
			NUMBER,
			SPECIAL
		};

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
			"--only_lower",
			"--include_numbers",
			"--include_special_char",
			"--number",
		};
		//default options, can be changed by passing arguments into comandline
		size_t length = DEFAULT_LENGTH_VALUE;
		bool only_lower = false;
		bool include_numbers = true;
		bool include_special_char = false;
		unsigned int number_of_passwords = DEFAUlT_NUM_OF_PASSWORDS;
		//helepr methods
		void parse_arguments(int argc, char* argv[]);
		key_value_t check_arg(std::string arg);
		bool is_positive_number(const std::string &s);
		void parse_boolean(const key_value_t &key_val, bool &member);
		void parse_numeric(const key_value_t &key_val, unsigned int default_val, unsigned int &member);
		void parse_numeric(const key_value_t &key_val, size_t default_val, size_t &member);
		char generate_single_char(std::mt19937 &mt);
		//constants
		static constexpr size_t DEFAULT_LENGTH_VALUE = 8;
		static constexpr unsigned int  DEFAUlT_NUM_OF_PASSWORDS = 1;
		const std::vector<char> SPECIAL_CHARACTERS = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '+', '-', '_', '=', '{', '}', '[', ']', '<', '>', '?', '/'};
	};
}