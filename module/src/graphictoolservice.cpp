// Local Includes
#include "graphictoolservice.h"
#include "parameterwindow.h"
#include "audiodevicesettingsgui.h"
#include "infowindow.h"

// External Includes
#include <parameterguiservice.h>
#include <appguiservice.h>
#include <nap/core.h>

RTTI_BEGIN_CLASS_NO_DEFAULT_CONSTRUCTOR(nap::GraphicToolService)
	RTTI_CONSTRUCTOR(nap::ServiceConfiguration*)
RTTI_END_CLASS

namespace nap
{
	bool GraphicToolService::init(nap::utility::ErrorState& errorState)
	{
        return true;
	}


	void GraphicToolService::getDependentServices(std::vector<rtti::TypeInfo>& dependencies)
	{
        dependencies.emplace_back(RTTI_OF(ParameterGUIService));
        dependencies.emplace_back(RTTI_OF(audio::AudioService));
	}


    void GraphicToolService::registerObjectCreators(rtti::Factory &factory)
    {
        auto* appgui_service = getCore().getService<AppGUIService>();
        factory.addObjectCreator(std::make_unique<InfoWindowObjectCreator>(*appgui_service));
        factory.addObjectCreator(std::make_unique<ParameterWindowObjectCreator>(*appgui_service));
        factory.addObjectCreator(std::make_unique<audio::AudioDeviceSettingsWindowObjectCreator>(*appgui_service));
    }
}
