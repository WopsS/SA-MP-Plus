#pragma once

template<typename T>
class Singleton
{
public:

	template<typename... Args>
	static T* GetInstance(Args&& ...args)
	{
		std::call_once(m_once, [&]()
		{
			m_instance = new T(std::forward<Args>(args)...);
		});

		return m_instance;
	}

	static const bool IsReleased()
	{
		return m_instance == nullptr;
	}

	static bool Release()
	{
		if (m_instance != nullptr)
		{
			delete m_instance;
			m_instance = nullptr;

			return true;
		}

		return false;
	}

protected:

	Singleton() = default;
	virtual ~Singleton() = default;

private:

	static T* m_instance;

	static std::once_flag m_once;
};

template<typename T>
T* Singleton<T>::m_instance = nullptr;

template<typename T>
std::once_flag Singleton<T>::m_once;