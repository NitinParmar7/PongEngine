#pragma once
#include <memory>
#include <string_view>
#include "CoreTypeDef.h"

namespace sf
{
	class RenderWindow;
}

ENGINE_BEGIN
	class EngineCore
	{

	public:
	
		EngineCore(const EngineCore&) = delete;

		EngineCore(const EngineCore&&) = delete;

		EngineCore& operator=(const EngineCore&) = delete;

		EngineCore& operator=(const EngineCore&&) = delete;

		static EngineCore& get();

		void init(unsigned int width_to_set, unsigned int height_to_set, std::string_view title_to_set);

		void start();


	private:

		EngineCore() = default;

		~EngineCore() = default;

		unsigned int width_ = 1080;

		unsigned int height_ = 720;

		std::string_view title_;

		std::shared_ptr<sf::RenderWindow> render_window_;

	};

ENGINE_END
