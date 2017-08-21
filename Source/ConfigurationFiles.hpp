
#ifndef CONFIGURATION_FILES
#define CONFIGURATION_FILES

#include <string>
#include <map> // We could use unordered map here...
#include <vector>

//TODO: Split this into a mapper and a configuration file reader !

// Base class for all configuration files...
class ConfigurationFile
{
private:
  std::map<std::string, std::string> m_dic;
public:
	ConfigurationFile(const std::string &filename);
	std::string getKeyValue(const std::string &key);
	std::vector<std::string> getKeys();
};

#endif // CONFIGURATION_FILES
