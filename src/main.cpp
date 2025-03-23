// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>

int main() {
    std::cout << faStr1("One two 3 4 five./,") << std::endl;
    std::cout << faStr2("One Tw2 three Four f/") << std::endl;
    std::cout << faStr3("One Twoooooooooo Three34w") << std::endl;
}
