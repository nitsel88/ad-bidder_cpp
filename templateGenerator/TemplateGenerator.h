/*
 * TemplateGenerator.h
 *
 *  Created on: Feb 5, 2020
 *      Author: nithy
 */

#ifndef TEMPLATEGENERATOR_TEMPLATEGENERATOR_H_
#define TEMPLATEGENERATOR_TEMPLATEGENERATOR_H_

#include "interfaces/iTemplateGenerator.h"
#include <string>
#include <fstream>

class TemplateGenerator: public iTemplateGenerator {

std::ofstream ofs;

public:
	TemplateGenerator(std::string);
	virtual ~TemplateGenerator();
	void generateTemplate(const std::string);
};

#endif /* TEMPLATEGENERATOR_TEMPLATEGENERATOR_H_ */
