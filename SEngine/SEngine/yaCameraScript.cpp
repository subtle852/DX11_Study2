#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();


		if (Input::GetKey(eKeyCode::NUM6))
		{
			pos.z += 5.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::NUM4))
		{
			pos.z -= 5.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::NUM1))
		{
			pos.x -= 5.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::NUM3))
		{
			pos.x += 5.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::NUM2))
		{
			pos.y -= 5.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::NUM5))
		{
			pos.y += 5.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

	}
}
