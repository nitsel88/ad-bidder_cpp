/*
 * ResponseParser.h
 *
 *  Created on: Feb 5, 2020
 *      Author: nithy
 */

#ifndef RESPONSEPARSER_RESPONSEPARSER_H_
#define RESPONSEPARSER_RESPONSEPARSER_H_


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "interfaces/iResponseParser.h"
#include "bid/bid.h"

class ResponseParser : public iResponseParser {

private:
   std::istream& input;
   std::vector<Bid> bids;
   std::ifstream inputFileStream;
   rapidjson::Document doc;
   void parseBids();

public:
	ResponseParser(std::string);
	virtual ~ResponseParser();
	std::vector<Bid> getBids();
};

#endif /* RESPONSEPARSER_RESPONSEPARSER_H_ */
