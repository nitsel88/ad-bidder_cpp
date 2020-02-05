/*
 * iResponseParser.h
 *
 *  Created on: Feb 5, 2020
 *      Author: 269069
 */

#ifndef IRESPONSEPARSER_H_
#define IRESPONSEPARSER_H_

class iResponseParser {
   public:
      virtual void getBids() = 0;
      virtual ~iResponseParser() = default;
};

#endif /* IRESPONSEPARSER_H_ */
