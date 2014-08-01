#ifndef WORLDPROPERTIES_H
#define WORLDPROPERTIES_H
#include <QString>
#include <QSettings>
#include <QObject>

class WorldProperties: public QObject
{
    Q_OBJECT
public:
    WorldProperties(const QString & iniFileName);
    ~WorldProperties();

    quint16 genomeMaxWheels() const;
    quint16 genomeBodyLength() const;
    quint32 population() const;
    double  bodyFriction() const;
    double  wheelMaxRadius() const;
    double  bodyEdgeLength() const;
    double wheelFriction() const;
    double wheelMaxSpeed() const;
    double wheelMinSpeed() const;
    double groundFriction() const;
    double wheelMinRadius() const;

    double timeMultiplier() const;
    double carDieTime() const;
    quint16 genomeMixPart() const;
    double genomeMutateRate() const;
    quint16 genomeMutateMaxCount() const;

    quint16 mixCarsCount() const;
    double groundMultiplier() const;
    double groundPlateLength() const;

    double trianglePower() const;

public slots:
    void setPopulation(quint16);


    void setBodyFriction(double);
    void setWheelFriction(double);
    void setGroundFriction(double);

    void setWheelMaxRadius(double);
    void setWheelMinRadius(double);

    void setWheelMaxSpeed(double);
    void setWheelMinSpeed(double);

    void setTimeMultiplier(double);

    void setCarDieTime(double);
    void setGenomeMixPart(quint16);
    void setGenomeMutateRate(double);
    void setGenomeMutateMaxCount(quint16);
    void setDynasties(quint16);
    void setMixCross(quint16);
    void setMixCarsCount(quint16);
    void setTrianglePower(double);

private :
    QSettings *settings;
    quint16 _genomeMaxWheels;
    quint16 _genomeBodyLength;
    double _bodyFriction;
    double _wheelMinTorque;
    double _wheelMaxTorque;
    quint32 _population;
    double _wheelMaxRadius;
    double _bodyEdgeLength;
    double _wheelFriction;
    double _wheelMaxSpeed;
    double _wheelMinSpeed;
    double _groundFriction;
    double _wheelMinRadius;
    double _timeMultiplier;
    double _carDieTime;
    quint16 _genomeMixPart;
    quint16 _genomeMutateMaxCount;
    double _genomeMutateRate;
    quint16 _dynasties;
    quint16 _mixCrosses;
    double _groundMultiplier;
    double  _groundPlateLength;
    quint16 _mixCarsCount;
    double _trianglePower;
};

#endif // WORLDPROPERTIES_H
