#ifndef RENDERER_H
#define RENDERER_H




namespace ING {
	namespace Engine {

		class RenderSystem;

		class Mesh;

		class Material;

		class Shader;

		class RenderState;

		class RenderGroup;

		class Renderer {
		public:
			Renderer();
			~Renderer();

		public:
			RenderSystem* system;

		private:
			Material* material;
			Mesh* mesh;
			RenderState* renderState;

		public:
			Material* GetMaterial();
			Mesh* GetMesh();
			RenderState* GetRenderState();

		public:
			void SetMaterial(Material* mat);
			void SetMesh(Mesh* mesh);
			void SetRenderState(RenderState* rState);

		public:
			RenderGroup* group;
			Renderer* next;
			Renderer* prev;

		};

	}
}

#endif