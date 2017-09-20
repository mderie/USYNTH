
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
  std::map<std::string, std::map<std::string, std::string> > m_contents; // The "> > " means I'm old school :)
public:
	ConfigurationFile(const std::string &filename);
	//Not needed ? virtual ~ConfigurationFile();
	~ConfigurationFile();
	std::string keyValue(const std::string &section, const std::string &key);
	std::vector<std::string> keyNames(const std::string &section);
};

class GlobalConfigurationSingleton : public ConfigurationFile
{
private:
  static GlobalConfigurationSingleton *s_instance;
  GlobalConfigurationSingleton();
  //GlobalConfigurationSingleton(const GlobalConfigurationSingleton &) {}
public:
   static GlobalConfigurationSingleton *instance();
  //~GlobalConfigurationSingleton();
};

class MidiConfigurationSingleton : public ConfigurationFile
{
//TODO
};

#endif // CONFIGURATION_FILES
