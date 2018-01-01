/*
 * file.c
 *
 *  Created on: Dec 14, 2014
 *      Author: reuben
 */
#include "i2ceeprom.h"

// data save on eeprom
// sensor type(1 byte) sensor id (2 bytes) + time stamp(ddmmyyhhmm - 10 bytes)  + length_measures(1 byte) + measures(2 byte)

typedef union{
	unsigned int word;
	union{
		unsigned char low;
		unsigned char high;
	}byte;
}t_measure;

typedef union{
	unsigned int word;
	union{
		unsigned char low;
		unsigned char high;
	}byte;
}t_sensor_id;

typedef union{
	unsigned int word;
	union{
		unsigned char low;
		unsigned char high;
	}byte;
}t_day;

typedef union{
	unsigned int word;
	union{
		unsigned char low;
		unsigned char high;
	}byte;
}t_mouth;

typedef union{
	unsigned int word;
	union{
		unsigned char low;
		unsigned char high;
	}byte;
}t_year;

typedef union{
	unsigned int word;
	union{
		unsigned char low;
		unsigned char high;
	}byte;
}t_hour;

typedef union{
	unsigned int word;
	union{
		unsigned char low;
		unsigned char high;
	}byte;
}t_minute;

typedef union{
	t_day		day;
	t_mouth		mouth;
	t_year		year;
	t_hour 		hour;
	t_minute	minute;
}t_time_stamp;

typedef struct ee_sensor_data
{
	unsigned char		sensor_type;	// 1 byte
	t_sensor_id			sensor_id;		// 2 bytes
	t_time_stamp		time_stamp;		// 10 bytes
	unsigned char		measure_len;	// 1 byte
	t_measure			measure;		// 48 bytes
}t_ee_sensor_data;


static t_ee_sensor_data	ee_sensor_data;

t_ee_sensor_data *get_ee_sensor_data(void)
{
	return &ee_sensor_data;
}





