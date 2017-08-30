
#ifndef KEYWORD_COMMANDS
#define KEYWORD_COMMANDS

#include <string>

//TODO: Support the following ones.
// ls (dir), patch (link?), exit (quit), add (?), edit (change? modify), remove (delete)
// load (?), save (?), assfun, describe (dump)

// Base class for all keyword commands...
class KeywordCommand
{
public:
  static bool process(std::string& what); // Return false for unknown command & clear what if exit or quit found !
};

#endif // KEYWORD_COMMANDS
