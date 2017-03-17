#ifndef V2CAMERALIST_H
#define V2CAMERALIST_H
#include "v2module.h"
#include <QSharedPointer>
#include <v2camera.h>

class V2CameraList : public V2Module
{
    Q_OBJECT
public:
    V2CameraList();
    ~V2CameraList();


    const QSharedPointer<V2Camera>& currentCamera();

public slots:
    void setCurrent(QSharedPointer<V2Camera>&);

signals:
    void newCameraSelected(const QSharedPointer<V2Camera>&);
private:
    QSharedPointer<V2Camera> _current;

};

#endif // CAMERALIST_H
