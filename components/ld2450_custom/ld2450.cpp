#include "ld2450.h"

void LD2450::loop() {
  while (available() >= 39) {
    uint8_t header[2];
    read_array(header, 2);

    if (header[0] != 0xAA || header[1] != 0xFF) {
      continue;
    }

    uint8_t buf[37];
    read_array(buf, 37);

    auto parse_track = [&](int offset, float &x, float &y, float &d, float &s) {
      x = (int16_t)((buf[offset + 1] << 8) | buf[offset]);
      y = (int16_t)((buf[offset + 3] << 8) | buf[offset + 2]);
      d = (int16_t)((buf[offset + 5] << 8) | buf[offset + 4]);
      s = (int16_t)((buf[offset + 7] << 8) | buf[offset + 6]);
    };

    parse_track(0, x1, y1, d1, s1);
    parse_track(8, x2, y2, d2, s2);
    parse_track(16, x3, y3, d3, s3);

    track1_x->publish_state(x1);
    track1_y->publish_state(y1);
    track1_distance->publish_state(d1);
    track1_speed->publish_state(s1);

    track2_x->publish_state(x2);
    track2_y->publish_state(y2);
    track2_distance->publish_state(d2);
    track2_speed->publish_state(s2);

    track3_x->publish_state(x3);
    track3_y->publish_state(y3);
    track3_distance->publish_state(d3);
    track3_speed->publish_state(s3);
  }
}