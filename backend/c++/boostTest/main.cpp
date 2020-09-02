#include <string>
#include <boost/regex.hpp>
#include <iostream>

int main()
{
	std::string line;
	boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

	std::cout << "Regex: " << pat << std::endl;

	bool any = false;

	while (std::cin)
	{
		any = true;
		std::getline(std::cin, line);
		std::cout << "Read line: " << line << std::endl;
		boost::smatch matches;
		if (boost::regex_match(line, matches, pat))
		{
			std::cout << "Matches [" << matches.size() << "]: ";
			for(const auto& match : matches)
			{
				std::cout << match;
				if(&match != &matches[(int) matches.size() - 1])
					std::cout << " | ";
			}
			std::cout << std::endl;
		}
		else
		{
			std::cout << "No Matches" << std::endl;
		}
	}

	if(!any){
		std::cout << "ERROR: no lines found in std::cin" << std::endl;
	}
}