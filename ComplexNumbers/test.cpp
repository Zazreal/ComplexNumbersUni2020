#include<iostream>
#include<fstream>
#include<exception>
#include<sstream>
#include<string>
#include<vector>


main() {
	std::string The_story_of_DPtW = " ";
	try {
		std::ofstream CreateFile(("TheGreatTradgedy.txt"));
		CreateFile << The_story_of_DPtW;
		CreateFile.close();
		if (!CreateFile.good()) throw std::runtime_error("FileNotCreatedException");
	}
	catch (std::exception &e) {
		std::cout << "An Exception has occured: " << e.what();
	}



	std::vector<std::string> FilesVector(0);
	std::stringstream ss(The_story_of_DPtW);
	std::string tempstr = "";
	char separator = ' ';
	int breaker = 0;
	while (std::getline(ss, tempstr, separator)) {
		std::string pathname2 = "\\BACKUP\\" + tempstr + ".txt";
		try {
			std::ofstream TheActualLegend(pathname2);
			TheActualLegend << The_story_of_DPtW;
			if (!TheActualLegend.good()) {
				throw std::runtime_error("FileNotCreatedException, FileName: " + tempstr + ".txt\n");
				TheActualLegend.close();
			}
			TheActualLegend.close();
		}
		catch (std::exception &e) {
			std::cout << "An Exception has occured: " << e.what() << std::endl;
		}
		FilesVector.push_back(pathname2);
		breaker++;
		if (breaker == 50) { break; }

	}
}