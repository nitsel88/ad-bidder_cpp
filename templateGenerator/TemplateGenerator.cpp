/*
 * TemplateGenerator.cpp
 *
 *  Created on: Feb 5, 2020
 *      Author: nithy
 */
#include <string>
#include "TemplateGenerator.h"

TemplateGenerator::TemplateGenerator(std::string filename) {
   ofs.open(filename);
}

TemplateGenerator::~TemplateGenerator() {
   if (ofs.is_open())
   {
     myfile.close();
   }
}

void TemplateGenerator::generateTemplate(std::string markup) {

  std::cout << markup;
}
