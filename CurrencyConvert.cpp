//	CurrencyConvert
//	By: Jesper Andersson

//https://www.boost.org/ beast/asio
//https://github.com/nlohmann/json

/*
	Requirements:
	Query and interpret exchange-rate data ?European exchange?
	Convert from one currency to another
	Santize user input
	============ EXTRA ============
	Display latest search history
	Cryptocurrency support
	Display historical conversion ("1 USD to SEK in 2019")
	
*/

#include <iostream>
#include <fstream>
#include <string>
#include <json.hpp>
#include <boost/asio.hpp>
#include <openssl/err.h>


int main()
{
	FILE * jsonFile;
	std::string myText;

	//jsonFile = fopen("./samplehttp.json", "r");

	std::ifstream MyReadFile("./samplehttp.json");
	while (getline (MyReadFile, myText)){
		std::cout << myText;
		std::cout << std::endl;
	}

	MyReadFile.close();

	/*
	// Debug Variables:
	*/
	std::string defaultCurrencies[3] = {"USD", "EUR", "SEK"};
	std::string currencyValuesArr[] = {
		"EUR", "1",
		"USD", "1.08",
		"SEK", "10.3",
	};


	bool nonspecificTarget = false;
	std::string baseCurrency;
	std::string targetCurrency;

	std::cout << "Enter the currency you'd like to convert from: \n";
	std::cin >> baseCurrency;
	baseCurrency = "USD"; //DEBUG!!!
	std::cout << "\n";

	std::cout << "Enter the currency you'd like to convert to: \n";
	std::cout << "[Leaving this blank will display " << baseCurrency << " in USD, EUR, SEK]\n"; //TODO: Display from defaultCurrencies array.
	std::cin >> targetCurrency;

	nonspecificTarget = targetCurrency.empty();

	if (nonspecificTarget)
	{
		for (size_t i = 0; i < 5; i++)
		{
			if (currencyValuesArr[i] == defaultCurrencies[0] || currencyValuesArr[i] == defaultCurrencies[1] || currencyValuesArr[i] == defaultCurrencies[3])
			{
				std::cout << currencyValuesArr[i + 1];
			}
		}
	}
	else 
	{
		std::cout << currencyValuesArr[currencyValuesArr->find(baseCurrency)];
		std::string baseCurrencyValueStr = currencyValuesArr[currencyValuesArr->find(baseCurrency) + 1];
		double baseCurrencyValue = std::stod(baseCurrencyValueStr);

		std::string targetCurrencyValueStr = currencyValuesArr[currencyValuesArr->find(targetCurrency) + 1];
		double targetCurrencyValue = std::stod(targetCurrencyValueStr);
	}
}