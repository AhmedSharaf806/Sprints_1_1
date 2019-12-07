/*
 * pushButton.h
 *
 *  Created on: Oct 21, 2019
 *      Author: Sprints
 */

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include "pushButtonConfig.h"
#include "softwareDelay.h"

typedef enum En_buttonId{
	BTN_0,
	BTN_1,
	BTN_2,
	BTN_3
}En_buttonId;

typedef enum En_buttonStatus_t{
	Released,
	Prepressed,
	Pressed,
	Prereleased

}En_buttonStatus_t;


typedef struct pushButton_status{

    uint8 pushButton_saved_status;
    uint8 pushButton_status_btn;

}pushButton_status;

/**
 * Description: Initialize the BTN_x Pin state (where x 0, 1, 2, 3) to Input
 * @param btn_id: The btn to be initialized and it takes
 * 				  one of the enum (En_buttonId) parameters
 *
 */
void pushButton_Init(En_buttonId btn_id);
/**
 * Description: read all BTN_x (where x 0, 1, 2, 3) states and store it in the program
 *
 * @note : this function must be called in the system tick hundler or in the super loop hundler
 */
void pushButton_Update(void);
/**
 * Description: read BTN_x (where x 0, 1, 2, 3) state which is stored in the program
 * 				in the update function
 *
 */
En_buttonStatus_t pushButton_GetStatus(En_buttonId btn_id);

#endif /* PUSHBUTTON_H_ */
