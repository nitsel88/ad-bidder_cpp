#include "BidManager.h"

BidManager::~BidManager() {
   // TODO Auto-generated destructor stub
}

//returns the selected bid object
Bid* BidManager::getSelectedBid() {
   bids = responseParser.getBids();
   auto selBidIterator = std::max_element(bids.begin(), bids.end(),
         [](Bid &a, Bid &b) { return a.getPrice() < b.getPrice();});
   selectedBid = &(*selBidIterator);
   return selectedBid;
}

//wires the markup from selected bid to template generator
void BidManager::run() {
   Bid* selectedBid = getSelectedBid();
   templateGenerator.generateTemplate(selectedBid->getMarkup());
   std::cout << "Selected Bid Id: " << selectedBid->getBidId() << std::endl;
   std::cout << "Selected Bid Price: " << selectedBid->getPrice() << std::endl;
   std::cout << "index.html generated " << std::endl;
}
