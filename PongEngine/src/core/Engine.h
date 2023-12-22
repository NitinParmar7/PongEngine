#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "CoreTypeDef.h"


ENGINE_BEGIN

	class SceneManager;

	class EngineCore
	{

	public:

		~EngineCore() = default;
	
		EngineCore(const EngineCore&) = delete;

		EngineCore(const EngineCore&&) = delete;

		EngineCore& operator=(const EngineCore&) = delete;

		EngineCore& operator=(const EngineCore&&) = delete;

		static EngineCore& get();

		void init(unsigned int width_to_set, unsigned int height_to_set, std::string_view title_to_set);

		void run();


	private:

		EngineCore() = default;



		unsigned int width_ = 1080;

		unsigned int height_ = 720;

		std::string_view title_;

		std::shared_ptr<sf::RenderWindow> render_window_;

		std::unique_ptr<SceneManager> scene_manager_;

	};

ENGINE_END
