

/* =============
Copyright (c) 2022, STMicroelectronics

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that
the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other materials provided with the distribution.

* Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
  products derived from this software without specific prior written permission.

*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER / OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*
*/
/**@vuese
  **************************************************************************
  * Demo: NanoEdge AI process to include in main program body
  *
  * @note  This program must be completed and customized by the user
  **************************************************************************
  */

/* Includes --------------------------------------------------------------------*/
#include "NanoEdgeAI.h"
#include "knowledge.h"
/* Private define --------------------------------------------------------------*/
/* Private variables defined by user -------------------------------------------*/
float input_user_buffer[DATA_INPUT_USER * AXIS_NUMBER]; // Buffer of input values
float output_class_buffer[CLASS_NUMBER]; // Buffer of class probabilities
/* Private function prototypes defined by user ---------------------------------*/
/*
 * @brief Collect data process
 *
 * This function is defined by user, depends on applications and sensors
 *
 * @param sample_buffer: [in, out] buffer of sample values
 * @retval None
 * @note   If AXIS_NUMBER = 3 (cf NanoEdgeAI.h), the buffer must be
 *         ordered as follow:
 *         [x0 y0 z0 x1 y1 z1 ... xn yn zn], where xi, yi and zi
 *         are the values for x, y and z axes, n is equal to
 *         DATA_INPUT_USER (cf NanoEdgeAI.h)
 */
void fill_buffer(float sample_buffer[])
{
	/* USER BEGIN */
	/* USER END */
}
/* -----------------------------------------------------------------------------*/
int main(void)
{
	/* Initialization ------------------------------------------------------------*/
	enum neai_state error_code = neai_classification_init(knowledge);
	if (error_code != NEAI_OK) {
		/* This happens if the knowledge does not correspond to the library or if the library works into a not supported board. */
	}

	/* Classification ------------------------------------------------------------*/
	uint16_t id_class = 0;
	while (1) {
		fill_buffer(input_user_buffer);
		neai_classification(input_user_buffer, output_class_buffer, &id_class);
		/* USER BEGIN */
		/*
		* e.g.: Trigger functions depending on id_class
		* (print output class probabilities using output_class_buffer[],
		* print the name of the identified class using id2class[id_class],
		* blink LED, ring alarm, etc.).
		*/
		/* USER END */
	}
}
