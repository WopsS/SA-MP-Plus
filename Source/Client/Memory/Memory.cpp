#include <stdafx.hpp>
#include <Memory/Memory.hpp>

void Memory::Copy(void* Destination, const void* Source, const std::size_t Count)
{
	auto OldProtection = Unprotect(Destination, Count);

	std::memcpy(Destination, Source, Count);
	Protect(Destination, Count, OldProtection);
}

void Memory::Protect(void* Address, const std::size_t Size, DWORD OldProtection)
{
	VirtualProtect(Address, Size, OldProtection, nullptr);
}

void Memory::Set(void* Destination, const int Source, const std::size_t Count)
{
	auto OldProtection = Unprotect(Destination, Count);

	std::memset(Destination, Source, Count);
	Protect(Destination, Count, OldProtection);
}

const DWORD Memory::Unprotect(void* Address, const std::size_t Size)
{
	DWORD OldProtection;	 
	VirtualProtect(Address, Size, PAGE_READWRITE, &OldProtection);

	return OldProtection;
}
