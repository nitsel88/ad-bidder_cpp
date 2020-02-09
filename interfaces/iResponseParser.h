/*
response parser - abstract class 
*/
#ifndef IRESPONSEPARSER_H_
#define IRESPONSEPARSER_H_

#include <vector>
#include "../bid/Bid.h"

class iResponseParser {
   public:
      virtual std::vector<Bid> getBids() = 0;
      virtual ~iResponseParser() = default;
};

#endif /* IRESPONSEPARSER_H_ */
