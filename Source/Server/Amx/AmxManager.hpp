#pragma once

class AmxManager : public Singleton<AmxManager>
{
public:

	void Add(AMX* Amx);

	const std::list<AMX*>& GetList() const;

	void Remove(AMX* Amx);

private:

	friend class Singleton<AmxManager>;

	AmxManager() = default;
	~AmxManager() = default;

	std::list<AMX*> m_amxInstances;
};