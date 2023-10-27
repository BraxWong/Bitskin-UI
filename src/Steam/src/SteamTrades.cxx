#include "../header/SteamTrades.h"
#include <iostream>
#include <string>

bool SteamTrades::getSteamTrades(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string appID, limit, offset;
  std::cout << "Please provide the appID:\ncs2: 730\ndota2: 570\ntf2: 440\nrust: 252490\n";
  std::getline(std::cin, appID);
  std::cout << "Please provide the limit:\n";
  std::getline(std::cin, limit);
  std::cout << "Please provide the offset:\n";
  std::getline(std::cin, offset);
  std::vector<std::string> keys = {"app_id", "limit", "offset"};
  std::vector<std::string> values = {appID, limit, offset};
  std::vector<std::string> dataTypes = {"Number", "Number", "Number"};
  this->executeBash->executeBashScript("https://api.bitskins.com/steam/trade/list", this->profile->user->getAPIKey(), keys, values, dataTypes);
  return true;
}

