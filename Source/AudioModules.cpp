
#include "AudioModules.hpp"

AudioModule::AudioModule()
{
  m_max_loop = MAX_LOOP;
}

WhiteNoise::WhiteNoise()
{
  // No ! Rookie error, it is not heap allocated !
  //m_ins = new dico();

  m_outs["OUT"] = "";
}

WhiteNoise::~WhiteNoise()
{
  //TODO: Needed ?
}

NinjaStar::NinjaStar()
{
  m_ins["IN"] = "";
  m_outs["OUT_1"] = "";
  m_outs["OUT_2"] = "";
  m_outs["OUT_3"] = "";
  m_outs["OUT_4"] = "";
  m_outs["OUT_5"] = "";
}

NinjaStar::~NinjaStar()
{
  //TODO: Needed ?
}
