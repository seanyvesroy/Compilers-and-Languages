#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool isNum(std::string test) {
    if(test.find_first_not_of("0123456789") == std::string::npos) {
        return true;
    } else {
        return false;
    }
}
bool isReserve(std::string test) {
    if(test == "while" || test == "for" || test == "switch" 
            || test == "do" || test == "return") {
                return true;
            } else {
                return false;
            }
}
bool isIdentifier(std::string test) {

    if(!((test[0] >= 'a' && test[0] <= 'z')
                || (test[0] >= 'A' && test[0] <= 'Z')
                || test[0] == '_' )) {
                    
                return false;
            }
                        
    for(int j = 0; j < test.length(); j++) {
        if(!((test[j] >= 'a' && test[j] <= 'z')
            || (test[j] >= 'A' && test[j] <= 'Z')
            || (test[j] >= '0' && test[j] <= '9')
            || test[j] == '_')) {
                return false;
            }
        }
    return true;
}
void validate(std::string fileName) {

    std::vector<std::vector<std::string>> inputList;
    std::vector<std::string> line;
    std::fstream myFile;
    std::string token;
    myFile.open(fileName, std::ios::in);
    if (myFile.is_open()) {
        while (std::getline(myFile, token)) {
            line.push_back(token);
            inputList.push_back(line);
            line.pop_back(); 
        }
    }
    for (int i = 0; i < inputList.size(); i++) {
        std::string testToken = inputList[i][0];
        
        if(isNum(testToken)) {
            inputList[i].push_back("yes");
            inputList[i].push_back("no");
            inputList[i].push_back("no");
        } else if(isReserve(testToken)) {
            inputList[i].push_back("no");
            inputList[i].push_back("no");
            inputList[i].push_back("yes");
        }else if(isIdentifier(testToken)) {
            inputList[i].push_back("no");
            inputList[i].push_back("yes");
            inputList[i].push_back("no");
        } else {
            inputList[i].push_back("no");
            inputList[i].push_back("no");
            inputList[i].push_back("no");
        }
        
    }
    std::cout << "Token       number  identifier  reserved word" << std::endl;
    for (int k = 0; k < inputList.size(); k++) {
        std::cout << inputList[k][0] << "          " << inputList[k][1] << "        "
                << inputList[k][2] << "       " << inputList[k][3] << std::endl;
    }
}


int main() {

    validate("text.txt");


}