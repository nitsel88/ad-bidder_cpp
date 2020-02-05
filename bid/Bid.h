/*
 * bid.h
 *
 *  Created on: Feb 5, 2020
 *      Author: 269069
 */

#ifndef BID_H_
#define BID_H_

class Bid {
      std::string bidId;
      std::string markUp;
      double price;

   public:
      Bid(std::string bidid, std:string markup, double prc) :
         bidId(bidid), markUp(markup), price(prc)_{}

      const std::string getBidId() const {
         return bidId;
      }
      const std::string getMarkup() const {
         return markUp;
      }
      const float getPrice() const {
         return price;
      }
};


#endif /* BID_H_ */
