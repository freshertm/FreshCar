#include "v2lightmanager.h"

V2LightManager::V2LightManager()
{
    _lights.resize(maxLights());
    for (int i=0; i< maxLights(); ++i) {
        _lights[i] = false;
    }
}

void V2LightManager::setLightingEnabled(bool enable)
{
    _lightingEnabled = enable;
    emit lightSettingsChanged();
}

bool V2LightManager::isLightingEnabled() const
{
    return _lightingEnabled;
}

uint16_t V2LightManager::maxLights() const
{
    return 8;
}

void V2LightManager::setLightEnabled(uint16_t num, bool enabled)
{
    if (num >= maxLights()){
        return;
    }
    _lights[num] = enabled;
    emit lightSettingsChanged();
}

bool V2LightManager::isLightEnabled(uint16_t num) const
{
    if (num >= maxLights()){
        return false;
    }
    return _lights[num];
}
