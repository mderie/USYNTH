
#ifndef CONFIGURATION_FILES
#define CONFIGURATION_FILES

#include <string>
#include <map> // We could also use unordered map here...
#include <vector>

//TODO: Split this into a mapper and a configuration file reader !

// Base class for all configuration files...
//TODO: Implement default value and section support
class ConfigurationFile
{
private:
  std::map<std::string, std::string> m_dic;
public:
	ConfigurationFile(const std::string &filename);
	std::string getKeyValue(const std::string &key);
	std::vector<std::string> getKeys();
};

class GlobalConfigurationSingleton : public ConfigurationFile
{
private:
  static GlobalConfigurationSingleton *s_instance;
  GlobalConfigurationSingleton();
  //GlobalConfigurationSingleton(const GlobalConfigurationSingleton &) {}
public:
  static GlobalConfigurationSingleton *getInstance();
};

class MidiConfigurationSingleton : public ConfigurationFile
{
//TODO
};

#endif // CONFIGURATION_FILES
