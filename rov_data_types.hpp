//
// Created by zinjkov on 30.03.18.
//

#ifndef RC_ROV_SERVER_ROV_DATA_TYPES_HPP
#define RC_ROV_SERVER_ROV_DATA_TYPES_HPP

#include <stdint.h>
#include "base_packet_t.hpp"


namespace rov_types {
    struct rov_telimetry : public base_packet_t<0x1E, 13, 15> {

        float yaw = 0;
        float pitch = 0;
        float roll = 0;
    private:
        void data_serialize(binary_stream &bs) override final;

        void data_deserialize(binary_stream &bs) override final;
    };

    struct rov_control : public base_packet_t<0x2E, 5, 7> {

        int8_t axis_x = 0;
        int8_t axis_y = 0;
        int8_t axis_z = 0;
        int8_t axis_w = 0;
    private:
        void data_serialize(binary_stream &bs) override final;

        void data_deserialize(binary_stream &bs) override final;
    };


    struct rov_hardware_control : public base_packet_t<0x1A, 9, 11> {

        int8_t horizontal_power[4];
        int8_t vertical_power[4];
    private:
        void data_serialize(binary_stream &bs)  final;

        void data_deserialize(binary_stream &bs)  final;
    };
};


#endif //RC_ROV_SERVER_ROV_DATA_TYPES_HPP
