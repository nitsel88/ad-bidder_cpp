/*
ResponseParser - Has JSON response parsing logic
*/
#ifndef RESPONSEPARSER_RESPONSEPARSER_H_
#define RESPONSEPARSER_RESPONSEPARSER_H_


#include "../thirdParty/rapidjson/include/rapidjson/document.h"
#include "../thirdParty/rapidjson/include/rapidjson/writer.h"
#include "../thirdParty/rapidjson/include/rapidjson/stringbuffer.h"

#include "../interfaces/iResponseParser.h"
#include "../bid/Bid.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class ResponseParser : public iResponseParser {

private:
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
