#include <stdafx.hpp>
#include <Amx/AmxManager.hpp>

void AmxManager::Add(AMX* Amx)
{
	m_amxInstances.push_back(Amx);
}

const std::list<AMX*>& AmxManager::GetList() const
{
	return m_amxInstances;
}

void AmxManager::Remove(AMX* Amx)
{
	m_amxInstances.remove(Amx);
}
