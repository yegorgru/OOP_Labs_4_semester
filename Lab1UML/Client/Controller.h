#pragma once

#include "EnumCode.h"

namespace Docking::Client {
	class Controller {
	public:
		virtual Code Run()=0;
	};
}