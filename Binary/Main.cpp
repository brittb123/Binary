#include <iostream>
#include <fstream>

int main()
{
	char inputletter;
	char answer = ' ';

	std::cout << "Press 1 to save a number you type or press 2 to load the last number." << std::endl;
	std::cin >> answer;

	if (answer == '1')
	{
		std::cout << "Type a letter you wish to save" << std::endl;
		std::cin >> inputletter;

		std::fstream file;
		file.open("save.txt", std::ios::out | std::ios::binary);

		if (!file.is_open())
		{
			return 3;
		}

		file.write((char*)&inputletter, sizeof(char));
		file.close();
		return 0;
	}

	if (answer == '2')
	{
		char loaded = 0;
		std::cout << "Here is the last number saved" << std::endl;
		std::fstream file;
		file.open("save.txt", std::ios::in | std::ios::binary);

		if (!file.is_open())
		{
			return 3;
		}
		
		file.read((char*)&loaded, sizeof(char));
		file.close();

		std::cout << loaded << std::endl;
		return 0;
	}

	return 0;
}