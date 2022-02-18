#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>


int postfix () {
    
    std::vector<std::string> inputVect;
    std::string inputString;
    std::cout << "Enter a postfix expression with a $ at the end: " << std::endl;
    getline(std::cin, inputString);
    std::string word = "";
    std::string space = " ";

    size_t position = 0;
    while ((position = inputString.find(space)) != std::string::npos) {
        inputVect.push_back(inputString.substr(0, position));
        inputString.erase(0, position + 1);
    }
        inputVect.push_back(inputString);

    for (const auto &str : inputVect) {
        std::cout << str << std::endl;
    }
    
    std::vector<int> stack;
    for (const auto &str : inputVect) {
        if (isdigit(str[0])) {
            int x = stoi(str);
            stack.push_back(x);
        } else if (str == "$") {
            return stack.back();
        }else if (str == "+") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            int c = a + b;
            stack.push_back(c);
        } else if (str == "-") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            int c = a - b;
            stack.push_back(c);
        } else if (str == "/") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            int c = a / b;
            stack.push_back(c);
        } else if (str == "*") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            int c = a * b;
            stack.push_back(c);
        } else {
            std::cout << "please enter a value for " << str << std::endl;
            int t;
            std::cin >> t;
            stack.push_back(t);
        }
    }
   
}


int main (int argc, char * argv[]) {

    int number = 0;
    number = postfix();
    std::cout << number;

}