#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "CoreTypeDef.h"
#include "EngineData.h"
#include "graphics/RenderComponent.h"
#include "input/InputComponent.h"


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

		template<class T>
		std::unique_ptr<T> CreateComponent(T* component);

		void init(unsigned int width_to_set, unsigned int height_to_set, std::string_view title_to_set);

		void run();

		[[nodiscard]] std::shared_ptr<EngineData> GetData() const { return  data_; }


	private:

		EngineCore() = default;

		std::shared_ptr<EngineData> data_;

		std::shared_ptr<sf::RenderWindow> render_window_;

		std::unique_ptr<SceneManager> scene_manager_;
		std::unique_ptr<InputComponent> input_component_;
		std::unique_ptr<RenderComponent> render_component_;

		std::vector<std::unique_ptr<EngineComponent>> engine_components_;
	};



ENGINE_END
