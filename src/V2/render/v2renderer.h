#ifndef V2RENDERER_H
#define V2RENDERER_H

#include <QObject>
#include "v2module.h"

class V2Renderer : public V2Module
{
    Q_OBJECT
public:
    explicit V2Renderer();
    virtual ~V2Renderer();
signals:

public slots:
};

#endif // V2RENDERER_H
