#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H


#include "EntityComponent.h"
#include <DirectXMath.h>

#include <iostream>

namespace ING {
	namespace Engine {



		namespace EntityComponents {

			class Transform : public EntityComponent {

			public:
				Transform();
				~Transform();

			public:
				DirectX::XMFLOAT3 localXMF3Pos;
				DirectX::XMFLOAT3 worldXMF3Pos;
				

#pragma region OverrideEvents 
			public:
				virtual void OnComponentAdded() override;
#pragma endregion OverrideEvents


			};


		}

	}
}


#endif