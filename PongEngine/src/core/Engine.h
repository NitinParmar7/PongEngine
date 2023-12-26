#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "CoreTypeDef.h"
#include "EngineData.h"


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

		[[nodiscard]] std::shared_ptr<EngineData> GetData() const { return  data_; }

	private:

		EngineCore() = default;

		std::shared_ptr<EngineData> data_;

		std::shared_ptr<sf::RenderWindow> render_window_;

		std::unique_ptr<SceneManager> scene_manager_;

	};

ENGINE_END
