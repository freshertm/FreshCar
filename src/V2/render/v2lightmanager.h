#ifndef V2LIGHTMANAGER_H
#define V2LIGHTMANAGER_H

#include "v2module.h"
#include <QVector>

class V2LightManager: public V2Module
{
    Q_OBJECT
public:
    V2LightManager();

    void setLightingEnabled(bool enable);
    bool isLightingEnabled() const;

    uint16_t maxLights() const;

    void setLightEnabled(uint16_t num, bool enabled);
    bool isLightEnabled(uint16_t num) const;

signals:
    void lightSettingsChanged();

private:
    bool _lightingEnabled = false;
    QVector<bool> _lights;
};

#endif // V2LIGHTMANAGER_H
