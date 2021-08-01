#ifndef RENDERER_H
#define RENDERER_H




namespace ING {
	namespace Engine {

		class RenderSystem;

		class Mesh;

		class Material;

		class Shader;

		class RenderState;

		class Renderer {
		public:
			Renderer();
			~Renderer();

		public:
			RenderSystem* system;

		public:
			Material* material;
			Mesh* mesh;
			RenderState* renderState;

		};

	}
}

#endif