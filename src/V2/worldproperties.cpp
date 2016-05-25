#include "worldproperties.h"

WorldProperties::WorldProperties(const QString &iniFileName)
{
    settings = new QSettings(iniFileName,QSettings::IniFormat);
    _genomeMaxWheels = settings->value("genome/max_wheels",5).toUInt();
    _wheelMaxRadius = settings->value("genome/wheel_max_radius", 5).toDouble();
    _wheelMinRadius = settings->value("genome/wheel_min_radius", 0.2).toDouble();
    _wheelMaxSpeed = settings->value("genome/wheel_max_speed",50).toDouble();
    _wheelMinSpeed = settings->value("genome/wheel_min_speed",1).toDouble();
    _genomeBodyLength = settings->value("genome/body_length",300).toUInt();

    _bodyFriction = settings->value("world/body_friction",0.2).toDouble();
    _wheelFriction = settings->value("world/wheel_friction",1).toDouble();
    _groundFriction = settings->value("world/ground_friction",1).toDouble();
    _bodyEdgeLength = settings->value("world/body_triangle_size",1.0).toDouble();
    _population = settings->value("world/population",50).toUInt();
    _timeMultiplier = settings->value("world/time_multiplier",1.0).toDouble();
    _carDieTime = settings->value("world/car_die_time",20).toDouble();
    _groundMultiplier = settings->value("world/ground_multiplier",1.007).toDouble();
    _groundPlateLength = settings->value("world/ground_plate_length",5).toDouble();
    _trianglePower = settings->value("world/triangle_power",20.0).toDouble();

    _genomeMixPart = settings->value("mix/part", 5).toUInt();

    _genomeMutateMaxCount = settings->value("mutate/max_count",3).toUInt();
    _genomeMutateRate = settings->value("mutate/rate",0.1).toDouble();

    _mixCarsCount = settings->value("mix/cars_count",30).toUInt();



}

WorldProperties::~WorldProperties()
{
    settings->sync();
    delete settings;
}

quint16 WorldProperties::genomeMaxWheels() const
{
    return _genomeMaxWheels;
}

quint16 WorldProperties::genomeBodyLength() const
{
    return _genomeBodyLength;
}

quint32 WorldProperties::population() const
{
    return _population;
}

double WorldProperties::bodyFriction() const
{
    return _bodyFriction;
}

double WorldProperties::wheelMaxRadius() const
{
    return _wheelMaxRadius;
}

double WorldProperties::bodyEdgeLength() const
{
    return _bodyEdgeLength;
}

double WorldProperties::wheelFriction() const
{
    return _wheelFriction;
}

double WorldProperties::wheelMaxSpeed() const
{
    return _wheelMaxSpeed;
}

double WorldProperties::wheelMinSpeed() const
{
    return _wheelMinSpeed;
}

double WorldProperties::groundFriction() const
{
    return _groundFriction;
}

double WorldProperties::wheelMinRadius() const
{
    return _wheelMinRadius;
}

double WorldProperties::timeMultiplier() const
{
    return _timeMultiplier;
}

double WorldProperties::carDieTime() const
{
    return _carDieTime;
}

quint16 WorldProperties::genomeMixPart() const
{
    return _genomeMixPart;
}

double WorldProperties::genomeMutateRate() const
{
    return _genomeMutateRate;
}

quint16 WorldProperties::genomeMutateMaxCount() const
{
    return _genomeMutateMaxCount;
}

quint16 WorldProperties::mixCarsCount() const
{
    return _mixCarsCount;
}

double WorldProperties::groundMultiplier() const
{
    return _groundMultiplier;
}

double WorldProperties::groundPlateLength() const
{
    return _groundPlateLength;
}

double WorldProperties::trianglePower() const
{
    return _trianglePower;
}

QVariantMap WorldProperties::serialize()
{
    QVariantMap p;
    p["genome_max_wheels"] = _genomeMaxWheels;
    p["wheel_max_radius"] = _wheelMaxRadius;
    p["wheel_min_radius"] = _wheelMinRadius;
    p["wheel_max_speed"] = _wheelMaxSpeed;
    p["wheel_min_speed"] = _wheelMinSpeed;
    p["wheel_max_torque"] = _wheelMaxTorque;
    p["wheel_min_torque"] = _wheelMinTorque;
    p["genome_body_length"] = _genomeBodyLength;

    p["body_friction"] = _bodyFriction;
    p["wheel_friction"] = _wheelFriction;
    p["ground_friction"] = _groundFriction;
    p["body_edge_length"] = _bodyEdgeLength;
    p["population"] = _population;
    p["time_multiplier"] = _timeMultiplier;
    p["car_die_time"] = _carDieTime;
    p["ground_multiplier"] = _groundMultiplier;
    p["ground_plate_length"] = _groundPlateLength;
    p["triangle_power"] = _trianglePower;
    p["genome_mix_part"] =_genomeMixPart;
    p["genome_mutate_max_count"] = _genomeMutateMaxCount;
    p["genome_mutate_rate"] = _genomeMutateRate;
    p["mix_cars_count"] = _mixCarsCount;

    return p;
}

void WorldProperties::setPopulation(quint16 v)
{
    _population = v;
    if (_mixCarsCount > v) setMixCarsCount(v);
    settings->setValue("world/population",v);
}


void WorldProperties::setBodyFriction(double v)
{
    _bodyFriction = v;
    settings->setValue("world/body_friction",v);
}

void WorldProperties::setWheelFriction(double v)
{
    _wheelFriction = v;
    settings->setValue("world/wheel_friction",v);
}

void WorldProperties::setGroundFriction(double v)
{
    _groundFriction = v;
    settings->setValue("world/ground_friction",v);
}

void WorldProperties::setWheelMaxRadius(double v)
{
    _wheelMaxRadius = v;
    settings->setValue("genome/wheel_max_radius",v);
}

void WorldProperties::setWheelMinRadius(double v)
{
    _wheelMinRadius =v;
    settings->setValue("genome/wheel_min_radius",v);
}

void WorldProperties::setWheelMaxSpeed(double v)
{
    _wheelMaxSpeed = v;
    settings->setValue("genome/wheel_max_speed",v);
}

void WorldProperties::setWheelMinSpeed(double v)
{
    _wheelMinSpeed = v;
    settings->setValue("genome/wheel_min_speed",v);
}

void WorldProperties::setTimeMultiplier(double v)
{
    _timeMultiplier =v;
    settings->setValue("world/time_multiplier",v);
}

void WorldProperties::setCarDieTime(double v)
{
    _carDieTime =v;
    settings->setValue("world/car_die_time",v);
}

void WorldProperties::setGenomeMixPart(quint16 v)
{
    _genomeMixPart =v;
    settings->setValue("mix/part",v);
}

void WorldProperties::setGenomeMutateRate(double v)
{
    _genomeMutateRate =v;
    settings->setValue("mutate/rate",v);
}

void WorldProperties::setGenomeMutateMaxCount(quint16 v)
{
    _genomeMutateMaxCount =v;
    settings->setValue("mutate/max_count",v);
}

void WorldProperties::setDynasties(quint16 v)
{
    _dynasties =v;
    settings->setValue("mix/dynasties",v);
}

void WorldProperties::setMixCross(quint16 v)
{
    _mixCrosses =v;
    settings->setValue("mix/crosses",v);
}

void WorldProperties::setMixCarsCount(quint16 v)
{
    _mixCarsCount = v;
    if (v > _population) v = _population;
    settings->setValue("mix/cars_count",v);
}

void WorldProperties::setTrianglePower(double v)
{
    _trianglePower = v;
    settings->setValue("world/triangle_power",v);
}
