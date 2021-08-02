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



		struct RendererNode {
			Renderer* value;
			RendererNode* next;
			RendererNode* prev;
		};

		struct RendererList {
			RendererNode* head;
			RendererNode* tail;

			void Add(RendererNode* rendererNode) {
				if (head == nullptr) {
					head = rendererNode;
					tail = rendererNode;
				}
				else{
					tail->next = rendererNode;
					tail = rendererNode;
				}
			}

		};

	}
}

#endif