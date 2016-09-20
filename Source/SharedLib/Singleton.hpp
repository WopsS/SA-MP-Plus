#pragma once

namespace SharedLib
{
	template<typename T>
	class Singleton
	{
	public:

		template<typename... Args>
		static T* GetInstance(Args&& ...args)
		{
			std::call_once(m_once, [](auto&&... args)
			{
				m_instance = std::make_unique<T>(decltype(args)(args)...);
			}, std::forward<Args>(args)...);

			return m_instance.get();
		}

		static bool Release()
		{
			if (m_instance != nullptr)
			{
				m_instance.reset();

				return true;
			}

			return false;
		}

	protected:

		Singleton() = default;
		virtual ~Singleton() = default;

	private:

		static std::unique_ptr<T> m_instance;

		static std::once_flag m_once;
	};

	template<typename T>
	std::unique_ptr<T> Singleton<T>::m_instance = nullptr;

	template<typename T>
	std::once_flag Singleton<T>::m_once;
}