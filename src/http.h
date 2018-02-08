/*
 * http.h
 *
 *  Created on: 08.02.2018.
 *      Author: srkos
 */

#ifndef HTTP_H_
#define HTTP_H_

// successful response keyword string from server
#define SUCCESSFUL_RESPONSE			"OK"

enum E_RETURN_ACK
{
	RETURN_ACK_OK,
	RETURN_ACK_ERROR,
};

/**
 * Send POST data to the twr_ack_url and get response
 *
 * @param twr_ack_url Full URI location
 * @param post_fields null terminated string with post fields
 * @return 0 (RETURN_ACK_OK) if web-script return "OK", otherwise 1 (RETURN_ACK_ERROR)
 */
int http_ack(char *twr_ack_url, char *post_fields);

#endif /* HTTP_H_ */
