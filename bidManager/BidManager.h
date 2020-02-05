/*
 * BidManager.h
 *
 *  Created on: Feb 5, 2020
 *      Author: 269069
 */

#ifndef BIDMANAGER_H_
#define BIDMANAGER_H_

#include "interfaces/iResponseParser.h"
#include "interfaces/iTemplateGenerator.h"
#include "bid/bid.h
#include <vector>

class BidManager {

      iResponseParser& responseParser;
      iTemplateGenerator& templateGenerator;
      std::vector<Bid> bids;
      Bid& getSelectedBid();

   public:
      BidManager(iResponseParser& respParser, iTemplateGenerator& templateGen):
               responseParser(respParser), templateGenerator(templateGen) {}
      virtual ~BidManager();
      void run();
};

#endif /* BIDMANAGER_H_ */
