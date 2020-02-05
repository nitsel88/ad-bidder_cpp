/*
 * iTemplateGenerator.h
 *
 *  Created on: Feb 5, 2020
 *      Author: 269069
 */

#ifndef ITEMPLATEGENERATOR_H_
#define ITEMPLATEGENERATOR_H_

class iTemplateGenerator {

   public:
      virtual void generateTemplate() = 0;
      virtual ~iTemplateGenerator() = default;
};

#endif /* ITEMPLATEGENERATOR_H_ */
