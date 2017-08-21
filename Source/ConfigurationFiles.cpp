
#include <iostream>
#include <fstream>

#include "ConfigurationFiles.hpp"

ConfigurationFile::ConfigurationFile(const std::string &filename)
{
	std::ifstream ifs;
	std::string line;
	size_t pos;

	//std::cout << "filename = " << filename << std::endl;

	ifs.open(filename);
	while(!ifs.eof())
	{
		std::getline(ifs, line);
		//std::cout << "line = " << line << std::endl;
		if (line[0] == ';')
		{
			continue;
		}

		if ((pos = line.find('=', 0)) != std::string::npos)
		{
			//std::cout << "key = '" << line.substr(0, pos - 1) << "', value = '" << line.substr(pos + 1, line.size() - pos + 1) << "'" << std::endl;
			m_dic[line.substr(0, pos - 1)] = line.substr(pos + 1, line.size() - pos + 1);
		}
	}
	ifs.close();
}

std::vector<std::string> ConfigurationFile::getKeys()
{
  std::vector<std::string> result;
  for(auto const& kvp : m_dic)
  {
    result.push_back(kvp.first);
	}

	return result;
}

std::string ConfigurationFile::getKeyValue(const std::string &key)
{
	return m_dic[key];
}
