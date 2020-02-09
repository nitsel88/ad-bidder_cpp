/*
 BidManager - business logic for selecting bids
*/
#ifndef BIDMANAGER_H_
#define BIDMANAGER_H_

#include "../interfaces/iResponseParser.h"
#include "../interfaces/iTemplateGenerator.h"
#include "../bid/bid.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class BidManager {

      iResponseParser& responseParser;
      iTemplateGenerator& templateGenerator;
      std::vector<Bid> bids;
      Bid* selectedBid = 0; 

   public:
      BidManager(iResponseParser& respParser, iTemplateGenerator& templateGen):
               responseParser(respParser), templateGenerator(templateGen) {}
      Bid* getSelectedBid();
      virtual ~BidManager();
      void run();
};

#endif /* BIDMANAGER_H_ */
