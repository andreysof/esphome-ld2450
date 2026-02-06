#pragma once
#include "esphome.h"

class LD2450 : public Component, public UARTDevice {
 public:
  LD2450(UARTComponent *parent) : UARTDevice(parent) {}

  float x1 = NAN, y1 = NAN, d1 = NAN, s1 = NAN;
  float x2 = NAN, y2 = NAN, d2 = NAN, s2 = NAN;
  float x3 = NAN, y3 = NAN, d3 = NAN, s3 = NAN;

  Sensor *track1_x = new Sensor();
  Sensor *track1_y = new Sensor();
  Sensor *track1_distance = new Sensor();
  Sensor *track1_speed = new Sensor();

  Sensor *track2_x = new Sensor();
  Sensor *track2_y = new Sensor();
  Sensor *track2_distance = new Sensor();
  Sensor *track2_speed = new Sensor();

  Sensor *track3_x = new Sensor();
  Sensor *track3_y = new Sensor();
  Sensor *track3_distance = new Sensor();
  Sensor *track3_speed = new Sensor();

  void setup() override {}
  void loop() override;
};
