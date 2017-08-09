
#include "AudioModules.hpp"

#include <limits>

using namespace std;

/*
CaseSingleton::CaseSingleton()
{
  // ?
}

CaseSingleton::~CaseSingleton()
{
  clear();
}
*/

void CaseSingleton::clear()
{
  m_elements.clear();
}

void CaseSingleton::add(CaseElement* element)
{
  // Who compute the element.id ? What to do if max reached ?
  m_elements[element->getId()] = element;
}

void CaseSingleton::del(CaseElement* element)
{
  m_elements.erase(element->getId());
}

CaseElement* CaseSingleton::getElement(const std::string& id)
{
  if (m_elements.find(id) == m_elements.end())
  {
    return nullptr;
  }
  else
  {
    return m_elements[id];
  }
}

int CaseSingleton::getSize()
{
  return m_elements.size();
}

/*
const std::string& CaseSingleton::getId(int index)
{
  if (index > m_elements.size())
  {
    return "";
  }
  else
  {
    return m_elements
  }
}
*/

AudioModule::AudioModule()
{
  m_loop_counter_max = LOOP_COUNTER_MAX;
  reset();
}

void join(string &dest, const string &key, const string &value)
{
	if (dest.size() >= 0)
	{
		dest += ',' ;
	}

  dest += key + '=' + value;
}

string AudioModule::dump()
{
	string result = "IN = ";
	string tmp = "";
  // for_each(m_ins.begin(), m_ins.end(), join(result, it*...second ? ))
  for (const auto& kv : m_ins)
  {
    join(tmp, kv.first, kv.second);
	}

	result += tmp + ";OUT = ";
	tmp = "";
  for (const auto& kv : m_outs)
  {
    join(tmp, kv.first, kv.second);
	}
	return result + tmp;
}

void AudioModule::reset()
{
  m_loop_counter = 0;
}

WhiteNoise::WhiteNoise()
{
  // No ! Rookie error, it is not heap allocated !
  //m_ins = new dico();

  m_kind = Kind::RND;
  m_outs["OUT"] = "";
}

WhiteNoise::~WhiteNoise()
{
  //TODO: Needed ?
}

NinjaStar::NinjaStar()
{
  m_kind = Kind::DUP;
  m_ins["IN"] = "";
  m_outs["OUT_1"] = "";
  m_outs["OUT_2"] = "";
  m_outs["OUT_3"] = "";
  m_outs["OUT_4"] = "";
  m_outs["OUT_5"] = "";
  m_loop_counter_max = numeric_limits<int>::max(); // There is no limit !-)
}

NinjaStar::~NinjaStar()
{
  //TODO: Needed ?
}

PatchCable::PatchCable()
{
  m_kind = Kind::CBL;
}

PatchCable::~PatchCable()
{
  //TODO: Needed ?
}
