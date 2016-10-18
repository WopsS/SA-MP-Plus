#pragma once

namespace Memory
{
	void Copy(void* Destination, const void* Source, const std::size_t Count);

	void Protect(void* Address, const std::size_t Size, DWORD OldProtection);

	template<typename TDestination, typename TValue>
	void Put(TDestination Destination, const TValue& Value)
	{
		Copy((void*)Destination, &Value, sizeof(TValue));
	}

	void Set(void* Destination, const int Source, const std::size_t Count);

	const DWORD Unprotect(void* Address, const std::size_t Size);
}