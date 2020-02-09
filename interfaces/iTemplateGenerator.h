/*
template generator- abstract class
*/
#ifndef ITEMPLATEGENERATOR_H_
#define ITEMPLATEGENERATOR_H_

#include<string>

class iTemplateGenerator {

   public:
      virtual void generateTemplate(std::string) = 0;
      virtual ~iTemplateGenerator() = default;
};

#endif /* ITEMPLATEGENERATOR_H_ */
