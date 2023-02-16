#pragma once

namespace password_generator {
	class PasswordGenerator {
	public:
		PasswordGenerator() {};
		PasswordGenerator(int argc, char* argv[]);
		void generate();
	private:
		//default options, can be changed by passing arguments into comandline
		size_t length = 8;
		bool only_lower = false;
		bool include_numbers = true;
		bool include_special_char = false;
		unsigned int number_of_passwords = 1;
	};
}