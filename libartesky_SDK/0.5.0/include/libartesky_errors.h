#pragma once

#include <stdint.h>
typedef uint32_t ASL_ERROR;

constexpr auto ASL_NO_ERROR             = 0x00;
constexpr auto ASL_COM_ERROR            = 0x01;
constexpr auto ASL_CONNECTION_ERROR     = 0x02;
constexpr auto ASL_TURN_ON_ERROR        = 0x03;
constexpr auto ASL_TURN_OFF_ERROR       = 0x04;
constexpr auto ASL_SET_BRIGHTNESS_ERROR = 0x05;
constexpr auto ASL_GET_BRIGHTNESS_ERROR = 0x06;
constexpr auto ASL_GET_STATUS_ERROR     = 0x07;
constexpr auto ASL_COM_FINDER_ERROR     = 0x08;