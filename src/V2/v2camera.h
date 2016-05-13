#ifndef V2CAMERA_H
#define V2CAMERA_H

#include <QObject>
#include <glm.hpp>

class V2Camera: public QObject
{
    Q_OBJECT
public:
    V2Camera();
    virtual ~V2Camera();

    virtual bool enable(){return true;}
    virtual bool disable(){return true;}

    const glm::mat4 &matrix();

    glm::vec3 position() { return _position;}
    glm::vec3 up() {return _upVector;}
    glm::vec3 lookPoint(){ return _lookPoint;}

public slots:
    virtual void setLookPoint(const glm::vec3& lookTo);
    virtual void setUp(const glm::vec3& upVector);
    virtual void setPosition(const glm::vec3& position);

protected:
    virtual glm::mat4 getPojectionMatrix();
    void updateCamera();

signals:
    void cameraChanged(V2Camera *);

private:
    glm::mat4 _cameraMatrix;
    glm::vec3 _position;
    glm::vec3 _lookPoint;
    glm::vec3 _upVector;
};

#endif // V2CAMERA_H
