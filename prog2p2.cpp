#include <iostream>
#include <string>


char sCheck(char letter, char state) {
    if(state == 'S') {
        if(letter == 'a') {
            return 'S';
        } else if(letter == 'b') {
            return 'B';
        } else if(letter == 'c') {
            return 'C';
        } else {
            return '~';
        }

    }
    if(state == 'B') {
        if(letter == 'a') {
            return 'C';
        } else if(letter == 'b') {
            return 'B';
        } else if(letter == 'c') {
            return 'D';
        } else if(letter == '$') {
            return '$';
        } else {
            return '~';
        }
    } 
    if(state == 'C') {
        if(letter == 'a') {
            return 'S';
        } else if(letter == 'b') {
            return 'D';
        } else if(letter == 'c') {
            return 'D';
        } else if(letter == '$') {
            return '$';
        } else {
            return '~';
        }
    }
    if(state == 'D') {
        if(letter == 'b') {
            return 'D';
        } else if(letter == 'a') {
            return 'B';
        } else if(letter == 'c') {
            return 'C';
        } else {
            return '~';
        }
    }

}
bool grammarCheck(std::string word) {

    int i = 0;
    char state = 'S';
    for (int i = 0; i < word.size(); i++) {
         if(state == '~') {
            return false;
        }
        state = sCheck(word[i], state);
       
    }
     if(state == '~') {
            return false;
        } else {
            return true;
        }
}

int main() {
    bool answer;

    answer = grammarCheck("aaaaaab$");

    if(answer) {
        std::cout << "Word passes" << std::endl;
    } else {
        std::cout << "Word fails" << std::endl;
    }
}