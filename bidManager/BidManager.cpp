/*
 * BidManager.cpp
 *
 *  Created on: Feb 5, 2020
 *      Author: 269069
 */

#include "BidManager.h"

BidManager::~BidManager() {
   // TODO Auto-generated destructor stub
}

Bid& BidManager::getSelectedBid() {
   bids = responseParser.getBids();
   Bid& selectedBid = std::max_element(bids.begin(), bids.end(),
         [](const Bid &a, const Bid &b) { return a.getPrice() < b.getPrice();});
   return selectedBid;
}
void BidManager::run() {
   Bid selectedBid = getSelectedBid();
   templateGenerator.generateTemplate(selectedBid.getMarkup());
}
