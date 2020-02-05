/*
 * ResponseParser.cpp
 *
 *  Created on: Feb 5, 2020
 *      Author: nithy
 */

#include "ResponseParser.h"

void ResponseParser::parseBids() {
   std::stringstream tmp;
   tmp << fileStream.rdbuf();
   std::string s = tmp.str();
   const char *inputJsonStr = s.c_str();

   //Parse the char string to JSON
   doc.Parse(inputJsonStr);

   //get the bid details from JSON to a vector
   for (auto const& seatBid : doc["seatbid"].GetArray()) {
      for (auto const& bid : seatBid["bid"].GetArray()) {
         std:string bidId = bid["id"].GetString();
         std:string markUp = bid["adm"].GetString();
         float price = bid["price"].GetString();
         bids.push_back(Bid(bidId, markUp, price));
      }
   }

}

ResponseParser::ResponseParser(std::string s) {
   inputFileStream = std::ifstream(s.c_str());
   //Read the file stream to char
   if (inputFileStream.is_open()) {
      parseBids();
   } else {
      std::cout << "unable to open file";
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

