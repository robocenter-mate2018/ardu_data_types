//
// Created by zinjkov on 30.03.18.
//

#include "rov_data_types.hpp"


void rov_types::rov_telimetry::data_serialize(rov_types::binary_stream &bs) {
    bs << roll;
    bs << pitch;
    bs << yaw;
}

void rov_types::rov_telimetry::data_deserialize(rov_types::binary_stream &bs) {
    bs >> roll;
    bs >> pitch;
    bs >> yaw;
}


void rov_types::rov_control::data_serialize(rov_types::binary_stream &bs) {
    bs << axis_x;
    bs << axis_y;
    bs << axis_z;
    bs << axis_w;
}

void rov_types::rov_control::data_deserialize(rov_types::binary_stream &bs) {
    bs >> axis_x;
    bs >> axis_y;
    bs >> axis_z;
    bs >> axis_w;
}

void rov_types::rov_hardware_control::data_serialize(rov_types::binary_stream &bs) {
    for(auto & p : horizontal_power) {
        bs << p;
    }
    for(auto & p : vertical_power) {
        bs << p;
    }
}

void rov_types::rov_hardware_control::data_deserialize(rov_types::binary_stream &bs) {
    for(auto & p : horizontal_power) {
        bs >> p;
    }
    for(auto & p : vertical_power) {
        bs >> p;
    }
}