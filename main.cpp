#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include <sstream>
#include "retclass.cpp"

int main(int argc, char *argv[]) {

    std::vector<Rectangles> RectLists;

    for (int i = 1; i < argc; ++i) {
        std::ifstream f(argv[i]);
        if (!f.is_open()) {
            std::cerr << "Error opening file: " << argv[i] << std::endl;
            return 1;
        }

        std::string fcontent;
        std::getline(f, fcontent);

        std::vector<double> content;
        std::istringstream iss(fcontent);
        double x;
        while (iss >> x) {
            content.push_back(x);
        }

        Rectangles ret(content[0], content[1], content[2], content[3], "ret" + std::to_string(i));
        RectLists.push_back(ret);

        f.close();
    }
	


    for (Rectangles ret : RectLists) {
        std::cout << "\n\n+++++++++++++++++" << std::endl;
        std::cout << ret.getName() << " Intersections: \n" << std::endl;

        for (Rectangles otherRet : RectLists) {
            if (ret.IntersectionWith(otherRet)) {
                std::cout << otherRet.getName() << std::endl;
            }
        }

        std::cout << "+++++++++++++++++\n" << std::endl;
    }

    return 0;
}
