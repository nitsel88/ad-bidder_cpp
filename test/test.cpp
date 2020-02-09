#include "pch.h"
#include "CppUnitTest.h"
#include "../responseParser/ResponseParser.h"
#include "../templateGenerator/TemplateGenerator.h"
#include "../bidManager/BidManager.h"
#include "../bid/Bid.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace adBidderTest
{
	std::string inputPath = "../bid-response.json";
	std::string outPutPath = "../test.html";
	TEST_CLASS(ResponseParserTest)
	{
	public:

		TEST_METHOD(getBidsReturnsListofBids)
		{

			ResponseParser r(inputPath);
			std::vector<Bid> bids = r.getBids();
			Assert::AreEqual(size_t(2), bids.size());
		}
	};

	TEST_CLASS(BidManagerTest)
	{
	public:

		TEST_METHOD(getSelectedBidReturnsBidWithMaxPrice)
		{

			ResponseParser r(inputPath);
			TemplateGenerator t(outPutPath);
			BidManager b(r, t);
			Bid *bid = b.getSelectedBid();
			Assert::AreEqual(5.01089295, bid->getPrice());
		}
	};

	TEST_CLASS(TemplateGeneratorTest)
	{
	public:
		TEST_METHOD(runMethodCreatesTemplateFile)
		{
			ResponseParser r(inputPath);
			TemplateGenerator t(outPutPath);
			BidManager b(r, t);
			b.run();
			std::ifstream templateFile(outPutPath);
			Assert::IsTrue(true == templateFile.good());
		}
	};
}
