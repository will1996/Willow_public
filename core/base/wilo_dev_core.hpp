#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include<optional>
#include<map>
#include<functional>
#include<assert.h>
#include<memory>
#include<atomic>
#include "logr.hpp"
#include "WiloConfig.h"
#include "wilo_APICodes.hpp"

#define WILO_ASSERT(result) assert(result==true)


namespace wilo {
	inline bool fexists(const std::string& path) {
		FILE* file = fopen(path.c_str(), "r");
		if (file)
			fclose(file);
		return file;
	}
	inline bool endsWith(const std::string& str, const std::string& suffix) {
		return str.size() > suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
	}

	template<typename T>
	using UniquePointer = std::unique_ptr<T>;

	 template<typename T, typename ... Args>
	constexpr UniquePointer<T> CreateUniquePointer(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)... );
	}

	template<typename T>
	using SharedPointer = std::shared_ptr<T>;

	 template<typename T, typename ... Args>
	constexpr SharedPointer<T> CreateSharedPointer(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)... );
	}
}
