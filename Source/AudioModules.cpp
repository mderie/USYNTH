
#include "AudioModules.hpp"

#include <limits>
#include <algorithm>

Kind moduleKind(const std::string &s)
{
  // No std::find for classical array ?
  for (unsigned i = 0; i < sizeOfArray(Kinds); i++)
  {
		if (stringUpper(s) == Kinds[i])
		{
			return (Kind) i;
		}
  }

  return Kind::LAST_ITEM;
}

/////////////////////// CaseElement ///////////////////////

std::string CaseElement::dump()
{
	return Kinds[(int) m_kind] + '_' + m_id;
}

CaseElement::~CaseElement()
{
// Strange he ? See http://www.geeksforgeeks.org/pure-virtual-destructor-c/
}

/////////////////////// CaseSingleton ///////////////////////

CaseSingleton* CaseSingleton::s_instance = nullptr;

CaseSingleton* CaseSingleton::instance()
{
	if (s_instance == nullptr)
	{
		s_instance = new CaseSingleton();
	}

	return s_instance;
}

CaseSingleton::~CaseSingleton()
{
  clear();
}

// See : https://stackoverflow.com/questions/6353149/does-vectorerase-on-a-vector-of-object-pointers-destroy-the-object-itself
void CaseSingleton::clear()
{
  // Doesn't compile...
  // std::for_each(m_elements.begin(), m_elements.end(), delete);

  // Does not infer the good type ?
  //for (auto item : m_elements) delete item->second();
  for (auto cIter = m_elements.cbegin(); cIter != m_elements.cend(); cIter++)
  {
     delete cIter->second;
  }
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
  delete element;
}

CaseElement* CaseSingleton::element(const std::string& id)
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

int CaseSingleton::size()
{
  return m_elements.size();
}

std::string CaseSingleton::dump()
{
	//std::string result = "toto\ntiti";
	std::string result = "";

  for (const auto& kv : m_elements)
  {
    join(result, kv.first + "=" + kv.second->dump(),"\n"); // Or use "," as delimiter ?
	}

	if (result.size() == 0)
	{
		result = "The case is still empty ! Use the ADD command to stuff it :)";
	}

	return result;
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

/////////////////////// AudioModule ///////////////////////

AudioModule* CreateModuleFactory(Kind kind)
{
	switch (kind)
	{
		case Kind::LFO :
		case Kind::VCO : //TODO: You are the next one !-)
		case Kind::VCF :
		case Kind::VCA : { return nullptr; }
		case Kind::RND : return new WhiteNoise();
		case Kind::DUP :
		case Kind::ENV :
		case Kind::ADD :
		case Kind::SUB :
		case Kind::AND :
		case Kind::MIX :
		case Kind::NOT :
		case Kind::PAN :
		case Kind::OUT : return nullptr;
		default: return nullptr;
	}
}

AudioModule::AudioModule()
{
  m_loop_counter_max = LOOP_COUNTER_MAX;
  reset();
}

std::string AudioModule::dump()
{
	std::string result = "IN = ";
	std::string tmp = "";
  // for_each(m_ins.begin(), m_ins.end(), join(result, it*...second ? ))
  for (const auto& kv : m_ins)
  {
    join(tmp, kv.first + '=' + kv.second, ",");
	}

	result += tmp + ";OUT = ";
	tmp = "";
  for (const auto& kv : m_outs)
  {
    join(tmp, kv.first + '=' + kv.second, ",");
	}
	return result + tmp;
}

void AudioModule::reset()
{
  m_loop_counter = 0;
}

/////////////////////// OutModule ///////////////////////

OutModule::OutModule()
{
	m_kind = Kind::OUT;
  m_ins["L"] = "";
  m_ins["R"] = "";
}

OutModule::~OutModule()
{
//TODO: Needed ?
}

/////////////////////// WhiteNoise ///////////////////////

WhiteNoise::WhiteNoise()
{
  // No ! Rookie error, it is not heap allocated !
  //m_ins = new dico();

  m_kind = Kind::RND; //TODO: Check if we have a 1-to-1 mapping between module kind and AudioModule subclass !
  m_outs["OUT"] = "";
}

WhiteNoise::~WhiteNoise()
{
  //TODO: Needed ?
}

/////////////////////// NinjaStar ///////////////////////

NinjaStar::NinjaStar()
{
  m_kind = Kind::DUP;
  m_ins["IN"] = "";
  m_outs["OUT_1"] = "";
  m_outs["OUT_2"] = "";
  m_outs["OUT_3"] = "";
  m_outs["OUT_4"] = "";
  m_outs["OUT_5"] = "";
  m_loop_counter_max = std::numeric_limits<int>::max(); // There is no limit !-)
}

NinjaStar::~NinjaStar()
{
  //TODO: Needed ?
}

/////////////////////// PatchCable ///////////////////////

PatchCable::PatchCable()
{
  m_kind = Kind::CBL;
}

PatchCable::~PatchCable()
{
  //TODO: Needed ?
}
