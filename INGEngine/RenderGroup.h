#ifndef RENDERGROUP_H
#define RENDERGROUP_H


#include "RenderLayer.h"

namespace ING {
	namespace Engine {

		class RenderLayer;

		class Renderer;

		class RenderGroup {
		public:
			RenderGroup();
			~RenderGroup();

		public:
			RenderLayer* layer;

		public:
			RenderGroup* next;
			RenderGroup* prev;
		
		private:
			Renderer* headRenderer;
			Renderer* tailRenderer;


		public:
			void Add(Renderer* renderer);
			void Remove(Renderer* renderer);
		};

	}
}

#endif