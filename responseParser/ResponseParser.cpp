#include "ResponseParser.h"
#include <stdexcept>

void ResponseParser::parseBids() {
   std::stringstream tmp;

   tmp << inputFileStream.rdbuf();
   std::string s = tmp.str();
   const char *inputJsonStr = s.c_str();

   //Parse the char string to JSON
   doc.Parse(inputJsonStr);
   if (doc.ObjectEmpty()) {
       throw std::runtime_error("Json object is empty");
   }
   else {
       //get the bid details from JSON to a vector of bid objects
       for (auto const& seatBid : doc["seatbid"].GetArray()) {
           for (auto const& bid : seatBid["bid"].GetArray()) {
               auto bidId = bid["id"].GetString();
               auto markUp = bid["adm"].GetString();
               double price = bid["price"].GetDouble();
               bids.push_back(Bid(bidId, markUp, price));
           }
       }
   }
}

ResponseParser::ResponseParser(std::string s) {
   inputFileStream = std::ifstream(s.c_str());
   //Read the file stream to char
   if (!inputFileStream.is_open()) {
       throw std::runtime_error("Error opening bid-response.json");
   } else {
      parseBids();
   }
}

std::vector<Bid> ResponseParser::getBids() {
   return bids;
}

ResponseParser::~ResponseParser() {
   if (inputFileStream.is_open()) {
      inputFileStream.close();
   }
}

