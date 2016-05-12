#ifndef V2RENDERER_H
#define V2RENDERER_H

#include <QObject>
#include "imodule.h"

class V2Renderer : public IModule
{
    Q_OBJECT
public:
    explicit V2Renderer();
    virtual ~V2Renderer();
signals:

public slots:
};

#endif // V2RENDERER_H
