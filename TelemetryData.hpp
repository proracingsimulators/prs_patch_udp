/**
 * @file TelemetryData.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __TELEMETRYDATA__H__
#define __TELEMETRYDATA__H__

struct TelemetryData {
    double roll;
    double pitch;
    double heave;
    double yaw;
    double sway;
    double surge;
    double tractionLoss;
    int gear;
} __attribute__((packed));

#endif  //!__TELEMETRYDATA__H__