
#include <iostream>
#include <fstream>

#include "ConfigurationFiles.hpp"
#include "CommonStuffs.hpp"

ConfigurationFile::ConfigurationFile(const std::string &filename)
{
	std::ifstream ifs;
	std::string line;
	size_t pos;
	std::string section;

	//std::cout << "filename = " << filename << std::endl;

	ifs.open(filename);
	while(!ifs.eof())
	{
		std::getline(ifs, line);
		//std::cout << "line = " << line << std::endl;
		if (line[0] == ';')
		{
			//std::cout << "Found comment = " << line << std::endl;
			continue; // Just ignore comment :)
		}

		if (line.size() == 0)
		{
			//std::cout << "Found empty line !" << line << std::endl;
			continue; // Just ignore empty line
		}

		if ((line.front() == '[') and (line.back() == ']'))
		{
			section = line.substr(1, line.size() - 2); // We also use cbegin() and cend() but why bother !
			//std::cout << "Found section = " << section << std::endl;
		}
		else if ((pos = line.find('=', 0)) != std::string::npos)
		{
			//std::cout << "key = '" << line.substr(0, pos) << "', value = '" << line.substr(pos + 1, line.size() - pos + 1) << "'" << std::endl;
			m_contents[section][line.substr(0, pos)] = line.substr(pos + 1, line.size() - pos + 1);
		}
		else
		{
			std::cout << "Found bad line in filename = " << filename << " value = " << line << std::endl;
			/*
			We can't log yet ! Ca we ?
			logThis("Found error in the configuration file !", Target::misc);
			logThis("Filename = ...", Target::misc);
			logThis(filename.c_str(), Target::misc);
			logThis("Line = ...", Target::misc);
			logThis(line.c_str(), Target::misc);
			*/
		}
	}
	ifs.close();
}

ConfigurationFile::~ConfigurationFile()
{
	m_contents.clear();
}

std::vector<std::string> ConfigurationFile::keyNames(const std::string &section)
{
  std::vector<std::string> result;
  for(auto const &kvp : m_contents[section])
  {
    result.push_back(kvp.first);
	}

	return result;
}

std::string ConfigurationFile::keyValue(const std::string &section, const std::string &key)
{
	return m_contents[section][key];
}

/////////////////////// GlobalConfigurationSingleton ///////////////////////

GlobalConfigurationSingleton *GlobalConfigurationSingleton::s_instance = nullptr;

GlobalConfigurationSingleton *GlobalConfigurationSingleton::instance()
{
	if (s_instance == nullptr)
	{
	  // Unusual :p One singleton per "generalized" configuration file...
	  std::string fullFilename = appendPath({ runningFolder(), folders[(int) Folder::configurations], "global.sex" });
	  //std::cout << "fullFilename = " << fullFilename << std::endl;

	  // Upcast...
		s_instance = (GlobalConfigurationSingleton *) (new ConfigurationFile(fullFilename));
	}

	return s_instance;
}

/*
GlobalConfigurationSingleton::~GlobalConfigurationSingleton()
{
	std::cout << "~GlobalConfigurationSingleton" << std::endl;
}
*/
