
#include <iostream.h>
#include <string>
#include "responseParser/ResponseParser.h"
#include "templateGenerator/TemplateGenerator.h"

int main() {
  ResponseParser parser("bid-response.json");
  TemplateGenerator tempGen("index.html");
  BidManager{parser, tempGen}.run();
}
