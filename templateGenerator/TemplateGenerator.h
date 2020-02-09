/*
Template generator
*/
#ifndef TEMPLATEGENERATOR_TEMPLATEGENERATOR_H_
#define TEMPLATEGENERATOR_TEMPLATEGENERATOR_H_

#include "../interfaces/iTemplateGenerator.h"
#include "../thirdParty/HtmlBuilder/include/HTML/HTML.h"
#include <string>
#include <fstream>
#include <iostream>


class TemplateGenerator: public iTemplateGenerator {

std::ofstream ofs;
std::string formatMarkup(std::string);

public:
	TemplateGenerator(std::string);
	virtual ~TemplateGenerator();
	void generateTemplate(const std::string);
};

#endif /* TEMPLATEGENERATOR_TEMPLATEGENERATOR_H_ */
