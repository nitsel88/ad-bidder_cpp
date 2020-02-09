/*
Bid - Model for the Bid
*/

#ifndef BID_H_
#define BID_H_

#include <string>

class Bid {
      std::string bidId;
      std::string markUp;
      double price;

   public:
      Bid(std::string bidid, std::string markup, double prc) :
           bidId(bidid), markUp(markup), price(prc) {}
      const std::string getBidId ();
      const std::string  getMarkup();
      const double getPrice();
};


#endif /* BID_H_ */
