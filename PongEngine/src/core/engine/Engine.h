#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

#include "EngineData.h"
#include "../../CoreTypeDef.h"

ENGINE_BEGIN

	class EngineComponent;
	class RendererComponent;
	class InputComponent;

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
		std::shared_ptr<T> CreateComponent();

		void init(unsigned int width_to_set, unsigned int height_to_set, std::string_view title_to_set);

		void run();

		[[nodiscard]] std::shared_ptr<EngineData> GetData() const { return  data_; }


	private:

		EngineCore() = default;

		std::shared_ptr<EngineData> data_;

		std::shared_ptr<sf::RenderWindow> render_window_;

		std::shared_ptr<SceneManager> scene_manager_;
		std::shared_ptr<InputComponent> input_component_;
		std::shared_ptr<RendererComponent> renderer_component_;

		std::vector<std::shared_ptr<EngineComponent>> engine_components_;
	};


ENGINE_END


