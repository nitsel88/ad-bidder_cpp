#include "TemplateGenerator.h"
#include <stdexcept>

std::string TemplateGenerator::formatMarkup(std::string markup) {
    std::string finalMarkup;

 for(size_t idx(0); idx < markup.length(); ++idx) {
     if((markup[idx] == '\\') && (markup[idx+1] == 'n')) {
         finalMarkup += "\\r";
         ++idx;
     }
     else
     {
         finalMarkup += markup[idx];
     }
 }
 return finalMarkup;
} 

TemplateGenerator::TemplateGenerator(std::string filename) {
   ofs.open(filename);
   if (!ofs.is_open()) {
       throw std::runtime_error("Error opening outputfile");
   }
}

TemplateGenerator::~TemplateGenerator() {
   if (ofs.is_open())
   {
     ofs.close();
   }
}

void TemplateGenerator::generateTemplate(std::string markup) {

   HTML::Document document("Welcome to ad-bidder");
   document.addAttribute("lang", "en");
   document << HTML::Header3("Ad-bidder HTML") << HTML::Break() << HTML::Break();
   document.body() << formatMarkup(markup);
   ofs << document;
}
