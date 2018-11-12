#include <iostream>

#define LOG(message) std::cout << message << std::endl;

void init_all();

int main(int argc, const char** argv) {

	LOG("Hello World");

	std::cin.get();

	return 0;
}

//Initialization Function
void init_all() {

}