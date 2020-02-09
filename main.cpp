
#include <iostream>
#include <string>
#include "responseParser/ResponseParser.h"
#include "templateGenerator/TemplateGenerator.h"
#include "bidManager/BidManager.h"

//Main program
int main() {

    try {
        ResponseParser parser("../bid-response.json");
        TemplateGenerator tempGen("../index.html");
        BidManager{ parser, tempGen }.run();
    }
    catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
    }

}
